/***********************************************
 * FILE:: ex3.c
 * DESCRIPTION:
 *  OpenMP Example - Loop work-sharing - C/C++ version
 *  In this example, the iterations of a loop are scheduled dynamically
 *  across the team of threads. A thread will perform CHUNK iterationsù
 *  at a time before being scheduled for the next CHUNK of work.
 **********************************************/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNKSIZE 4
#define N 17

int main (int argc, char *argv[]){
    int nthreads, tid, i, chunk;
    float a[N], b[N], c[N];

    /*Some initializations*/
    for (i=0;i<N;i++)
        a[i] = b[i] = i * 1.0;
    
    chunk = CHUNKSIZE;

    #pragma omp parallel shared(a,b,c,nthreads,chunk) private(i,tid)
    {
        tid = omp_get_thread_num();

        #pragma omp master
        {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }

        printf("Thread %d starting...\n",tid);
        
        #pragma omp for schedule(static,chunk)
            for (i=0;i<N;i++){
                c[i] = a[i] + b[i];
                printf("Thread %d: c[%d]= %f\n",tid,i,c[i]);
            }        
    }   /*end of parallel section*/

}