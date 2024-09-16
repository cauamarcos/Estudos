#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> positions(n - 1);
        vector<int> diffs(n - 1);
        
        for (int i = 0; i < n - 1; i++) {
            cin >> positions[i];
        }
        
        for (int i = 1; i < n; i++) {
            diffs[i - 1] = positions[i - 1] - (i == 1 ? 0 : positions[i - 2]);
        }

        sort(diffs.begin(), diffs.end(), greater<int>());
        
        int sum = 0;
        for (int i = k - 1; i < n - 1; i++) {
            sum += diffs[i];
        }
        
        cout << sum << endl;
    }

    return 0;
}
