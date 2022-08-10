#include <iostream>
using namespace std;

int main() {
	double a, b;
	int x;
	cin >> a >> b >> x;
	if (x == 1) {
		cout << (a+b) / 2;
	}else if ( x == 2) {
		if (a > b) {
			cout << a - b;
		}else {
			cout << b - a;
		}
	}else if (x == 3) {
		cout << a * b;
	}else if (x == 4){
		cout << a / b;
	}else if (x < 1 or x > 4){
		cout << "ERRO";
	}
	
	return 0;
}
