#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void printMenu();
void printPokemon(char*);
int attack(int, int);
void playGame(char*, int);

int main() {
  // set up random number generator
  srand(time(NULL));

  char playerName[20];
  int playerHP = 100;

  printf("Welcome to the Pokemon game!\n");
  printf("Enter your name: ");
  scanf("%s", playerName);

  playGame(playerName, playerHP);

  printf("Thanks for playing!\n");
  return 0;
}

void playGame(char* playerName, int playerHP) {
  char opponent[10] = "Pikachu";
  int opponentHP = 100;

  printf("\n%s, your opponent is:\n", playerName);
  printPokemon(opponent);

  // loop until someone wins or loses
  while (playerHP > 0 && opponentHP > 0) {
    printMenu();

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // player attacks
        opponentHP -= attack(10, 20);
        printf("You attacked %s!\n", opponent);
        printf("%s's HP is now %d.\n", opponent, opponentHP);
        break;
      case 2:
        // opponent attacks
        playerHP -= attack(5, 15);
        printf("%s attacked you!\n", opponent);
        printf("Your HP is now %d.\n", playerHP);
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }

  // print winner or loser
  if (playerHP > 0) {
    printf("%s wins!\n", playerName);
  } else {
    printf("%s wins!\n", opponent);
  }
}

void printMenu() {
  printf("1. Attack\n");
  printf("2. Defend\n");
}

void printPokemon(char* name) {
  printf("    ,___,\n");
  printf("   /     \\\n");
  printf("  |  %s |\n", name);
  printf("  \\     /\n");
  printf("   `---'\n");
}

int attack(int min, int max) {
  // generate a random number between min and max inclusive
  return rand() % (max - min + 1) + min;
}
