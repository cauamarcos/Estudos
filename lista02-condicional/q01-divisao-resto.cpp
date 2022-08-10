#include <iostream>
using namespace std;

int main() {
	int dividendo, divisor;
	cin >> dividendo >> divisor;
	if (divisor == 0) {
		cout << "erro";
	}else {
		cout << dividendo / divisor << endl << dividendo % divisor; 
	}
	
	return 0;
}
