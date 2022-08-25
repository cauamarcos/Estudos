#include <iostream>
using namespace std;

void somar(int a, int b, int& soma){
	soma = a + b;
	cout << soma;
}
		
int main() {
	int x, y, s;
	cin >> x >> y;
	somar(x, y, s);
	
	return 0;
}
