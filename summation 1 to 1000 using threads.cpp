#include<stdio.h>
#include<pthread.h>

#define ARRAYSIZE 1000
#define THREAD 2
void *summming(void *id);


int data[ARRAYSIZE];
pthread_mutex_t mutex;
int wsize;
int result=0;

void *summing(void *id){
   
    int low =(int) id*wsize;
    int high=low+wsize;
    int sum=0;
    
    for(int i=low;i<high;i++){
        sum+=data[i];
        }
        pthread_mutex_lock(&mutex);
        result+=sum;
        pthread_mutex_unlock(&mutex);
        
        return;
        
}

main(){
    pthread_t tid[THREAD];
    pthread_mutex_init(&mutex,NULL);
    
    wsize =ARRAYSIZE/THREAD;
    
    for(int i=0;i<1000;i++)
        data[i]=i+1;
    
    for(int i=0;i<THREAD;i++){
        if(pthread_create(&tid[i],NULL,summing,(void *) i)!=0)
                perror("Pthread_create fails");
    }
    for(int i=0;i<THREAD;i++){
        if(pthread_join(tid[i],NULL))
            perror("Pthread_create fails");
    }
    printf("Sum of : %d",result);
                
}
