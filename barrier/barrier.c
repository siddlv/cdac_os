#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_barrier_t barr_t;

void* lcd(void* data){
	printf("LCD: Initialization started\n");
	sleep(3);
	printf("LCD: Initialization finished\n");
	pthread_barrier_wait(&barr_t);
	printf("LCD: Functionality started\n");
}

void* serial(void* data){
	printf("SERIAL: Initialization started\n");
	sleep(5);
	printf("SERIAL: Initialization finished\n");
	pthread_barrier_wait(&barr_t);
	printf("SERIAL: Functionality started\n");
}

void* network(void* data){
	printf("NETWORK: Initialization started\n");
	sleep(8);
	printf("NETWORK: Initialization finished\n");
	pthread_barrier_wait(&barr_t);
	printf("NETWORK: Functionality started\n");
}

void* sensor(void* data){
	printf("SENSOR: Initialization started\n");
	sleep(1);
	printf("SENSOR: Initialization finished\n");
	pthread_barrier_wait(&barr_t);
	printf("SENSOR: Functionality started\n");
}

int main(int argc, char const *argv[])
{
	pthread_t lcd_t, serial_t, network_t, sensor_t;

	pthread_barrier_init(&barr_t, NULL, 4);

	pthread_create(&lcd_t, NULL, lcd, NULL);
	pthread_create(&serial_t, NULL, serial, NULL);
	pthread_create(&network_t, NULL, network, NULL);
	pthread_create(&sensor_t, NULL, sensor, NULL);

	pthread_join(lcd_t, NULL);
	pthread_join(serial_t, NULL);
	pthread_join(network_t, NULL);
	pthread_join(sensor_t, NULL);

	pthread_barrier_destroy(&barr_t);

	return 0;
}