// Don't modify this file as it will be overwritten.
//
#include "CDR/CDR.h"
#include "ReturnCode.h"
#include "BasicTypes.h"

#ifndef IDL_tpc_Grade_hh
#define IDL_tpc_Grade_hh

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




#endif /*IDL_tpc_Grade_hh */
