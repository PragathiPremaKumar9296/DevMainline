#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
int count = 0;
int buffer[BUFFER_SIZE];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

void *producer(void *args) {
    int item = 0;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex); // Wait if buffer is full
        }
        buffer[count++] = item++;
        printf("Produced: %d\n", item); // Add a newline for better readability
        pthread_cond_signal(&not_empty); // Notify consumer that there's an item
        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulate time taken to produce an item
    }
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex); // Wait if buffer is empty
        }
        int item = buffer[--count];
        printf("Consumed: %d\n", item); // Add a newline for better readability
        pthread_cond_signal(&not_full); // Notify producer that there's space in the buffer
        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulate time taken to consume an item
    }
}

int main() {
    pthread_t prodThread, consThread;

    // Create producer and consumer threads
    pthread_create(&prodThread, NULL, &producer, NULL);
    pthread_create(&consThread, NULL, &consumer, NULL);

    // Join threads (this is just for clean termination, though they run infinitely)
    pthread_join(prodThread, NULL);
    pthread_join(consThread, NULL);

    return 0;
}
