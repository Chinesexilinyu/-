// Don't modify this file as it will be overwritten.
//
#include "IDL_tpc_AvgGrade.h"

AverageGrade::AverageGrade(const AverageGrade &IDL_s){
  avgScore = IDL_s.avgScore;
  ID1 = IDL_s.ID1;
  ID2 = IDL_s.ID2;
  ID3 = IDL_s.ID3;
}

AverageGrade& AverageGrade::operator= (const AverageGrade &IDL_s){
  if (this == &IDL_s) return *this;
  avgScore = IDL_s.avgScore;
  ID1 = IDL_s.ID1;
  ID2 = IDL_s.ID2;
  ID3 = IDL_s.ID3;
  return *this;
}

void AverageGrade::Marshal(CDR *cdr) const {
  cdr->PutFloat(avgScore);
  cdr->PutString(ID1);
  cdr->PutString(ID2);
  cdr->PutString(ID3);
}

void AverageGrade::UnMarshal(CDR *cdr){
  cdr->GetFloat(avgScore);
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(ID1 != NULL )
    {
        delete ID1;
        ID1 = NULL;
    }
    ID1 = IDL_str;
  }
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(ID2 != NULL )
    {
        delete ID2;
        ID2 = NULL;
    }
    ID2 = IDL_str;
  }
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(ID3 != NULL )
    {
        delete ID3;
        ID3 = NULL;
    }
    ID3 = IDL_str;
  }
}

