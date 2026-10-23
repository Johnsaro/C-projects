// The program picks a random number from 1 to 100, and you guess until you get it right, with “too high/too low” hints.

#include <stdio.h>
#include <windows.h> 
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>

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

int score(int wrong_guesses){
    int penalty = 15;
    int base = 100;
    int total_score = base - (wrong_guesses * penalty);
    return total_score;
}



void guess() {
    int default_score = 0;

    int user_guess = 0;// user input

    int tries = 0;
    int max_guess = 5;
    int correct_number = generate_random_number();

    while (user_guess != correct_number && tries < max_guess) {
        printf("Your guess: ");

        while (scanf("%d", &user_guess) != 1) {
            printf("[warning] Enter Number from 1-100!\n");
            while(getchar() != '\n');
        }
    

        if (user_guess == correct_number) {
            int new_score = score(tries);
            printf("You Guess the Correct Number in %d tries!\n", tries);
            printf("You Win!, Congratulations\n");
            printf("+%d score\n",new_score);
            

        } else {
            if(user_guess < 1 || user_guess > 100) {
                printf("[WARNING] Out of range enter 1 - 100 only! \n");
            } else {
                if (user_guess < correct_number) {
                    printf("[HINT] Guess is too low!\n");
                    tries++;
                    int guess_left = max_guess - tries;
                    printf("Tries left: %d/%d\n", guess_left, max_guess);
                } else {
                    printf("[HINT] Guess is too high!\n");
                    int guess_left = max_guess - tries;
                    printf("Tries left: %d/%d\n", guess_left, max_guess);
                }
            } 
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
    int play_again = 1;
    int number_of_games = 1;
    
    printf("Project Number 1: Number Guessing Game\n");
    printf("1. Start\n");
    printf("2. Exit\n");

    while (scanf("%d", &choice) != 1) {
        printf("Invalid Pls enter a number!\n");
        while (getchar() != '\n');
    } 

    if (choice == 1){
        while(play_again == 1) {
            printf("Loading game\n");
            loading_animation();
            printf("[ROUND %d] \n", number_of_games);
            printf("# 5 Guess only \n");
            guess();
            printf("\n[1] Play again    [2] Exit\n");

            // FIX 1: Read directly into play_again instead of choice
            while(scanf("%d", &play_again) != 1) {
                printf("[Warning] Enter 1 or 2 only!\n");
                while(getchar() != '\n');
            }

            // FIX 2: Handle invalid input if they type numbers other than 1 or 2
            while (play_again != 1 && play_again != 2) {
                printf("[Warning] Enter 1 or 2 only!\n");
                printf("\n[1] Play again    [2] Exit\n");
                while(scanf("%d", &play_again) != 1) {
                    while(getchar() != '\n');
                }
            }

            // Increment the game round tracker
            number_of_games++;
        }
        
        printf("Exiting program. Goodbye!\n");

    } else if (choice == 2) {
        printf("Exiting program. Goodbye!\n");
    } else {
        printf("Invalid choice! Please run again and type 1 or 2.\n");
    }
    
    return 0;
}


// Next patch : 
/*
 file handling for user local saved progress so score keep coming up
 more improve txt and UI

*/

