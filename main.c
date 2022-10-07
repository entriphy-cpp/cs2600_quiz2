// Tic Tac Toe game between 2 players or player vs. computer
#include <stdio.h>
#include <stdlib.h>

enum GameType { pvp, computer };

char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
void printBoard();

int main() {
    // Prompt user for game they wish to play
    printf("Welcome to Tic Tac Toe!\n");
    printf("- 1: Player vs. Player\n");
    printf("- 2: Player vs. Computer\n");
    printf("Make a selection (1 or 2): ");

    // Read information from console
    enum GameType gameType;
    scanf("%d", &gameType);
    gameType--; // Converts gameType to 0/1 for enum
    
    // Process input
    if (gameType != pvp && gameType != computer) {
        printf("Invalid input; exiting...");
        return 1;
    }
    printf("You have entered %s\n", gameType == pvp ? "1: Player vs. Player" : "2: Player vs. Computer");

    /*
     * Game loop
     */
    // Display board
    printBoard();

    // Let player 1 move

    // Check if there's a winner

    // Display board

    // Let player 2 or computer move

    // Check if there's a winner

    // Exit
    return 0;
}

void printBoard() {
    printf("-------\n");
    for (int i = 0; i < 3; i++) {
        printf("|%c|%c|%c|\n", board[i][0], board[i][1], board[i][2]);
        printf("-------\n");
    }
}