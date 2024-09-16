#include <iostream>
using namespace std;

int fatorial (int n){
	int fat = 1;
	while (n > 0){
		fat *= n;
		n--;
	}
	return fat;
}

int main() {
	int n;
	cin >> n;
	cout << fatorial(n);
	return 0;
}
