#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct Customer {
    int process_time;
    int leave_time = 0;
};

int N, M, K, Q;
Customer c[1001];

int main() {
    int i, j, cursor = 1;
    cin >> N >> M >> K >> Q;
    queue<int> q[N];
    for (i = 1; i <= K; i++)
        cin >> c[i].process_time;
    for (int Time = 480; Time < 1020; Time++) {
        // 送客
        for (i = 0; i < N; i++) {
            if (q[i].size()) {
                j = q[i].front();
                if (c[j].leave_time == Time) {
                    q[i].pop();
                }
            }
        }

        // 入队
        for (j = 1; j <= M; j++) {
            for (i = 0; i < N; i++) {
                if (q[i].size() < j) {
                    if (cursor <= K) {
                        q[i].push(cursor);
                        cursor++;
                    }
                }
            }
        }

        // 迎客
        for (i = 0; i < N; i++) {
            if (q[i].size()) {
                j = q[i].front();
                if (c[j].leave_time == 0) {
                    c[j].leave_time = Time + c[j].process_time;
                }
            }
        }
    }
    while (Q--) {
        cin >> i;
        if (c[i].leave_time == 0) {
            cout << "Sorry\n";
        } else {
            printf("%02d:%02d\n", c[i].leave_time / 60, c[i].leave_time % 60);
        }
    }

    return 0;
}