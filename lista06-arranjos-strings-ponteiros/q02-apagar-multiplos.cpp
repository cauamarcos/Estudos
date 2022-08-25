#include <iostream>
using namespace std;

int* validar(int a[], int& b){
	int cont = 0, f = 0;
	for(int i = 0; i < b; i++){
		if (a[i] % 3 == 0){
			a[i] = -1;
			cont++;
		}
	}
		int* novo = new int[b-cont];
		for (int i = 0; i < b; i++){
			if (a[i] != -1){
				novo[f] = a[i];
				f++;
		}
	}
	b -= cont;
	return novo;
}

int main() {
	int n;
	cin >> n;
	int vetor[n];
	for(int i = 0; i < n; i++)
		cin >> vetor[i];
	int* v;
	v = validar(vetor, n);
	for(int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl << n;

	return 0;
}
