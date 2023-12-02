#include <iostream>
using namespace std;

int main() {
	int cont_a = 0, cont_b = 0, cont = 0;
	char letra;
	while (cont < 10){
		cin >> letra;
		cont++;
		if (letra == 'a')
			cont_a++;
		else
			cont_b++;
	}
	if (cont_a < cont_b)
		cout << "1";
	else
		cout << "0";
	return 0;
}
