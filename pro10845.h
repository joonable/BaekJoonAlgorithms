//
// Created by JoonYoung Jeon on 04/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10845_H
#define BAEKJOONALGORITHMS_PRO10845_H

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10000;
int queue[MAX];
int head = 0, tail = 0;

void QSize(){
    printf("%d\n", tail - head);
}

bool QEmpty(){
    if( head == tail ){
        printf("1\n");
        return true;
    }
    else{
        printf("0\n");
        return false;
    }
}

void QPush(int x){
    if ( tail == MAX - 1 ){
        printf("-1\n");
    }
    else{
        queue[tail++] = x;
    }
}

void QPop(){
    if ( head == tail ){
        printf("-1\n");
    }
    else{
        printf("%d\n", queue[head++]);
    }
}

void QFront(){
    if( head == tail ){
        printf("-1\n");
    }
    else{
        printf("%d\n", queue[head]);
    }
}

void QBack(){
    if( head == tail ){
        printf("-1\n");
    }
    else{
        printf("%d\n", queue[tail - 1]);
    }
}

int pro10845(){
    int N;      cin>>N;
    for ( int i = 0 ; i < N ; ++i ) {
        char menu[8];     cin>>menu;
        cin.ignore();
        if ( strcmp(menu, "push") == 0){
            int x;      cin>>x;
            QPush(x);
        }
        else if (strcmp(menu, "pop") == 0){
            QPop();
        }
        else if(strcmp(menu, "size") == 0){
            QSize();
        }
        else if(strcmp(menu, "empty") == 0){
            QEmpty();
        }
        else if(strcmp(menu, "front") == 0){
            QFront();
        }
        else if(strcmp(menu, "back") == 0){
            QBack();
        }
        else{
            break;
        }
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO10845_H
