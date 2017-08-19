//
// Created by JoonYoung Jeon on 17/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1012_H
#define BAEKJOONALGORITHMS_PRO1012_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;

int shiftX[] = {0, 0, 1, -1};
int shiftY[] = {1, -1, 0, 0};
bool InRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void Dfs(const vector<vector<bool>>& cabbage, vector<vector<bool>>& visited, int x, int y){
    visited[x][y] = true;

    for( int i = 0 ; i < 4 ; ++i ){
        int newX = x + shiftX[i];
        int newY = y + shiftY[i];

        if( !(InRange(newX, newY)) ){
            continue;
        }

        if( !visited[newX][newY] && cabbage[newX][newY]){
            Dfs(cabbage, visited, newX, newY);
        }
    }
}

int pro1012(){
    int T;      cin>>T;
    for( int t = 0 ; t < T ; ++t ){
        int K, cnt = 0;    scanf("%d %d %d", &M, &N, &K);
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        vector<vector<bool>> cabbage(N, vector<bool>(M, false));
        queue<pair<int, int>> Queue;

        for( int k = 0 ; k < K ; ++k ){
            int i, j;
            scanf("%d %d", &j, &i);
            cabbage[i][j] = true;
            Queue.emplace(make_pair(i, j));
        }

        while( !Queue.empty() ){
            int x = Queue.front().first;
            int y = Queue.front().second;
            Queue.pop();

            if(cabbage[x][y] && !visited[x][y]){
                cnt++;
                Dfs(cabbage, visited, x, y);
            }
        }
        cout<<cnt<<endl;
    }


    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1012_H
