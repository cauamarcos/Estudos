#include <iostream>
using namespace std;

int menor(int vet[], int a, int b, int& c){
	if (a < 0){
		return b;
	}
	if (vet[a] <= b){
		b = vet[a];
		c = a;
	}
	return menor(vet, a-1, b, c);
}

int main() {
	int n, ult, pos;
	cin >> n;
	int vetor[n];
	for (int i = 0; i < n; i++)
		cin >> vetor[i];
	ult = vetor[n-1];
	cout << menor(vetor, n-1, ult, pos);
	cout << " " << pos;

	return 0;
}
