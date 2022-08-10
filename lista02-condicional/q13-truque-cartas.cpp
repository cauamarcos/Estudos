#include <iostream>
using namespace std;

int main() {
	int qtd, posicao, metade;
	cin >> qtd >> posicao;
	metade = qtd / 2;
	if (posicao >= metade) {
		cout << (posicao - metade) * 2;
	}else if (posicao < metade) {
		cout << 1 + (posicao * 2);
	}
	
	return 0;
}
