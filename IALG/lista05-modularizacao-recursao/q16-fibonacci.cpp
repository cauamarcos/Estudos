#include <iostream>
using namespace std;

int fibonacci(int n){
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	int x, cont = 1;
	cin >> x;
	while (cont <= x){
		cout << fibonacci(cont) << " ";
		cont++;
	}
	
	return 0;
}
