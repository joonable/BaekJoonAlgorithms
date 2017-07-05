//
// Created by JoonYoung Jeon on 03/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1874_H
#define BAEKJOONALGORITHMS_PRO1874_H

#include <iostream>
using namespace std;

int pro1874(){
    const int MAX = 100000;

    int N;      cin >> N;

    int series[MAX];
    int idx = 0;
    for (int i = 0; i < N; i++) {  //수열입력
        cin >> series[i];
    }

    int stack[MAX];
    int top = -1;
    for ( int i = 0 ; i < N ; ++i ) {
        stack[i] = i + 1;
    }

    int num = 1;


    while ( true ){
        //종료
        if (idx == N ){
            break;
        }

        if(stack[top] < series[idx]){
            stack[++top] = num++;
            printf("+\n");
        }
        else if( stack[top] == series[idx] ){
            top--;
            idx++;
            printf("-\n");
        }
        else{
            printf("NO\n");
            return 0;
        }
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1874_H
