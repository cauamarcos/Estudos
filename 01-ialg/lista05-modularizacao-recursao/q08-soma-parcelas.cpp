#include <iostream>
using namespace std;

float f(int n, float& s){
	float cont = 1;
	while (cont <= n){
		s += (cont * (cont + 1)) / (cont + 3);
		cont++;
	}
	return s;
}
		
int main() {
	int x;
	float soma = 0;
	cin >> x;
	cout << f(x, soma);
	
	return 0;
}
