#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>

void main1(void);
void * firstThread();
void * secondThread();

void main2(void);
void * producer();
void * consumer();
void produceItem();
void consumeItem();

void main3();
void * sayHi1();
void * sayHi2();
void * sayHi3();
void * sayHi4();

int main(int agrc, char **agrv) {

    main3();
    return 0;
}

/*
 * Here, thread1 only executes after thread2 (most of the times oeiwoeweiooweiweo)
 */
pthread_t tid1, tid2;

void main1(void) {
    int error;

    error = pthread_create(&tid1, NULL, firstThread, NULL);
    if(error) {
        perror("Couldn't create thread\n");
        exit(-1);
    }
    error = pthread_create(&tid2, NULL, secondThread, NULL);
    if(error) {
        perror("Couldn't create thread\n");
        exit(-1);
    }
    pthread_join(tid1, NULL);
    printf("Thread 1 finished\n");
}

void * firstThread() {
    if(!pthread_join(tid2, NULL)) {
        printf("Thread 2 finished\n");
        printf("Thread 1 -> (%ld) executing\n", pthread_self());
    }
}

void * secondThread() {
    printf("Thread 2 -> (%ld) executing\n", pthread_self());
}

/*
 * Here producer runs it's CR first
 */
#define TAM 100
sem_t mutex, producerCalls, consumerCalls;
int item = 0;

void main2() {

    pthread_t prodId, consId;
    int error;

    sem_init(&mutex, 0, 1);
    sem_init(&producerCalls, 0, TAM);
    sem_init(&consumerCalls, 0, 0);

    srand(time(NULL));

    error = pthread_create(&prodId, NULL, producer, NULL);
    if(error) {
        printf("Couldn't create thread producer\n");
        exit(-1);
    }
    error = pthread_create(&consId, NULL, consumer, NULL);
    if(error) {
        printf("Couldn't create thread consumer\n");
        exit(-1);
    }

    pthread_join(prodId, NULL);
    pthread_join(consId, NULL);
    sem_destroy(&mutex);
    sem_destroy(&producerCalls);
    sem_destroy(&consumerCalls);
    printf("main2 shutting down\n");
}

void * producer() {
    while(1) if(item < TAM) produceItem();
}

void produceItem() {
    sem_wait(&producerCalls);
    sem_wait(&mutex);
    item++;
    printf("P: %d\n", item);
    sem_post(&mutex);
    sem_post(&consumerCalls);
}
void * consumer() {
    while(1) if(item > 0) consumeItem();
}

void consumeItem() {
    sem_wait(&consumerCalls);
    sem_wait(&mutex);
    item--;
    printf("C: %d\n", item);
    sem_post(&mutex);
    sem_post(&producerCalls);
}

/*
 * Here thread1 and thread2 execute in any order
 * thread3 executes only after thread1 and 2 and thread4
 * executes after thread3
 */
sem_t s_p1, s_p2, s_p3, s_p4;

void main3() {

    pthread_t thread1, thread2, thread3, thread4;

    sem_init(&s_p1, 0, 0);
    sem_init(&s_p2, 0, 0);
    sem_init(&s_p3, 0 ,0);
    sem_init(&s_p4, 0, 0);

    pthread_create(&thread1, NULL, sayHi1, NULL);
    pthread_create(&thread2, NULL, sayHi2, NULL);
    pthread_create(&thread3, NULL, sayHi3, NULL);
    pthread_create(&thread4, NULL, sayHi4, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    sem_destroy(&s_p1);
    sem_destroy(&s_p2);
    sem_destroy(&s_p3);
    sem_destroy(&s_p4);
}

void * sayHi1() {

    printf("Hi, it's me thread 1 %ld\n", pthread_self());
    sem_post(&s_p1);
}
void * sayHi2() {

    printf("Hi, it's me thread 2 %ld\n", pthread_self());
    sem_post(&s_p2);
}
void * sayHi3() {

    sem_wait(&s_p1);
    sem_wait(&s_p2);
    printf("Hi, it's me thread 3 %ld\n", pthread_self());
    sem_post(&s_p3);
}
void * sayHi4() {

    sem_wait(&s_p3);
    printf("Hi, it's me thread 4 %ld\n", pthread_self());
    sem_post(&s_p4);
}
