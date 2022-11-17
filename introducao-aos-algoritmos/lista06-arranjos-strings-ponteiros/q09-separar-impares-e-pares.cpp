#include <iostream>
using namespace std;

int main() {
	int vetor[20], c1 = 0, c2 = 0, pares[20], impares[20];
	for (int i = 0; i < 20; i++)
		cin >> vetor[i];
	for (int i = 0; i < 20; i++){
		if (vetor[i] % 2 == 0){
			pares[c1] = vetor[i];
			c1++;
		}
		else{
			impares[c2] = vetor[i];
			c2++;
		}
	}
	for (int i = 0; i < c1; i++)
		cout << pares[i] << " ";
	cout << endl;
	for (int i = 0; i < c2; i++)
		cout << impares[i] << " ";
	return 0;
}
