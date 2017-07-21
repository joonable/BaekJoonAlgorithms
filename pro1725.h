//
// Created by JoonYoung Jeon on 21/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1725_H
#define BAEKJOONALGORITHMS_PRO1725_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare( const pair<int, int>& i, const pair<int, int>& j){
    return i.first > j.first;
}

int pro1725(){
    int N;      cin>>N;

    vector<pair<int, int >> items(N);
    bool checked[100000] = {false};
    int histogram[100000];
    int max;
    int bound;

//    int i = 0;
    for( int j = 0 ; j < N ; ++j ){
        int len;    scanf("%d", &len);
        histogram[j] = len;
        items[j].first = len;
        items[j].second = j;
    }

    sort(items.begin(),items.end(), Compare);
//    max = N;
    max = items.begin()->first ;
    checked[items.begin()->second] = true;

//    i = 0;
    for( auto& item : items ){

        int len = item.first;
        int idx = item.second;
//        cout<<"len :" <<len<<endl;
//        cout<<"idx :" <<idx<<endl;

        bound = len * N;

        if(checked[idx]){
//            cout<<"checked"<<endl<<endl;
            continue;
        }

        checked[idx] = true;

        if(bound < max){
//            cout<<"bound < max"<<endl<<endl;
            break;
        }

        int width = 1;

        bool expandable = true;

        while(expandable){
            if( --idx == -1){
                break;
            }

            if(histogram[idx] == len){
                checked[idx] = true;
                width++;
            }
            else if(histogram[idx] > len){
                width++;
            }
            else{
                expandable = false;
            }
        }

        expandable = true;
        idx = item.second;
        while(expandable){
            if( ++idx == N){
                break;
            }

            if(histogram[idx] == len){
                checked[idx] = true;
                width++;

            }
            else if(histogram[idx] > len){
                width++;
            }
            else{
                expandable = false;
            }
        }


//        cout<<"width : "<<width<<", len : "<<len<<", width*len : "<<width*len<<", max : "<<max<<endl;

        if(width * len > max){
            max = width * len;
        }

    }
    cout<<max;
    return 0;
}


#endif