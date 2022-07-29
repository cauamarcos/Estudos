#include <iostream>
using namespace std;

int main(){
	int n, cont, a, b, c, d, e, marcou;
	string resp, gabarito = "";
	cin >> n;
	while (n != 0){
		cont = 1;
		while (cont <= n){
			cin >> a >> b >> c >> d >> e;
			marcou = 0;
			if (a <= 127)
				marcou++;
			if (b <= 127)
				marcou++;
			if (c <= 127)
				marcou++;
			if (d <= 127)
				marcou++;
			if (e <= 127)
				marcou++;
			if (marcou == 0 or marcou > 1)
				resp = "*";
			else {
				if (a <= 127)
					resp = "A";
				else if (b <= 127)
					resp = "B";
				else if (c <= 127)
					resp = "C";
				else if (d <= 127)
					resp = "D";
				else
					resp = "E";
			}
			cont++;
			gabarito += resp + "\n";
		}
		cin >> n;
	}
	cout << gabarito;
				
	return 0;
}
