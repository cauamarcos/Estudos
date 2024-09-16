#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long int N;
    while (cin >> N) {
        vector<long long int> cards(N);
        for (long long int i = 0; i < N; i++) {
            cin >> cards[i];
        }

        if (N == 0) break;

        vector<long long int> previous(N, 0);
        vector<long long int> current(N, 0);

        for (long long int i = 0; i < N; i++) {
            previous[i] = cards[i];
        }

        for (long long int len = 2; len <= N; len+=2) {
            for (long long int i = 0; i <= N - len; i++) {
                long long int j = i + len - 1;

                long long int pickLeft = cards[i] + min((i + 2 <= j ? previous[i + 2] : 0), (i + 1 <= j - 1 ? previous[i + 1] : 0));
                long long int pickRight = cards[j] + min((i + 1 <= j - 1 ? previous[i + 1] : 0), (i <= j - 2 ? previous[i] : 0));

                current[i] = max(pickLeft, pickRight);
            }
            swap(previous, current);
        }

        cout << previous[0] << endl;
    }

    return 0;
}
