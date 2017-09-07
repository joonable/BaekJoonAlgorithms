
// Created by JoonYoung Jeon on 21/08/2017.

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int MAP[8][8] = { 0, };

int N, M;
int MAX = 0;

vector<pair<int, int>> zero;
vector<pair<int, int>> virus;

void check_spray(int x, int y) {
    if ((MAP[x + 1][y] == 0) && (x+1 < N )) {
        MAP[x + 1][y] = 4;
        check_spray(x + 1, y);
    }
    if ((MAP[x][y + 1] == 0) && (y+1 < M)) {
        MAP[x][y + 1] = 4;
        check_spray(x, y + 1);
    }
    if ((MAP[x-1][y] == 0) && (x - 1 >= 0)) {
        MAP[x-1][y] = 4;
        check_spray(x-1, y);
    }
    if ((MAP[x][y - 1] == 0) && (y - 1 >= 0)) {
        MAP[x][y - 1] = 4;
        check_spray(x, y - 1);
    }
}

void check_max() {
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 0)
                tmp += 1;
            if ((MAP[i][j] == 3) || (MAP[i][j] == 4))
                MAP[i][j] = 0;
        }
    }
    if (tmp > MAX)
        MAX = tmp;
}

int main(int argc, char **argv) {
    cin >> N >> M;

    for (int i = 0; i < N;i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 0)
                zero.push_back({ i, j });
            if (MAP[i][j] == 2)
                virus.push_back({ i,j });
        }
    }

    for (size_t i = 0; i < zero.size(); i++) {
        for (size_t j = i + 1; j < zero.size(); j++) {
            for (size_t k = j + 1; k < zero.size(); k++) {
                MAP[zero[i].first][zero[i].second] = 3;
                MAP[zero[j].first][zero[j].second] = 3;
                MAP[zero[k].first][zero[k].second] = 3;
                for (auto p : virus) {
                    check_spray(p.first, p.second);
                }
                check_max();
            }
        }
    }
    cout << MAX;
    return 0;
}