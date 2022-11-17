#include <iostream>
using namespace std;

int main() {
	int n, d1, d2, d3, d4, d5, resto;
	int cont_par = 0;
	int cont_impar = 0;
	cin >> n;
	d1 =  n / 10000;
	resto = n % 10000;
	d2 = resto / 1000;
	resto = resto % 1000;
	d3 = resto / 100;
	resto = resto % 100;
	d4 = resto / 10;
	resto = resto % 10;
	d5 = resto;
	if (d1 % 2 == 0) {
		cont_par++;
	}else {
		cont_impar++;
	}if (d2 % 2 == 0) {
		cont_par++;
	}else {
		cont_impar++;
	}if (d3 % 2 == 0) {
		cont_par++;
	}else {
		cont_impar++;
	}if (d4 % 2 == 0) {
		cont_par++;
	}else {
		cont_impar++;
	}if (d5 % 2 == 0) {
		cont_par++;
	}else {
		cont_impar++;
	}
	cout << cont_par << endl << cont_impar;
	
	return 0;
}
