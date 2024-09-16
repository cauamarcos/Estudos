#include <iostream>
using namespace std;

int fibonacci(int n, int& cont){
    cont++;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n-1, cont) + fibonacci(n-2, cont);
}

int main () {
    int n, x, result;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num_calls = -1;
        cin >> x;
        result = fibonacci(x, num_calls);
        cout << "fib(" << x << ") = " << num_calls << " calls = " << result << endl;
    }
}
