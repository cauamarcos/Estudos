#include <iostream>
using namespace std;

string* limpar(string vet[], unsigned& a){
	unsigned b = 0, cont = 1;
	bool se = true;
	string* novo = new string[a];
	for (unsigned x = 0; x < a; x++){
		while (se and b < cont){
			if (novo[b] == vet[x])
				se = false;
			b++;
		}
		if (x < a-1)
			b = 0;
		if (se){
			novo[cont-1] = vet[x];
			cont++;
		}
		se = true;
	}
	a = cont-1;
	return novo;

}

int main() {
	unsigned n;
	cin >> n;
	string nomes[n];
	for (unsigned i = 0; i < n; i++)
		cin >> nomes[i];
	string* v;
	v = limpar(nomes, n);
	cout << n << endl;
	for (unsigned i = 0; i < n; i++)
		cout << v[i] << endl;

	return 0;
}
