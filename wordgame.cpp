#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 4  
#define MAX_PLAYERS 100

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordEntry;

void readPlayerWords(int n, char player[][MAX_LENGTH]) {
    for (int i = 0; i < n; i++) {
        scanf("%s", player[i]);
    }
}

void countWordOccurrences(int n, char player[][MAX_LENGTH], WordEntry words[], int wordCount) {
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < wordCount; j++) {
            if (strcmp(words[j].word, player[i]) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[wordCount].word, player[i]);
            words[wordCount].count = 1;
            (wordCount)++;
        }
    }
}

int calculatePlayerPoints(int n, char player[][MAX_LENGTH], WordEntry words[], int wordCount) {
    int points = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < wordCount; j++) {
            if (strcmp(words[j].word, player[i]) == 0) {
                if (words[j].count == 1) {
                    points += 3;
                } else if (words[j].count == 2) {
                    points += 1;
                }
                break;
            }
        }
    }
    return points;
}

void printResults(int points[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("%d ", points[i]);
    }
    printf("\n");
}

int main() {
    int t;
    printf("Enter the number of testcases:");
    scanf("%d", &t);  
    while (t--) {
        int n;
        scanf("%d", &n);
        int numPlayers = 3;  

        char players[MAX_PLAYERS][MAX_WORDS][MAX_LENGTH];
        for (int p = 0; p < numPlayers; p++) {
            readPlayerWords(n, players[p]);
        }

        WordEntry words[MAX_WORDS * MAX_PLAYERS];
        int wordCount = 0;

        for (int p = 0; p < numPlayers; p++) {
            countWordOccurrences(n, players[p], words, wordCount);
        }

        int points[MAX_PLAYERS] = {0};
        for (int p = 0; p < numPlayers; p++) {
            points[p] = calculatePlayerPoints(n, players[p], words, wordCount);
        }

        printResults(points, numPlayers);
    }

    return 0;
}

