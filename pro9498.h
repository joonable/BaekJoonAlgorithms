//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9498_H
#define BAEKJOONALGORITHMS_PRO9498_H
#include <iostream>
using namespace std;

int pro9498(){
    int score;      cin>>score;
    if(90 <= score && score <= 100){
        cout<<"A";
    }
    else if(80 <= score && score < 90){
        cout<<"B";
    }
    else if(70 <= score && score < 80){
        cout<<"C";
    }
    else if(60 <= score && score < 70){
        cout<<"D";
    }
    else {
        cout<<"F";
    }

    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO9498_H
