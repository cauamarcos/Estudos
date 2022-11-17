#include <iostream>
using namespace std;

int f(int a);

int h(int n){
	if (n == 0)
		return 0;
	else
		return h(n-1) + f(n-1);
}

int f(int a){
	if (a == 0)
		return 1;
	else if (a % 2 == 0)
		return 2* h(a) + f(a-1);
	else
		return 2 * h(a) - f(a-1);
}

int main(){
	int x;
	cin >> x;
	cout << f(x);
	
	return 0;
}
