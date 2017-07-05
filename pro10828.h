//
// Created by JoonYoung Jeon on 03/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10828_H
#define BAEKJOONALGORITHMS_PRO10828_H

#include <iostream>
#include <cstring>
using namespace std;

int top = -1;
const int MAX = 10000;
int stack[MAX];

void Push(const int& x){
    if(top + 1 == MAX){
        printf("-1\n");
    }
    else{
        stack[++top] = x;
    }
}

void QPop(){
    if(top == -1){
        printf("-1\n");
    }
    else{
        printf("%d\n", stack[top--]);
    }
}

void QSize(){
    printf("%d\n", top + 1);
}

void QEmpty(){
    if (top == -1){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}

void Top(){
    if(top == -1){
        printf("-1\n");
    }
    else{
        printf("%d\n", stack[top]);
    }
}


int pro10828(){

    int N;      cin>>N;
    for ( int i = 0 ; i < N ; ++i ) {
        char menu[8];     cin>>menu;
        cin.ignore();
        if ( strcmp(menu, "push") == 0){
            int x;      cin>>x;
            Push(x);
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
        else if(strcmp(menu, "top") == 0){
            Top();
        }
        else{
            break;
        }
    }

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO10828_H