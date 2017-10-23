#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[100];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread

void* playandcount(void *arg,int *t)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
    if(pthread_equal(id,tid[0])){
        for(iter;iter<10;iter++)
        {
            printf("%d",iter);
        }
    }
    return NULL;
}
int main(void)
{
    int i=0;
    int err,n,t,*t2;
    t2=&t;
    scanf("%d",&n);
    scanf("%d",&t);
    while(i<t)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,int *t2);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        i++;
    }
    i=0;
    while(i<t){
    pthread_join(tid[i],NULL);
    i++;
    }
    return 0;
}
