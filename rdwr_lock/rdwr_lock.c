#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_rwlock_t rw_id;
int count = 10;

void* rdThread1(void* data){
	pthread_rwlock_rdlock(&rw_id);
	printf("Read Thread 1 | Count: %d\n", count);
	sleep(5);
	pthread_rwlock_unlock(&rw_id);
}

void* rdThread2(void* data){
	pthread_rwlock_rdlock(&rw_id);
	printf("Read Thread 2 | Count: %d\n", count);
	sleep(3);
	pthread_rwlock_unlock(&rw_id);
}

void* rdThread3(void* data){
	pthread_rwlock_rdlock(&rw_id);
	printf("Read Thread 3 | Count: %d\n", count);
	sleep(1);
	pthread_rwlock_unlock(&rw_id);
}

void* wrThread1(void* data){
	pthread_rwlock_wrlock(&rw_id);
	printf("Write Thread | Count: %d\n", ++count);
	pthread_rwlock_unlock(&rw_id);
}

int main(int argc, char const *argv[])
{
	pthread_t rd1, rd2, rd3, wr1;

	pthread_rwlock_init(&rw_id, NULL);

	pthread_create(&rd1, NULL, rdThread1, NULL);
	pthread_create(&rd2, NULL, rdThread2, NULL);
	pthread_create(&rd3, NULL, rdThread3, NULL);
	pthread_create(&wr1, NULL, wrThread1, NULL);

	pthread_join(rd1, NULL);
	pthread_join(rd2, NULL);
	pthread_join(rd3, NULL);
	pthread_join(wr1, NULL);

	pthread_rwlock_destroy(&rw_id);

	return 0;
}