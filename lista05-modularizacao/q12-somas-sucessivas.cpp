#include <iostream>
using namespace std;

int f(int a, int b){
	int  soma = 0;
	if (b == 0)
		return 0;
	else if (b == 1){
		soma += a;
		return soma;
	} else
		return a + f(a, b-1);
}
		
int main() {
	int x, y;
	cin >> x >> y;
	cout << f(x, y);
	
	return 0;
}
