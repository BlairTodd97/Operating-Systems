// Blair Todd
// CS 4328
// Project 2



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main()

{

char *path, *argv[20], buf[80], n, *p;
int m, status, inword, continu;

while(1) {

inword = 0;

p = buf;

m = 0;

continu=0;


printf( "\nshhh> ");

while ( ( n = getchar() ) != '\n'  || continu ) {
	if ( n ==  ' ' ) {
	    if ( inword ) {
		inword = 0;
		*p++ = 0;
	    }
	}

	else if ( n == '\n' ) continu = 0;

	else if ( n == '\\' && !inword ) continu = 1;

	else {
	    if ( !inword ) {

		 inword = 1;

		 argv[m++] = p;

		 *p++ = n;

	     }

	     else

		 *p++ = n;

	}

}

*p++ = 0;

argv[m] = 0;



if ( strcmp(argv[0],"exit") == 0 ) exit (0);

/* Your change starts from here */

   char *inPath, *outPath;
   int count = 0;
   int pipes = 0;
   int input_flag = 0; //flags
   int output_flag = 0;
   int i, pid; //ids
   int start[20] = {0}, r_fd[2], l_fd[2]; //arrays

   while(argv[count] != 0){
      if(strcmp(argv[count], "|") == 0){
         argv[count] = 0;
         pipes++;
         start[pipes] = count + 1;
      }

      else if(strcmp(argv[count], "<") == 0){
         inPath = argv[count + 1];
         input_flag = 1;
         argv[count] = 0;
         argv[count + 1] = 0;
         count++;
      }

      else if(strcmp(argv[count], ">") == 0){
         outPath = argv[count + 1];
         output_flag = 1;
         argv[count] = 0;
         argv[count + 1] = 0;
         count++;

      }
      else
         start[count] = count;
         count++;
     }

      for(i = 0; i <= pipes; i++){
         if(pipes > 0 && i != pipes)
            pipe(r_fd);

      pid = fork();

      if(pid < 0){
         fprintf(stderr, "Fork failed\n");
         exit(-1);
      }

      else if(pid == 0){
         if(input_flag == 1 && i == 0){
            int file = open(inPath, O_RDONLY, 0400);

            if(file == -1){
               perror("Input file failed to open\n");
               exit(-1);
            }
            close(0);
            dup(file);
            close(file);
         }

      if(output_flag == 1 && i == pipes){
         int file = open(outPath, O_WRONLY | O_CREAT, 0755);

         if(file == -1){
            perror("Output file failed to open\n");
            exit(-1);
         }
         close(1);
         dup(file);
         close(file);
      }

      if(pipes > 0){
         if(i == 0){
            close(1);
            dup(r_fd[1]);
            close(r_fd[1]);
            close(r_fd[0]);
         }

         else if(i < pipes){
            close(0);
            dup(l_fd[0]);
            close(l_fd[0]);
            close(l_fd[1]);
            close(1);
            dup(r_fd[1]);
            close(r_fd[1]);
            close(r_fd[0]);
         }

         else{
            close(0);
            dup(l_fd[0]);
            close(l_fd[0]);
            close(l_fd[1]);
         }
      }

      execvp(argv[start[i]], &argv[start[i]]);
      perror("Command failed\n");
      }

      else{
         if(i > 0){
            close(l_fd[0]);
            close(l_fd[1]);
         }

      l_fd[0] = r_fd[0];
      l_fd[1] = r_fd[1];


      wait(&status);

         }

    }

      }
   exit(0);
}

