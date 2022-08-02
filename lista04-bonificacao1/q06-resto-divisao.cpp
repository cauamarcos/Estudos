#include <iostream>
using namespace std;

int main(){
	int a, b, cont = 0;
	cin >> a >> b;
	if (a > b){
		while (a >= b){
			a -= b;
			cont++;
		}
		cout << a << endl;
		cout << cont;
	} else if (b >= a){
		while (b >= a){
			b -= a;
			cont++;
		}
		cout << b << endl;
		cout << cont;
	}
	return 0;
}
