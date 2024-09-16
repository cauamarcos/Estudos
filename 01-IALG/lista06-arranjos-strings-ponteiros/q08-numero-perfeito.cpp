#include <iostream>
using namespace std;

int main() {
	int n, cont = 1, tam = 0, s = 0;
	cin >> n;
	int divisores[n] = {0};
	while (cont < n){
		if (n % cont == 0){
			divisores[tam] = cont;
			tam++;
		}
		cont++;
	}
	for (int i = 0; i < tam; i++)
		s += divisores[i];
	if (s == n){
		for (int i = 0; i < tam; i++)
			cout << divisores[i] << " ";
	}
	else 
		cout << "-1";
	
	return 0;
}
