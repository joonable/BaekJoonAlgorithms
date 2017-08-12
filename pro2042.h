//
// Created by JoonYoung Jeon on 12/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2042_H
#define BAEKJOONALGORITHMS_PRO2042_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long treeLen;
int arr[1000000] = {0,};

void InitTree( vector<long long>& tree, long long node, int start, int end ){
    if(start > end || node > treeLen){
        return;
    }
    for( int i = start ; i <= end ; ++i ){
        tree[node] += arr[i];
    }
    InitTree(tree, 2 * node, start, ( start + end ) / 2);
    InitTree(tree, 2 * node + 1, ( start + end ) / 2 + 1, end);
}

long long SumSegment(vector<long long>& tree, long long node, int& left, int& right, int start, int end){
    if(start > end || node > treeLen){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    return SumSegment(tree, 2 * node, left, right, start, ( start + end ) / 2) +
            SumSegment(tree, 2 * node + 1, left, right, ( start + end ) / 2 + 1, end);
}

void modifySegment(vector<long long>& tree, int node, int& pos, int& diff, int start, int end){
    if(start > end || node > treeLen){
        return;
    }
    if( start <= pos && pos <= end){
        tree[node] += diff;
    }
    modifySegment(tree, 2 * node, pos, diff, start, ( start + end ) / 2);
    modifySegment(tree, 2 * node + 1, pos, diff, ( start + end ) / 2 + 1, end);
}

int pro2042(){
    int N, M, K;        cin>>N>>M>>K;
    treeLen = (long long)pow(2, ceil(log2(N)) + 1);

    vector<long long> tree(treeLen, 0);

    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &arr[i]);
    }

    InitTree(tree, 1, 0, N - 1);

    for( int i = 0 ; i < M + K ; ++i ){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int& menu = a, &pos = b, &val = c, &left = b, &right = c;
        switch(menu){
            case 1:{
                pos--;
                int diff = - arr[pos] + val;
                modifySegment(tree, 1, pos, diff, 0, N - 1);
                break;
            }
            case 2:{
                left--;     right--;
                long long result = SumSegment(tree, 1, left, right, 0, N - 1);
                printf("%lli", result);
                break;
            }
            default:
                break;
        }
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2042_H
