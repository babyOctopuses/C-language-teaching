#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printPokemon();
void playGame(char playerName[20], int playerHP);
void printMenu();
int attack(int min, int max);

// function prototypes
int main() {
  // set up random number generator
    srand(time(NULL));

    char playerName[20];
    int playerHP = 100;
    printf("\n1playerHP=%d", playerHP);

    printf("welcome to the world of pokemon\n");
    printf("what's your name?\n");
    scanf("%s", playerName);

    playGame(playerName,playerHP);

    printf("Thanks for playing!\n");
  return 0;
}

void printMenu(){
    printf("1. Attack\n");
    printf("2. Defend\n");
}

void playGame(char playerName[20], int PlayerHP ){
    char pokemonName[20];
    int pokemonHP=100;

    printf("\na wild pikachu has appeared\n");
    printPokemon("Pikachu");

    while(PlayerHP > 0 && pokemonHP > 0){
        printMenu();

        int choice;

        printf("enter your choice");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                pokemonHP -= attack(10,15);
                printf("\n%s attacked %s\n", playerName, pokemonName);
                printf("\n%s's hp is now %d\n", pokemonName, pokemonHP);
                break;
            case 2:
                PlayerHP -= attack(10,15);
                printf("\n%s attacked %s\n", pokemonName, playerName);
                printf("\n%s's hp is now %d\n", playerName, PlayerHP);
                break;
            default:
                printf("\nplease choose the correct option\n");
                break;
        }
    }

    if(PlayerHP>0){
        printf("%s wins", playerName);
    }else{
        printf("%s wins", pokemonName);
    }
}



void printPokemon(char* name) {
  printf("    ,___,\n");
  printf("   /     \\\n");
  printf("  |  %s |\n", name);
  printf("  \\     /\n");
  printf("   `---'\n");
}

int attack(int min, int max){
    int num = rand() % (max-min+1)+min;
    printf("%d", num);
    return num;
}


/*
1. player's name and hp
2. a welcome board and enter name
3. a function to playgame
    1. create opponents' name and hp
    2. print pokemon's name and picture
    3. a function to display menu (attack and defends)
    4. an option if player attacks, pokemon's hp is decreased
    5. an option if player defends, player's hp is decreased
        attack is rand() % (max-min+1)+min
    6. an option if it's neither, player has to choose the correct options
    7. if player's hp is more than 0, pokemon wins, else opponent wins
*/