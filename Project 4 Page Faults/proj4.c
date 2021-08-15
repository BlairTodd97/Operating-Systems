//Blair Todd
//CS 4328
//Project 4



   #include <stdio.h>
   #include <stdlib.h>
   #include <time.h>

  

   #define SIZE 20

   void showFrames(int frames[], int frameSize){
      int i;

      for(i = 0; i < frameSize; i++)
         printf("%d\t", frames[i]);
  
      }

   
   void incrementCount(int frames[], int counter[], int frameSize){
      int i;

      for(i = 0; i < frameSize; i++)
         if(frames[i] != 0)
            counter[i]++;

   }


   int LRU(int str[], int frameSize){
      int pageFaults = 0;
      int oldest = 0;

      int frames[frameSize];
      int counter[frameSize];
      int flag[2];

      int i,j;

      for(i = 0; i < frameSize; i++){
         flag[0] = 0;
         flag[1] = 0;

         for(j = 0; j < frameSize; j++){
            if(str[i] == frames[j]){
               counter[j] = 0;
               flag[0] = 1;
               flag[1] = 1;
               break;
         }

            else if(flag[0] == 0 && frames[j] == 0){
               frames[j] = str[i];
               incrementCount(frames, counter, frameSize);
               pageFaults++;
               flag[1] = 1;
               break;
            }
         }
      
      if(flag[1] == 0){
         oldest = 0;
         for(j = 0; j < frameSize; j++)
            if(counter[j] > oldest)
               oldest = counter[j];

         for(j = 0; j < frameSize; j++)
            if(oldest == counter[j])
               break;


         frames[j] = str[i];
         pageFaults++;
         counter[j] = 0;
         incrementCount(frames,counter,frameSize);
      }

      printf("\n");
      showFrames(frames,frameSize);
     } 
     
 
      printf(" LRU PAGE FAULTS: %d\n", pageFaults);
      return pageFaults;

   }


   int optimal(int str[], int frameSize){

      int pageFaults = 0, farthest = 0;
      int frames[frameSize], future[frameSize], flag[3];
      int i,j,k;

      for(i = 0; i < frameSize; i++){
         frames[i] = 0;
         future[i] = 0;
      }

      for( i = 0; i < SIZE; i++){
         flag[0] = 0;
         flag[1] = 0;

         for(j = 0; j < frameSize; j++){
            if(str[i] == frames[j]){
               flag[0] = 1;
               flag[1] = 1;
               break;
            }
 
            else if(flag[0] == 0 && frames[j] == 0){
               frames[j] = str[i];
               pageFaults++;
               flag[1] = 1;
               break;
            }
         }

         if(flag[1] == 0){
            flag[2] = 0;

            for(j = 0; j < frameSize; j++){
              future[j] = 0;
 
              for(k = i+1; k < SIZE; k++){
                 if(str[k] == frames[j]){
                    future[j] = k;
                    break;
                 }
              }

              if(future[j] == 0){
                 farthest = 0;
                 for(j = 0; j < frameSize; j++){
                    if(future[j] > farthest)
                       farthest = future[j];
                }

                 for(j = 0; j < frameSize; j++){
                    if(farthest == future[j])
                       break;
                 }

              frames[j] = str[i];
              pageFaults++;

           }

           printf("\n");
           showFrames(frames,frameSize);
           }

           printf(" OPTIMAL PAGE FAULTS: %d\n", pageFaults);
           return pageFaults;
        }
      }
     
   }
        int randomNum(int lower, int upper){
           int num = 0;
           num = (rand() % (upper - lower + 1)) + lower;
           return num;
        }

        int main(){
           int frames = 0, i, difference = 0;
           int refString[SIZE];

           srand(time(0));
 
           printf(" Enter number of frames:\t");
           scanf(" %d", &frames);
           
           while(frames < 1){
              printf(" Re-enter frame number:\t");
              scanf(" %d", &frames);
           }

           for(i = 0; i < SIZE; i++){
              refString[i] = randomNum(1,5);
           }
              
           printf("\nReference String: ");
           for(i = 0; i < SIZE; i++){
              printf(" %d ", refString[i]);
           }

           printf("\n");

           int lru = LRU(refString, frames);
           int opt = optimal(refString, frames);

           if(lru > opt){
             difference = lru - opt;
             printf("\nLRU had %d more page faults than Optimal.\n", difference);
          }

          else if(lru < opt){
             difference = opt - lru;
             printf("\n Optimal had %d more page faults than LRU. \n", difference);
         }
         else
            printf("\n Both LRU and Optimal had the same number of page faults.\n");

         printf("\n");

         return 0;
         }
