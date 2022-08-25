#include <iostream>
using namespace std;

float metro(float d){
	return (d*0.01);
}

float centimetro(float d){
	return (d*100);
}

int main(){
	float n;
	string converter;
	cin >> n >> converter;
	if (converter == "metro")
		cout << metro(n) << " m";
	else if (converter == "centimetro")
		cout << centimetro(n) << " cm";
	else cout << "ERRO";
		
	return 0;
}
