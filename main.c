#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printPrompt();
int generateNumber(int min, int max);
int getGuesses(int guess);
void checkGuess(int myGuess, int target);

//learn about function
int main(){
    int num;
    int myGuess;
    
    srand(time(NULL));

    int target = generateNumber(1,100);
    int guess = 0;

    
    printPrompt();

    while(1){
        myGuess = getGuesses(guess);
        checkGuess(myGuess, target);
        guess++;
        if (myGuess == target) {
        break;
    }
    };

    printf("Thank you for playing");

    return 0;
}

void printPrompt(){
    printf("\nplease choose 1-100\n");
    printf("can you guess the number?\n");
}

int generateNumber(int min, int max){
    int num = (rand() % (max-min+1))+min;
    return num;
}

int getGuesses(int guess){
    printf("\nGuess #%d: ", guess+1);
    
    int myGuess;
    scanf("%d", &myGuess);
    return myGuess;
}

void checkGuess(int myGuess, int target){
    if(myGuess<target){
        printf("\ntoo low, enter higer number");
    }else if(myGuess > target){
        printf("\ntoo high, enter a lower number");
    }else{
        printf("Correct");
    }
}