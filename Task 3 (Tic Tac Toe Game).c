#include <stdio.h>

// CP = Current Player

#define n 3


int check(char Board[n][n]) {
    for (int i = 0; i < n; i++) 
        if ((Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ') || (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[0][i] != ' ')){
             return 1;
        }
            
    return (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0] != ' ') || (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[0][2] != ' ');
           
}
void BoardPrint(char Board[n][n]) {
    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %c ", Board[i][j]);
            if (j < n - 1) {
                printf("|");
            }
        }
        printf("\n");

        if (i < n - 1) {
              printf("---|---|---\n");
        }
    }
    printf("\n");
}

int main() {
    char Board[n][n] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int r, c, moves = 0, CP = 1;

    while (1) {
        BoardPrint(Board);
        printf("Player %d, enter row and column (1-3): ", CP);
        scanf("%d %d", &r, &c);

        if (r < 1 || r > 3 || c < 1 || c > 3 || Board[r-1][c-1] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        Board[r-1][c-1] = (CP == 1) ? 'X' : 'O';
        moves++;

        if (check(Board)) {
            BoardPrint(Board);
            printf("Player %d wins!\n", CP);
            break;
        }

        if (moves == 9) {
            BoardPrint(Board);
            printf("It's a draw!\n");
            break;
        }

        CP = 3 - CP;
    }

    return 0;
}
