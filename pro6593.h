//
// Created by JoonYoung Jeon on 28/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO6593_H
#define BAEKJOONALGORITHMS_PRO6593_H

#define MAX 27001

#include <iostream>
#include <array>
#include <tuple>
#include <queue>
#include <cstdio>

using namespace std;
const int MAX = 30;
typedef tuple<int, int, int> iPair;

int L, R, C;
int dL[] = {0, 0, 0, 0, 1, -1};
int dR[] = {0, 0, 1, -1, 0, 0};
int dC[] = {1, -1, 0, 0, 0, 0};

bool InRange(int l, int r, int c){
    return (0 <= l) && (l < L) && (0 <= r) && (r < R) && (0 <= c) && (c < C);
}

int pro6593(){
    while(true){
        cin>>L>>R>>C;

        if(L == 0 && R == 0 && C == 0) break;
        iPair start, escaping;

        array<array<array<char, MAX>, MAX>, MAX> building = {1};
        array<array<array<bool, MAX>, MAX>, MAX> visited = {false};
        bool sFound = false, eFound = false;
        for( int l = 0 ; l < L ; ++l )
            for( int r = 0 ; r < R ; ++r ){
                scanf("%s", &building[l][r]);
                if(!sFound){
                    for( int c = 0 ; c < C ; ++c ){
                        if(building[l][r][c] == 'S'){
                            start = make_tuple(l, r, c);
                            sFound = true;
                            break;
                        }
                    }
                }

                if(!eFound){
                    for( int c = 0 ; c < C ; ++c ){
                        if(building[l][r][c] == 'E'){
                            escaping = make_tuple(l, r, c);
                            eFound = true;
                            break;
                        }
                    }
                }
            }

        queue<iPair> Queue;
        Queue.push(start);

        int minute = 0;
        bool found = false;
        while( !Queue.empty() ){
            if (found) break;
            minute++;
            int qSize = (int)Queue.size();
            for( int i = 0 ; i < qSize ; ++i ){
                if (found) break;
                iPair current = Queue.front();
                Queue.pop();

                for( int n = 0 ; n < 6 ; ++n ){
                    int newL = get<0>(current) + dL[n];
                    int newR = get<1>(current) + dR[n];
                    int newC = get<2>(current) + dC[n];

                    if( !InRange(newL, newR, newC) ) continue;
                    if( visited[newL][newR][newC]  ) continue;
                    if( building[newL][newR][newC] == '#' ){
                        visited[newL][newR][newC] = true;
                        continue;
                    }
                    if( building[newL][newR][newC] == 'E' ){
                        cout<<"Escaped in "<<minute<<" minute(s)."<<endl;
                        found = true;
                        break;
                    }
                    visited[newL][newR][newC] = true;
                    Queue.emplace(newL, newR, newC);
                }
            }
        }
        if (!found){
            cout<<"Trapped!"<<endl;
        }
    }
    return 0;
}


#endif //BAEKJOONALGORITHMS_PRO6593_H
