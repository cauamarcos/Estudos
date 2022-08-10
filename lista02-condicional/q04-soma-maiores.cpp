#include <iostream>
using namespace std;

int main() {
	float n1, n2, n3, n4;
	float s = 0;
	cin >> n1 >> n2 >> n3 >> n4;
	if (n1 > n2 or n1 > n3 or n1 > n4) {
		s += n1;
	}if (n2 > n1 or n2 > n3 or n2 > n4) {
		s += n2;
	}if (n3 > n1 or n3 > n2 or n3 > n4) {
		s += n3;
	}if (n4 > n1 or n4 > n2 or n4 > n3) {
		s += n4;
	}
	cout << s;
	
	return 0;
}
