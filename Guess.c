// The program picks a random number from 1 to 100, and you guess until you get it right, with “too high/too low” hints.

#include <stdio.h>
#include <windows.h> 
#include <stdlib.h> 
#include <time.h>

void loading_animation() {
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        Sleep(1000);
    }
    printf("\n");
    system("cls");
} 


int generate_random_number() {
    int number = rand() % 100 + 1;
    return number;
}


void guess() {
    int default_score = 0;
    int correct_score = 30;
    int new_score = default_score + correct_score;

    int user_guess; // user input

    int tries = 0;
    int max_guess = 5;

    int correct_number = generate_random_number();

    printf("Score: %d\n", default_score);
    printf("[DEBUG] The correct number is: %d\n", correct_number);


    while (user_guess != correct_number && tries < max_guess) {
        printf("Your guess: ");

        while (scanf("%d", &user_guess) != 1) {
            printf("[warning] Enter Number from 1-100!\n");
            while(getchar() != '\n');
        }
    

        if (user_guess == correct_number) {
            printf("You Guess the Correct Number in %d tries!\n", tries);
            printf("You Win!, Congratulations\n");
            break;
        } else {
            if (user_guess < correct_number) {
            printf("[HINT] Guess is too low!\n");
            tries++;
            } else {
                printf("[HINT] Guess is too high!\n");
                tries++;
            }
            printf("Tries left: %d/%d\n", tries, max_guess);
        }

        if(tries == max_guess){
            printf("You run out of Guess Better luck next Time!\n");
            printf("[GAMEOVER]\n");
        }
    }
}


int main(void){
    srand(time(NULL));
    int choice;


    printf("Project Number 1: Number Guessing Game\n");
    printf("1. Start\n");
    printf("2. Exit\n");

    while (scanf("%d", &choice) != 1) {
        printf("Invalid Pls enter a number!\n");
        while (getchar() != '\n');
    } 

    if (choice == 1){
        printf("Starting game\n");
        loading_animation();
        printf("# 5 Guess only \n");
        guess();
    } else if (choice == 2) {
        printf("Exiting program. Goodbye!\n");
    } else {
        printf("Invalid choice! Please run again and type 1 or 2.\n");
    }

    return 0;
}

// Next patch : 
/*
 Need to clear the terminal after loading animation
 Add a guess turn or retries 5x
 add a while loop for the ff:
 menu choice
 guess - done
 add hints - done
 improve scoring for more fun
 file handling for user local saved progress so score keep coming up
 more improve txt and UI

*/

