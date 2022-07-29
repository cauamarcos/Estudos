#include <iostream>
using namespace std;

int main() {
	int n, penultimo = 0, ultimo = 1, cont = 1, aux = 1;
	cin >> n;
	while(cont <= n){
		cout << penultimo << endl;
		penultimo = aux;
		aux = ultimo;
		ultimo += penultimo;
		cont++;
	}
	return 0;
}
