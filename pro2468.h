//
// Created by JoonYoung Jeon on 11/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2468_H
#define BAEKJOONALGORITHMS_PRO2468_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int ShiftX[] = {0, 0, 1, -1};
int ShiftY[] = {1, -1, 0, 0};

void Dfs(const vector< vector<int> >& map, vector< vector<bool> >& sunk,
         vector< vector<bool> >& visited, int i, int j, const int threshold){
    visited[i][j] = true;
    int x;  int y;
    for( int n = 0 ; n < 4 ; ++n ){

        x = i + ShiftX[n];
        y = j + ShiftY[n];

        if( x < 0 || y < 0 || x >= N || y >= N){
            continue;
        }

        if( sunk[x][y] || visited[x][y]){
            continue;
        }

        if( map[x][y] > threshold ){
            Dfs(map, sunk, visited, x, y, threshold);
        }
        else{
            sunk[x][y] = true;
        }
    }
}

int pro2468(){
    cin>>N;
    int maxSafeAreas = -1;
    vector< vector<int> > map(N,(vector<int>(N, 0)));
    vector< vector<bool> > sunk(N,(vector<bool>(N, false)));

    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < N ; ++j ){
            scanf("%d", &map[i][j]);
        }
    }

    for( int threshold = 0 ; threshold < 101 ; ++threshold ){
        vector< vector<bool> > visited(N,(vector<bool>(N, false)));

        int numOfSafeArea = 0;

        for( int i = 0 ; i < N ; ++i ){
            for( int j = 0 ; j < N ; ++j ){
                if( sunk[i][j] || visited[i][j]){
                    continue;
                }

                if( map[i][j] > threshold ){
                    numOfSafeArea++;
                    Dfs(map, sunk, visited, i, j, threshold);
                }
                else{
                    sunk[i][j] = true;
                }
            }
        }
        maxSafeAreas = max(maxSafeAreas, numOfSafeArea);
    }
    cout<<maxSafeAreas;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2468_H
