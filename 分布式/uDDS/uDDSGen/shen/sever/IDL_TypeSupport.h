#ifndef _IDL_TYPESUPPORT_H_INCLUDED_ 
#define _IDL_TYPESUPPORT_H_INCLUDED_

#include <string>
using std::string;
#include "IDL_DataWriter.h"
#include "IDL_DataReader.h"
#include "DDS/TypeSupport.h"

class GradeTypeSupport : public TypeSupport {
public:
	static Grade* create_data()
	{
		return new Grade;
	}

	static ReturnCode_t delete_data(Grade* pGrade)
	{
		delete pGrade->name;
		pGrade->name = NULL;
		delete pGrade->ID;
		pGrade->ID = NULL;
		delete pGrade;
		pGrade = NULL;
		return ReturnCode_t();
	}

	static void print_data(Grade* pGrade,int layer = 0)
	{
		char *c = new char[layer];
		int i = 0;
		for (; i < layer; i++)
		{
			c[i] = '\t';
		}
		c[i] = '\0';
		std::cout<<c<<"Grade:"<<std::endl;
		std::cout<<c<<"  name = "<< pGrade->name <<std::endl;
		std::cout<<c<<"  ID = "<< pGrade->ID <<std::endl;
		std::cout<<c<<"  score = "<< pGrade->score <<std::endl;
	}

	static const char* get_type_name()
	{
		return "Grade";
	}

	static int register_type(DomainParticipant* participant, string type_name)
	{
		if (type_name.empty())
			type_name = get_type_name();

		return participant->register_type(type_name);
	}
};

class AverageGradeTypeSupport : public TypeSupport {
public:
	static AverageGrade* create_data()
	{
		return new AverageGrade;
	}

	static ReturnCode_t delete_data(AverageGrade* pAverageGrade)
	{
		delete pAverageGrade->ID1;
		pAverageGrade->ID1 = NULL;
		delete pAverageGrade->ID2;
		pAverageGrade->ID2 = NULL;
		delete pAverageGrade->ID3;
		pAverageGrade->ID3 = NULL;
		delete pAverageGrade;
		pAverageGrade = NULL;
		return ReturnCode_t();
	}

	static void print_data(AverageGrade* pAverageGrade,int layer = 0)
	{
		char *c = new char[layer];
		int i = 0;
		for (; i < layer; i++)
		{
			c[i] = '\t';
		}
		c[i] = '\0';
		std::cout<<c<<"AverageGrade:"<<std::endl;
		std::cout<<c<<"  avgScore = "<< pAverageGrade->avgScore <<std::endl;
		std::cout<<c<<"  ID1 = "<< pAverageGrade->ID1 <<std::endl;
		std::cout<<c<<"  ID2 = "<< pAverageGrade->ID2 <<std::endl;
		std::cout<<c<<"  ID3 = "<< pAverageGrade->ID3 <<std::endl;
	}

	static const char* get_type_name()
	{
		return "AverageGrade";
	}

	static int register_type(DomainParticipant* participant, string type_name)
	{
		if (type_name.empty())
			type_name = get_type_name();

		return participant->register_type(type_name);
	}
};

#endif
