Blair Todd
CS 4328

-Compilation
gcc shell.c -o shell
gcc pre.c -o pre
gcc sort.c -o sort

run with: ./shell

Sample commands:

shhh>ls 

shhh>ls -t -al

shhh>cat file.txt   (file.txt is an existing file)

shhh>ls -al > output.txt

And then open output.txt to see if the content is correct or not

shhh> ls | more | wc

shhh>./pre < input.txt | ./sort > output.txt (./pre and ./sort are the executable from proj1. 
                                          input.txt is the file that provides the input
                                          and output.txt is the output file)

shhh> exit
