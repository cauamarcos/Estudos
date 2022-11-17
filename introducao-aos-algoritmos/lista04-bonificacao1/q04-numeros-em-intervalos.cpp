#include <iostream>
using namespace std;

int main(){
	int valor1, valor2, valor3, valor4, n, cont1 = 0, cont2 = 0;
	cin >> valor1 >> valor2 >> valor3 >> valor4;
	cin >> n;
	while (n > 0){
		if ((n < valor1 or (n >= valor2 and n < valor3)) and n % 2 == 0)
			cont1++;
		else if (((n >= valor1 and n < valor2) or (n >= valor3 and n < valor4)) and n % 2 != 0)
			cont2++;
		cin >> n;
	}
	cout << cont1 << endl << cont2;
	return 0;
}
