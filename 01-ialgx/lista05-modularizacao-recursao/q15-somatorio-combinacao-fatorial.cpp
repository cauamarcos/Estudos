#include <iostream>
using namespace std;

long long int fatorial(int n){
	long long int fat = 1;
	while (n > 0){
		fat *= n;
		n--;
	}
	return fat;
}

long long int combinacao(int n, int k){
	if (k == 0)
		return 0;
	else
		return fatorial(n) / (fatorial(k) * fatorial(n-k)); 
}

long long int somatorio(int n){
	int k = 1;
	long long int soma = 0;
	while (k <= n){
		if (k == n)
			soma += 1;
		else
			soma += combinacao(n, k);
		k++;
	}
	return soma;
}

int main() {
	int x;
	cin >> x;
	cout << somatorio(x);
	
	return 0;
}
