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

int main()
{
    
    
    return 0;
}
