#include <iostream>
using namespace std;

float distancia(float& a, float b, float c){
	float d;
	d = (a + (b*c)) / 1.852;
	a /= 1.852;
	return d;
}

int main(){
	float d, v, t, x;
	float *v1, *v2, *c1, *c2;
	int cont = 0;
	cin >> d;
	while (d >= 0){
		c1 = v1;
		c2 = v2;
		cont++;
		cin >> v >> t;
		x = distancia(d, v, t);
		v1 = new float[cont];
		v2 = new float[cont];
		for (int i = 0; i < cont; i++){
			if (i < cont-1){
				v1[i] = c1[i];
				v2[i] = c2[i];
			}
			if (i == cont-1){
				v1[i] = d;
				v2[i] = x;
			}
		}
		cin >> d;
	}
	for (int i = 0; i < cont; i++)
		cout << v1[i] << " " << v2[i] << endl;
	
	return 0;
}
