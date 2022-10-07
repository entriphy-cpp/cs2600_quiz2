// Tic Tac Toe game between 2 players or player vs. computer
#include <stdio.h>
#include <stdlib.h>

enum GameType { pvp, computer };

char board[3][3] = {
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '
};
void printBoard();
void playerMove(int player);
void computerMove();
int checkWinner(int player);
int checkRow(int row, int player);
int checkColumn(int column, int player);
int checkDiagonals(int player);

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
    int winner = 0;

    while (winner == 0) {
        // Display board
        printBoard();

        // Let player 1 move

        // Display board
        printBoard();

        // Check if there's a winner
        checkWinner(1);

        // Let player 2 or computer move
        if (gameType == pvp) {
            playerMove(2);
        } else {
            computerMove();
        }

        // Display board
        printBoard();

        // Check if there's a winner
        checkWinner(2);
    }

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

int checkRow(int row, int player) {
    char check = player == 1 ? 'X' : 'O';
    return board[row][0] == check && board[row][1] == check && board[row][2] == check;
}

int checkColumn(int column, int player) {
    char check = player == 1 ? 'X' : 'O';
    return board[0][column] == check && board[1][column] == check && board[2][column] == check;
}

int checkDiagonals(int player) {
    char check = player == 1 ? 'X' : 'O';
    return (board[0][0] == check && board[1][1] == check && board[2][2] == check ||
        (board[0][2] == check && board[1][1] == check && board[2][0] == check);
}

int checkWinner(int player) {
    int rowWin = checkRow(0, player) || checkRow(1, player) || checkRow(2, player);
    int columnWin = checkColumn(0, player) || checkColumn(1, player) || checkColumn(2, player);
    int diagonalWin = checkDiagonals(player);
    return rowWin || columnWin || diagonalWin ? player : 0;
}