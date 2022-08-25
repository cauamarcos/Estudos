#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream ler("numeros");
	ofstream gravar("pares");
	ofstream g("impares");
	if (ler){
		int n;
		while(ler >> n){
			if(n % 2 == 0)
				gravar << n << " ";
			else
				g << n <<  " ";
		}
	gravar.close();
	g.close();
	}

	return 0;
}
