#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full (a tie)
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        // Display the current state of the board
        displayBoard(board);

        // Get the player's move
        cout << "Player " << currentPlayer << ", enter row (0, 1, or 2) and column (0, 1, or 2): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win or a tie
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            break;
        } else if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a tie! The game is over." << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
