//
// Created by JoonYoung Jeon on 16/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10868_H
#define BAEKJOONALGORITHMS_PRO10868_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int treeLen;
int arr[100000] = {0,};
const int INF = 1000000001;

int InitTree( vector<int>& tree, long long node, long long start, long long end ){
    if(start == end){
        return tree[node] = arr[start];
    }
    return tree[node] = min(InitTree(tree, 2 * node, start, ( start + end ) / 2),
                        InitTree(tree, 2 * node + 1, ( start + end ) / 2 + 1, end));

}

long long SumSegment(vector<long long>& tree, long long node, long long& left, long long& right,
                     long long start, long long end){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    return SumSegment(tree, 2 * node, left, right, start, ( start + end ) / 2) +
           SumSegment(tree, 2 * node + 1, left, right, ( start + end ) / 2 + 1, end);
}

void updateSegment( vector<long long>& tree, int node, long long& pos, long long& diff, int start, int end ){
    if(pos < start || pos > end){
        return;
    }

    tree[node] += diff;

    if(start != end){
        updateSegment(tree, 2 * node, pos, diff, start, ( start + end ) / 2);
        updateSegment(tree, 2 * node + 1, pos, diff, ( start + end ) / 2 + 1, end);
    }
}

int GetMin(vector<int>& tree, int node, const int& left, const int& right, int start = 0, int end = N - 1){
    if(left > end || right < start){
        return INF;
    }
    if( left <= start && end <= right ){
        return tree[node];
    }
    int val1 = GetMin(tree, 2*node, left, right, start, (start+end)/2);
    int val2 = GetMin(tree, 2*node + 1, left, right, (start+end)/2 + 1, end);
    return ( min(val1, val2) );
}

int pro10868(){
    cin>>N>>M;
    treeLen = (int)pow(2, ceil(log2(N)) + 1);

    vector<int> tree(treeLen, INF );

    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &arr[i]);
    }

    InitTree(tree, 1, 0, N - 1);

    for( int i = 0 ; i < M ; ++i ){
        int a, b;
        scanf("%d %d", &a, &b);
        a--;     b--;
        printf("%d\n", GetMin(tree, 1, a, b));
    }
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO10868_H
