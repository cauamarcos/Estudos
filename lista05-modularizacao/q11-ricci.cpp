#include <iostream>
using namespace std;

int ricci(int r1, int r2, int n){
	if (n == 1) {
		return r1;
	} else if (n == 2){
		return r2;
	} else {
		return ricci(r1, r2, n-1) + ricci(r1, r2, n-2);
	}
}

int main(){
	int a, b, x;
	cin >> a >> b >> x;
	int cont = 1;
	while (cont <= x){
		cout << ricci(a, b, cont) << " ";
		cont++;
	}
	
	return 0;
}
