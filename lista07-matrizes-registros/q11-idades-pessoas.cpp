#include <iostream>
using namespace std;

struct idade{
	string nome;
	int dia;
	int mes;
	int ano;
};

int main(){
	int n;
	cin >> n;
	idade vetor[n+1];
	for(int i = 0; i < n; i++)
		cin >> vetor[i].nome >> vetor[i].dia >> vetor[i].mes >> vetor[i].ano;
	cin >> vetor[n].dia >> vetor[n].mes >> vetor[n].ano;
	for(int i = 0; i < n; i++){
		cout << vetor[i].nome << ": ";
		int a = vetor[n].ano - vetor[i].ano;
		int m = vetor[n].mes - vetor[i].mes;
		int d = vetor[n].dia - vetor[i].dia;
		if((a > 1 and m > 0) or (a > 1 and m == 0 and d >= 0))
			cout << a << " anos";
		else if((a > 1 and m < 0) or (a > 1 and m == 0 and d < 0)){
			if(a > 2)
				cout << a-1 << " anos";
			else
				cout << "1 ano";
		}
		else if((a == 1 and m > 0) or (a == 1 and m == 0 and d >= 0))
			cout << " 1 ano";
		else if((a == 1 and m < 0) or (a == 1 and m == 0 and d < 0))
			cout << "0 ano";
		else
			cout << "-1";
		cout << endl;
	}

	return 0;
}
