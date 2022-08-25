#include <iostream>
using namespace std;

void imprime_vetor(int a[], int b){
	cout << "[";
	for(int x = 0; x < b; x++){
		if (x == b-1)
			cout << a[x];
		else
			cout << a[x] << ", ";
	}
	cout << "]";

}

int main() {
	int n;
	cin >> n;
	int vetor[n];
	for(int i = 0; i < n; i++)
		cin >> vetor[i];
	imprime_vetor(vetor, n);

	return 0;
}
