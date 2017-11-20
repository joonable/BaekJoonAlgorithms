//
// Created by JoonYoung Jeon on 11/09/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO14500_H
#define BAEKJOONALGORITHMS_PRO14500_H

#include <iostream>
#include <array>
using namespace std;

int N, M;
int maxVal;

bool InRagne(int i, int j){
    return (0 <= i && i < N && 0 <= j && j < M);
}

int CaseOne(int i, int j){
    if ( !(1 <= i && i < N - 1 && 1 <= j && j < N - 1) )
        return -1;

    int maxCaseOne;



    return maxCaseOne;
}
void Tetromino( const array<array<int, 500>, 4>& map, const int& i, const int& j){
    int current = map[i][j];

}
int pro14500(){
    cin>>N>>M;
    array<array<int, 500>, 4> map = {0};

    for( int i = 0 ; i < N ; ++i )
        for( int j = 0 ; j < M ; ++j )
            scanf("%d", &map[i][j]);

    for( int i = 0 ; i < N ; ++i )
        for( int j = 0 ; j < M ; ++j )
            Tetromino( map, i, j );



    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO14500_H
