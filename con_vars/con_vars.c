#include <stdio.h>
#include <pthread.h>

int event = 0;

pthread_mutex_t eve_mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_t;

void* wait(void* data){
	pthread_mutex_lock(&eve_mut);
	printf("Wait: Mutex grabbed\n");
	
	while (event != 1) {
		pthread_cond_wait(&cond_t, &eve_mut);
	}

	printf("Wait: Event set\n");
	pthread_mutex_unlock(&eve_mut);
}

void* setter(void* data){
	pthread_mutex_lock(&eve_mut);
	printf("Setter: Mutex grabbed\n");
	
	event = 1;

	printf("Setter: Event set\n");
	pthread_mutex_unlock(&eve_mut);
	pthread_cond_signal(&cond_t);
}

int main(int argc, char const *argv[])
{
	pthread_t a_t, b_t;
	
	pthread_cond_init(&cond_t, NULL);

	pthread_create(&a_t, NULL, wait, NULL);
	pthread_create(&b_t, NULL, setter, NULL);

	pthread_join(a_t, NULL);
	pthread_join(b_t, NULL);

	pthread_cond_destroy(&cond_t);

	return 0;
}