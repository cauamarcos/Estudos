#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int opcao;
	double angulo1, angulo2, rad;
	cin >> opcao;
	if (opcao == 1){
		cin >> angulo1;
		rad = (angulo1 / 180) * (M_PI);
		cout << sin(rad);
	}else if (opcao == 2) {
		cin >> angulo1;
		rad = (angulo1 / 180) * (M_PI);
		cout << cos(rad);
	}else if (opcao == 3) {
		cin >> angulo1 >> angulo2;
		cout << angulo1 * angulo2;
	}
	
	return 0;
}
