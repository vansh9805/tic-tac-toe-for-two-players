# tic-tac-toe-for-two-players
this is tic tac toe game designed in c language 

My code demonstrates a simple yet engaging implementation of the classic game. Here’s a brief overview of how it works:

The game board is represented as a 3x3 grid, stored in the BOARD array.
Players take turns entering their moves (either ‘X’ or ‘O’) by specifying the row and column.
The game checks for a winner after each move, considering rows, columns, and diagonals.
If no winner is found and there are still empty spaces, the game continues.
Finally, the winner (if any) is announced, or it’s declared a tie.

Let’s break down some key parts:

The print_board() function displays the current state of the Tic Tac Toe board.
The player1_Move() and player2_Move() functions handle player input and validate moves.
The check_winner() function determines if there’s a winner.
The print_winner() function announces the result.
