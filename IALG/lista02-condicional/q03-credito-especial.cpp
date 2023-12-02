#include <iostream>
using namespace std;

int main() {
	float sm;
	cin >> sm;
	if (sm <= 0) {
		cout << sm << endl << sm * 0 << endl;
	}else if (sm > 0 and sm < 200) {
		cout << sm << endl << sm * 0.1 << endl;
	}else if (sm >= 200 and sm < 400) {
		cout << sm << endl << sm * 0.15 << endl;
	}else if (sm >= 400 and sm < 800) {
		cout << sm << endl << sm * 0.2 << endl;
	}else if (sm >= 800 and sm < 1600) {
		cout << sm << endl << sm * 0.25 << endl;
	}else if (sm >= 1600) {
		cout << sm << endl << sm * 0.3 << endl;
	}
		
	return 0;
}
