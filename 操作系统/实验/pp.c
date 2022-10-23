#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
typedef int buffer_item;
#define pdc_num 4     
#define csm_num 3     
#define BUFFER_SIZE 5           
#define RAND_max 100
buffer_item buffer[BUFFER_SIZE]; 
sem_t empty;
sem_t full;                       
pthread_mutex_t mutex;
int in=0;
int out=0; 
int loops=20;

void Producer(void *arg){
        buffer_item item;
    while(loops>0){
        sleep(1);
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);       
        item=rand()%RAND_max;
	buffer[in]=item;
        in=(in+1)%BUFFER_SIZE;
	loops--;
        printf("producer produced %d\n",item);
        pthread_mutex_unlock(&mutex);       
        sem_post(&full);
    }
    pthread_exit(0);
}

void Consumer(void* arg){
	buffer_item item;
    while(loops>0){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);         
        item=buffer[out];
        out=(out+1)%BUFFER_SIZE;
	loops--;
        pthread_mutex_unlock(&mutex);        
        sem_post(&empty);
        printf("consumer consumed  %d\n",item); 
    }
    pthread_exit(0);
}

int main(){
    pthread_t producer[pdc_num];
    pthread_t consumer[csm_num]; 
    int var,i;
    pthread_mutex_init(&mutex,NULL); 
    var=sem_init(&empty,0,BUFFER_SIZE);      
    if(var!=0){
        printf("error");
        exit(0);
    }          
    var=sem_init(&full,0,0);                  
    if(var!=0){
        printf("error");
        exit(0);
    }    
    for(i=0;i<pdc_num;i++){         
        var=pthread_create(&producer[i],NULL,(void *)Producer,NULL);
        if(var!=0){
        printf("error in create");  
        exit(0);
        }
    }

    for(i=0;i<csm_num;i++){         
        var=pthread_create(&consumer[i],NULL,(void *)Consumer,NULL);  
        if(var!=0){
        printf("error in create");
        exit(0);
        }

    }
    for(i=0;i<pdc_num;i++){
        pthread_join(producer[i],NULL);
    }
    for(i=0;i<csm_num;i++){
         pthread_join(consumer[i],NULL);
    }
    sleep(10);
     return 0;
 }



