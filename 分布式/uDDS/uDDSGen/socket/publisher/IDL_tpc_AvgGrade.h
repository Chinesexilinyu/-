// Don't modify this file as it will be overwritten.
//
#include "CDR/CDR.h"
#include "ReturnCode.h"
#include "BasicTypes.h"

#ifndef IDL_tpc_AvgGrade_hh
#define IDL_tpc_AvgGrade_hh

#ifndef AverageGrade_defined
#define AverageGrade_defined

struct AverageGrade {
  AverageGrade()
	{
		ID1 = NULL;
		ID2 = NULL;
		ID3 = NULL;
	}

  AverageGrade(const AverageGrade  &IDL_s);

  ~AverageGrade(){}

  AverageGrade& operator= (const AverageGrade &IDL_s);

  void Marshal(CDR *cdr) const;
  void UnMarshal(CDR *cdr);

  float avgScore;
char* ID1;
char* ID2;
char* ID3;
  
};

typedef sequence<AverageGrade> AverageGradeSeq;

#endif




#endif /*IDL_tpc_AvgGrade_hh */
