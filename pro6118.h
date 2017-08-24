//
// Created by JoonYoung Jeon on 21/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO6118_H
#define BAEKJOONALGORITHMS_PRO6118_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

const int INF = 987654321;

class Graph{
public:
    int V;
    list<int>* adj;

    Graph( int V ) : V(V){
        this->adj = new list<int>[V];
    }

    void AddEdge(int u, int v){
        adj[u].push_back(v);
    }

    void ShortestPath(int src){
        queue<int> Queue;
        vector<int> distance(V, INF);
        Queue.push(src);
        distance[src] = 0;
        int depth = 0;

        while(!Queue.empty()){
            int qSize = (int)Queue.size();
            depth++;

            for( int i = 0 ; i < qSize ; ++i ){
                int u = Queue.front();
                Queue.pop();

                for(auto& v : adj[u]){
                    if( distance[v] > depth ){
                        distance[v] = depth;
                        Queue.push(v);
                    }
                }
            }
        }

        int longestPath = -1;
        int maxIdx = 0;

        for( int i = 0 ; i < V ; ++i ){
            if(distance[i] > longestPath){
                longestPath = distance[i];
                maxIdx = i + 1;
            }
        }

        int cnt = 0;
        for( auto& dist : distance ){
            if( dist == longestPath){
                cnt++;
            }
        }
        cout<<maxIdx<<" "<<longestPath<<" "<<cnt;
    }
};

int pro6118(){
    int N, M;       cin>>N>>M;

    Graph farm = Graph(N);

    int u, v;
    for( int i = 0 ; i < M ; ++i ){
        scanf("%d %d", &u, &v);
        u--;    v--;
        farm.AddEdge(u, v);
        farm.AddEdge(v, u);
    }

    farm.ShortestPath(0);

    return 0;
}


#endif //BAEKJOONALGORITHMS_PRO6118_H
