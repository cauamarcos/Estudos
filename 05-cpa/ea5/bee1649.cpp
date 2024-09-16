#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, r, c;

    while(cin >> n >> m >> r >> c) {
        if(n == 0 && m == 0 && r == 0 && c == 0) break;

        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            string line;
            cin >> line;
            for(int j = 0; j < m; j++) {
                grid[i][j] = line[j] - '0';
            }
        }

        int operations = 0;

        for(int i = 0; i <= n - r; i++) {
            for(int j = 0; j <= m - c; j++) {
                if(grid[i][j] == 1) {
                    operations++;
                    for(int x = i; x < i + r; x++) {
                        for(int y = j; y < j + c; y++) {
                            grid[x][y] = 1 - grid[x][y];
                        }
                    }
                }
            }
        }

        bool possible = true;
        for(int i = 0; i < n && possible; i++) {
            for(int j = 0; j < m && possible; j++) {
                if(grid[i][j] == 1) {
                    possible = false;
                }
            }
        }

        if(possible)
            cout << operations << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
