#include <iostream>
using namespace std;

int main(){
	int n, linha = 1, cor, cont;
	cin >> n;
	while (linha <= n){
		if (linha % 2 == 0)
			cor = 1;
		else
			cor = 2;
		cont = 0;
		while (cont < n){
			if (cor == 1){
				cout << "#";
				cor++;
			} else if (cor == 2){
				cout << ".";
				cor--;
			}
			cont++;
		}
		cout << endl;
		linha++;
	}
	return 0;
}
