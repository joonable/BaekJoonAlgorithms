//
// Created by JoonYoung Jeon on 12/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1629_H
#define BAEKJOONALGORITHMS_PRO1629_H

#include <iostream>
#include <cmath>
using namespace std;

int pro1629(){
    unsigned long long a, b, c;   cin>>a>>b>>c;

    unsigned long long a_ = a % c, b_ = 1, result = 1;

    while(true){
        if(b <= b_ * 2 ){
            b = b - b_;
            b_ = 1;
            result = (result * a_) % c;
            a_ = a % c;
            if(b == 0){
                break;
            }
            else if (b == b_){
                result = (result * a_) % c;
                break;
            }
        }

        a_ = (unsigned long long)pow(a_, 2) % c;
        b_ *= 2;
    }

    cout<<result;

    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO1629_H
