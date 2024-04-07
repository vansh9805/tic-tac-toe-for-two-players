#include <stdio.h>

char BOARD[3][3];
const char PLAYER_1 = 'X';
const char PLAYER_2 = 'O';

void print_board(){
     printf(" %c | %c | %c  ",BOARD[0][0],BOARD[0][1],BOARD[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c  ",BOARD[1][0],BOARD[1][1],BOARD[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c  ",BOARD[2][0],BOARD[2][1],BOARD[2][2]);
    printf("\n");
}
int check_freeSpaces() {
    int freeSpaces = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (BOARD[i][j] == ' ')
                freeSpaces++;
        }
    }
    return freeSpaces;
}
void player1_Move() {
    int x, y;
    do {
         printf("Player's 1 turn\n");
        printf("Enter row (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column (1-3): ");
        scanf("%d", &y);
        y--;

        if (BOARD[x][y] != ' ') {
            printf("Invalid move\n");
        } else {
            BOARD[x][y] = PLAYER_1;
            break;
        }
    } while (1);
}

void player2_Move() {
    int x, y;
    do {
         printf("Player's 2 turn\n");
        printf("Enter row (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column (1-3): ");
        scanf("%d", &y);
        y--;

        if (BOARD[x][y] != ' ') {
            printf("Invalid move\n");
        } else {
            BOARD[x][y] = PLAYER_2;
            break;
        }
    } while (1);
}
char check_winner() {
    for (int i = 0; i < 3; i++) {
        if (BOARD[i][0] == BOARD[i][1] && BOARD[i][0] == BOARD[i][2] && BOARD[i][0] != ' ')
            return BOARD[i][0];

        if (BOARD[0][i] == BOARD[1][i] && BOARD[0][i] == BOARD[2][i] && BOARD[0][i] != ' ')
            return BOARD[0][i];
    }

    if (BOARD[0][0] == BOARD[1][1] && BOARD[0][0] == BOARD[2][2] && BOARD[0][0] != ' ')
        return BOARD[0][0];

    if (BOARD[0][2] == BOARD[1][1] && BOARD[0][2] == BOARD[2][0] && BOARD[0][2] != ' ')
        return BOARD[0][2];

    return ' ';
}

void print_winner(char winner) {
    if (winner == PLAYER_1)
        printf("Player 1 wins\n");
    else if (winner == PLAYER_2)
        printf("Player 2 wins\n");
    else
        printf("It's a tie\n");
}

int main() {
    char winner = ' ';
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            BOARD[i][j] = ' ';
        }
    }

    do {
        print_board();
        player1_Move();
        winner = check_winner();
        if (winner != ' ')
            break;

        freeSpaces--;

        if (freeSpaces == 0)
            break;

        print_board();
        player2_Move();
        winner = check_winner();
        if (winner != ' ')
            break;

        freeSpaces--;
    } while (freeSpaces > 0);

    print_board();
    print_winner(winner);
     printf("Thanks for playing");
    return 0;
}
