//
// Created by JoonYoung Jeon on 12/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1629_H
#define BAEKJOONALGORITHMS_PRO1629_H

#include <iostream>
using namespace std;

unsigned long a, b, c, n = 1;

unsigned long func(unsigned long low, unsigned long high){
    if( low < b ){
        n = (n * 2);
        func(low * 2, high);
    }
    else if( low > b ){
        func(low, high / 2);
    }
    else if( low == b ){

    }
}

int pro1629(){
    cin>>a>>b>>c;
    n = a;
    for( int i = 0 ; i < b ; ++i ){
        a = (a * a) % c;
        if (a == 0){
            a = n;
        }
    }

    a %= c;
    cout<<a;

//    cout<<result<<endl;
//    result %= c;
//    cout<<result<<endl;

    return 0;
}
//2147483647
#endif //BAEKJOONALGORITHMS_PRO1629_H
