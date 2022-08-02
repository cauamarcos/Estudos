#include <iostream>
using namespace std;

int main(){
	int dia, hora, minutos, t;
	cin >> dia >> hora >> minutos >> t;
	minutos += t;
	hora += minutos / 60;
	dia += hora / 24;
	hora %= 24;
	minutos %= 60;
	cout << dia << " " << hora << " " << minutos;
	return 0;
}
