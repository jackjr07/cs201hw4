#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int menu();

int addition(char *argv[], int total){
    int i = 1;
    int sum = 0;
    while(i <= total){
        sum += atoi(argv[i]);
        ++i;
    }
    for(int i = 1; i <= total; ++i){
       if(i == total){
        printf("%s = %d\n", argv[i], sum);
       }else{
        printf("%s + ", argv[i]);
       }
    }
};

int upHex(char argvH[]){
    int sum = 0;
    for(int i =0; i<2; ++i){
        int hold = argvH[i];
        printf("%d - hold\n", hold);
        if(hold >= 48 && hold <= 57){
            hold -= 48;
            sum += hold;
            //printf("%d - sum\n", sum);
        }
        else if(hold >= 97 && hold <= 102){
            hold -= 87;
            sum += hold;
            //printf("%d - sum\n", sum);
        }
    }
    printf("%d - Fsum\n", sum);
    return sum;
}
int additionH(char *argvH[], int total){
    int hold, sum = 0;
    for(int i = 1; i<=total; ++i){
        printf("%s --\n", argvH[i]);
        hold += upHex(argvH[i]+2);
    }
    printf("%d - sumH", sum);
    
};
int substraction(char *argv[], int total){
    int i = 1;
    int diff = atoi(argv[i]);
    ++i;
    while(i <= total){
        diff -= atoi(argv[i]);
        ++i;
    }
    for(int i = 1; i <= total; ++i){
       if(i == total){
        printf("%s = %d\n", argv[i], diff);
       }else{
        printf("%s - ", argv[i]);
       }
    }
}

int multiplication(char *argv[], int total){
    int i = 1;
    int mul = atoi(argv[i]);
    ++i;
    while(i <= total){
        mul *= atoi(argv[i]);
        ++i;
    }
    for(int i = 1; i <= total; ++i){
       if(i == total){
        printf("%s = %d\n", argv[i], mul);
       }else{
        printf("%s * ", argv[i]);
       }
    }
}

int division(char *argv[], int total){
    int i = 1;
    if(atoi(argv[i+1]) == 0){
        printf("%s / %s = -nan\n", argv[i], argv[i+1]);
        return 1;
    }
    float div = (float)atoi(argv[i])/(float)atoi(argv[i+1]);
    printf("%s / %s = %f\n", argv[i], argv[i+1], div);
}

int modulo(char *argv[], int total){
    int i = 1;
    int mod = atoi(argv[i]) % atoi(argv[i+1]);
    printf("%s mod %s = %d\n", argv[i], argv[i+1], mod);
}

int reverse(char * argv[], int total){
    while(total != 0){
        printf("%s ", argv[total]);
        --total;
    }
    printf("\n");
}

int updateHexToDec(char argvD[]){
    int sum = 0;
    for(int i = 0; i<2; ++i){
       int hold = argvD[i];
       //printf("%d - hold\n", hold);
        if(hold >= 48 && hold <= 57){
            hold -= 48;
            sum += hold;
            if(i==0) sum *= 16;
            //printf("%d - sum\n", sum);

        }
        else if(hold >= 97 && hold <= 102){
            hold -= 87;
            sum += hold;
            //printf("%d - sum\n", sum);
        }
    }
    //printf("%d - Fsum\n", sum);
    return sum;
}

int main(int argc, char *argv[]){

    //Create Vals
    int ans = 99;
    int total = argc-1;
    char *argvH[total];
    char *argvD[total];

    //Check does user gave enough parameters
    if(argc < 3 || argc > 16){
        if(argc < 3){
            printf("You MUST give at least 2 numbers\n");
        }else{
            printf("You give too much number, MAX at 15 parameters\n");
        }
        return 0;
    }
    //update hex to decimal
    int j = 1;
    while(j <=total){
        if(argv[j][1] == 'x'){
            //printf("%s\n", argv[j]+2);
            argvD[j] = argv[j]+2;
            int temp = updateHexToDec(argvD[j]);
            //printf("%d - test", test);
            sprintf(argvD[j], "%d", temp);
        }else{
            argvD[j] = argv[j];
        }
        ++j;
    }
/*
    printf("%s\n", argv[1]);
    //Update decimal to Hex
    int k = 1;
    while(k <=total){
        if(argv[k][1] == 'x'){
            printf("%s\n", argv[k]+2);
            argvH[k] = argv[k];
        }else{
            char hold[] = "0x";
            strcat(hold, argv[k]);
            argvH[k] = hold;
        }
        ++k;
    }
    for(int i = 1; i <= total; ++i){
        printf("%s - ", argvH[i]);
    }
    */
    
    while(ans != 0){
        ans = menu();
        if(ans == 1){
            addition(argvD, total);
        }
        else if(ans == 2){
            substraction(argvD, total);
        }
        else if(ans == 3){
            multiplication(argvD, total);
        }
        else if(ans == 4){
            division(argvD, total);
        }
        else if(ans == 5){
            modulo(argvD, total);
        }
        else if(ans == 6){
            reverse(argv, total);
        }
    }

    return 0;
}

int menu(){
    int ans;
    printf(" 0. Exit\n 1. Addition\n 2. Substraction\n 3. Multiplication\n 4. Division\n 5. Modulo\n 6. Reverse Input\n");
    printf("Menu Item: ");
    scanf("%d", &ans);
    if(ans >= 0 && ans <= 6){
        return ans;
    }else{
        printf("Invalid Selection. Try again\n");
        return menu();
    }
}
