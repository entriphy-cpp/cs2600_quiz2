// Tic Tac Toe game between 2 players or player vs. computer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum GameType { pvp, computer };
enum Mark { empty = ' ', p1 = 'X', p2 = 'O'};

enum Mark board[3][3] = {
    empty, empty, empty,
    empty, empty, empty,
    empty, empty, empty
};
int totalMoves = 0;

void printBoard();
void playerMove(int player);
void computerMove();
char getPlayerMark(int player);
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
    if (gameType == computer) {
        srand((unsigned int)time(NULL)); // Set seed for random number generator
    }

    /*
     * Game loop
     */
    int winner = 0; // 0 if no winner yet, -1 if tie, player won if otherwise

    // Display board
    printBoard();

    while (winner == 0) {
        // Let player 1 move
        printf("=======\n");
        playerMove(1);
        totalMoves++;

        // Display board
        printBoard();

        // Check if there's a winner
        winner = checkWinner(1);
        if (winner != 0) break;

        // Let player 2 or computer move
        printf("=======\n");
        if (gameType == pvp) {
            playerMove(2);
        } else {
            computerMove();
        }
        totalMoves++;

        // Display board
        printBoard();

        // Check if there's a winner
        winner = checkWinner(2);
    }

    // Print winner of game
    printf("=======\n");
    if (winner == -1) {
        printf("TIE GAME\n");
    } else {
        printf("WINNER: PLAYER %d\n", winner);
    }

    // Exit
    return 0;
}

// Prints the board
void printBoard() {
    printf("-------\n");
    for (int i = 0; i < 3; i++) {
        printf("|%c|%c|%c|\n", board[i][0], board[i][1], board[i][2]);
        printf("-------\n");
    }
}

// Prompts the specified player for a row and column to place their mark
void playerMove(int player) {
    printf("PLAYER %d MOVE (%c)\n", player, getPlayerMark(player));

    int row = 0;
    while (row < 1 || row > 3) {
        printf("Enter row: ");
        scanf("%d", &row);
        if (row < 1 || row > 3) {
            printf("Invalid row (must be 1-3)\n");
        }
    }

    int column = 0;
    while (column < 1 || column > 3) {
        printf("Enter column: ");
        scanf("%d", &column);
        if (column < 1 || column > 3) {
            printf("Invalid column (must be 1-3)\n");
        }
    }

    // Decrement values to make it a valid index
    row--;
    column--;

    if (board[row][column] == empty) {
        board[row][column] = getPlayerMark(player);
    } else {
        printf("There is already a mark at this position.\n");
        playerMove(player);
    }
}

// Randomly puts a mark at a location
void computerMove() {
    printf("COMPUTER MOVE (%c)\n", getPlayerMark(2));
    int row = rand() % 3;
    int column = rand() % 3;
    while (board[row][column] != empty) {
        row = rand() % 3;
        column = rand() % 3;
    }
    board[row][column] = getPlayerMark(2);
    printf("Row: %d\n", row + 1);
    printf("Column: %d\n", column + 1);
}

// Gets the mark character for the specified player (defined in Mark enum)
char getPlayerMark(int player) {
    return player == 1 ? p1 : p2;
}

// Checks if the specified player has won by having all marks in a specific row
int checkRow(int row, int player) {
    char mark = getPlayerMark(player);
    return board[row][0] == mark && board[row][1] == mark && board[row][2] == mark;
}

// Checks if the specified player has won by having all marks in a specific column
int checkColumn(int column, int player) {
    char mark = getPlayerMark(player);
    return board[0][column] == mark && board[1][column] == mark && board[2][column] == mark;
}

// Checks if the player has won via 
int checkDiagonals(int player) {
    char mark = getPlayerMark(player);
    return (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark);
}

// Returns 1 or 2 if the specified player won (-1 if tie, 0 if no winner)
int checkWinner(int player) {
    if (totalMoves == 9) {
        return -1; // Tie
    }

    int rowWin = checkRow(0, player) || checkRow(1, player) || checkRow(2, player);
    int columnWin = checkColumn(0, player) || checkColumn(1, player) || checkColumn(2, player);
    int diagonalWin = checkDiagonals(player);
    return rowWin || columnWin || diagonalWin ? player : 0;
}