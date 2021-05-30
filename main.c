#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu();

int main(int argc, char *argv[]){

    //Create Vals
    int i = 0;
    int sum = 0;
    int diff = 0;
    int multiplication = 0;
    int divide = 0;
    int modulo = 0;

    //start menu
    int ans = menu();

    //Check does user gave enough parameters
    if(argc != 3){
        printf("You MUST give 2 numbers");
        return 0;
    }

    sum = atoi(argv[1])+atoi(argv[2]);
    diff = atoi(argv[1]) - atoi(argv[2]);

    printf("Sum: %d\n", sum);
    printf("Different: %d\n", diff);

    return 0;
}

int menu(){
    int ans;
    printf(" 0. Exit\n 1. Addition\n 2. Substraction\n 3. Multiplication\n 4. Division\n 5. Modulo\n 6. Reverse Input\n");
    printf("Menu Item: ");
    scanf("%d", &ans);
    return ans;
}
