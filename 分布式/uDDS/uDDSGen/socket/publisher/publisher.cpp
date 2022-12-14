/**********************************************************
*****************�����˳���publisher.cpp********************
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

/* IDL_TypeSupport.h�а�������������ͷ�ļ� */
#include "IDL_TypeSupport2.h"
#include "IDL_TypeSupport1.h"







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
	Topic* topic = NULL;
	DataWriter* writer = NULL;
	GradeDataWriter* Grade_writer = NULL;
	Grade* tpc_grade = NULL;
	ReturnCode_t retcode1,retcode2;
	InstanceHandle_t instance_handle = HANDLE_NIL;
	const char* type_name1 = NULL;
	const char* type_name2 = NULL;
	int count = 0;
	int flag = 0;
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
	topic = participant->create_topic(
		"tpc_Grade"/* ������ */,
		type_name1 /* ������ */, TOPIC_QOS_DEFAULT/* Ĭ��QoS */,
		NULL /* listener */, STATUS_MASK_NONE);
	if (topic == NULL) {
		fprintf(stderr, "create_topic error\n");
		publisher_shutdown(participant);
		return -1;
	}
	/* 5. ����datawriter��������datawriter��QoS */
	/* ����1���ڳ������������ȴ���datawriter */
	/* ����2������һ�μ��ɣ������ظ����� */
	/* ����3���ڳ����˳�ʱ�ٽ����ͷ� */
	/* ����4��������㷢������ʱ����datawriter���������ݺ�ɾ����������������Դ��Ӱ������ */
	writer = publisher->create_datawriter(
		topic, DATAWRITER_QOS_DEFAULT/* Ĭ��QoS */,
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
	/* 6. ����һ���������� */
	/* ���飺������Ϊnew�����ģ�ʹ�ú��û���Ҫ����delete_data�����ͷ��ڴ�*/
	tpc_grade = GradeTypeSupport::create_data();
	if (tpc_grade == NULL) {
		fprintf(stderr, "GradeTypeSupport::create_data error\n");
		publisher_shutdown(participant);
		return -1;
	}
	char name1[100],ID1[100];
	float f;
	/* 7. ��ѭ�� ���������� */
	for (count = 0; (sample_count == 0) || (count < sample_count); ++count,flag++) {
		/* �ڴ˴��޸����� */
		tpc_grade->name = new char[100];
		tpc_grade->ID = new char[100];
		//scanf("%s", stu1.id);
		scanf_s("%s", name1,100);
		scanf_s("%s", ID1,100);
		scanf_s("%f", &f);
		tpc_grade->score = f;
		strcpy_s(tpc_grade->name, 100, name1);
		strcpy_s(tpc_grade->ID,100, ID1);
		retcode1 = Grade_writer->write(*tpc_grade, instance_handle);
		if (retcode1 != RETCODE_OK) {
			fprintf(stderr, "write error %d\n", retcode1);
		}
		else
			fprintf(stderr, "%d : write successfully . . \n", count);
		if (flag == 2)
		{
			fprintf(stderr, "wait a minute:\n");
			flag = 0;
			Sleep(1000);//��˯1��
		}
	}
	/* 8. ɾ���������� */
	retcode1 = GradeTypeSupport::delete_data(tpc_grade);
	if (retcode1 != RETCODE_OK) {
		fprintf(stderr, "GradeTypeSupport::delete_data error %d\n", retcode1);
	}
	/* 9. ɾ������ʵ�� */
	return publisher_shutdown(participant);
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
