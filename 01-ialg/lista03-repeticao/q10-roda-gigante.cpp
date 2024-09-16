#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int raio, qtd, cont = 1;
	double x, y, angulo = 0, angulo1;
	cin >> raio >> qtd;
	angulo1 = (2 * M_PI) / qtd;
	while(cont <= qtd){
		x = raio * cos(angulo);
		y = raio * sin(angulo);
		if (angulo == M_PI)
			y = -0.00;
		cout << x << " " << y << endl;
		angulo += angulo1;
		cont++;
	}
	
	return 0;
}
