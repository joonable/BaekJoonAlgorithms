//
// Created by JoonYoung Jeon on 21/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2931_H
#define BAEKJOONALGORITHMS_PRO2931_H
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <tuple>
//
//using namespace std;
//
//typedef pair<int, int> iPair;
//
//
//int R, C;
//iPair zagreb, moscow;
//
//const iPair left = iPair(-1, 0);
//const iPair down = iPair(0, -1);
//const iPair right = iPair(1, 0);
//const iPair up = iPair(0, 1);
//const char EMPTY = '.';
//iPair lostBlock;
//int cnt = 0;
//
////int shiftI[] = {0, 0, -1, 1};
////int shiftJ[] = {-1, 1, 0, 0};
//const iPair shift[] = {left, down, right, up};
//char pipes[] = {'|', '-', '+', '1', '2', '3', '4'};
//
//bool JRange(int j){
//    return 0 <= j && j < C;
//}
//
//bool IRange(int i){
//    return 0 <= i && i < R;
//}
//
//
//int pro2931(){
//    cin>>R>>C;
//    vector<vector<char>> map(R, vector<char>(C, 0));
//    vector<vector<bool>> visited(R, vector<bool>(C, false));
//    queue<iPair> Queue;
////    queue<tuple> TupleQueue;
//    for( int i = 0 ; i < R ; ++i ){
//        for( int j = 0 ; j < C ; ++j ){
//            scanf("%c", &map[i][j]);
//            if(map[i][j] == 'M'){
//                moscow = make_pair(i, j);
//            }
//            else if(map[i][j] == 'Z'){
//                zagreb = make_pair(i, j);
//            }
//        }
//    }
//    for( int n = 0 ; n < 4 ; ++n ){
//        if( map[moscow.first + shift[n].first][moscow.second + shift[n].second] != EMPTY ){
//            Queue.emplace(moscow.first + shift[n].first, moscow.second + shift[n].second);
////            TupleQueue.emplace(moscow.first + shift[n].first, moscow.second + shift[n].second, cnt++);
//        }
//    }
////    while(!TupleQueue.empty()){
////
////    }
//    while(!Queue.empty()){
//        int i = Queue.front().first;
//        int j = Queue.front().second;
//        int current = map[i][j];
//        Queue.pop();
//
//        if( current == EMPTY ){
//            lostBlock = make_pair(i, j);
//            break;
//        }
//
//        if( current == '-' ){
//            if(JRange(j+1) && JRange(j-1)){
//                Queue.push(make_pair(i, j + 1));
//                Queue.push(make_pair(i, j - 1));
//            }
//        }
//        else if( current == '|' ){
//            if(IRange(i-1) && IRange(i+1)){
//                Queue.push(make_pair(i - 1, j));
//                Queue.push(make_pair(i + 1, j));
//            }
//        }
//        else if( current == '+' ){
//            if(IRange(i-1) && IRange(i+1) && JRange(j+1) && JRange(j-1)){
//                Queue.push(make_pair(i, j + 1));
//                Queue.push(make_pair(i, j - 1));
//                Queue.push(make_pair(i - 1, j));
//                Queue.push(make_pair(i + 1, j));
//            }
//        }
//        else if(current == '1'){
//            if(IRange(i - 1) && JRange(j + 1) ){
//                Queue.push(make_pair(i - 1, j));
//                Queue.push(make_pair(i, j + 1));
//            }
//        }
//        else if(current == '2'){
//            if(IRange(i + 1) && JRange(j + 1) ){
//                Queue.push(make_pair(i + 1, j));
//                Queue.push(make_pair(i, j + 1));
//            }
//        }
//        else if(current == '3'){
//
//            Queue.push(make_pair(i + 1, j));
//            Queue.push(make_pair(i, j - 1));
//        }
//        else if(current == '4'){
//            Queue.push(make_pair(i, j - 1));
//            Queue.push(make_pair(i - 1, j));
//        }
//        for( int n = 0 ; n < 4 ; ++n ){
//            int newI = i + shift[n].first;
//            int newJ = j + shift[n].second;
//            int current = map[newI][newJ];
//
//            if(n == 0){
//                if(current == '-' or '1' or '2' or '+'){
//
//                }
//            }
//            else if(n == 1){
//
//            }
//            else if(n == 2){
//
//            }
//            else if(n == 3){
//
//            }
//        }
//    }
//    return 0;
//}
#include <iostream>

#define MAXR 25
#define MAXC 25
using namespace std;
int R, C;
char map[MAXR][MAXC + 1];


bool GoLeft( int i, int j ){
    return j > 0 && ( map[i][j - 1] == '+' || map[i][j - 1] == '-' || map[i][j - 1] == '1' || map[i][j - 1] == '2' );
}

bool GoRight( int i, int j ){
    return j < C - 1 &&
           ( map[i][j + 1] == '+' || map[i][j + 1] == '-' || map[i][j + 1] == '3' || map[i][j + 1] == '4' );
}

bool GoUp( int i, int j ){
    return i > 0 && ( map[i - 1][j] == '+' || map[i - 1][j] == '|' || map[i - 1][j] == '1' || map[i - 1][j] == '4' );
}

bool GoDown( int i, int j ){
    return i < R - 1 &&
           ( map[i + 1][j] == '+' || map[i + 1][j] == '|' || map[i + 1][j] == '2' || map[i + 1][j] == '3' );
}

int main( void ){
    scanf("%d %d", &R, &C);
    for( int r = 0 ; r < R ; ++r ){
        scanf("%s", map[r]);
    }

    for( int i = 0 ; i < R ; ++i )
        for( int j = 0 ; j < C ; ++j ){
            if( map[i][j] != '.' )
                continue;

            if( GoLeft(i, j) && GoRight(i, j) && GoUp(i, j) && GoDown(i, j) ){
                printf("%d %d +\n", i + 1, j + 1);
            }
            else if( GoLeft(i, j) && GoRight(i, j) ){
                printf("%d %d -\n", i + 1, j + 1);
            }
            else if( GoUp(i, j) && GoDown(i, j) ){
                printf("%d %d |\n", i + 1, j + 1);
            }
            else if( GoRight(i, j) && GoDown(i, j) ){
                printf("%d %d 1\n", i + 1, j + 1);
            }
            else if( GoRight(i, j) && GoUp(i, j) ){
                printf("%d %d 2\n", i + 1, j + 1);
            }
            else if( GoLeft(i, j) && GoUp(i, j) ){
                printf("%d %d 3\n", i + 1, j + 1);
            }
            else if( GoLeft(i, j) && GoDown(i, j) ){
                printf("%d %d 4\n", i + 1, j + 1);
            }
        }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2931_H
