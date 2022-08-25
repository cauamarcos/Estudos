#include <iostream>
using namespace std;

int main(){
	string x, limpa = "";
	cin >> x;
	limpa += x[0];
	for(unsigned i = 1; i < x.size(); i++){
		if(x[i] != x[i-1])
			limpa += x[i];
	}
	cout << limpa;

	return 0;
}
