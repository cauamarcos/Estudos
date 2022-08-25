#include <iostream>
using namespace std;

int tribonacci(int n){
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else
		return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
}
		
int main() {
	int x;
	cin >> x;
	int cont = 1;
	while (cont <= x){
		cout << tribonacci(cont) << " ";
		cont++;
	}
	
	return 0;
}
