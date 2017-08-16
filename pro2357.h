//
// Created by JoonYoung Jeon on 16/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2357_H
#define BAEKJOONALGORITHMS_PRO2357_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int N, M;
int treeLen;
int arr[100000] = {0,};
const int INF = 1000000001;

using namespace std;

int InitMinTree( vector<int>& tree, long long node, long long start, long long end ){
    if( start == end ){
        return tree[node] = arr[start];
    }
    return tree[node] = min(InitMinTree(tree, 2 * node, start, ( start + end ) / 2),
                            InitMinTree(tree, 2 * node + 1, ( start + end ) / 2 + 1, end));

}

int InitMaxTree( vector<int>& tree, long long node, long long start, long long end ){
    if( start == end ){
        return tree[node] = arr[start];
    }
    return tree[node] = max(InitMaxTree(tree, 2 * node, start, ( start + end ) / 2),
                            InitMaxTree(tree, 2 * node + 1, ( start + end ) / 2 + 1, end));

}

int GetMin( vector<int>& tree, int node, const int& left, const int& right, int start = 0, int end = N - 1 ){
    if( left > end || right < start ){
        return INF;
    }
    if( left <= start && end <= right ){
        return tree[node];
    }
    int val1 = GetMin(tree, 2 * node, left, right, start, ( start + end ) / 2);
    int val2 = GetMin(tree, 2 * node + 1, left, right, ( start + end ) / 2 + 1, end);
    return ( min(val1, val2) );
}

int GetMax( vector<int>& tree, int node, const int& left, const int& right, int start = 0, int end = N - 1 ){
    if( left > end || right < start ){
        return 0;
    }
    if( left <= start && end <= right ){
        return tree[node];
    }
    int val1 = GetMax(tree, 2 * node, left, right, start, ( start + end ) / 2);
    int val2 = GetMax(tree, 2 * node + 1, left, right, ( start + end ) / 2 + 1, end);
    return ( max(val1, val2) );
}

int pro2357(){

    cin>>N>>M;

    treeLen = (int)pow(2, ceil(log2(N)) + 1);

    vector<int> minTree(treeLen, INF);
    vector<int> maxTree(treeLen, 0);

    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &arr[i]);
    }

    InitMinTree(minTree, 1, 0, N - 1);
    InitMaxTree(maxTree, 1, 0, N - 1);
    for( int i = 0 ; i < M ; ++i ){
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        printf("%d %d\n", GetMin(minTree, 1, a, b), GetMax(maxTree, 1, a, b));
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2357_H
