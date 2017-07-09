//
// Created by JoonYoung Jeon on 09/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO5430_H
#define BAEKJOONALGORITHMS_PRO5430_H

#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

bool isError = false;
bool IsNumber( char c ){
    return (('0' <= c) && (c <= '9'));
}

deque<int> RFunc(deque<int> Origin){
    deque<int> Reverse;
    while( !Origin.empty() ){
        int temp = Origin.front();
        Origin.pop_front();
        Reverse.push_front(temp);
    }
    return Reverse;
}


void DFunc(deque<int> &Origin){
    if( Origin.empty() ){
        isError = true;
        return;
    }
    Origin.pop_front();
}

int pro5430(){
    int T;      cin>>T;
    for( int t = 0 ; t < T ; ++t ){
        cin.ignore();       cin.clear();
        isError = false;

        char funcs[100001];     cin>>funcs;
        int n;                  cin>>n;
        char str[300];          cin>>str;

        deque<int> Deque;

        for( int i = 0 ; i < strlen(str) ; ++i ){
            int num = 0;
            if( IsNumber(str[i])) {
                num = str[i++] - '0';
                while( IsNumber(str[i]) ){
                    num = num * 10 + (str[i++] - '0');
                }
                Deque.push_back(num);
            }
        }

        for( int i = 0 ; i < strlen(funcs) ; ++i ){
            if(funcs[i] == 'R'){
                Deque = RFunc(Deque);
            }

            if(funcs[i] == 'D'){
                DFunc(Deque);
                if(isError){
                    printf("error\n");
                    break;
                }
            }
        }

        if(isError){
            continue;
        }

        printf("[%d", Deque.front());
        Deque.pop_front();

        while(!Deque.empty()){
            printf(",%d", Deque.front());
            Deque.pop_front();
        }

        printf("]\n");
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO5430_H
