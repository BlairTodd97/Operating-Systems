#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){

   struct States{
      char name[3];
   };

   struct States states[10];
   struct States temp;

   int counter = 0;
   int i;
   int j;

   //To DO: Fix EOF detection

   while(scanf("%s", states[counter].name) != EOF){
    counter++;
    if(counter == 10)
        break;
   }

   for(i = 0; i <= counter; i++)
       for(j = 0; j <= counter - i; j++){
            if(strcmp(states[j].name, states[j+1].name) > 0){
                temp = states[j+1];
                states[j+1] = states[j];
                states[j] = temp;
            }
       }
   

       for(i = 0; i < counter; i++)
           printf("%s\n", states[i].name);

   return 0;
   }
