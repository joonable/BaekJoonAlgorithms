//
// Created by JoonYoung Jeon on 03/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10828_H
#define BAEKJOONALGORITHMS_PRO10828_H

#include <iostream>
//#define "push" 1
using namespace std;

int stack[10000];
int top = -1;

void Push(const int& N, const int& x){
    if(top + 1 == N){
        printf("-1\n");
    }
    else{
        stack[++top] = x;
    }
}

void Pop(const int& N){
    if(top == -1){
        printf("-1\n");
    }
    else{
        printf("%d\n", stack[top--]);
    }
}

void Size(){
    printf("%d\n", top + 1);
}

void Empty(){
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
    int N;    cin>>N;

    while(true){
        char menu[8];     cin>>menu;
        cin.ignore();
        if ( strcmp(menu, "push") == 0){
            int x;      cin>>x;
            Push(N, x);
        }
        else if (strcmp(menu, "pop") == 0){
            Pop(N);
        }
        else if(strcmp(menu, "size") == 0){
            Size();
        }
        else if(strcmp(menu, "empty") == 0){
            Empty();
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
