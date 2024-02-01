#include<stdio.h>
#include<stdlib.h>

void MatrixC(int A[][3], int B[][2], int Arows, int Acolumns, int Brows, int Bcolumns){
int C[Arows][Bcolumns],i,j,k;
if(Acolumns!=Brows){
        printf("The dimensions of the multiplication matrices do not match");
        return;}
else{
for(i=0;i<Arows;i++){
 for(j=0;j<Bcolumns;j++){
     C[i][j]=0;
    for(k=0;k<Brows;k++){
        *(*(C+i)+j)=C[i][j]+ (*(*(A+i)+k))* (*(*(B+k)+j));
         //C[i][j]=C[i][j]+A[i][k]*B[k][j];//
         }
        }
       }
for(i=0;i<Arows;i++){
        printf("\n");
 for(j=0;j<Bcolumns;j++){
    printf("%d ", C[i][j]);
    }
   }
  }
 }
 void Dynamicdo(int ***array, int row, int column){
 /* int i,j;
 *array=(int**)malloc(sizeof(int)*row);
 for(i=0;i<row;i++){
   *(*array+i)=(int*)malloc(sizeof(int)*column);
    for(j=0;i<column;j++){
        *(*(*array+i)+j)=rand()%9;
    }
   } */
   int i,j;
    *array=(int**)malloc(row*sizeof(int*));
    for(i=0; i<row; i++){
        *(*array+i)= (int*)malloc(column*sizeof(int));
        for(j=0; j<column; j++)
            *(*(*array+i)+j)= rand()%2;
    }
  }

int main(){

int A[][3]={{1,2,3},{4,5,6}};
int B[][2]={{1,2},{3,4},{5,6}};
int *C, *D;

MatrixC(A,B,2,3,3,2);
Dynamicdo(&C,2,3);
Dynamicdo(&D,3,2);
MatrixC(C,D,2,3,3,2);


return 0;
}
