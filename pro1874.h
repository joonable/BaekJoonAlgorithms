//
// Created by JoonYoung Jeon on 03/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1874_H
#define BAEKJOONALGORITHMS_PRO1874_H

#include <iostream>
#include <stack>

using namespace std;

int pro1874(){
    const int MAX = 100000;
    int N;      cin >> N;

    int series[MAX];
    for (int i = 0; i < N; i++) {  //수열입력
        cin >> series[i];
    }
//    bool popList[MAX] = { false };
    stack<int> Stack;
    int max = 0;
    Stack.push(0);

    for( int i = 0 ; i < N ; ++i ){
        while(true){
//            for( int j = 0 ; j < N ; ++j ){
//                if( popList[ series[i] ]) {
//                    printf("NO\n");
//                    exit(0);
//                }
//            }
            if(Stack.top() == series[i]){
//                if(Stack.top() == 0){
//                    printf("NO\n");
//                    exit(0);
//                }
//                popList[Stack.top()] = { false };
                Stack.pop();
                printf("-\n");
                break;
            }
            else if(Stack.top() > series[i]){
//                if(Stack.top() == 0){
//                    printf("NO\n");
//                    exit(0);
//                }
//                popList[Stack.top()] = { false };
                Stack.pop();
                printf("-\n");
            }
            else if(max < series[i]){
                Stack.push(++max);
                printf("+\n");
            }
            else{
//                do nothing
            }
        }
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1874_H
