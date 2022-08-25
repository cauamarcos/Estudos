#include <iostream>
using namespace std;

int main(){
	int h, m, cont = 0, x = 0, a, b;
	cin >> h;
	int vetor[100];
	while(h > 0){
		cin >> m;
		cont++;
		vetor[x] = h;
		vetor[x+1] = m;
		x += 2;
		cin >> h;
	}
	cin >> a >> b;
	x = 0;
	while(((float(x)/2 + 1)/cont) < 0.7){
		x += 2;
	}
	cout << vetor[x] << ":" << vetor[x+1] << endl;
	x = 0;
	float c;
	while((vetor[x] < a) or (vetor[x] == a and vetor[x+1] <= b)){
		c++;
		x +=2;
	}
	cout << (c/cont)*100;

	return 0;
}
