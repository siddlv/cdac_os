#include <pthread.h>
#include <stdio.h>

void* rtc_thread1(void* data)
{
	printf("NEW THREAD 1\n");
}

void* rtc_thread2(void* data)
{
	printf("NEW THREAD 2\n");
}

void* rtc_thread3(void* data)
{
	printf("NEW THREAD 3\n");
}

int main()
{
	pthread_t id1_rtc;
	pthread_t id2_rtc;
	pthread_t id3_rtc;

	pthread_create(&id1_rtc, NULL, rtc_thread1, NULL);
	pthread_join(id1_rtc,NULL);

	pthread_create(&id2_rtc, NULL, rtc_thread2, NULL);
	pthread_join(id2_rtc,NULL);

	//int err = pthread_detach(id2_rtc);

	pthread_create(&id3_rtc, NULL, rtc_thread3, NULL);
	pthread_join(id3_rtc,NULL);
	
	printf("MAIN THREAD\n");

	return 0;
}


