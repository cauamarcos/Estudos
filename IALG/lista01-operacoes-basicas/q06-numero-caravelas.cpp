#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float qtd_de_homens;
	cin >> qtd_de_homens;
	cout << ceil((qtd_de_homens - (5 * 200))/80);
	
	return 0;
}
