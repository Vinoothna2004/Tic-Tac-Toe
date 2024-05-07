#include <stdio.h>
#include <stdbool.h>

// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    printf("\n-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// Function to check if the board is full
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function to check if there's a winner
char checkWinner(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    
    return ' ';
}

// Function to play Tic Tac Toe
void playTicTacToe() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;

    while (true) {
        // Print the board
        printBoard(board);
        
        // Get player's move
        printf("Player %c's turn. Enter row and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        // Place the player's move on the board
        board[row][col] = currentPlayer;
        
        // Check for a winner
        char winner = checkWinner(board);
        if (winner != ' ') {
            printBoard(board);
            printf("Player %c wins!\n", winner);
            break;
        }
        
        // Check for a tie
        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a tie!\n");
            break;
        }
        
        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// Main function
int main() {
    printf("Let's play Tic Tac Toe!\n");
    playTicTacToe();
    return 0;
}
 