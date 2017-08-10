//
// Created by JoonYoung Jeon on 10/08/2017.
//

#ifndef BOOSTTEST_PRO1922_H
#define BOOSTTEST_PRO1922_H

#include <iostream>
#include <limits>
#include <vector>
//#include <numeric_limits>
const int INF = numeric_limits<int>::max();

using namespace std;

int N;

int minKey(vector<int>& key, vector<bool>& mstSet){
    // Initialize min value
    int min = INF, min_index;

    for (int v = 0; v < N; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(vector<int>& parent, int n, vector<vector<int>>& W){
    for (int i = 1; i < N; i++){
        n += W[i][parent[i]];
    }
    cout<<n;
}

void primMST(vector<vector<int>>& W){
    vector<int> parent(N);
    vector<int> key(N);
    vector<bool> mstSet(N);

    // Initialize all keys as INFINITE
    for (int i = 0; i < N; i++)
        key[i] = INF, mstSet[i] = false;


    key[0] = 0;
    parent[0] = -1;

    // The MST will have N vertices
    for (int count = 0; count < N-1; count++){
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < N; v++)
            if (W[u][v] && mstSet[v] == false && W[u][v] <  key[v])
                parent[v]  = u, key[v] = W[u][v];
    }

    printMST(parent, 0, W);
}

int pro1922() {
    int M;
    cin>>N>>M;
    vector<vector<int>> W(N ,vector<int>(N, 0));

    for( int m = 0 ; m < M ; ++m ){
        int i, j, weight;
        scanf("%d %d %d", &i, &j, &weight);
        W[i-1][j-1] = weight;
        W[j-1][i-1] = weight;
    }

    primMST(W);
    return 0;
}

#endif //BOOSTTEST_PRO1922_H
