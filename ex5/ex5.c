/**************************************************************************
* FILE: ex5.c
* DESCRIPTION:
*   OpenMP Example - Parallel region with an orphaned directive - C version
*   This example demonstrates a dot product being performed by an orphaned
*   loop reduction construct. Scoping of the reduction variable is critical.
**************************************************************************/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define VECLEN 100

float a[VECLEN],b[VECLEN],sum;

void dotprod (){
    int i,tid;//tid is private varible for parallel region

    tid= omp_get_thread_num();
    /*this is the orphaned directive*/ // critical region
    #pragma omp parallel for reduction(+:sum)
        for (i=0; i<VECLEN; i++)
        {
            sum+=a[i]*b[i];
            printf("    tid=%d i=%d sum=%f\n",tid,i,sum);
        }
}

int main (int argc, char *argv[]){
    int i;

    for (i=0;i<VECLEN;i++)
        a[i]=b[i]=1.0*i;
    sum=0.0;

    #pragma omp parallel
        dotprod();
    printf("Sum = %f",sum);
}