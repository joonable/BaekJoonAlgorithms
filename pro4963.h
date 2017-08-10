//
// Created by JoonYoung Jeon on 07/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO4963_H
#define BAEKJOONALGORITHMS_PRO4963_H
// A simple representation of graph using STL,
// for the purpose of competitive programming
//#include<bits/stdc++.h>

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int w, h;

int xShift[8]={-1,-1,-1,0,0,1,1,1};
int yShift[8]={-1,0,1,-1,1,-1,0,1};

void DFS( vector<vector<bool>>& marine, int i, int j ){
    int x, y;
    marine[i][j] = false;
    for( int n = 0 ; n < 8 ; ++n ){
        x = i + xShift[n];
        y = j + yShift[n];
        if(x < 0 || y < 0 || x >= h || y >= w){
            continue;
        }
        if (marine[x][y]){
            DFS(marine, x, y);
        }
    }
}

int pro4963(){
    while(true){
        int cnt = 0;

        cin>>w>>h;
        if(w == 0 && h == 0){
            break;
        }

        queue<pair<int, int>> Queue;
        vector<vector<bool>> marine(h, vector<bool>(w, false));

        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                int num;    scanf("%d", &num);
                if(num == 1){
                    marine[i][j] = true;
                    Queue.push(pair<int, int>(i, j));
                }
            }
        }

        while(!Queue.empty()){
            int i = Queue.front().first;
            int j = Queue.front().second;
            Queue.pop();

            if(marine[i][j]){
                cnt++;
                DFS(marine, i, j);
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO4963_H
