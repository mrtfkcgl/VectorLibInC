//
// Created by emre on 18.02.2024.
//
#include "VectorInC.h"
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
HVECTOR CreateVector(void)
{
    return CreateVectorWithCapacity(DEFAULT_CAP);

}

HVECTOR CreateVectorWithCapacity(size_t capacity)
{
    HVECTOR hvector;
    if((hvector = (HVECTOR) malloc(sizeof(VECTOR)))== NULL) {
        return NULL;
    }
    if((hvector->pData = (DATATYPE*)malloc(sizeof(DATATYPE)*capacity)) == NULL){
        free(hvector);
        return NULL;
    }

    hvector->size = 0;
    hvector->capacity = capacity;
    assert(hvector != NULL);

    return hvector;
}
HVECTOR CreateVectorWithArray(const DATATYPE *p, size_t size) {

    HVECTOR hvector;
    if ((hvector = (HVECTOR) malloc(sizeof(*hvector))) == NULL) { return NULL; }

    if ((hvector->pData = (DATATYPE *) malloc(sizeof(DATATYPE) * size)) == NULL)
    {
        free(hvector);
    return NULL;
    }
    memmove(hvector->pData,p,sizeof(DATATYPE)*size);
    hvector->size = size;
    hvector->capacity = size;

    return hvector;
}
_Bool SetCapacity(HVECTOR hvector,size_t new_capacity)
{
    DATATYPE *pnewdata;
    if(new_capacity<hvector->size)
        return false;
    if((pnewdata = (DATATYPE*)realloc(hvector->pData,sizeof(DATATYPE)*new_capacity))==NULL)
        return false;

    hvector->pData = pnewdata;
    hvector->capacity = new_capacity;
    return  true;
}
_Bool PushBack(HVECTOR hvector, DATATYPE val)
{
    assert(hvector != NULL);
    if(hvector->size == hvector->capacity && !SetCapacity(hvector,hvector->capacity*2))
        return printf("Error");
    hvector->pData[hvector->size++] = val;

    return true;
}
_Bool GetItemRef(HVECTOR hvector,size_t index,DATATYPE* p)
{
    assert(hvector != NULL);
    if(index>= hvector->size)
        return false;
    *p = hvector->pData[index];

    return true;
}
size_t FindItem(HVECTOR hvector,DATATYPE val)
{
    assert(hvector != NULL);
    size_t i;
    for(i=0;i<hvector->size;i++)
        if(hvector->pData[i]==val)
            return i;
    return NOT_FOUND;
}
_Bool InsertItem(HVECTOR hvector,size_t index,DATATYPE val)
{
    assert(hvector != NULL);
    if(index>hvector->size)
        return false;
    if(hvector->size == hvector->capacity && !SetCapacity(hvector,hvector->capacity*2))
        return false;
    memmove(hvector->pData+index+1,hvector->pData+index,(hvector->size-index)*sizeof(DATATYPE));
    hvector->pData[index] = val;
    ++hvector->size;
    return true;
}
_Bool DeleteItem(HVECTOR hvector, size_t index)
{
    if (index>=hvector->size)
        return false;
    memmove(hvector->pData+index,hvector->pData+index+1,(hvector->size-index-1)*sizeof(DATATYPE));
    --hvector->size;
    return true;
}
_Bool RemoveITem(HVECTOR hvector,DATATYPE val)
{
    size_t index = FindItem(hvector,val);
    if(index == NOT_FOUND)
        return false;

    return DeleteItem(hvector,index);
}
void ShrinkToFit(HVECTOR hvector)
{
    realloc(hvector->pData,sizeof(DATATYPE)*hvector->size);
    hvector->capacity = hvector->size;
}
void CloseVector(HVECTOR hvector)
{
    free(hvector->pData);
    free(hvector);
}
_Bool PopBack(HVECTOR hvector)
{
    assert(hvector != NULL);
    if(hvector->size == 0)
        return false;
    --hvector->size;
    return  true;
}
size_t RemoveAll(HVECTOR hvector,DATATYPE val){
    size_t write_idx = 0;
    for (size_t i = 0; i<hvector->size; i++)
    {
        if(hvector->pData[i] != val)
            hvector->pData[write_idx++] = hvector->pData[i];
     }
    int retval = hvector->size -write_idx;
    hvector->size = write_idx;

    return retval;
}