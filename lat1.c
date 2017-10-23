#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
  
pthread_t tid1;
pthread_t tid2;
int status;
     
void* salin1(void *arg)
{
	FILE *FileIn; 
	FILE *FileOut;
	char buf[BUFSIZ];
	size_t readd;
	status=0;
	
        FileIn = fopen("baca.txt", "r");
	FileOut = fopen("salin1.txt", "w+");
	while(readd = fread(buf,1,BUFSIZ,FileIn)) {
		fwrite(buf,1,readd,FileOut);
	}
	fclose(FileIn);
	fclose(FileOut);
    status = 1;
}

void* salin2(void *arg)
{
	FILE *FileIn; 
	FILE *FileOut;
	char buf[BUFSIZ];
	size_t readd;
	
    while(status != 1)
    {
	FileIn = fopen("salin1.txt", "r");
	FileOut = fopen("salin2.txt", "w");

	while(readd = fread(buf,1,BUFSIZ,FileIn)) {
		fwrite(buf,1,readd,FileOut);
	}
	fclose(FileIn);
	fclose(FileOut);
    }
}
 
int main(void)
{
    pthread_create(&(tid1), NULL, &salin1, NULL);
    pthread_create(&(tid2), NULL, &salin2, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
