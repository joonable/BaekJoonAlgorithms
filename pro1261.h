//
// Created by JoonYoung Jeon on 14/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1261_H
#define BAEKJOONALGORITHMS_PRO1261_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = numeric_limits<int>::max() - 10;

int xShift[] = {0, 0, 1, -1};
int yShift[] = {1, -1, 0, 0};
int N, M;

bool IsInRange( int x, int y ){
    return (0 <= x && x < N && 0 <= y && y < M);
}
void BFS(const vector<vector<bool>>& Wall, vector<vector<int>>& d, int i, int j){
    d[i][j] = 0;

    queue<pair<int, int>> Queue;
    Queue.push(make_pair(i, j));

    while(!Queue.empty()){
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();

        for( int n = 0 ; n < 4 ; ++n ){
            int newX = x + xShift[n];
            int newY = y + yShift[n];

            if( IsInRange(newX, newY) ){
                if(!Wall[newX][newY] && (d[x][y] < d[newX][newY]) ){
                    d[newX][newY] = d[x][y];
                    Queue.push(make_pair(newX, newY));
                }
                else if(Wall[newX][newY] && (d[x][y] + 1 < d[newX][newY])){
                    d[newX][newY] = d[x][y] + 1;
                    Queue.push(make_pair(newX, newY));
                }
            }
        }
    }
}

int pro1261(){
    cin>>M>>N;
    vector<vector<bool>> Wall(N, (vector<bool>(M, false)));
    vector<vector<int>> d(N, (vector<int>(M, INF)));

    int state;
    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < M ; ++j ){
            scanf("%1d", &state);
            if (state == 1){
                Wall[i][j] = true;
            }
        }
    }

    BFS(Wall, d, 0, 0);
    cout<<d[N-1][M-1];
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1261_H
