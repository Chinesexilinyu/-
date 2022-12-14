/**********************************************************
*****************发布端程序publisher.cpp********************
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

/* IDL_TypeSupport.h中包含所有依赖的头文件 */
#include "IDL_TypeSupport.h"

int flag = 0;

/* UserDataTypeListener继承于DataReaderListener，
 需要重写其继承过来的方法on_data_available()，在其中进行数据监听读取操作 */
class UserDataTypeListener : public DataReaderListener {
public:
	virtual void on_data_available(DataReader* reader);
};
/* 重写继承过来的方法on_data_available()，在其中进行数据监听读取操作 */
void UserDataTypeListener::on_data_available(DataReader* reader)
{
	AverageGradeDataReader* AverageGrade_reader = NULL;
	AverageGradeSeq data_seq;
	SampleInfoSeq info_seq;
	ReturnCode_t retcode;
	int i;
	/* 利用reader，创建一个读取UserDataType类型的UserDataType_reader*/
	AverageGrade_reader = AverageGradeDataReader::narrow(reader);
	if (AverageGrade_reader == NULL) {
		fprintf(stderr, "DataReader narrow error\n");
		return;
	}

	/* 获取数据，存放至data_seq，data_seq是一个队列 */
	retcode = AverageGrade_reader->read(
		data_seq, info_seq, 10, 0, 0, 0);
	if (retcode == RETCODE_NO_DATA) {
		return;
	}
	else if (retcode != RETCODE_OK) {
		fprintf(stderr, "take error %d\n", retcode);
		return;
	}
	/* 打印数据 */
	/* 建议1：避免在此进行复杂数据处理 */
	/* 建议2：将数据传送到其他数据处理线程中进行处理 *
	/* 建议3：假如数据结构中有string类型，用完后需手动释放 */
	for (i = 0; i < data_seq.length(); ++i)
	{
		printf("receive: ID1=%s,ID2=%s,ID33=%s,averagescore=%f\n",
			data_seq[i].ID1, data_seq[i].ID2, data_seq[i].ID3, data_seq[i].avgScore);
		delete data_seq[i].ID1;
		data_seq[i].ID1 = NULL;
		delete data_seq[i].ID2;
		data_seq[i].ID2 = NULL;
		delete data_seq[i].ID3;
		data_seq[i].ID3 = NULL;
		flag = 0;
	}
}
/* 删除所有实体 */
static int publisher_shutdown(DomainParticipant* participant)
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
/* 发布者函数 */
extern "C" int publisher_main(int domainId, int sample_count)
{
	DomainParticipant* participant = NULL;
	Publisher* publisher = NULL;
	Subscriber* subscriber = NULL;
	Topic* topic1 = NULL;
	Topic* topic2 = NULL;
	DataReader* reader = NULL;
	DataWriter* writer = NULL;
	GradeDataWriter* Grade_writer = NULL;
	UserDataTypeListener* reader_listener = NULL;
	Grade* tpc_grade = NULL;
	ReturnCode_t retcode1;
	ReturnCode_t retcode2;
	InstanceHandle_t instance_handle = HANDLE_NIL;
	const char* type_name1 = NULL;
	const char* type_name2 = NULL;
	int count = 0;
	
	int status = 0;
	/* 1. 创建一个participant，可以在此处定制participant的QoS */
	/* 建议1：在程序启动后优先创建participant，进行资源初始化*/
	/* 建议2：相同的domainId只创建一次participant，重复创建会占用大量资源 */
	participant = DomainParticipantFactory::get_instance()->create_participant(
		domainId, PARTICIPANT_QOS_DEFAULT/* participant默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (participant == NULL) {
		fprintf(stderr, "create_participant error\n");
		publisher_shutdown(participant);
		return -1;
	}
	/* 2. 创建一个publisher，可以在创建publisher的同时定制其QoS */
	/* 建议1：在程序启动后优先创建publisher */
	/* 建议2：一个participant下创建一个publisher即可，无需重复创建 */
	publisher = participant->create_publisher(
		PUBLISHER_QOS_DEFAULT /* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (publisher == NULL) {
		fprintf(stderr, "create_publisher error\n");
		publisher_shutdown(participant);
		return -1;
	}
	subscriber = participant->create_subscriber(
		SUBSCRIBER_QOS_DEFAULT/* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (subscriber == NULL) {
		fprintf(stderr, "create_subscriber error\n");
		publisher_shutdown(participant);
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
		publisher_shutdown(participant);
		return -1;
	}
	if (retcode2 != RETCODE_OK) {
		fprintf(stderr, "register_type error %d\n", retcode2);
		publisher_shutdown(participant);
		return -1;
	}
	/* 4. 创建主题，并定制主题的QoS */
	/* 建议1：在程序启动后优先创建Topic */
	/* 建议2：一种主题名创建一次即可，无需重复创建 */
	topic1 = participant->create_topic(
		"tpc_Grade"/* 主题名 */,
		type_name1 /* 类型名 */, TOPIC_QOS_DEFAULT/* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (topic1 == NULL) {
		fprintf(stderr, "create_topic error\n");
		publisher_shutdown(participant);
		return -1;
	}
	topic2 = participant->create_topic(
		"tpc_AvgGrade"/* 主题名 */,
		type_name2 /* 类型名 */, TOPIC_QOS_DEFAULT/* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (topic2 == NULL) {
		fprintf(stderr, "create_topic error\n");
		publisher_shutdown(participant);
		return -1;
	}
	reader_listener = new UserDataTypeListener();
	/* 5. 创建datawriter，并定制datawriter的QoS */
	/* 建议1：在程序启动后优先创建datawriter */
	/* 建议2：创建一次即可，无需重复创建 */
	/* 建议3：在程序退出时再进行释放 */
	/* 建议4：避免打算发送数据时创建datawriter，发送数据后删除，该做法消耗资源，影响性能 */
	writer = publisher->create_datawriter(
		topic1, DATAWRITER_QOS_DEFAULT/* 默认QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (writer == NULL) {
		fprintf(stderr, "create_datawriter error\n");
		publisher_shutdown(participant);
		return -1;
	}
	Grade_writer = GradeDataWriter::narrow(writer);
	if (Grade_writer == NULL) {
		fprintf(stderr, "DataWriter narrow error\n");
		publisher_shutdown(participant);
		return -1;
	}
	reader = subscriber->create_datareader(
		topic2, DATAREADER_QOS_DEFAULT/* 默认QoS */,
		reader_listener/* listener */, STATUS_MASK_ALL);
	if (reader == NULL) {
		fprintf(stderr, "create_datareader error\n");
		publisher_shutdown(participant);
		delete reader_listener;
		return -1;
	}
	/* 6. 创建一个数据样本 */
	/* 建议：该数据为new出来的，使用后用户需要调用delete_data进行释放内存*/
	tpc_grade = GradeTypeSupport::create_data();
	if (tpc_grade == NULL) {
		fprintf(stderr, "GradeTypeSupport::create_data error\n");
		publisher_shutdown(participant);
		return -1;
	}
	char name1[100], ID1[100];
	float f;
	/* 7. 主循环 ，发送数据 */
	for (count = 0; (sample_count == 0) || (count < sample_count); ++count, flag++) {
		/* 在此处修改数据 */
		tpc_grade->name = new char[100];
		tpc_grade->ID = new char[100];
		//scanf("%s", stu1.id);
		scanf_s("%s", name1, 100);
		scanf_s("%s", ID1, 100);
		scanf_s("%f", &f);
		tpc_grade->score = f;
		strcpy_s(tpc_grade->name, 100, name1);
		strcpy_s(tpc_grade->ID, 100, ID1);
		retcode1 = Grade_writer->write(*tpc_grade, instance_handle);
		if (retcode1 != RETCODE_OK) {
			fprintf(stderr, "write error %d\n", retcode1);
		}
		else
			fprintf(stderr, "%d : write successfully . . \n", count);
		while(flag == 2)
		{
			reader_listener->on_data_available(reader);
		}
		Sleep(1000);   //沉睡一秒
	}
	/* 8. 删除数据样本 */
	retcode1 = GradeTypeSupport::delete_data(tpc_grade);
	if (retcode1 != RETCODE_OK) {
		fprintf(stderr, "GradeTypeSupport::delete_data error %d\n", retcode1);
	}
	/* 9. 删除所有实例 */
	status = publisher_shutdown(participant);
	delete reader_listener;
	return status;
}
int main(int argc, char* argv[])
{
	int domain_id = 0;
	int sample_count = 0; /* 无限循环 */
	if (argc >= 2) {
		domain_id = atoi(argv[1]); /* 发送至域domain_id */
	}
	if (argc >= 3) {
		sample_count = atoi(argv[2]); /* 发送sample_count次 */
	}
	return publisher_main(domain_id, sample_count);
}
