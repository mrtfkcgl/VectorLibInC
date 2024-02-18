//
// Created by emre on 18.02.2024.
//

#ifndef VECTORC_VECTORINC_H
#define VECTORC_VECTORINC_H

#include<stdlib.h>
#include<stddef.h>
#include<stdbool.h>

/*Functional Macros*/


typedef int DATATYPE;

typedef struct tagVECTOR{
    size_t size;
    size_t capacity;
    DATATYPE* pData;

}VECTOR,*HVECTOR;

#define NOT_FOUND ((size_t)(-1))
#define DEFAULT_CAP 10

#define GetSize(HVECTOR)    ((HVECTOR)->size)
#define GetCapacity(HVECTOR) ((HVECTOR)->capacity)
#define GetItem(HVECTOR,idx)  ((HVECTOR)->pData[(idx)])
#define Clear(HVECTOR)  ((HVECTOR)->size=0)


HVECTOR CreateVector(void);
HVECTOR CreateVectorWithCapacity(size_t capacity);
HVECTOR CreateVectorWithArray(const DATATYPE *p, size_t capacity);
_Bool SetCapacity(HVECTOR Vector,size_t new_capacity);
_Bool PushBack(HVECTOR, DATATYPE);
_Bool GetItemRef(HVECTOR,size_t index,DATATYPE*);
size_t FindItem(HVECTOR,DATATYPE VAL);
_Bool InsertItem(HVECTOR,size_t index,DATATYPE);
_Bool DeleteItem(HVECTOR, size_t idx);
_Bool RemoveITem(HVECTOR,DATATYPE);
void ShrinkToFit(HVECTOR);
void CloseVector(HVECTOR);
_Bool PopBack(HVECTOR hvector);
size_t RemoveAll(HVECTOR hvector,DATATYPE val);


#endif //VECTORC_VECTORINC_H
