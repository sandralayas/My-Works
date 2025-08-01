#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

void *Thread();

int main() {
    
    clock_t T; 
    T = clock(); 
    
    printf("Enter the number of threads : ");
    int number;
    scanf("%d", &number);
    
    pthread_t t[number];
    int i;
    for(i=0;i<number;i++){
        pthread_create(&t+i,NULL,Thread,NULL);
        pthread_join(t[i],NULL);
    }
    
    T = clock() - T; 
    double time_taken = ((double)T)/CLOCKS_PER_SEC;
    printf("%f is the execution time", time_taken);
    
    return 0;
}

void *Thread(void *add){
    printf("Enter the size of the array : ");
    int size;
    scanf("%d", &size);
    
    int array[size];
    //Thread((void *) &array);
    
    int i;
    for (i = 0; i < size; i++) {
        int value=rand()%100;
        array[i]=value;
    }
    int sum;
    for (i = 0; i < size; i++) {
        sum+=array[i];
    }
    printf("%d is the sum\n", sum);
    
}
