#include <iostream>
using namespace std;

int main() {
	int codigo_produto, pais;
	float kg, preco, peso, preco_bruto, imposto, i, pt;
	cin >> codigo_produto >> kg >> pais;
	if (codigo_produto >= 1 and codigo_produto <= 4) {
		preco = 10;
	}else if (codigo_produto >= 5 and codigo_produto <= 7) {
		preco = 25;
	}else if (codigo_produto >= 8 and codigo_produto <= 10) {
		preco = 35;
	}
	if (pais == 1) {
		imposto = 0;
	}if (pais == 2) {
		imposto = 0.15;
	}if (pais == 3) {
		imposto = 0.25;
	}
	peso = kg * 1000;
	preco_bruto = preco * peso;
	i = imposto * preco_bruto;
	pt = preco_bruto + i;
	cout << peso << endl << preco_bruto << endl << i << endl << pt;
	
	return 0;
}
