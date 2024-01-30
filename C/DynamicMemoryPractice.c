#include <stdio.h>
#include <stdlib.h>

int dynamic1DArray(int **arrayb, int elementCount){
    int i;
    *arrayb=(int*)malloc(sizeof(int)*elementCount);
    for(i=0; i<elementCount; i++)
    {
        *(*arrayb+i)=rand()%100;
        printf("%d\n", *(*arrayb+i));
    }

}

int main(){

    int *ram;
    ram=(int*) malloc(sizeof(int));
    *ram=12;
    printf("%d value \n", *ram);
    printf("%p address \n", ram);


    int a[2], *arraya, i;
    arraya=(int*)malloc(sizeof(int)*3);
    for(i=0; i<3; i++)
    {
        *(a+i)=rand()%100;
        printf("Array's %d th element= %d\n", i+1,*(a+i));
    }
    free(arraya);


    int b[4], *arrayb;
    arrayb=b;
    dynamic1DArray(&arrayb,5);

}

