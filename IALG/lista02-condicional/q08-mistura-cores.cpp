#include <iostream>
using namespace std;

int main() {
	int n1, n2, soma;
	string cor1, cor2;
	cin >> cor1;
	if (cor1 == "azul") {
		n1 = 1;
	}else if (cor1 == "vermelho") {
		n1 = 2;
	}else if (cor1 == "amarelo") {
		n1 = 3;
	}
	cin >> cor2;
	if (cor2 == "azul") {
		n2 = 1;
	}else if (cor2 == "vermelho") {
		n2 = 2;
	}else if (cor2 == "amarelo") {
		n2 = 3;
	}
	soma = n1 + n2;
	if (cor1 == cor2) {
		cout << cor1;
	}else {
		if (soma == 3) {
			cout << "violeta";
		}else if (soma == 4) {
			cout << "verde";
		}else if (soma == 5){
			cout << "laranja";
		}
	}
	
	return 0;
}
