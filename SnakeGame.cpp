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

void gameDraw(){
    system("cls");
    for (int i = 0; i < width + 2; i++){
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (j == 0){
                cout << "#";
            }
            if (i == snakeY && j == snakeX){
                cout << "O";
            }
            else if (i == orb_x && j == orb_y){
                cout << "@";
            }
            else{
                bool print = false;
                for (int k = 0; k < tailNum; k++){
                    if(tailX[k] == j && tailY[k] == i){
                        cout << "o";
                        print = true;
                    }
                }
                if(!print){
                    cout << " ";
                }
            }
            if (j == width - 1){
                cout << "#";
            }   
		}
		cout << endl;
	}

    for (int i = 0; i < width + 2; i++){
        cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void userInput(){
    if (_kbhit()){
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void gameMechanics() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snakeX;
    tailY[0] = snakeY;
    for (int i = 1; i < tailNum; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
        case LEFT:
            snakeX--;
            break;
        case RIGHT:
            snakeX++;
            break;
        case UP:
            snakeY--;
            break;
        case DOWN:
            snakeY++;
            break;
        default:
            break;
    }

    if (snakeX >= width || snakeX < 0 || snakeY >= height || snakeY < 0) {
        gameOver = true;
    }
    for(int i = 0; i < tailNum; i++){
        if(tailX[i] == snakeX && tailY[i] == snakeY){
            gameOver = true;
        }
    }
    if (snakeX == orb_y && snakeY == orb_x) {
        score += 10;
        orb_x = rand() % width;
        orb_y = rand() % height;
        tailNum++;
    }
}


int main()
{
    srand(time(0));
    setUP();
    while(!gameOver){
        gameDraw();
        userInput();
        gameMechanics();

    }
    
    return 0;
}
