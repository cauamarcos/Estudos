#include <iostream>
using namespace std;

int main() {
	int dinheiro, resto, n;
	cin >> dinheiro;
	n = dinheiro / 100;
	resto = dinheiro % 100;
	cout << n << endl;
	n = resto / 50;
	resto = resto % 50;
	cout << n << endl;
	n = resto / 20;
	resto = resto % 20;
	cout << n << endl;
	n = resto / 10;
	resto = resto % 10;
	cout << n << endl;
	n = resto / 5;
	resto = resto % 5;
	cout << n << endl;
	n = resto / 2;
	resto = resto % 2;
	cout << n << endl;
	cout << resto;
	
	
	return 0;
}
