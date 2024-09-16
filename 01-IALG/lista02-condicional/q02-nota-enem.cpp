#include <iostream>
using namespace std;

int main() {
	float mat, n, l, red, h, media;
	cin >> mat >> n >> l >> red >> h;
	if (red < 200) {
		media = -1;
		cout << media;
	} else {
		media = ((mat*3) + 2*(n + l + red) + h) / 10;
		cout << media;
	}
	
	return 0;
}
