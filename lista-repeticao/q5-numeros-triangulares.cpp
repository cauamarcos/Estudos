#include <iostream>
using namespace std;

int main() {
	int n, soma = 2, ultimo = 1;
	cin >> n;
	if (n == 1)
		cout << "1";
	else {
		while (soma <= n){
			ultimo += soma;
			soma++;
		}
		cout << ultimo;
	}
	return 0;
}
