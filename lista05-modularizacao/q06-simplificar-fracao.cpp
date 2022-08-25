#include <iostream>
using namespace std;

int simplificar(int a, int &b){
	int cont = 1, menor, divisor;
	if (a < b)
		menor = a;
	else
		menor = b;
	while (cont <= menor){
		if (a % cont == 0 and b % cont == 0)
			divisor = cont;
		cont++;
	}
	b /= divisor;
	return a / divisor;
}
		
int main() {
	int numerador, denominador;
	cin >> numerador >> denominador;
	cout << simplificar(numerador, denominador) << endl;
	cout << denominador;
	
	return 0;
}
