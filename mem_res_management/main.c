#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

int* get_block(pthread_t );
void free_block(pthread_t id);
int* create_block(int );
void destroy(int *);
void* thrd1_add(void *data)
{
	pthread_t t1_id;
	t1_id = pthread_self();
	int *arr1 = get_block(t1_id);
	printf("in t1.add:\n");
	arr1[0] = 20;
	arr1[1] = 10;
	arr1[2] = arr1[0] + arr1[1];
	printf("res:%d\n", arr1[2]);
	sleep(5);
	free_block(t1_id);
}

void* thrd2_sub(void *data)
{
	pthread_t t2_id = pthread_self();
	int *arr2 = get_block(t2_id);
	printf("in t2.sub:\n");
	arr2[0] = 20;
	arr2[1] = 10;
	arr2[2] = arr2[0] - arr2[1];
	printf("res:%d\n", arr2[2]);
	sleep(10);
	free_block(t2_id);
}
void* thrd3_mul(void *data)
{
	pthread_t t3_id = pthread_self();
	int *arr3 = get_block(t3_id);
	//use
	printf("in t3.mul:\n");
	arr3[0] = 20;
	arr3[1] = 10;
	arr3[2] = arr3[0] * arr3[1];
	printf("res:%d\n", arr3[2]);
	sleep(15);
	free_block(t3_id);
}
void* thrd4_div(void *data)
{
	int *arr4;
	pthread_t t4_id = pthread_self();
	arr4 = get_block(t4_id);
	//use
	printf("in t4.div:\n");
	arr4[0] = 20;
	arr4[1] = 10;
	arr4[2] = arr4[0] / arr4[1];
	printf("res:%d\n", arr4[2]);
	free_block(t4_id);
}

int count1 = 1;
int count2 = 1;
int count3 = 1;

int *b1, *b2, *b3;
pthread_t use_id1, use_id2, use_id3;
sem_t sem_rsource;

//main functionality
int main()
{
	pthread_t thrd1_id, thrd2_id, thrd3_id, thrd4_id;

//create semaphore
	sem_init(&sem_rsource, 0, 3);

//create block
	b1 = create_block(10);
	b2 = create_block(10);
	b3 = create_block(10);

//create threads
	pthread_create(&thrd1_id, NULL, thrd1_add, NULL);
	pthread_create(&thrd2_id, NULL, thrd2_sub, NULL);
	pthread_create(&thrd3_id, NULL, thrd3_mul, NULL);
	pthread_create(&thrd4_id, NULL, thrd4_div, NULL);

//wait till joining of threads
	pthread_join(thrd1_id, NULL);
	pthread_join(thrd2_id, NULL);
	pthread_join(thrd3_id, NULL);
	pthread_join(thrd4_id, NULL);

//destroy semaphore
	sem_destroy(&sem_rsource);

//free block
	destroy(b1);
	destroy(b2);
	destroy(b3);

	return 0;
}
