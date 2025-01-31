#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TOTAL_WORDS 100
#define MAX_WORD_LENGTH 20
void selectRandomWord(char *selectedWord){
    const char *wordList[TOTAL_WORDS]={
    	"apple", "banana", "cherry", "date", "elderberry","fig", "grape", "honeydew", "kiwi", "lemon","mango", "nectarine", "orange", "papaya", "quince","raspberry", "strawberry", "tangerine", "ugli", "watermelon",
        "ant", "bear", "cat", "dog", "elephant","frog", "giraffe", "hippopotamus", "iguana", "jaguar","kangaroo", "lion", "monkey", "newt", "octopus","penguin", "quail", "rabbit", "snake", "turtle","umbrella", "vulture", "wolf", "xenops", "yak",
   		"zebra", "airplane", "bicycle", "car", "drone","engine", "ferry", "gondola", "helicopter", "igloo","jacket", "kite", "lamp", "mug", "notebook","orange", "piano", "quilt", "ring", "socks",
        "table", "umbrella", "vase", "watch", "xylophone","yarn", "zucchini", "computer", "phone", "television",
        "keyboard", "mouse", "monitor", "printer", "router","camera", "drum", "guitar", "flute", "saxophone","trumpet", "violin", "couch", "bed", "table","chair", "shelf", "cabinet", "mirror", "rug",
        "window", "door", "ceiling", "floor", "wall"
    };
    int randomIndex=rand()%TOTAL_WORDS;
    strcpy(selectedWord,wordList[randomIndex]);
}
void displayCurrentProgress(char *selectedWord, int *correctlyGuessed){
    for (int i=0;i<strlen(selectedWord);i++) {
        if (correctlyGuessed[i]){
            printf("%c ", selectedWord[i]);
        } 
		else{
            printf("_ ");
        }
    }
    printf("\n");
}
int main() {
    char selectedWord[MAX_WORD_LENGTH];
    int correctlyGuessed[MAX_WORD_LENGTH] = {0};
    int remainingAttempts = 10; 
    int totalCorrectGuesses = 0;
    srand(time(NULL)); 
    selectRandomWord(selectedWord);
    printf("Welcome to Guessify!\n");
    printf("You have %d attempts to guess the word.\n", remainingAttempts);
    while (remainingAttempts > 0 && totalCorrectGuesses < strlen(selectedWord)){
        displayCurrentProgress(selectedWord, correctlyGuessed);
        printf("Enter a letter: ");
        char guessedLetter;
        scanf(" %c", &guessedLetter); 
        int found = 0;
        for (int i = 0; i < strlen(selectedWord); i++){
            if (selectedWord[i] == guessedLetter && !correctlyGuessed[i]){
                correctlyGuessed[i] = 1; 
                totalCorrectGuesses++;
                found = 1;
            }
        }
        if (!found){
            remainingAttempts--;
            printf("Wrong guess! You have %d attempts left.\n", remainingAttempts);
        } else{
            printf("Good guess!\n");
        }
    }
    if (totalCorrectGuesses==strlen(selectedWord)){
        printf("Congratulations! You've guessed the word: %s\n", selectedWord);
    } else{
        printf("Sorry, you've run out of attempts. The word was: %s\n", selectedWord);
    }
    return 0;
}
