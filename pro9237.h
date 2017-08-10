//
// Created by JoonYoung Jeon on 07/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9237_H
#define BAEKJOONALGORITHMS_PRO9237_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare (int i, int j) { return (i > j); }

int pro9237(){
    int days = 0;
    int N;      cin>>N;
    vector<int> trees(N);
    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &trees[i]);
    }

    sort(trees.begin(), trees.end(), Compare);

    int max = 0;
    for( int& tree : trees ){
        if(tree + ++days > max){
            max = tree + days;
        }
    }
    cout<<max + 1;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO9237_H
