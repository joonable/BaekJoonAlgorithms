//
// Created by JoonYoung Jeon on 12/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1629_H
#define BAEKJOONALGORITHMS_PRO1629_H

#include <iostream>

using namespace std;

long long c;

long long Power( const long long& a, long long b ){
    if( b == 0 ){
        return 1;
    }
    if( b == 1 ){
        return a % c;
    }

    long long x = Power(a, b / 2) % c;
    if( b % 2 == 1 ){
        return (x * x * a) % c;
    }

    if( b % 2 == 0 ){
        return (x * x) % c;
    }
}

int pro1629(){
    long long a, b;

    cin>>a>>b>>c;
    cout<<Power(a % c, b)<<endl;
    return 0;
}
//
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<stdio.h>
//using namespace std;
//long long A, B, C;
//int power( long long a, int b )
//{
//    if (b == 0)return 1;
//    if (b == 1)return a%C;
//    if (b % 2 == 0)return power(( a * a ) % C, b / 2);
//    else return (a* power(( a * a ) % C, ( b - 1 ) / 2)) % C;
//}
//int main() {
//    cin >> A >> B >> C;
//    printf("%d", power(A, B));
//}
#endif //BAEKJOONALGORITHMS_PRO1629_H
