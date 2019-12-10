#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

extern int count1;
extern int count2;
extern int count3;
extern int *b1;
extern int *b2;
extern int *b3;

extern pthread_t use_id1, use_id2, use_id3;
extern sem_t sem_rsource;

int* get_block(pthread_t id){
    sem_wait(&sem_rsource);
    if (count1){
        count1--;
        use_id1 = id;
        printf("thread id: %ld allocated B1= %p\n", id, b1);

        return b1;
    }
    else if (count2){
        count2--;
        use_id2 = id;
        printf("thread id: %ld allocated B2= %p\n", id, b2);

        return b2;
    }
    else if (count3){
        count3--;
        use_id3 = id;
        printf("thread id: %ld allocated B3= %p\n", id, b3);

        return b3;
    }
    else
        return NULL;
}
