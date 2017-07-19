//
// Created by JoonYoung Jeon on 19/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2580_H
#define BAEKJOONALGORITHMS_PRO2580_H

#include <iostream>
using namespace std;

int sudoku[9][9] = {0};

bool Promising(int i, int j, int n){

    for( int k = 0 ; k < 9 ; ++k ){
        if( sudoku[i][k] == n || sudoku[k][j] == n ){
            return false;

        }
    }

    i = i - i % 3;
    j = j - j % 3;

    int box[9] = {
            sudoku[i][j], sudoku[i][j + 1], sudoku[i][j + 2],
            sudoku[i + 1][j], sudoku[i + 1][j + 1], sudoku[i + 1][j + 2],
            sudoku[i + 2][j], sudoku[i + 2][j + 1], sudoku[i + 2][j + 2],
    };

    for( int k = 0 ; k < 9 ; ++k ){
        if( box[k] == n){
            return false;
        }
    }
    return true;
}

bool FindUnassignedLocation(int& i, int& j){
    for( i = 0 ; i < 9 ; ++i ){
        for( j = 0 ; j < 9 ; ++j ){
            if (sudoku[i][j] == 0){
                return true;
            }
        }
    }
    return false;
}

bool Sudoku(){
    int row, col;

    if(!FindUnassignedLocation(row, col)){
        return true;
    }

    for( int n = 1 ; n <= 9 ; ++n ){
        if( Promising(row, col, n) ){
            sudoku[row][col] = n;
            if( Sudoku() ){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;

}


int pro2580(){
    for( int i = 0 ; i < 9 ; ++i ){
        for( int j = 0 ; j < 9 ; ++j ){
            scanf("%d", &sudoku[i][j]);
        }
    }

    if (Sudoku()){
        for( int i = 0 ; i < 9 ; ++i ){
            for( int j = 0 ; j < 9 ; ++j ){
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("no answer");
    }

    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO2580_H
