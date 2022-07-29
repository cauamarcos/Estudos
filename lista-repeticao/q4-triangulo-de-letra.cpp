#include <iostream>
using namespace std;

int main(){
	int n, linha = 1, letra, cont;
	cin >> n;
	while (linha <= n){
		letra = 97;
		cont = 0;
		while (cont < linha){
			cout << char(letra+cont) << " ";
			cont++;
		}
		cout << endl;
		linha++;
	}
	return 0;
}