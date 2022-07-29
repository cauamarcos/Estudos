#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, cont = 1;
	double pi, x, raiz = sqrt(2), numerador = 1;
	cin >> n;
	while (cont <= n){
		numerador *= raiz;
		raiz = sqrt(2 + raiz);
		cont++;
	}
	x = numerador / pow(2, n);
	pi = 2 / x;
	cout << pi;	
	
	return 0;
}
