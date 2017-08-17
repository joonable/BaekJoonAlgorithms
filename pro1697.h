//
// Created by JoonYoung Jeon on 11/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1697_H
#define BAEKJOONALGORITHMS_PRO1697_H

#include <iostream>
#include <queue>
#include <vector>

#define MAX 1000001
using namespace std;


int pro1697(){
    int N, K;       cin>>N>>K;

    if (N == K){
        cout<<0;
        return 0;
    }

    vector<bool> visited(MAX, false);
    queue<int> Queue;
    Queue.push(N);      visited[N] = true;

    int value, depth = 0;
    while(!Queue.empty()){
        int qSize = (int)Queue.size();
        depth++;
        for( int i = 0 ; i < qSize ; ++i ){
            value = Queue.front();
            Queue.pop();

            if (value - 1 >= 0 && visited[value - 1] == false){
                Queue.push(value - 1);
                visited[value - 1] = true;
            }

            if (value + 1 < MAX && visited[value + 1] == false){
                Queue.push(value + 1);
                visited[value + 1] = true;
            }

            if (value * 2 < MAX && visited[value * 2] == false){
                Queue.push(value * 2);
                visited[value * 2] = true;
            }

            if (visited[K] == true){
                cout<<depth;
                return 0;
            }
        }
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1697_H
