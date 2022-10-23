#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define north_num 4     
#define south_num 3     
#define MAX 10

sem_t mutexN;
sem_t mutexS;                       
pthread_mutex_t mutex;
int north=0;
int south=0; 


void Norther(void *arg){
       	sem_wait(&mutexN);
	north++;
	if(north==1)
	       	pthread_mutex_lock(&mutex);       
        sem_post(&mutexN);
	printf("Now the farmers towards north are in the fridge.\n");
	sleep(1);
	sem_wait(&mutexN);
	north--;
	if(north==0){
		printf("The last famer towards north leaves the fridge.\n");
		pthread_mutex_unlock(&mutex);
	}       
        sem_post(&mutexN);
    pthread_exit(0);
}

void Souther(void* arg){
        sem_wait(&mutexS);
	south++;
	if(south==1)
	       	pthread_mutex_lock(&mutex);         
        sem_post(&mutexS);
	printf("Now the farmers towards south are in the fridge.\n");
        sleep(1);
	sem_wait(&mutexS);
	south--;
	if(south==0){
		printf("The last farmer towards south leaves the fridge.\n");
		pthread_mutex_unlock(&mutex);
	}	
        sem_post(&mutexS);
    pthread_exit(0);
}

int main(){
    pthread_t norther[north_num];
    pthread_t souther[south_num]; 
    int var,i;
    pthread_mutex_init(&mutex,NULL); 
    var=sem_init(&mutexN,0,1);      
    if(var!=0){
        printf("error");
        exit(0);
    }          
    var=sem_init(&mutexS,0,1);                  
    if(var!=0){
        printf("error");
        exit(0);
    }    
    for(i=0;i<north_num;i++){         
        var=pthread_create(&norther[i],NULL,(void *)Norther,NULL);
        if(var!=0){
        printf("error in create");  
        exit(0);
        }
    }

    for(i=0;i<south_num;i++){         
        var=pthread_create(&souther[i],NULL,(void *)Souther,NULL);  
        if(var!=0){
        printf("error in create");
        exit(0);
        }

    }
    for(i=0;i<north_num;i++){
        pthread_join(norther[i],NULL);
    }
    for(i=0;i<south_num;i++){
         pthread_join(souther[i],NULL);
    }
     return 0;
 }



