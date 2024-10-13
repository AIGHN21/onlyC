#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, P, M;
    cin >> N >> P >> M;
    vector<int> x(P), y(P), direction(P);
    for (int i = 0; i < P; ++i) {
        cin >> x[i] >> y[i] >> direction[i];
        --direction[i];
    }
    for (int i = 0; i < M; ++i) {
        char cmd;
        int K;
        cin >> cmd >> K;
        if (cmd == 'A') {
            for (int j = 0; j < P; ++j) {
                int dir = direction[j];
                x[j] = (x[j] + dx[dir] * K % N + N) % N;
                y[j] = (y[j] + dy[dir] * K % N + N) % N;
            }
        } else if (cmd == 'R') {
            for (int j = 0; j < P; ++j) {
                direction[j] = (direction[j] + K) % 4;
            }
        } else if (cmd == 'Z') {

            int new_x = K / N;
            int new_y = K % N;
            for (int j = 0; j < P; ++j) {
                x[j] = new_x;
                y[j] = new_y;
            }
        }
    }

    for (int i = 0; i < P; ++i) {
        cout << x[i] << " " << y[i] << "\n";
    }

    return 0;
}
