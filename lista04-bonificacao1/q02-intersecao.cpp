#include <iostream>
using namespace std;

int main() {
	float x1, x2, y1, y2, p, a, b, pp;
	char reta;
	cin >> x1 >> y1 >> x2 >> y2 >> reta >> p;
	if (x1 == x2 and reta == 'y')
		cout << x1;
	else if (x1 == x2 and reta == 'x' and p != x1)
		cout << "nenhuma";
	else if (y1 == y2 and reta == 'y' and p != y1)
		cout << "nenhuma";
	else {
		a = (y2 - y1)/(x2 - x1);
		b = y1 - a*x1;
		if (reta == 'x')
			pp = a * p + b;
		else if (reta == 'y')
			pp = (p - b)/ a;
		cout << pp;
	}
	return 0;
}
