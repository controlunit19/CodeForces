#include <bits/stdc++.h>
using namespace std;

pair<string, long long> solve_test_case(int n, vector<vector<int>>& grid) {
    vector<vector<char>> smallest(2, vector<char>(n+1, 0));
    vector<vector<long long>> count(2, vector<long long>(n+1, 0));

    smallest[0][1] = smallest[1][1] = grid[0][0] + '0';
    count[0][1] = count[1][1] = 1;

    for (int j = 2; j <= n; ++j) {
        if (grid[0][j-1] >= smallest[0][j-1] - '0') {
            smallest[0][j] = smallest[0][j-1];
            count[0][j] = count[0][j-1];
        } else {
            smallest[0][j] = grid[0][j-1] + '0';
            count[0][j] = 1;
        }

        if (grid[1][j-1] >= smallest[1][j-1] - '0') {
            smallest[1][j] = smallest[1][j-1];
            count[1][j] = count[1][j-1];
        } else {
            smallest[1][j] = grid[1][j-1] + '0';
            count[1][j] = 1;
        }

        if (smallest[0][j] > smallest[1][j]) {
            smallest[0][j] = smallest[1][j];
            count[0][j] = count[1][j];
        } else if (smallest[0][j] < smallest[1][j]) {
            smallest[1][j] = smallest[0][j];
            count[1][j] = count[0][j];
        } else {
            count[0][j] += count[1][j];
        }
    }

    return {smallest[1][n], count[1][n]};
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> grid(2, vector<int>(n));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                grid[i][j] = c - '0';
            }
        }
        auto result = solve_test_case(n, grid);
        cout << result.first << endl;
        cout << result.second << endl;
    }

    return 0;
}
