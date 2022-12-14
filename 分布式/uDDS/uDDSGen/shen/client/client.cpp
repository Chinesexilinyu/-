/**********************************************************
*****************�����˳���publisher.cpp********************
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

/* IDL_TypeSupport.h�а�������������ͷ�ļ� */
#include "IDL_TypeSupport.h"

int flag = 0;

/* UserDataTypeListener�̳���DataReaderListener��
 ��Ҫ��д��̳й����ķ���on_data_available()�������н������ݼ�����ȡ���� */
class UserDataTypeListener : public DataReaderListener {
public:
	virtual void on_data_available(DataReader* reader);
};
/* ��д�̳й����ķ���on_data_available()�������н������ݼ�����ȡ���� */
void UserDataTypeListener::on_data_available(DataReader* reader)
{
	AverageGradeDataReader* AverageGrade_reader = NULL;
	AverageGradeSeq data_seq;
	SampleInfoSeq info_seq;
	ReturnCode_t retcode;
	int i;
	/* ����reader������һ����ȡUserDataType���͵�UserDataType_reader*/
	AverageGrade_reader = AverageGradeDataReader::narrow(reader);
	if (AverageGrade_reader == NULL) {
		fprintf(stderr, "DataReader narrow error\n");
		return;
	}

	/* ��ȡ���ݣ������data_seq��data_seq��һ������ */
	retcode = AverageGrade_reader->read(
		data_seq, info_seq, 10, 0, 0, 0);
	if (retcode == RETCODE_NO_DATA) {
		return;
	}
	else if (retcode != RETCODE_OK) {
		fprintf(stderr, "take error %d\n", retcode);
		return;
	}
	/* ��ӡ���� */
	/* ����1�������ڴ˽��и������ݴ��� */
	/* ����2�������ݴ��͵��������ݴ����߳��н��д��� *
	/* ����3���������ݽṹ����string���ͣ���������ֶ��ͷ� */
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
/* ɾ������ʵ�� */
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
/* �����ߺ��� */
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
	/* 1. ����һ��participant�������ڴ˴�����participant��QoS */
	/* ����1���ڳ������������ȴ���participant��������Դ��ʼ��*/
	/* ����2����ͬ��domainIdֻ����һ��participant���ظ�������ռ�ô�����Դ */
	participant = DomainParticipantFactory::get_instance()->create_participant(
		domainId, PARTICIPANT_QOS_DEFAULT/* participantĬ��QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (participant == NULL) {
		fprintf(stderr, "create_participant error\n");
		publisher_shutdown(participant);
		return -1;
	}
	/* 2. ����һ��publisher�������ڴ���publisher��ͬʱ������QoS */
	/* ����1���ڳ������������ȴ���publisher */
	/* ����2��һ��participant�´���һ��publisher���ɣ������ظ����� */
	publisher = participant->create_publisher(
		PUBLISHER_QOS_DEFAULT /* Ĭ��QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (publisher == NULL) {
		fprintf(stderr, "create_publisher error\n");
		publisher_shutdown(participant);
		return -1;
	}
	subscriber = participant->create_subscriber(
		SUBSCRIBER_QOS_DEFAULT/* Ĭ��QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (subscriber == NULL) {
		fprintf(stderr, "create_subscriber error\n");
		publisher_shutdown(participant);
		return -1;
	}
	/* 3. �ڴ�������֮ǰע���������� */
	/* ����1���ڳ������������Ƚ���ע�� */
	/* ����2��һ����������ע��һ�μ��� */
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
	/* 4. �������⣬�����������QoS */
	/* ����1���ڳ������������ȴ���Topic */
	/* ����2��һ������������һ�μ��ɣ������ظ����� */
	topic1 = participant->create_topic(
		"tpc_Grade"/* ������ */,
		type_name1 /* ������ */, TOPIC_QOS_DEFAULT/* Ĭ��QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (topic1 == NULL) {
		fprintf(stderr, "create_topic error\n");
		publisher_shutdown(participant);
		return -1;
	}
	topic2 = participant->create_topic(
		"tpc_AvgGrade"/* ������ */,
		type_name2 /* ������ */, TOPIC_QOS_DEFAULT/* Ĭ��QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (topic2 == NULL) {
		fprintf(stderr, "create_topic error\n");
		publisher_shutdown(participant);
		return -1;
	}
	reader_listener = new UserDataTypeListener();
	/* 5. ����datawriter��������datawriter��QoS */
	/* ����1���ڳ������������ȴ���datawriter */
	/* ����2������һ�μ��ɣ������ظ����� */
	/* ����3���ڳ����˳�ʱ�ٽ����ͷ� */
	/* ����4��������㷢������ʱ����datawriter���������ݺ�ɾ����������������Դ��Ӱ������ */
	writer = publisher->create_datawriter(
		topic1, DATAWRITER_QOS_DEFAULT/* Ĭ��QoS */,
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
		topic2, DATAREADER_QOS_DEFAULT/* Ĭ��QoS */,
		reader_listener/* listener */, STATUS_MASK_ALL);
	if (reader == NULL) {
		fprintf(stderr, "create_datareader error\n");
		publisher_shutdown(participant);
		delete reader_listener;
		return -1;
	}
	/* 6. ����һ���������� */
	/* ���飺������Ϊnew�����ģ�ʹ�ú��û���Ҫ����delete_data�����ͷ��ڴ�*/
	tpc_grade = GradeTypeSupport::create_data();
	if (tpc_grade == NULL) {
		fprintf(stderr, "GradeTypeSupport::create_data error\n");
		publisher_shutdown(participant);
		return -1;
	}
	char name1[100], ID1[100];
	float f;
	/* 7. ��ѭ�� ���������� */
	for (count = 0; (sample_count == 0) || (count < sample_count); ++count, flag++) {
		/* �ڴ˴��޸����� */
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
		Sleep(1000);   //��˯һ��
	}
	/* 8. ɾ���������� */
	retcode1 = GradeTypeSupport::delete_data(tpc_grade);
	if (retcode1 != RETCODE_OK) {
		fprintf(stderr, "GradeTypeSupport::delete_data error %d\n", retcode1);
	}
	/* 9. ɾ������ʵ�� */
	status = publisher_shutdown(participant);
	delete reader_listener;
	return status;
}
int main(int argc, char* argv[])
{
	int domain_id = 0;
	int sample_count = 0; /* ����ѭ�� */
	if (argc >= 2) {
		domain_id = atoi(argv[1]); /* ��������domain_id */
	}
	if (argc >= 3) {
		sample_count = atoi(argv[2]); /* ����sample_count�� */
	}
	return publisher_main(domain_id, sample_count);
}
