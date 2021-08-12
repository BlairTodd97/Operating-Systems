// Blair Todd
// Operating Systems
// Project 1

#include <stdio.h>

int main(int argc, char * argv[]){

    struct States{
        char name[2];
        int pop;
    };

    int counter = 0;
    int i = 0;

    struct States states[10];

    // Test EOF detection
    while(scanf("%s %d", states[counter].name, &states[counter].pop) != EOF){ //scan input

        counter++;
        if(counter == 10)
           break;
    }

    counter = 0;

    printf("\n");

  
    while(i < 10){ // output if pop more than 10
        if(states[counter].pop > 10){
            printf("%s %d \n", states[counter].name, states[counter].pop);
            counter++;
        }
        else
           counter++;
           i++;
    }

    return 0;

}
