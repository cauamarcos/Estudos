#include <iostream>
using namespace std;
void piramide(int n){
	int numero = 1, linha = 1;
	while (linha <= n){
		while (numero <= linha){
			cout << numero << " ";
			numero++;
		}
		cout << endl;
		linha++;
		numero = 1;
	}
}
int main() {
	int n;
	cin >> n;
	piramide(n);
	return 0;
}
