/*
 ============================================================================
 Name        : CColeThreeNPlusOne.c
 Author      : Cody Cole
 Version     :
 Copyright   : 26 August 20
 Description : ThreeNPlusOne CS 137
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int computeMaxSequenceLength(int minRange, int maxRange);//Calls computeSequenceLength and returns length of sequence
int computeSequenceLength(int n);//Calls computeNextValue and returns sequenceLength
int computeNextValue(int n);//Uses the algo to compute sequenceLength and returns
int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    char fileName[50];
    int maxSequence = 0;

    puts("Enter filename for output");
    fgets(fileName, 50, stdin);
    fileName[strcspn(fileName, "\n")] = 0;
    //Must use fgets instead. scanf leaves \n char in buffer
    FILE *fptr = fopen(fileName, "w+");//open file

    int minRange = 0, maxRange = 0, flag = 0;
    char minAsChar[6], maxAsChar[6];

    while(flag != 1){//Might need to change flag
        fgets(minAsChar, 6, stdin);//Might leave \n character in buffer
        if(minAsChar[0] == 10){//Checks if minValue is a newline
            flag = 1;
            continue;
        }

        minRange = atoi(minAsChar);//Turn char to int
        //Used fgets instead of scanf to avoid \n char. Using fgets requires charstring
        fgets(maxAsChar, 6, stdin);
        maxRange = atoi(maxAsChar);//Turn character into integer

        //Call to compute
        maxSequence = computeMaxSequenceLength(minRange, maxRange);
        fprintf(fptr, "%d\t%d\t%d\n", minRange, maxRange, maxSequence);
    }
    fclose(fptr);
    printf("Complete\n");//Might need to use printf and \n instead
    return 0;
}

int computeMaxSequenceLength(int minRange, int maxRange){
    //for loop iterates over each n
    int i, maxSequence = 0;
    for(i = minRange; i <= maxRange; i++){//for each value call computeSequenceLength to achieve length
        int sequenceLength = computeSequenceLength(i);
        //Check to see if new sequence is larger than current
        if(sequenceLength > maxSequence)
            maxSequence = sequenceLength;
    }
return maxSequence;//Return largest sequence not maxRange
}

int computeSequenceLength(int n){
    //Calls computeNextValue to find sequence
    int sequenceLength = computeNextValue(n);
return sequenceLength;//Return sequence length for n
}

int computeNextValue(int n){//Uses the algorithim to find number of sequences
    int sequenceLength = 1;
    while(n != 1){
        if(n%2 == 0){//If n is even.
            n /= 2;
        }else if(n%2 == 1){
            n = 3*n + 1;
        }
        sequenceLength++;
    }
return sequenceLength;
}
