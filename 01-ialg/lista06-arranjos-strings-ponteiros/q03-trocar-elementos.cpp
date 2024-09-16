#include <iostream>
using namespace std;

int main() {
	char a[10], b[10], aux;
	for(int i = 0; i < 10; i++)
		cin >> a[i];
	for(int i = 0; i < 10; i++)
		cin >> b[i];
	for(int i = 0; i < 10; i+=2){
		aux = a[i];
		a[i] = b[9-i/2];
		b[9-i/2] = aux;
	}
	for(int i = 0; i < 10; i++)
		cout <<  a[i] << " ";
	cout << endl;
	for(int i = 0; i < 10; i++)
		cout << b[i] << " ";

	return 0;
}
