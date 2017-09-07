//
// Created by JoonYoung Jeon on 01/09/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO14501_H
#define BAEKJOONALGORITHMS_PRO14501_H

#include <iostream>
#include <array>
#include <queue>
#include <tuple>

#define MAX 15
using namespace std;

typedef tuple<double, int, int, int> Schedule;

int N;

bool IsFeasible(array<bool, MAX>& allocated, const int& date, const int& days ){
    for( int i = date ; i < date + days ; ++i )
        if( allocated[i] )
            return false;
    return true;
}

int pro14501(){
    cin>>N;
    priority_queue<Schedule> pQueue;
    array<bool, MAX> allocated = {false};

    Schedule schedule;
    double profitPerDay;
    int days, date, profit, totalProfit = 0;

    for( int n = 0 ; n < N ; ++n ){
        scanf("%d", &days);
        scanf("%d", &profit);
        profitPerDay = (double)profit/days;
        if(n + days > N) continue;
        pQueue.emplace(profitPerDay, profit, days, -n);
    }
    while(!pQueue.empty()){
        schedule = pQueue.top();
        profitPerDay = get<0>(schedule);
        profit = get<1>(schedule);
        days = get<2>(schedule);
        date = -get<3>(schedule);
        cout<<"profitPerDay : "<<profitPerDay<<", profit : "<<profit<<", date : "<<date<<", days : "<<days<<endl;
        pQueue.pop();

        if( IsFeasible(allocated, date, days) ){
            for( int i = date; i < date + days ; ++i )
                allocated[i] = true;
            totalProfit += (profit);
        }
    }
    cout<<totalProfit;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO14501_H
