// Tic Tac Toe game between 2 players or player vs. computer
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Prompt user for game they wish to play
    printf("Welcome to Tic Tac Toe!\n");
    printf("- 1: Player vs. Player\n");
    printf("- 2: Player vs. Computer\n");
    printf("Make a selection (1 or 2): ");

    // Read information from console
    int gameType;
    scanf("%d", &gameType);
    
    // Process input
    if (gameType != 1 && gameType != 2) {
        printf("Invalid input; exiting...");
        return 1;
    }
    printf("You have entered %s\n", gameType == 1 ? "1: Player vs. Player" : "2: Player vs. Computer");

    // Initialize values (array)

    /*
     * Game loop
     */
    // Display board

    // Let player 1 move

    // Check if there's a winner

    // Display board

    // Let player 2 or computer move

    // Check if there's a winner

    // Exit
    return 0;
}