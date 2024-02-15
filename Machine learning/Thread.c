#include <stdio.h>
#include <pthread.h>

void *Thread();

int main() {
    pthread_t t1;
    pthread_create(&t1,NULL,Thread,NULL);
    pthread_join(t1,NULL);
    return 0;
}

void *Thread(){
    printf("Enter the size of the array : ");
    int number;
    scanf("%d", &number);
    int i;
    for (i = 0; i < number; i++) {
        printf("%d ", i);
    }
}
