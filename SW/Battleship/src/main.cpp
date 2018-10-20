/*
 * main.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: chris
 */
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

const int rows = 5 + 1;
const int columns = 5 + 1;
const int maxShips = 5;

char board[rows][columns];

void clear(){
    for (int i=0; i<rows; i++){
        for (int j=0; j<rows; j++){
            board[i][j] = 'O';
        }
    }
}

void showAll(){
    for (int i=1; i<rows; i++){
        for (int j=1; j<rows;j++){
            cout << board[i][j] << "   ";
        }
        cout << endl << endl << endl;
    }
    cout << endl;
}

void showHits(){
    for (int i=1; i<rows; i++){
        for (int j=1; j<rows;j++){
            if(board[i][j] == 'X' || board[i][j] == 'M')
                cout << board[i][j] << "   ";
            else
                cout << 'O' << "   ";
        }
        cout << endl << endl << endl;
    }
    cout << endl;
}

int numberOfShips(){
    int c = 0;

    for (int i=1; i<rows; i++){
        for (int j=1; j<rows; j++){
            if(board[i][j] == 'S')
                c++;
        }
    }
    return c;
}

void setShips(){
    int s = 0;
    while(s < maxShips){
        int x = rand() % rows;
        int y = rand() % columns;

        if(board[x][y] != 'S'){
            s++;
            board[x][y] = 'S';
        }
    }
}

bool attackShip(int x, int y){
    if(board[x][y] == 'S'){
        board[x][y] = 'X';
        return true;
    }
    else{
        board[x][y] = 'M';
        return false;
    }

}

int main(){

    int pos1, pos2, turn = 0;
    char exit = 'n';
    srand(time(NULL));
    clear();
    showAll();
    setShips();

    while(1) {
        if(turn == 0)
            cout <<"Ahoi there captain! The battlefield is " << rows - 1 << "x" << columns - 1 << " miles" << endl
                 <<"My fleet consist out of " << numberOfShips() << " ships. Lets see if you can take me down!!";

        cout <<"Please enter the x and y coordinates of where you want to attack: ";
        cin >> pos1 >> pos2;
        cout << endl << endl;

        if(attackShip(pos1, pos2))
            cout << "Ship is going down!!" << endl;
        else
            cout << "You missed!!" << endl;

        showHits();

        cout << "There are " << numberOfShips() << " ships left in the battle" << endl;

        turn ++;
        cout << "You shot " << turn << " missiles... Do you want to surrender? (y/n)";
        cin >> exit;
        if(exit == 'y'){
            showAll();
            break;
        }
    };

  return 0;
}



