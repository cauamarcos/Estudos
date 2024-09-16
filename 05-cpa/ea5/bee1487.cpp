#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, t, instance = 1;
    cin >> n >> t;

	while(n != 0){

		vector<int> points(t+1, 0);

		vector<pair<int, int>> rides(n);

		for(int i = 0; i < n; i++) 
            cin >> rides[i].first >> rides[i].second;

		for(int time=1; time <= t; ++time){
			for(pair<int, int> ride:rides){
				if(time >= ride.first){
					points[time] = max(points[time], ride.second + points[time-ride.first]);
				}
			}
		}

		cout << "Instancia " << instance << endl << points[t] << endl << endl;
		instance++;

		cin >> n >> t;
	}
}
