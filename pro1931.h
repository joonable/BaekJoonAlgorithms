//
// Created by JoonYoung Jeon on 22/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1931_H
#define BAEKJOONALGORITHMS_PRO1931_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CompareByFirst( const pair<int, int>& i, const pair<int, int>& j){
    return i.first < j.first;
}


bool CompareBySecond( const pair<int, int>& i, const pair<int, int>& j){
    return i.second < j.second;
}

int pro1931(){
    int N;      cin>>N;

    vector<pair<int, int>> schedule(N);
    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &(schedule[i].first));
        scanf("%d", &(schedule[i].second));
    }
    sort(schedule.begin(), schedule.end(), CompareByFirst);
    sort(schedule.begin(), schedule.end(), CompareBySecond);

//    for( int i = 0 ; i < N ; ++i ){
//        cout<<schedule[i].first<<" "<<schedule[i].second<<endl;
//    }

    int cnt = 0, end = -1;
    for( int i = 0 ; i < N ; ++i ){
        if(schedule[i].first >= end ){
//            cout<<schedule[i].first<<" "<<schedule[i].second<<endl;
            end = schedule[i].second;
            cnt++;

        }
    }
    cout<<cnt;

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1931_H
