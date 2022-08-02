#include <iostream>
using namespace std;

int maior_valor(int a, int& b){
	if (a > b)
		b = a;
	return b;
}

int main(){
	int a, maior;
	cin >> a;
	maior = a;
	char continuar = 'S';
	cin >> continuar;
	while (continuar == 'S'){
		cin >> a >> continuar;
		maior_valor (a, maior);
	}
	cout << maior;
	
	return 0;
}
