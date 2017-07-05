//
// Created by JoonYoung Jeon on 03/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2504_H
#define BAEKJOONALGORITHMS_PRO2504_H

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int MAX = 31;
void PrintError(){
    printf("0\n");
    exit(0);
}

void PrintError();

int pro2504(){
    stack<char> Stack;

    char brackets[MAX];      cin>>brackets;
    int len = (int)strlen(brackets);
    int result = 0, temp = 1;

    if (brackets[0] == ')' || brackets[0] == ']'){
        PrintError();
    }

    for ( int i = 0 ; i < len + 1 ; ++i ) {
        if( brackets[i] == '(' ){
            Stack.push( brackets[i] );
            temp *= 2;
        }
        else if( brackets[i] == '[' ){
            Stack.push( brackets[i] );
            temp *= 3;
        }
        else if(brackets[i] == ')' ){
            if(Stack.empty()){
                PrintError();
            }

            if(Stack.top() != '('){
                PrintError();
            }
            else{
                if (brackets[i - 1] == '('){
                    result += temp;
                }
                Stack.pop();
                temp /= 2;
            }
        }
        else if(brackets[i] == ']' ){
            if(Stack.empty()){
                PrintError();
            }

            if(Stack.top() != '['){
                PrintError();
            }
            else{
                if (brackets[i - 1] == '['){
                    result += temp;
                }
                Stack.pop();
                temp /= 3;

            }
        }
        else{
            //do nothing
        }

    }

    if(!Stack.empty()){
        PrintError();
    }
    cout<<result<<endl;

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2504_H
