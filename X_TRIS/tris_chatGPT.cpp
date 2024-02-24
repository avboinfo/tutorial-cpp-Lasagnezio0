#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    bool isGameOver;
    int moves;

public:
    TicTacToe() {
        // Initialize the board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '1' + (i * 3 + j);
            }
        }
        currentPlayer = 'X';
        isGameOver = false;
        moves = 0;
    }

    // Function to display the Tic-Tac-Toe board
    void displayBoard() {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }

    // Function to check if the move is valid
    bool isValidMove(int move) {
        if (move < 1 || move > 9) {
            return false;
        }
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            return false;
        }
        return true;
    }

    // Function to make a move
    void makeMove(int move) {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        board[row][col] = currentPlayer;
        moves++;
    }

    // Function to check if the game is over
    bool checkGameOver() {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                isGameOver = true;
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                isGameOver = true;
                return true;
            }
        }
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            isGameOver = true;
            return true;
        }
        if (moves >= 9) {
            isGameOver = true;
            return true;
        }
        return false;
    }

    // Function to switch players
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Function to start the game
    void startGame() {
        cout << "Welcome to Tic-Tac-Toe!" << endl;

        while (!isGameOver) {
            displayBoard();

            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (isValidMove(move)) {
                makeMove(move);
                if (checkGameOver()) {
                    displayBoard();
                    if (moves < 9) {
                        cout << "Player " << currentPlayer << " wins!" << endl;
                    } else {
                        cout << "It's a draw!" << endl;
                    }
                }
                switchPlayer();
            } else {
                cout << "Invalid move. Please try again." << endl;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.startGame();
    return 0;
}
