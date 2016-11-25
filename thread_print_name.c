#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>



void  * thread_function(void * data){
	int number = (int *)data;
	printf("hello from thread%-d  meu id é pthread_self() =  %lu  :: gettid() =  %u\n",number,pthread_self(), syscall(SYS_gettid));
		sleep(2);
}

int main(int argc,char *argv[]){
    printf("Digite um a quantidade de threads \n");
    int nThreads;
    scanf("%d",&nThreads);
    printf("%d \n",nThreads);
    pthread_t thread_id[nThreads];
    int i;
    int status;
    for(i=0;i<nThreads;i++)    {
        pthread_create (&thread_id[i], NULL ,&thread_function, (void*)(intptr_t)i);
    }  

   sleep(15); // para conseguir mostrar os resultados
}
