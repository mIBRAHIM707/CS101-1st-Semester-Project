#include <iostream>
#include <conio.h>
#include<ctime>
using namespace std;

bool gameOver;
const int width = 20, height = 20;
int snakeX, snakeY, orb_x, orb_y, score;
int tailX[100], tailY[100];
int tailNum;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void setUP(){
    gameOver = false;
    dir = STOP;
    snakeX = width / 2;
    snakeY = height / 2;
    orb_x = rand() % width;
    orb_y = rand() % height;
    score = 0;
}

int main()
{
    
    
    return 0;
}
