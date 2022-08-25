#include <iostream>
using namespace std;

int main() {
	unsigned n, maior = 0, x;
	cin >> n;
	string vetor[n];
	for(unsigned i = 0; i < n; i++){
		cin >> vetor[i];
		x = vetor[i].size();
		if (x > maior)
			maior = x;
	}
	string novo[n];
	for (unsigned i = 0; i < n; i++){
		if (vetor[i].size() < maior){
			string p = "";
			for (unsigned a = 0; a < maior; a++){
				if (a < maior - vetor[i].size())
					p += "*";
			}
			p += vetor[i];
			novo[i] = p;
		}
		else
			novo[i] = vetor[i];
	}
	for (unsigned i = 0; i < n; i++)
		cout << novo[i] << endl;
	
	return 0;
}
