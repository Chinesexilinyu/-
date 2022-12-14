// Don't modify this file as it will be overwritten.
//
#include "IDL_tpc_Grade.h"

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

