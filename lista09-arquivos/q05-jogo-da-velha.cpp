#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream ler("entrada.txt");
	int matriz[3][3];
	if(ler){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++)
				ler >> matriz[i][j];
			}
		}
    ler.close();
    bool seguir = true, x, o;
    for (int i = 0; i < 3; i++){
        x = true, o = true;
        for (int j = 0; j < 3; j++){
            if (matriz[i][j] != 1)
                x = false;
            if(matriz[i][j] != 2)
                o = false;
        }
        if (x){
            seguir = false;
            cout << 1;
        }
        if (o){
            seguir = false;
            cout << 2;
        }
    }
    if(seguir){
        for (int i = 0; i < 3; i++){
            o = true, x = true;
            for (int j = 0; j < 3; j++){
                if (matriz[j][i] != 2)
                    o = false;
                if(matriz[j][i] != 1)
                    x = false;
            }
            if (o){
                seguir = false;
                cout << 2;
            }
            if (x){
                seguir = false;
                cout << 1;
            }
        }
    }
    if (seguir){
        x = true, o = true;
        for(int i = 0; i < 3; i++){
            if (matriz[i][i] != 1)
                x = false;
            if(matriz[i][i] != 2)
                o = false;
        }
        if(x){
            seguir = false;
            cout << 1;
        }
        if(o){
            seguir = false;
            cout << 2;
        }
    }
    if (seguir){
        x = true, o = true;
        for(int i = 0; i < 3; i++){
            for(int j = 2; j >= 0; j--){
                if (matriz[i][j] != 1)
                    x = false;
                if(matriz[i][j] != 2)
                    o = false;
                i++;
            }
        }
        if(x){
            seguir = false;
            cout << 1;
        }
        if(o){
            seguir = false;
            cout << 2;
        }
    }
    if (seguir)
        cout << "0";

	return 0;
}
