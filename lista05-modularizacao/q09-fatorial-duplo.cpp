#include <iostream>
using namespace std;

int fd(int n){
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return n * fd(n-2);
	
}

int main(){
	int x;
	cin >> x;
	cout << fd(x);
	
	return 0;
}
