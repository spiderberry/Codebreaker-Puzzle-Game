 /*
 Dandre Kennedy
 Guessing Minigame
 Generates a code and user has to guess within certain number tries.
 Provides feedback on the guess.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define TRIES 10
#define DIGITS 3
#define RANGE 10

int main() {
    int secretCode[DIGITS];
    int attemptsLeft = TRIES;
    int secretNumber = 0;
    char input[20];
    srand(time(NULL));  // Seed the random number generator

    // Generate secret code
    for (int i = 0; i < DIGITS; i++) {
        secretCode[i] = rand() % RANGE;
    }

    // Convert secret code array to a single integer for comparison
    for (int i = 0; i < DIGITS; i++) {
        secretNumber = secretNumber * 10 + secretCode[i];
    }

    printf("Guessing Minigame\n");
    printf("Guess the %d-digit code. Each digit ranges from 0 to %d.\n", DIGITS, RANGE - 1);
    printf("You have %d tries to guess the code. Enter \"q\" or \"Q\" to quit.\n\n", TRIES);

    while (attemptsLeft > 0) {
        printf("%d tries remaining. What is the code? ", attemptsLeft);
        scanf("%s", input); 

        if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
            printf("You quit the game. The secret code was %d.\n", secretNumber);
            exit(0);
        }

        if (strlen(input) != DIGITS) {
            printf("Invalid input! Enter exactly %d digits.\n\n", DIGITS);
            continue;
        }

        // Check if all characters are digits
        int valid = 1;
        for (int i = 0; i < DIGITS; i++) {
            if (!isdigit(input[i])) { 
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Invalid input! Only digits are allowed.\n\n");
            continue;
        }

        int guessNumber = atoi(input);
        int guess[DIGITS];
        int temp = guessNumber;

        // Convert the guess number back to an array of digits
        for (int i = DIGITS - 1; i >= 0; i--) {
            guess[i] = temp % 10;
            temp /= 10;
        }

        if (guessNumber == secretNumber) {
            printf("You opened the vault! The code was %d.\n", secretNumber);
            return 0; 
        }

        if (guessNumber > secretNumber)
            printf("Too high, ");
        else
            printf("Too low, ");

        // Count digits in correct position
        int correctPos = 0;
        for (int i = 0; i < DIGITS; i++) {
            if (guess[i] == secretCode[i])
                correctPos++;
        }

        // Count digits in correct/wrong positions
        int secretCount[RANGE] = {0};
        int guessCount[RANGE] = {0};
        for (int i = 0; i < DIGITS; i++) {
            secretCount[secretCode[i]]++;
            guessCount[guess[i]]++;
        }

        int totalCorrect = 0;
        for (int i = 0; i < RANGE; i++) {
            totalCorrect += (secretCount[i] < guessCount[i]) ? secretCount[i] : guessCount[i];
        }

        int wrongPos = totalCorrect - correctPos;

        printf("%d digits are correct and in the right place, %d digits are correct but in the wrong place.\n\n",
               correctPos, wrongPos);

        attemptsLeft--;
    }

    printf("Out of tries! The secret code was %d.\n", secretNumber);
    return 0;
}