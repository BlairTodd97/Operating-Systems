// Blair Todd
// CS 4328
// Project 3
//

   #include <stdio.h>
   #include <math.h>
   #include <unistd.h>
   #include <pthread.h>
  
   void *get25percent(char id);
   
   struct Award{
      int scholarship;
      int withdrawn; 
   };


   struct Award account; //shared memory

   pthread_mutex_t mutex;
   
   int main(){
   
      pthread_t studentA;
      pthread_t studentB;
      pthread_t studentC;

      account.scholarship = 4000;
      account.withdrawn = 0;
   
      pthread_create(&studentA, NULL, (void*(*)(void*)) get25percent, (void*) 'A');
      pthread_create(&studentB, NULL, (void*(*)(void*)) get25percent, (void*) 'B');
      pthread_create(&studentC, NULL, (void*(*)( void*))get25percent, (void*) 'C');
      
      pthread_join(studentA, NULL);
      pthread_join(studentB, NULL);
      pthread_join(studentC, NULL);
      
      printf("Total given out:%d \n", account.withdrawn);

  
      pthread_exit(0);
   }

   void *get25percent(char id){
      int myTotal = 0;
      int temp;  
  
      pthread_mutex_lock(&mutex);
   
      while(account.scholarship > 0){
      temp = ceil(account.scholarship * 0.25);
      account.scholarship = account.scholarship - temp;
    
      myTotal = myTotal + temp;
  
      printf(" %c = %d\n", id, temp);
   
      sleep(1); //delay output of thread
      pthread_mutex_unlock(&mutex);

    
      }
  
    account.withdrawn += myTotal;
  
   }   
