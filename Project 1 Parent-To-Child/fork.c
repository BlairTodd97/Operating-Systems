// Blair Todd
// Operating Systems
// Project 1

#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <sys/types.h>

int main(int argc, const char * argv[]){

   int pid; //create variables to hold ids
   int cid = getpid();
   int ppid = getppid();

   pid = fork(); //fork instances

   if(pid < 0){ //ERROR MESSAGE 
      
       printf("ERROR: Fork Failed");
       exit(-1);
   }

   else if(pid == 0){ // CHILD
    printf("Child Process ID: %d\n", cid);
    execvp(argv[1], &argv[1]);
   }

   else{ //PARENT
      wait(NULL); 
      printf("Parent Process ID Number: %d\n", ppid);

      exit(0); 
   }

   return 0;


}
