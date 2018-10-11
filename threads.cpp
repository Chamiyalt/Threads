#include<stdio.h>
#include<pthread.h>
#include <inttypes.h>

void *myt1(void *value){
    int myval=(int) value;
    printf("this is first thred  : %d \n",myval);
}

void *myt2(void *value){
    int myval=(int) value;
    printf("this is first thred : %d  \n",myval);
}

void main(){
   
    printf("main starts\n");
    pthread_t thread1,thread2;
    
    int i=123;
    
    pthread_create(&thread1,NULL,myt1,(void *)i);
    
     int j=456;
    
    pthread_create(&thread2,NULL,myt2,(void *)j);
    
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    
}
