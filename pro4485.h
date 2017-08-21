//
// Created by JoonYoung Jeon on 19/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO4485_H
#define BAEKJOONALGORITHMS_PRO4485_H

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <tuple>

using namespace std;
int N;

typedef pair<int, int> iPair;
/*struct Graph{
public:
    int V;
    list<iPair>* adj;

    Graph( int V ) : V(V){
        this->adj = new list<iPair>[V];
    }
    void AddEdge(int u, int v, int w){
        this->adj[u].emplace_back(iPair(v, w));
    }
};
*/
int iShift[] = {0, 0, -1, 1};
int jShift[] = {-1, 1, 0, 0};

bool InRange(int i, int j){
    return ( 0 <= i && i < N && 0 <= j && j < N);
}

const int INF = 987654321;

void BFS(const vector<vector<int>>& map, vector<vector<int>>& d){
    queue<iPair> Queue;
    Queue.push( make_pair(0, 0) );
    d[0][0] = map[0][0];

    while( !Queue.empty()) {
        int i = Queue.front().first;
        int j = Queue.front().second;
        Queue.pop();

        for( int n = 0 ; n < 4 ; ++n ){
            int newI = i + iShift[n];
            int newJ = j + jShift[n];

            if( !InRange(newI, newJ)) {
                continue;
            }

            if(d[newI][newJ] == INF){
                d[newI][newJ] = d[i][j] + map[newI][newJ];
                Queue.push( make_pair(newI, newJ) );
            }
            else if(d[newI][newJ] > d[i][j] + map[newI][newJ]){
                d[newI][newJ] = d[i][j] + map[newI][newJ];
//            d[newI][newJ] = min(d[newI][newJ], d[i][j] + map[newI][newJ]);
                Queue.push( make_pair(newI, newJ) );
            }
        }
    }
}

int pro4485(){
    int t = 1;
    while( true ){
        cin>>N;
        if( N == 0 ){
            return 0;
        }

        vector<vector<int>> map(N, vector<int>(N, 0));
        vector<vector<int>> d(N, vector<int>(N, INF));

        for( int i = 0 ; i < N ; ++i ){
            for( int j = 0 ; j < N ; ++j ){
                scanf("%d", &map[i][j]);
            }
        }
        d[0][0] = map[0][0];
        BFS(map, d);

        printf("Problem %d: %d\n", t++, d[N - 1][N - 1]);
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO4485_H
