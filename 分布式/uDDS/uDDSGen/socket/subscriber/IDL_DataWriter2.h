#ifndef _IDL_DATAWRITER_H_INCLUDED_
#define _IDL_DATAWRITER_H_INCLUDED_
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/DomainParticipantFactory.h"
#include "DDS/Topic.h"
#include "DDS/Publisher.h"
#include "DDS/DataWriter.h"
#include "IDL_tpc_AvgGrade.h"
class DataWriterImpl;

class AverageGradeDataWriter : public DataWriter
{
public:
	AverageGradeDataWriter(DataWriterImpl* pDataWriterImpl);

	~AverageGradeDataWriter();

	static AverageGradeDataWriter* narrow(DataWriter* pDataWriter);

ReturnCode_t write(AverageGrade& data,const InstanceHandle_t & handle);

};

#endif
