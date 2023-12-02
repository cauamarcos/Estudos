#include <iostream>
using namespace std;

unsigned fat(unsigned n){
	unsigned f = 1;
	while(n > 0){
		f *= n;
		n--;
	}
	return f;
}

void obterVetor(float vet[], int a){
	for(int i = 0; i < a; i++)
		vet[i] = (2 * fat(i) + i) / (i * i + 1.75);
}

int main(){
	int n, m;
	cin >> n >> m;
	float* vetor;
	vetor = new float[n];
	obterVetor(vetor, n);
	for(int i = m; i < n; i++)
		cout << vetor[i] << endl;

	return 0;
}
