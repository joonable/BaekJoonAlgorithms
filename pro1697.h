//
// Created by JoonYoung Jeon on 11/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1697_H
#define BAEKJOONALGORITHMS_PRO1697_H

#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;
int N, K;
bool found = false;

vector<bool> visited;
struct nextN{
    int n, seconds, gap;

    nextN( int n, int seconds, int gap )
            : n(n), seconds(seconds), gap(gap){ }
};

class Comparison{
    bool reverse;
public:
    Comparison(const bool& reverse = false)
            : reverse(reverse){ }
    bool operator() (const nextN& ref1, const nextN& ref2) const {
        if (reverse){
            if (ref1.seconds != ref2.seconds){
                return (ref1.seconds > ref2.seconds);
            }
            else{
                return (ref1.gap > ref2.gap);
            }
        }
//        else{
//            return (ref1.gap < ref2.gap);
    }
};

//priority_queue<nextN, vector<nextN>, Comparison > Queue;
queue<nextN> Queue;

void FindK(int n, int seconds){
//    visited[n] = true;
    if( found ){
        return;
    }
    if( n == K || n / 2 == K ){
        found = true;
        cout<<seconds<<" ";
        return;
    }
    if( n + 1 == K ||n - 1 == K){
        found = true;
        cout<<seconds + 1<<" ";
        return;
    }


//    cout<<n<<" ";
    if( n == 0) {
        Queue.push(nextN(n + 1, seconds + 1, 0));
        return;
    }
    int minusGap = abs(K - 2 * (n - 1));
    int plusGap = abs(K - 2 * (n + 1));

//    int gap = abs(K - 2 * (n) );
//    int minGap = min(minusGap, gap);
//    minGap = min(minGap, plusGap);
//
//    if (minGap == gap ){
//        Queue.push( nextN( 2 * n, seconds + 1, abs(K - 2 * (n) )) );
//    }
//    else if(plusGap == minGap && (n > 1)){
//        Queue.push( nextN(n - 1, seconds + 1, minusGap) );
//    }
//    else{
//        Queue.push( nextN(n + 1, seconds + 1, plusGap) );
//    }

    if( (minusGap < plusGap) && (n > 1)){
        Queue.push( nextN(n - 1, seconds + 1, minusGap) );
    }
    else{
        Queue.push( nextN(n + 1, seconds + 1, plusGap) );
    }
    if( abs(K - 2 * (n) ) < abs(K - (n))  ){
        Queue.push( nextN( 2 * n, seconds + 1, abs(K - 2 * (n) )) );
    }


}

int pro1697(){
    cin>>N>>K;
    visited.assign(K + 1, false);

    Queue.push(nextN(N, 0, 0));

    while(!Queue.empty()){
        int n = Queue.front().n;
        int seconds = Queue.front().seconds;
        Queue.pop();

        if(visited[n]){
            continue;
        }
        FindK(n, seconds);
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1697_H
