//Blair Todd
//CS4328
//Project 3 


   #include <stdio.h>
   #include <math.h>
   #include <unistd.h>
   #include <pthread.h> // import pthreads


   void *get25percent(char id);

   struct Award{
      int scholarship;
      int withdrawn;
   }; 
  
   struct Award account;

   int main(){
            //declare threads
      pthread_t studentA;
      pthread_t studentB;
      pthread_t studentC;

      account.scholarship = 4000; 
      account.withdrawn = 0;

      //initialize threads    
      pthread_create(&studentA, NULL, (void*(*)(void*)) get25percent, (void*) 'A');
      pthread_create(&studentB, NULL, (void*(*)(void*)) get25percent, (void*) 'B'); 
      pthread_create(&studentC, NULL, (void*(*)(void*)) get25percent, (void*) 'C');


      printf("Total given out:%d \n", account.withdrawn);

      pthread_exit(0);
   }

   void *get25percent(char id){
     
      int myTotal = 0;
      int temp;
      
      while((account.scholarship > 0)){ //while money is available

         temp = ceil(account.scholarship * 0.25); 
         account.scholarship = account.scholarship - temp;   //update scholarship

         myTotal += temp;  
 
         printf(" %c = %d\n", id, temp);
         sleep(1);    
      }

      account.withdrawn += myTotal;
   }
         
