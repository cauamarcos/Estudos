#include <iostream>
using namespace std;

int main(){
	int n;
	string resp = "";
	cin >> n;
	while (n > 0){
		int divisor = 1, soma = 0;
		while (divisor < n){
			if (n % divisor == 0)
				soma += divisor;
			divisor++;
		}
		if (soma == n)
			resp += "perfeito\n";
		else
			resp += "nao perfeito\n";
		cin >> n;
	}
	cout << resp;
	return 0;
}
