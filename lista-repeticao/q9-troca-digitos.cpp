#include <iostream>
using namespace std;

int main() {
	long long int n, n_novo, divisor = 1;
	int primeiro, ultimo, meio;
	cin >> n;
	if (n >= 10){
		while(n / divisor >= 10){
			divisor *= 10;
		}
		primeiro = n / divisor;
		ultimo = n % 10;
		meio = (n % divisor) / 10 * 10;
		n_novo = (ultimo * divisor) + meio + primeiro;
		cout << n_novo;
	}
	else
		cout << n;
	
	return 0;
}
