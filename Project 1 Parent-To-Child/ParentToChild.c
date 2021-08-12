// Blair Todd
// Operating Systems 
// Project 1
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, const char * argv[]){

   int p[2]; 
   int pid = 0;

   if(pipe(p) == -1){ // check for failure
   
    perror("failed pipe call");
    exit(1);

   }

   pid = fork();

   if(pid < 0){
   fprintf(stderr, "Error: Failed Fork");
    exit(-1);
   }

   //TEST check if parent to child
   else if(pid >  0){ //if Paraent 
        
    close(p[1]);
    dup(p[1]);
    close(p[0]);
    close(p[1]);
    execvp("./pre", NULL);
 
    exit(0);


   }


   // TEST 
   else{ // if child
     

    wait(NULL);
    close(p[0]);
    dup(p[0]);
    close(p[0]);
    close(p[1]);
    execvp("./sort", NULL);
    exit(0);
    


   }

   return 0;
}
