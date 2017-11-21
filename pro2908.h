//
// Created by JoonYoung Jeon on 20/11/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2908_H
#define BAEKJOONALGORITHMS_PRO2908_H

#include <iostream>
#include <string>

using namespace std;

int pro2908(){
    string num1, num2;
    cin>>num1>>num2;
    bool flag = false;

    for( int i = 2 ; i > 0 ; --i ){
        if(num1[i] != num2[i]){
            if(num1[i] > num2[i]){
                flag = true;
            }
            break;
        }

    }

    string result;

    if(flag){
        result = num1;
    }
    else{
        result = num2;
    }

    for( int i = 2 ; i >= 0 ; --i ){
        printf("%c", result[i]);
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2908_H
