#include"Gobang.h"

void PlayerMove(int board[ROW][COL], int who) {
    while (1) {
        printf("\nPlayer[ %d ] Please Enter Your Postion# ", who);
        scanf("%d%d", &x, &y);
        if (x<0 || y > COL) {
            printf("Postion Error!\n");
        }
        else if (board[x][y] != 0) {
            printf("Postion Is Occupied!\n");
        }
        else {
            board[x][y] = who;
            break;
        }
    }
}

int ChessCount(int board[ROW][COL], enum Dir d) {
    int _x = x;
    int _y = y;

    int count = 0;
    while (1) {
        switch (d) {
        case LEFT:
            _y--;
            break;
        case RIGHT:
            _y++;
            break;
        case UP:
            _x--;
            break;
        case DOWN:
            _x++;
            break;
        case LEFT_UP:
            _x--, _y--;
            break;
        case RIGHT_DOWN:
            _x++, _y++;
            break;
        case RIGHT_UP:
            _x--, _y++;
            break;
        case LEFT_DOWN:
            _x++, _y--;
            break;
        }
        if (_x < 0 || _x > ROW - 1 || _y < 0 || _y > COL - 1) {
            break;
        }
        if (board[x][y] == board[_x][_y]) {
            count++;
        }
        else {
            break;
        }
    }
    return count;
}


int IsOver(int board[ROW][COL]) {
    int count1 = ChessCount(board, LEFT) + ChessCount(board, RIGHT) + 1;
    int count2 = ChessCount(board, UP) + ChessCount(board, DOWN) + 1;
    int count3 = ChessCount(board, LEFT_UP) + ChessCount(board, RIGHT_DOWN) + 1;
    int count4 = ChessCount(board, LEFT_DOWN) + ChessCount(board, RIGHT_UP) + 1;
    if (count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5) {
        if (board[x][y] == PLAYER1) {
            return PLAYER1_WIN;
        }
        else {
            return PLAYER2_WIN;
        }
    }
    int i = 0;
    for (; i < ROW; i++) {
      int j = 0;
        for (; j < COL; j++) {
            if (board[i][j] == 0) {
                return NEXT;
            }
        }
    }
    return DRAW;
}

void ShowBoard(int board[ROW][COL]) {
    printf("\033c");
    printf("\n\n  ");
    int i = 0;
    for (; i < COL; i++) {
        printf("%3d", i);
    }
    printf("\n");
    for (i = 0; i < ROW; i++) {
        printf("%-3d", i);
        int j = 0;
        for (; j < COL; j++) {
            if (board[i][j] == PLAYER1) {
                //player1
                printf(" ● ");
            }
            else if (board[i][j] == PLAYER2) {
                //player2
                printf(" ○ ");
            }
            else {
                //Space
                printf(" · ");
            }
        }
        printf("\n");
    }
}
