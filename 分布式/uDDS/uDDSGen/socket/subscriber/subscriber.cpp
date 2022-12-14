/**********************************************************
*****************���Ķ˳���subscriber.cpp*******************
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
/* IDL_TypeSupport.h�а�������������ͷ�ļ� */
#include "IDL_TypeSupport1.h"
#include "IDL_TypeSupport2.h"
int flag = 0;
float avg[3],avs;
char ID[3][100];
/* UserDataTypeListener�̳���DataReaderListener��
 ��Ҫ��д��̳й����ķ���on_data_available()�������н������ݼ�����ȡ���� */
class UserDataTypeListener : public DataReaderListener {
public:
	virtual void on_data_available(DataReader* reader);
};
/* ��д�̳й����ķ���on_data_available()�������н������ݼ�����ȡ���� */
void UserDataTypeListener::on_data_available(DataReader* reader)
{
	GradeDataReader* Grade_reader = NULL;
	GradeSeq data_seq;
	SampleInfoSeq info_seq;
	ReturnCode_t retcode;
	int i;
	/* ����reader������һ����ȡUserDataType���͵�UserDataType_reader*/
	Grade_reader = GradeDataReader::narrow(reader);
	if (Grade_reader == NULL) {
		fprintf(stderr, "DataReader narrow error\n");
		return;
	}
	
	/* ��ȡ���ݣ������data_seq��data_seq��һ������ */
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
		printf("��һ������Ϊ: %f\n", avg[0]);
		printf("�ڶ�������Ϊ: %f\n", avg[1]);
		printf("����������Ϊ: %f\n", avg[2]);
		printf("average score: %f\n", avs);
	}
	/* ��ӡ���� */
	/* ����1�������ڴ˽��и������ݴ��� */
	/* ����2�������ݴ��͵��������ݴ����߳��н��д��� *
	/* ����3���������ݽṹ����string���ͣ���������ֶ��ͷ� */
	
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
/* ɾ������ʵ�� */
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
/* �����ߺ��� */
extern "C" int subscriber_main(int domainId, int sample_count)
{
	float avg[3], avs;
	char ID[3][100];
	DomainParticipant* participant = NULL;
	Subscriber* subscriber = NULL;
	Topic* topic = NULL;
	UserDataTypeListener* reader_listener = NULL;
	DataReader* reader = NULL;
	ReturnCode_t retcode1,retcode2;
	const char* type_name1 = NULL;
	const char* type_name2 = NULL;
	int count = 0;
	int status = 0;
	/* 1. ����һ��participant�������ڴ˴�����participant��QoS */
	/* ����1���ڳ������������ȴ���participant��������Դ��ʼ��*/
	/* ����2����ͬ��domainIdֻ����һ��participant���ظ�������ռ�ô�����Դ */
	participant = DomainParticipantFactory::get_instance()->create_participant(
		domainId, PARTICIPANT_QOS_DEFAULT/* participantĬ��QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (participant == NULL) {
		fprintf(stderr, "create_participant error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	/* 2. ����һ��subscriber�������ڴ���subscriber��ͬʱ������QoS */
	/* ����1���ڳ������������ȴ���subscriber*/
	/* ����2��һ��participant�´���һ��subscriber���ɣ������ظ����� */
	subscriber = participant->create_subscriber(
		SUBSCRIBER_QOS_DEFAULT/* Ĭ��QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (subscriber == NULL) {
		fprintf(stderr, "create_subscriber error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	/* 3. �ڴ�������֮ǰע���������� */
	/* ����1���ڳ������������Ƚ���ע�� */
	/* ����2��һ����������ע��һ�μ��� */
	type_name1 = GradeTypeSupport::get_type_name();
	//type_name2 = AverageGradeTypeSupport::get_type_name();
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
	/* 4. �������⣬�����������QoS */
	/* ����1���ڳ������������ȴ���Topic */
	/* ����2��һ������������һ�μ��ɣ������ظ����� */
	topic = participant->create_topic(
		"tpc_Grade"/* ��������Ӧ�뷢����������һ�� */,
		type_name1, TOPIC_QOS_DEFAULT/* Ĭ��QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (topic == NULL) {
		fprintf(stderr, "create_topic error\n");
		subscriber_shutdown(participant);
		return -1;
	}
	/* 5. ����һ�������� */
	reader_listener = new UserDataTypeListener();
	/* 6. ����datareader��������datareader��QoS */
	/* ����1���ڳ������������ȴ���datareader*/
	/* ����2������һ�μ��ɣ������ظ����� */
	/* ����3���ڳ����˳�ʱ�ٽ����ͷ� */
	/* ����4����������������ʱ����datareader���������ݺ�ɾ����������������Դ��Ӱ������ */
	reader = subscriber->create_datareader(
		topic, DATAREADER_QOS_DEFAULT/* Ĭ��QoS */,
		reader_listener/* listener */, STATUS_MASK_ALL);
	if (reader == NULL) {
		fprintf(stderr, "create_datareader error\n");
		subscriber_shutdown(participant);
		delete reader_listener;
		return -1;
	}
	/* 7. ��ѭ�� ����������Ĭ�ϵ���on_data_available()�������� */
	for (count = 0; (sample_count == 0) || (count < sample_count); ++count) {
		//���ֽ���һֱ����
		
	}
	/* 8. ɾ������ʵ��ͼ����� */
	status = subscriber_shutdown(participant);
	delete reader_listener;
	return status;
}
int main(int argc, char* argv[])
{
	int domain_id = 0;
	int sample_count = 0; /* ����ѭ�� */
	if (argc >= 2) {
		domain_id =atoi(argv[1]);/* ��������domain_id */
	}
	if (argc >= 3) {
		sample_count = atoi(argv[2]);/* ����sample_count�� */
	}
	return subscriber_main(domain_id, sample_count);
}