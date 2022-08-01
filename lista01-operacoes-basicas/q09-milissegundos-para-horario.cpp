#include <iostream>
using namespace std;

int main() {
	int tempo, h, m, resto;
	float s;
	cin >> tempo;
	h = tempo / 3600000;
	resto = tempo % 3600000;
	m = resto / 60000;
	resto = resto %  60000;
	s = resto / 1000.00;
	cout << h << " : " << m << " : " << s;
	
	return 0;
}
