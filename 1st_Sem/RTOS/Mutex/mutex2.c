//WITH MUTEX LOCK
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>


#define NUM_THREADS 2

// Shared variable
int sharedVariable = 0;

// Mutex declaration
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

// Function prototype
void* incrementThread(void* arg);

int main() {
    // Thread IDs and thread objects
    pthread_t threads[NUM_THREADS];

    // Create two threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, incrementThread, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Print the final value of the shared variable
    printf("Final value of the shared variable: %d\n", sharedVariable);

    return 0;
}

void* incrementThread(void* arg) {
    // Increment the shared variable in a loop
    for (int i = 0; i < 100000; ++i) {
        // Lock the mutex before modifying the shared variable
        pthread_mutex_lock(&myMutex);

        // Critical section: Increment the shared variable
        sharedVariable++;

        // Unlock the mutex after modifying the shared variable
        pthread_mutex_unlock(&myMutex);
    }

    // Exit the thread
    pthread_exit(NULL);
}