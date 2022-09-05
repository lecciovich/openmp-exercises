/********************************************
 * FILE: ex1.c
 * DESCRIPTION:
 *  OpenMP Example - Hello World - C/C++ version
 *  In this simple exampe, the master thread forks a parallel region.
 *  All threads in the team obtain their unique thread number and print it.
 *  The master thread prints the total number of threads. 2 OpenMP 
 *  library routines are used to obtain the number of threads and each 
 *  thread's number. 
 *  
 *  PS. export OMP_NUM_THREADS=5 can be used by terminal to set openmp n. of 
 *  threads that have to be used
*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[]){
    
    int nthreads,tid;

    #pragma omp parallel private(nthreads, tid)
    {
        /*Obtain thread number*/
        tid=omp_get_thread_num();
        printf("Hello world from thread = %d\n", tid);

        /*Only master thread does this. It is equivalent to 
            #pragma omp master */
        #pragma omp barrier
            if (tid==0){
                nthreads = omp_get_num_threads();
                printf("Total n.. of threads is = %d", nthreads);
            }
    }   /*All threads join master thread and are disbanded*/
}