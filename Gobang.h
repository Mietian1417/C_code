#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROW 30
#define COL 30

#define NEXT 0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 3

#define PLAYER1  1
#define PLAYER2  2

enum Dir {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    LEFT_UP,
    RIGHT_DOWN,
    RIGHT_UP,
    LEFT_DOWN
};

int x;
int y;
