#include <iostream>
using namespace std;

int* expandir(int vetor[], int& a){
	a += 5;
	int* novo;
	novo = new int[a];
	for (int j = 0; j < a; j++)
		novo[j] = vetor[j];
	delete vetor;
	return novo;
}

int main(){
	int cap = 5, n, cont = 0, c = 0;
	int* vet;
	vet = new int[cap];
	for(int i = 0; i <= cap; i++){
		cin >> n;
		c++;
		if (i == cap and n > 0){
			vet = expandir(vet, cap);
			cont++;
		}
		if (n <= 0)
			i = cap+1;
		else
			vet[i] = n;
	}
	for (int i = 0; i < c-1; i++)
		cout << vet[i] << " ";
	cout << endl << cap << endl << cont;

	return 0;
}
