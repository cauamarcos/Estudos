#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c, delta, r1, r2;
	cin >> a >> b >> c;
	delta = pow(b, 2) - (4*a*c);
	if (delta < 0) {
		cout << "nenhuma raiz";
	}else {
		r1 = (-b - sqrt(delta)) / (2 * a);
		r2 = (-b + sqrt(delta)) / (2 * a);
		cout << r1 << "   " << r2;
	}
	
	return 0;
}
