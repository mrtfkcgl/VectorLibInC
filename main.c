#include <assert.h>
#include <stdio.h>
#include "VectorLibInC/VectorInC.h"

void PrintVector(HVECTOR hvector)
{

    assert(hvector!=NULL);
    for(size_t i=0; i< hvector->size; ++i)
        printf("%d ", hvector->pData[i]);
    printf("\n");
}
int main() {
    HVECTOR hvec = CreateVector();
    for(int i = 0; i<20; ++i)
    {
        PushBack(hvec,i);
    }
    PrintVector(hvec);
    for(int i = 5;i<11;i++)
        InsertItem(hvec,i,1024);
    PrintVector(hvec);
    RemoveAll(hvec,1024);
    PrintVector(hvec);
    return 0;
}
