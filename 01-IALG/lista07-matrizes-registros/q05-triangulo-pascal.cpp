#include <iostream>
using namespace std;

int main(){
	unsigned n;
	cin >> n;
	unsigned matriz[n][n];
	for(unsigned i = 0; i < n; i++){
		for(unsigned j = 0; j <= i; j++){
			if(j == 0 or j == i)
				matriz[i][j] = 1;
			else
				matriz[i][j] = matriz[i-1][j] + matriz[i-1][j-1];
		}
	}
	for(unsigned i = 0; i < n; i++){
		for(unsigned j = 0; j <= i; j++)
			cout << matriz[i][j] << " ";
		cout << endl;
	}

	return 0;
}
