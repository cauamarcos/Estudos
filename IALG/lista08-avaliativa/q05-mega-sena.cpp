#include <iostream>
using namespace std;

int* maior(int v[], int& soma){
	soma = 0;
	for(int x = 0; x < 6; x++)
		soma += v[x];
	return v;
}

struct dezenas{
	int d1;
	int d2;
	int d3;
	int d4;
	int d5;
	int d6;
};

int main(){
	int n, a = 0, b = 0;
	cin >> n;
	dezenas r;
	int* vetor;
	vetor = new int[6];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++)
			cin >> vetor[j];
		int* vec = maior(vetor, a);
		if(a > b){
			r.d1 = vec[0];
			r.d2 = vec[1];
			r.d3 = vec[2];
			r.d4 = vec[3];
			r.d5 = vec[4];
			r.d6 = vec[5];
			b = a;
		}
	}
	cout << r.d1 << " " << r.d2 << " " << r.d3 << " " << r.d4 << " " << r.d5 << " " << r.d6;
	return 0;
}
