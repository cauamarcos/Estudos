#include <iostream>
using namespace std;

int main(){
	int cont = 1;
	float n, maior = 0, segundo_maior = 0, aux, soma = 0;
	while (cont <= 7){
		cin >> n;
		soma += n;
		if (n > maior){
			aux = maior;
			maior = n;
		} else if (n > segundo_maior){
			segundo_maior = n;
		}
		if (aux > segundo_maior and maior != aux){
			segundo_maior = aux;
		}
		cont++;
	}
	cout << maior << endl << segundo_maior << endl << (soma - maior - segundo_maior) / 5;

	return 0;
}
