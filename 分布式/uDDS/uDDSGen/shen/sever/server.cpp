/**********************************************************
*****************订阅端程序subscriber.cpp*******************
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
/* IDL_TypeSupport.h中包含所有依赖的头文件 */
#include "IDL_TypeSupport.h"

int flag = 0;
float avg[3], avs;
char ID[3][100];
bool zcy = false;
/* UserDataTypeListener继承于DataReaderListener，
 需要重写其继承过来的方法on_data_available()，在其中进行数据监听读取操作 */
class UserDataTypeListener : public DataReaderListener {
public:
	virtual void on_data_available(DataReader* reader);
};
/* 重写继承过来的方法on_data_available()，在其中进行数据监听读取操作 */
void UserDataTypeListener::on_data_available(DataReader* reader)
{
	GradeDataReader* Grade_reader = NULL;
	GradeSeq data_seq;
	SampleInfoSeq info_seq;
	ReturnCode_t retcode;
	int i;
	/* 利用reader，创建一个读取UserDataType类型的UserDataType_reader*/
	Grade_reader = GradeDataReader::narrow(reader);
	if (Grade_reader == NULL) {
		fprintf(stderr, "DataReader narrow error\n");
		return;
	}

	/* 获取数据，存放至data_seq，data_seq是一个队列 */
	retcode = Grade_reader->read(
		data_seq, info_seq, 10, 0, 0, 0);
	if (retcode == RETCODE_NO_DATA) {
		return;
	}
	else if (retcode != RETCODE_OK) {
		fprintf(stderr, "take error %d\n", retcode);
		return;
	}
	avg[flag] = data_seq[0].score;
	strcpy_s(ID[flag], 100, data_seq[0].ID);
	flag++;
	if (flag == 3)
	{
		avs = (avg[0] + avg[1] + avg[2]) / 3;
		flag = 0;
		zcy = true;
	}
	/* 打印数据 */
	/* 建议1：避免在此进行复杂数据处理 */
	/* 建议2：将数据传送到其他数据处理线程中进行处理 *
	/* 建议3：假如数据结构中有string类型，用完后需手动释放 */

	for (i = 0; i < data_seq.length(); ++i)
	{
		printf("receive: name=%s,ID=%s,score=%f\n",
			data_seq[i].name, data_seq[i].ID, data_seq[i].score);
		delete data_seq[i].name;
		data_seq[i].name = NULL;
		delete data_seq[i].ID;
		data_seq[i].ID = NULL;
	}
}
/* 删除所有实体 */
static int subscriber_shutdown(
	DomainParticipant* participant)
{
	ReturnCode_t retcode;
	int status = 0;
	if (participant != NULL) {
		retcode = participant->delete_contained_entities();
		if (retcode != RETCODE_OK) {
			fprintf(stderr, "delete_contained_entities error %d\n", retcode);
			status = -1;
		}
		retcode = DomainParticipantFactory::get_instance()->delete_participant(participant);
		if (retcode != RETCODE_OK) {
			fprintf(stderr, "delete_participant error %d\n", retcode);
			status = -1;
		}
	}
	return status;
}
/* 订阅者函数 */
extern "C" int subscriber_main(int domainId, int sample_count)
{
	DomainParticipant* participant = NULL;
	Subscriber* subscriber = NULL;
	Publisher* publisher = NULL;
	Topic* topic1 = NULL;
	Topic* topic2 = NULL;
	UserDataTypeListener* reader_listener = NULL;
	DataReader* reader = NULL;
	DataWriter* writer = NULL;
	ReturnCode_t retcode1,retcode2;
	AverageGradeDataWriter* AverageGrade_writer = NULL;
	AverageGrade* tpc_avggrade = NULL;
	const char* type_name1 = NULL;
	const char* type_name2 = NULL;
	int count = 0;
	int status = 0;
	InstanceHandle_t instance_handle = HANDLE_NIL;
	/* 1. 创建一个participant，可以在此处定制participant的QoS */
	/* 建议1：在程序启动后优先创建participant，进行资源初始化*/
	/* 建议2：相同的domainId只创建一次participant，重复创建会占用大量资源 */
	participant = DomainParticipantFactory::get_instance()->create_participant(
		domainId, PARTICIPANT_QOS_DEFAULT/* participant默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (participant == NULL) {
		fprintf(stderr, "create_participant error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	/* 2. 创建一个subscriber，可以在创建subscriber的同时定制其QoS */
	/* 建议1：在程序启动后优先创建subscriber*/
	/* 建议2：一个participant下创建一个subscriber即可，无需重复创建 */
	subscriber = participant->create_subscriber(
		SUBSCRIBER_QOS_DEFAULT/* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (subscriber == NULL) {
		fprintf(stderr, "create_subscriber error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	publisher = participant->create_publisher(
		PUBLISHER_QOS_DEFAULT /* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (publisher == NULL) {
		fprintf(stderr, "create_publisher error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	/* 3. 在创建主题之前注册数据类型 */
	/* 建议1：在程序启动后优先进行注册 */
	/* 建议2：一个数据类型注册一次即可 */
	type_name1 = GradeTypeSupport::get_type_name();
	type_name2 = AverageGradeTypeSupport::get_type_name();
	retcode1 = GradeTypeSupport::register_type(
		participant, type_name1);
	retcode2 = AverageGradeTypeSupport::register_type(
		participant, type_name2);
	if (retcode1 != RETCODE_OK) {
		fprintf(stderr, "register_type error %d\n", retcode1);
		subscriber_shutdown(participant);
		return -1;
	}
	if (retcode2 != RETCODE_OK) {
		fprintf(stderr, "register_type error %d\n", retcode2);
		subscriber_shutdown(participant);
		return -1;
	}
	/* 4. 创建主题，并定制主题的QoS */
	/* 建议1：在程序启动后优先创建Topic */
	/* 建议2：一种主题名创建一次即可，无需重复创建 */
	topic1 = participant->create_topic(
		"tpc_Grade"/* 主题名，应与发布者主题名一致 */,
		type_name1, TOPIC_QOS_DEFAULT/* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (topic1 == NULL) {
		fprintf(stderr, "create_topic error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	topic2 = participant->create_topic(
		"tpc_AvgGrade"/* 主题名，应与发布者主题名一致 */,
		type_name2, TOPIC_QOS_DEFAULT/* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (topic2 == NULL) {
		fprintf(stderr, "create_topic error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	/* 5. 创建一个监听器 */
	reader_listener = new UserDataTypeListener();

	/*6.1创建datawriter*/
	writer = publisher->create_datawriter(
		topic2, DATAWRITER_QOS_DEFAULT/* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (writer == NULL) {
		fprintf(stderr, "create_datawriter error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	AverageGrade_writer = AverageGradeDataWriter::narrow(writer);
	if (AverageGrade_writer == NULL) {
		fprintf(stderr, "DataWriter narrow error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	tpc_avggrade = AverageGradeTypeSupport::create_data();
	if (tpc_avggrade == NULL) {
		fprintf(stderr, "AverageGradeTypeSupport::create_data error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	/* 6. 创建datareader，并定制datareader的QoS */
	/* 建议1：在程序启动后优先创建datareader*/
	/* 建议2：创建一次即可，无需重复创建 */
	/* 建议3：在程序退出时再进行释放 */
	/* 建议4：避免打算接收数据时创建datareader，接收数据后删除，该做法消耗资源，影响性能 */
	reader = subscriber->create_datareader(
		topic1, DATAREADER_QOS_DEFAULT/* 默认QoS */,
		reader_listener/* listener */, STATUS_MASK_ALL);
	if (reader == NULL) {
		fprintf(stderr, "create_datareader error\n");
		subscriber_shutdown(participant);
		delete reader_listener;
		return -1;
	}
	/* 7. 主循环 ，监听器会默认调用on_data_available()监听数据 */
	for (count = 0; (sample_count == 0) || (count < sample_count); ++count) {
		//保持进程一直运行
		/*while (zcy == false)
		{
			reader_listener->on_data_available(reader);
		}*/
		if (zcy == true)
		{
			tpc_avggrade->ID1 = new char[100];
			tpc_avggrade->ID2 = new char[100];
			tpc_avggrade->ID3 = new char[100];
			tpc_avggrade->avgScore = avs;
			strcpy_s(tpc_avggrade->ID1, 100, ID[0]);
			strcpy_s(tpc_avggrade->ID2, 100, ID[1]);
			strcpy_s(tpc_avggrade->ID3, 100, ID[2]);
			retcode2 = AverageGrade_writer->write(*tpc_avggrade, instance_handle);
			if (retcode2 != RETCODE_OK)
			{
				fprintf(stderr, "write error %d\n", retcode2);
			}
			else
				fprintf(stderr, "%d : write successfully . . \n", count);
			zcy = false;
		}
	}
	retcode2 = AverageGradeTypeSupport::delete_data(tpc_avggrade);
	if (retcode2 != RETCODE_OK) {
		fprintf(stderr, "AverageGradeTypeSupport::delete_data error %d\n", retcode2);
	}
	printf("%s\n", "到最后一步了");
	/* 8. 删除所有实体和监听器 */
	status = subscriber_shutdown(participant);
	delete reader_listener;
	return status;
}
int main(int argc, char* argv[])
{
	int domain_id = 0;
	int sample_count = 0; /* 无限循环 */
	if (argc >= 2) {
		domain_id = atoi(argv[1]); //发送至域domain_id 
	}
	if (argc >= 3) {
		sample_count = atoi(argv[2]);// 发送sample_count次 
	}
	return subscriber_main(domain_id, sample_count);
}