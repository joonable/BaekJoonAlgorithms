//
// Created by JoonYoung Jeon on 19/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2098_H
#define BAEKJOONALGORITHMS_PRO2098_H

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <string>
#include <cmath>

#define NOT_ADJACENT 0
using namespace std;



const int MAX = 16;
int W[MAX][MAX];
int N;
bitset<MAX> mask;
int keys[32768];
int nCm[MAX][MAX];

int pro2098(){
    mask.set();
    cin>>N;

    array< array<int, MAX>, MAX> W = {0};
    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < N ; ++j ){
            scanf("%d", &W[i][j]);
        }
    }

    nCm[0][0] = 1;
    nCm[0][1] = 1;

    for( int n = 1 ; n < N ; ++n ){
        nCm[n][0] = 1;
        for( int m = 1 ; m <= n ; ++m ){
            nCm[n][m] = (nCm[n - 1][m - 1] + nCm[n - 1][m]);
        }
        nCm[n][n + 1] = 1;
    }

    int idx = 0;
    for( int i = 0 ; i < N ; ++i ){
        keys[idx++] = (int)pow(2, i);
    }
    for( int i = 2 ; i < N ; ++i ){
        for( int j = 0 ; j < nCm[N - 2][i + 1] ; ++j ){
            keys[4] = keys[1] + keys[0];
            keys[5] = keys[2] + keys[0];
            keys[6] = keys[2] + keys[1];
            keys[7] = keys[3] + keys[0];
            keys[8] = keys[3] + keys[1];
            keys[9] = keys[3] + keys[2];
            keys[idx++] = keys[N-4] + keys[N-5];
            keys[idx++] = keys[N-3] + keys[N-5];
            keys[idx++] = keys[N-3] + keys[N-5];
            keys[idx++] = keys[N-4] + keys[N-5];

        }
    }


    map< int, vector<int>> D;

    D[0];
    for( int i = 1 ; i < N ; ++i ){
        D[0].push_back(W[i][0]);
    }

    for( int k = 0 ; k < nCm[N-2][1] ; ++k ){
        int key = (int)pow(2, k);

        D[key];
        D[key].assign(3, NOT_ADJACENT);

        for( int n = 0 ; n < N-1 ; ++n ){
            if (k == n ){
                continue;
            }
            if(W[n+1][k+1] != NOT_ADJACENT && D[0].at(n) != NOT_ADJACENT){
                D[key].at(n) = W[n+1][k+1] + D[0].at(k);
                cout<<W[n+1][k+1]<<" + "<<D[0].at(k)<<endl;
            }
        }
    }

    for( int k = 0 ; k < 3 ; ++k ){
        for( int l = 0 ; l < N-1 ; ++l ){
            cout<<D[(int)pow(2,k)].at(l)<<" ";
        }
        cout<<endl;
    }



    for( int i = 1 ; i < N - 1 ; ++i ){     //부분집합의 원소의 갯수 반큼 반복(0개, 1개, N개는 제외)

        for( int k = 0 ; k < nCm[N - 2][i + 1] ; ++k ){     // nCm[N - 2][i + 1] = 원소가 같은 부분집합의 갯수
            for( int j = 0 ; j < N - 2 ; ++j ){
                for( int l = j + 1 ; l < N - 1 ; ++l ){
                    int key = (int)pow(2, j) + (int)pow(2, l);
                    D[key];
                    D[key].assign(3, NOT_ADJACENT);

                    for( int n = 0 ; n < N-1 ; ++n ){

                        if(W[n+1][k+1] != NOT_ADJACENT && D[0].at(n) != NOT_ADJACENT){
                            D[key].at(n) = W[n+1][k+1] + D[0].at(k);
                            cout<<W[n+1][k+1]<<" + "<<D[0].at(k)<<endl;
                        }
                    }
                }
            }
        }

    }

    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO2098_H
