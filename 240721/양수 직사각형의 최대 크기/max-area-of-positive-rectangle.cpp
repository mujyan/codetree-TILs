#include<iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int nums[20][20];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> nums[i][j];
        }
    }

    int ans = 0;
    bool chk = false;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (nums[i][j] > 0) {
                for (int k = i; k < N; ++k) {
                    for (int l = j; l < M; ++l) {
                        bool allPositive = true;
                        for (int x = i; x <= k; ++x) {
                            for (int y = j; y <= l; ++y) {
                                if (nums[x][y] <= 0) {
                                    allPositive = false;
                                    break;
                                }
                            }
                            if (!allPositive) {
                                break;
                            }
                        }
                        if (allPositive) {
                            chk = true;
                            int area = (k - i + 1) * (l - j + 1);
                            if (area > ans) {
                                ans = area;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << (chk ? ans : -1) << endl;

    return 0;
}