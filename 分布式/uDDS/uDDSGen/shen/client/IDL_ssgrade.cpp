// Don't modify this file as it will be overwritten.
//
#include "IDL_ssgrade.h"

Grade::Grade(const Grade &IDL_s){
  name = IDL_s.name;
  ID = IDL_s.ID;
  score = IDL_s.score;
}

Grade& Grade::operator= (const Grade &IDL_s){
  if (this == &IDL_s) return *this;
  name = IDL_s.name;
  ID = IDL_s.ID;
  score = IDL_s.score;
  return *this;
}

void Grade::Marshal(CDR *cdr) const {
  cdr->PutString(name);
  cdr->PutString(ID);
  cdr->PutFloat(score);
}

void Grade::UnMarshal(CDR *cdr){
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(name != NULL )
    {
        delete name;
        name = NULL;
    }
    name = IDL_str;
  }
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(ID != NULL )
    {
        delete ID;
        ID = NULL;
    }
    ID = IDL_str;
  }
  cdr->GetFloat(score);
}

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

