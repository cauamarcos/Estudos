#include <iostream>
using namespace std;

int main() {
	float salario_minimo, salario_bruto;
	int horas_trabalhadas;
	cin >> salario_minimo >> horas_trabalhadas;
	salario_bruto = (horas_trabalhadas* (0.05 * salario_minimo)) * 0.77;
	cout << salario_bruto;
	
	return 0;
}
