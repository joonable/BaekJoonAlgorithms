//
// Created by JoonYoung Jeon on 04/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1260_H
#define BAEKJOONALGORITHMS_PRO1260_H

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isEdge[1000][1000] = { false };
bool isNode[1000] = { false };

queue<int> Queue;
stack<int> Stack;

int N, M, V;

void Dfs(int v){
    if( Stack.empty() || !isNode[v - 1] ){
        return;
    }
    isNode[v - 1] = false;
    Stack.pop();
    printf("%d ", v);
    for ( int i = 0 ; i < N ; ++i ) {
        if ( isEdge[v - 1][i] ){
            Stack.push(i + 1);
            Dfs(Stack.top());
        }
    }
}

void Bfs(int v){
    if ( Queue.empty()){
        return;
    }

    isNode[v - 1] = false;
    printf("%d ", v);
    Queue.pop();

    for ( int i = 0 ; i < N ; ++i ) {
        if ( isEdge[v - 1][i] ){
            if (isNode[i]){
                Queue.push(i + 1);
                isNode[i] = false;
            }
        }
    }
    Bfs(Queue.front());
}
int pro1260(){
    cin>>N>>M>>V;
    for ( int i = 0 ; i < N ; ++i ) {
        isNode[i] = true;
    }
    for ( int i = 0 ; i < M ; ++i ) {
        int x, y;   cin>>x>>y;
        isEdge[x - 1][y - 1] = true;
        isEdge[y - 1][x - 1] = true;
    }
    Stack.push(V);
    Dfs(Stack.top());

    printf("\n");

    for ( int i = 0 ; i < N ; ++i ) {
        isNode[i] = true;
    }

    Queue.push(V);
    Bfs( Queue.front() );
    return 0;
}
/*
4 5 4
1 2
1 3
1 4
2 4
3 4
*/

#endif //BAEKJOONALGORITHMS_PRO1260_H
