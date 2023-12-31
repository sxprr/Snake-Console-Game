// Snake Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;

const int width = 20;
const int height = 20;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;

    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;

}


// Draw the map.
void Draw()
{
    system("cls"); // clear the screen.
    for (int i = 0; i < width; i++)
        cout << "#";
    cout << endl;

    // drawing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";

            // draw the player
            if (i == y && j == x)
                cout << "O";
            // draw the fruit
            else if (i == fruitY && j == fruitX)
                cout << "f";
            else
            {
                bool print = false;
                // loop through every element of our tail
                for (int k = 0; k < nTail; k++)
                {

                    // if our x and y coordinates match up....
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        //draw the tail from behind
                        cout << "o";
                        print = true;
                    }
                }
                    if(!print)
                        cout << " ";

            }

                cout << " ";
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;

}


// game controls using wasd and arrow keys
void Input()
{



    // check if wasd is being pressed:
    // also check if arrow keys are being pressed:
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT; 
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;

        }
    }

}

// Game logic
void Logic()
{
    // implementing the movement of the snake tail.
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prevX2, prevY2;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        //remember the current position of our tail segments
        prevX2 = tailX[i];
        prevY2 = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prevX2;
        prevY = prevY2;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case UP:
        y--;
        break;

    case DOWN:
        y++;
        break;
        

    default:
        break;
    }
    
    // if we go out of bounds, the game will terminate
    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true;
    
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;   
        nTail++;
    }

}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }

    return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
