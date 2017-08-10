//
// Created by JoonYoung Jeon on 08/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1058_H
#define BAEKJOONALGORITHMS_PRO1058_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxNumOfFrd = -1;
int N;
int cnt = 0;

void DFS( vector<vector<bool>>& fm, vector<bool>& visited, int i ){
    visited[i] = true;
    cnt++;

    queue<int> Queue;

    for( int j = 0 ; j < N ; ++j ){
        if(fm[i][j]){
            Queue.push(j);
        }
    }

    while(!Queue.empty()){
        int nextFrd = Queue.front();
        Queue.pop();

        if( !visited[nextFrd] ){
            DFS(fm, visited, nextFrd);
        }
    }
}

int pro1058(){
    cin>>N;
    vector<vector<bool>> friendMatrix(N, vector<bool>(N, false));
    vector<vector<bool>>& fm = friendMatrix;

    for( auto& row : fm ){
        for( auto&& col : row ){
            int ch = getchar();
            if(ch == 'Y'){
                col = true;
                continue;
            }
            if(ch == 'N'){
                col = false;
                continue;
            }
        }
        cin.ignore();
    }

    vector<bool> visited(N, false);

    for( int i = 0 ; i < N ; ++i ){
        if( !visited[i] ){
            cnt = -1;
            DFS(fm, visited, i);
            if( cnt > maxNumOfFrd){
                maxNumOfFrd = cnt;
            }
        }
    }
    cout<<maxNumOfFrd;
    return 0;
}


#endif //BAEKJOONALGORITHMS_PRO1058_H
