#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>

void *print_msg(void *ptr)
{
	printf("\n %s : %s",__func__,(char *)ptr);
}

int main()
{
	pthread_t thread1,thread2;
	char *msg1 = "I am Message 1";
	char *msg2 = "I am Message 2";
	int iret1,iret2;

	/* create independent threads each of which will execute function */

	iret1 = pthread_create(&thread1,NULL,print_msg,(void *)msg1);
	iret2 = pthread_create(&thread2,NULL,print_msg,(void *)msg2);

	/* Wait till threads are complete before main continues.
	 * unless we wait we run the risk of executing an exit which will
	 * terminate the process and all threads before the threads have
	 * completed.
	 * */

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	exit(0);
}
