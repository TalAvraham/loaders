#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

__thread int tls_var = 0;

void* thread_function(void* arg) {
    tls_var = (int)(long)arg;
    printf("Thread %d: tls_var = %d\n", (int)(long)arg, tls_var);
    return NULL;
}

int main() {
    pthread_t threads[3];
    for (int i = 0; i < 3; ++i) {
        pthread_create(&threads[i], NULL, thread_function, (void*)(long)i);
    }

    for (int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    _exit(0);
}
