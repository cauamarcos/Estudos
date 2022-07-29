#include <iostream>
using namespace std;

int main() {
	float altura, soma_turma = 0, soma_m = 0, soma_f = 0, maior = 0, menor;
	int  n, cont = 1, cont_m = 0, cont_f = 0;
	char sexo;
	cin >> n;
	while (cont <= n){
		cin >> altura >> sexo;
		if (cont == 1)
			menor = altura;
		if (altura > maior)
			maior = altura;
		else if (altura < menor)
			menor = altura;
		soma_turma += altura;
		if (sexo == 'm'){
			soma_m += altura;
			cont_m++;
		} else if (sexo == 'f'){
			soma_f += altura;
			cont_f++;
		}
		cont++;
	}
	cout << maior << endl << menor << endl;
	if (soma_f > 0)
		cout << soma_f / cont_f << endl;
	else
		cout << "erro" << endl;
	if (soma_m > 0)
		cout << soma_m / cont_m << endl;
	else
		cout << "erro" << endl;
	cout << soma_turma / n;
			
	return 0;
}
