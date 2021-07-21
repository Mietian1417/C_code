#include"Gobang.h"

void Menu()
{
    printf("############################\n");
    printf("## 0. Exit        1. Play ##\n");
    printf("############################\n");
    printf("Please Select# ");
}


void Game()
{
    int board[ROW][COL];
    memset(board, '\0', sizeof(board));
    int result = NEXT;
    do {
        ShowBoard(board);
        PlayerMove(board, PLAYER1);
        result = IsOver(board);
        if (NEXT != result) {
            break;
        }
        ShowBoard(board);
        PlayerMove(board, PLAYER2);
        result = IsOver(board);
        if (NEXT != result) {
            break;
        }
    } while (1);

    ShowBoard(board);
    switch (result) {
    case PLAYER1_WIN:
        printf("Player1 win!\n");
        break;
    case PLAYER2_WIN:
        printf("Player2 win!\n");
        break;
    case DRAW:
        printf("Player1 darw Player2!\n");
        break;
    }
}
int main()
{
    int quit = 0;
    int select = 0;
    while (!quit) {
        Menu();
        scanf("%d", &select);
        switch (select) {
        case 0:
            quit = 1;
            break;
        case 1:
            Game();
            break;
        defalut:
            printf("Please Select Again!\n");
            break;
        }
    }
}

