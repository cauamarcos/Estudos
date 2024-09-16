#include <iostream>
using namespace std;

int main() {
	int n, a1, a2, a3, a4, a5, a6, resto;
	string cor1, cor2;
	cin >> cor1 >> cor2 >> n;
	a1 = n / 100000;
	resto = n % 100000;
	a2 = resto / 10000;
	resto = resto % 10000;
	a3 = resto / 1000;
	resto = resto % 1000;
	a4 = resto / 100;
	resto = resto % 100;
	a5 = resto / 10;
	resto = resto % 10;
	a6 = resto;
	if (a1 == a6 and a2 == a5 and a3 == a4) {
		cout << cor1;
	}else {
		cout << cor2;
	}
	
	return 0;
}
