//
// Created by JoonYoung Jeon on 21/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9370_H
#define BAEKJOONALGORITHMS_PRO9370_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int INF = 1001;
typedef pair<int, int> iPair;
class Graph{
public:
    int V;
    int src;
    list<iPair>* adj;
    vector<int>* shortestPath;

    vector<int> dist;
    vector<int> distance;
    vector<int> touch;

    Graph( int V ) : V(V){
        this->adj = new list<iPair>[V];
        this->shortestPath= new vector<int>[V];
    }

    void AddEdge(int u, int v, int weight){
        adj[u].emplace_back(v, weight);
    }

    void ShortestPath(int src){
        this->src = src;
        this->dist.resize(V, INF);
        this->distance.resize(V);
        this->touch.resize(V, src);

        for( auto& nodeInfo : adj[src] ){
            int v = nodeInfo.first;
            int weight = nodeInfo.second;
            dist[v] = weight;
//            shortestPath[v].push_back(src);
        }
        distance[src] = 0;
        dist[src] = -1;

        for( int n = 0 ; n < V - 1 ; ++n ){
            int minWeight = INF;
            int minIdx = src;

            for( int i = 0 ; i < V ; ++i ){
                if( -1 < dist[i] && dist[i] < minWeight ){
                    minWeight = dist[i];
                    minIdx = i;
                }
            }

            for( int i = 0 ; i < V ; ++i ){
                for (auto& element : adj[minIdx]){
                    if(element.first == i){
                        if( dist[i] > minWeight + element.second){
                            dist[i] = minWeight + element.second;
                            touch[i] = minIdx;
                            break;
                        }
                    }
                }
            }
            distance[minIdx] = dist[minIdx];
            dist[minIdx] = -1;
        }
    }

    bool IsInShortestPath(int candidate, const int& g, const int& h){
        if(candidate != g && candidate != h ){
            int dis = distance[candidate];
            int dis1 = distance[h];
            int dis2 = -1, dis3 = -1;

            for( auto& nodeInfo: adj[h] ){
                if( nodeInfo.first == g ){
                    dis2 = nodeInfo.second;
                }
            }

            for( auto& nodeInfo: adj[g] ){
                if( nodeInfo.first == candidate ){
                    dis3 = nodeInfo.second;
                }
            }

            if( dis1 + dis2 + dis3 == dis && dis2 != -1 && dis3 != -1 ){
                return true;
            }

            dis1 = distance[g];
            dis2 = -1, dis3 = -1;

            for( auto& nodeInfo: adj[g] ){
                if( nodeInfo.first == h ){
                    dis2 = nodeInfo.second;
                }
            }

            for( auto& nodeInfo: adj[h] ){
                if( nodeInfo.first == candidate ){
                    dis3 = nodeInfo.second;
                }
            }

            if( dis1 + dis2 + dis3 == dis && dis2 != -1 && dis3 != -1 ){
                return true;
            }

            return false;
//        int d1 =
//        int prev = candidate, current = touch[candidate];
//
//        while(true){
//            if(prev == h && current == g){
//                return true;
//            }
//            if(prev == g && current == h){
//                return true;
//            }
//            prev = current;
//            current = touch[current];
//            if( prev == current ){
//                break;
//            }
//        }
//        return false;
        }
        else{
            int dis = distance[candidate];
            int dis1 = distance[h];
            int dis2 = -1;

            for( auto& nodeInfo: adj[h] ){
                if( nodeInfo.first == g ){
                    dis2 = nodeInfo.second;
                }
            }

            if( dis1 + dis2 == dis && dis2 != -1){
                return true;
            }

            dis1 = distance[g];
            dis2 = -1;

            for( auto& nodeInfo: adj[g] ){
                if( nodeInfo.first == h ){
                    dis2 = nodeInfo.second;
                }
            }

            if( dis1 + dis2 == dis && dis2 != -1){
                return true;
            }
            return false;
        }
    }
};

int pro9370(){
    int T, V, E, C, src, g, h;
    cin>>T;

    for( int t = 0 ; t < T ; ++t ){
        scanf("%d %d %d", &V, &E, &C);
        scanf("%d %d %d", &src, &g, &h);

        Graph map(V);
        list<int> results;
        int u, v, weight;
        for( int e = 0 ; e < E ; ++e ){
            scanf("%d %d %d", &u, &v, &weight);
            map.AddEdge(u-1, v-1, weight);
            map.AddEdge(v-1, u-1, weight);
        }

        map.ShortestPath(src - 1);

        int candidate;
        for( int c = 0 ; c < C ; ++c ){
            scanf("%d", &candidate);
            if( map.IsInShortestPath(candidate - 1, g - 1, h - 1) ){
                results.push_back(candidate);
                continue;
            }
        }

//        cout<<"shortestPath : "<<endl;
//
//        for( int i = 0 ; i < V ; ++i ){
//            for( auto& element : map.shortestPath[i] ){
//                cout<<element<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl<<endl;

//        cout<<"touch : "<<endl;
//        for( auto& element : map.touch){
//            int len = element + 1;
//            cout<<len<<" ";
//        }
//        cout<<endl<<endl;

        results.sort();
//        cout<<"result : "<<endl;
        for( auto& result : results){
            printf("%d ", result);
        }
        printf("\n");
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO9370_H
