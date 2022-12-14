// Don't modify this file as it will be overwritten.
//
#include "CDR/CDR.h"
#include "ReturnCode.h"
#include "BasicTypes.h"

#ifndef IDL_ssgrade_hh
#define IDL_ssgrade_hh

#ifndef Grade_defined
#define Grade_defined

struct Grade {
  Grade()
	{
		name = NULL;
		ID = NULL;
	}

  Grade(const Grade  &IDL_s);

  ~Grade(){}

  Grade& operator= (const Grade &IDL_s);

  void Marshal(CDR *cdr) const;
  void UnMarshal(CDR *cdr);

  char* name;
char* ID;
float score;
  
};

typedef sequence<Grade> GradeSeq;

#endif

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




#endif /*IDL_ssgrade_hh */
