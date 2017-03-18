#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>

int globalvar;

void *printmsg(void  *ptr)
{
 int a = 1;
 ++a;

 ++globalvar;
printf("\n %s - %s \nglobalvar = %d and local var a = %d",__func__,(char *)ptr,globalvar,a);

}

int main()
{
	pthread_t thread1,thread2;
	int ret1,ret2;
	globalvar = 0;
	ret1 = pthread_create(&thread1,NULL,printmsg,(void *)"Thread 1");
	ret2 = pthread_create(&thread2,NULL,printmsg,(void *)"Thread 2");

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("\n %s \nglobalvar value before exit : %d",__func__, globalvar);
	exit(0);

}
