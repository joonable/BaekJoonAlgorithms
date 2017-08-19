//
// Created by JoonYoung Jeon on 18/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1937_H
#define BAEKJOONALGORITHMS_PRO1937_H

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int N;
int shiftX[] =  {0, 0, -1, 1};
int shiftY[] =  {-1, 1, 0, 0};
int maxAliveDay = 0;

bool InRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

void Bfs( const vector<vector<int>>& bamboos,  vector<vector<int>>& d, int x, int y){
    int maxDay = 0;

    for( int i = 0 ; i < 4 ; ++i ){

        int newX = x + shiftX[i];
        int newY = y + shiftY[i];

        if( !InRange(newX, newY) ){
            continue;
        }

        if( bamboos[x][y] > bamboos[newX][newY] && d[newX][newY] > maxDay ){
            maxDay = max(maxDay, d[newX][newY]);
        }
        d[x][y] = maxDay + 1;
        maxAliveDay = max(d[x][y], maxAliveDay);
    }

}

int pro1937(){
    cin>>N;
    vector<vector<int>> bamboos(N, (vector<int>(N)));
    vector<vector<int>> d(N, (vector<int>(N, 0)));
    priority_queue<tuple<int, int, int>, vector< tuple<int, int, int> >, greater<tuple<int, int, int>>> pQueue;
//    priority_queue<tuple<int, int, int>> pQueue;

    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < N ; ++j ){
            scanf("%d", &bamboos[i][j]);
            pQueue.push( make_tuple(bamboos[i][j], i, j) );
        }
    }

    while(!pQueue.empty()){
        tuple<int, int, int> current = pQueue.top();

        int x = get<1>(current);
        int y = get<2>(current);

        Bfs(bamboos, d, x, y);
        pQueue.pop();
    }
    cout<<maxAliveDay;

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1937_H
