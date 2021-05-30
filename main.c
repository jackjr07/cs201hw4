#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])

{
    {
        int i, Sum = 0, Difference = 0, Multiplication = 0, Divide = 0, Modulo = 0;

            if (argc != 3) {
                       printf("You have forgot to specify two numbers.");
                              exit(1);
                                  }
            Sum= atoi(argv[1])+atoi(argv[2]);
            Difference = atoi(argv[1]) - atoi(argv[2]);
            Multiplication = atoi(argv[1]) * atoi(argv[2]);
            Divide = atoi(argv[1])/float(atoi(argv[2]));
            Modulo = atoi(argv[1])%atoi(argv[2]);
                printf("Sum = %d\n", Sum);
                printf("Difference = %d\n", Difference);
                printf("Multiplication = %d\n",Multiplication);
                printf("Division = %.2f\n", Divide);
                printf("Modulo= %d\n", Modulo);

                  
                        return 0;

    }

    {
        int k;
        char temp;
        int i,j=0;
        int strsize = 0;
        for (i=1; i<argc; i++) {
            strsize += strlen(argv[i]);
            if (argc > i+1)
                strsize++;
        }
        char *cmdstring;
        cmdstring = malloc(strsize);
        cmdstring[0] = ‘\0’;
        for (k=1; k<argc; k++) {
            strcat(cmdstring, argv[k]);
            if (argc > k+1)
                strcat(cmdstring, " ");
        }
        i = 0;
        j = strlen(cmdstring) – 1;
        while (i < j) {
            temp = cmdstring[i];
            cmdstring[i] = cmdstring[j];
            cmdstring[j] = temp;
            i++;
            j–;
        }
        printf("\nReverse string is :%s", cmdstring);
        return(0);
    }

}
