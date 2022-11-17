#include <iostream>
using namespace std;
	
int pot(int a, int b){
	if (b == 0)
		return 1;
	else
		return a * pot(a, b-1);
}

int main() {
	int n, x;
	cin >> n >> x;
	cout << pot (n, x);
	
	return 0;
}
