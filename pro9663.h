//
// Created by JoonYoung Jeon on 22/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9663_H
#define BAEKJOONALGORITHMS_PRO9663_H
//
// Created by JoonYoung Jeon on 14/07/2017.
//

#include <iostream>
using namespace std;
int N;
int col[100000];
int cnt = 0;

bool Promising(int i){
    int k = 0;
    bool promising = true;

    while( k < i && promising){
        if( col[i] == col[k] || abs(col[i] - col[k]) == i - k) {
            promising = false;
        }
        k++;
    }
    return promising;
}

void Queens(int i){
    if(Promising(i)){
        if( i == N - 1  ){
            cnt++;
        }
        else{
            for( int j = 0 ; j < N ; ++j ){
                col[i + 1] = j;
                Queens(i + 1);
            }
        }
    }
}


int pro9663 (){
    cin>>N;
    Queens(-1);
    cout<<cnt;
    return 0;
}


#endif //BAEKJOONALGORITHMS_PRO9663_H
