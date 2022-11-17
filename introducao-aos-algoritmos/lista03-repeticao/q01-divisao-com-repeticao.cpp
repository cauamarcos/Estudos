#include <iostream>
using namespace std;

int main() {
	int n, divisor, soma = 0, cont = 0;
	cin >>  n >> divisor;
	while (soma < n){
		soma += divisor;
		cont++;
	}
	if(soma > n)
		cout << cont - 1;
	else
		cout << cont;
	
	return 0;
}
