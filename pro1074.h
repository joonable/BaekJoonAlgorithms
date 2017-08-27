//
// Created by JoonYoung Jeon on 26/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1074_H
#define BAEKJOONALGORITHMS_PRO1074_H

#include <iostream>
#include <cmath>
#define MAX 15
using namespace std;
unsigned int N, r, c, cnt = 0;
void Divide(const int& rLow, const int& rHigh, const int& cLow, const int& cHigh){
    if(r == rLow && r == rHigh && c == cLow && c == cHigh){
        return;
    }

    int rMid = (rLow + rHigh) / 2;
    int cMid = (cLow + cHigh) / 2;
    auto len = (unsigned int)pow((rHigh - rMid), 2);

    if( (rLow <= r && r <= rMid) && (cLow <= c && c <= cMid)){
        Divide(rLow, rMid, cLow, cMid);
    }
    else if( (rLow <= r && r <= rMid) && (cMid + 1 <= c && c <= cHigh)){
        cnt += len;
        Divide(rLow, rMid, cMid + 1, cHigh);
    }
    else if( (rMid + 1 <= r && r <= rHigh) && (cLow <= c && c <= cMid)){
        cnt += len * 2;
        Divide(rMid + 1, rHigh, cLow, cMid);
    }
    else if( (rMid + 1 <= r && r <= rHigh) && (cMid + 1 <= c && c <= cHigh)){
        cnt += len * 3;
        Divide(rMid + 1, rHigh, cMid + 1, cHigh);
    }
}

int pro1074(){
    cin>>N>>r>>c;
    Divide(0, (int)pow(2, N) - 1, 0, (int)pow(2, N) - 1);
    cout<<cnt;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1074_H
