#include <iostream>
using namespace std;

int main(){
	float matriz[4][4];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++)
			cin >> matriz[i][j];
	}
	int n;
	float s = 0;
	cin >> n;
	int vetor[n];
	for(int i = 0; i < n; i++)
		cin >> vetor[i];
	for(int i = 0; i < n-1; i++){
		s += matriz[vetor[i]][vetor[i+1]];
	}
	cout << s;

	return 0;
}
