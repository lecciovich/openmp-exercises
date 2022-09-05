#include <stdio.h>
#include <omp.h>

int main(){
    #pragma omp parallel
    {
        printf("Hello World... from thread n. %d\n",omp_get_thread_num());
    }
    printf("Hello world!");
    return 0;
}