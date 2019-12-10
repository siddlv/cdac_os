#include<semaphore.h>
#include<pthread.h>

extern int count1;
extern int count2;
extern int count3;
extern pthread_t use_id1;
extern pthread_t use_id2;
extern pthread_t use_id3;
extern sem_t sem_rsource;

void free_block(pthread_t id)
{
    if (id == use_id1)
    {
        count1++;
        sem_post(&sem_rsource);
    }
    else if (id == use_id2)
    {
        count2++;
        sem_post(&sem_rsource);
    }

    else if (id == use_id3)
    {
        count3++;
        sem_post(&sem_rsource);
    }
    else {}
}