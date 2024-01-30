#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m;
deque<int> upside(n);
deque<int> downside(n);
deque<int> robotPosition;
vector<bool> robotOn(n);
int uploadPosition = 0;
int offloadPosition = -1;
int zeroDurability = 0;
int stage = 0;
void rotation(){
//	cout << "########################\n";
//	cout << "######   ROTATE   ######\n";
//	cout << "########################\n";
	//belt rotation
	int tempUp = upside.back();
	upside.pop_back();
	int tempDown = downside.front();
	downside.pop_front();
	upside.push_front(tempDown);
	downside.push_back(tempUp);

	//robot rotation
	for (int i = 0; i < robotPosition.size(); i++) {
		robotPosition[i]++;
	}
	if (robotPosition.size() != 0 && robotPosition[robotPosition.size() - 1] >= offloadPosition)
			robotPosition.pop_back();
	fill_n(robotOn.begin(), n, false);
	for (int i = 0; i < robotPosition.size(); i++) {
		int position = robotPosition[i];
		robotOn[position] = true;
	}
//	cout << "upside\n";
//	for (int i = 0; i < n; i++) {
//		cout << upside[i] << " ";
//	}
//	cout << "\n";
//	cout << "downside\n";
//	for (int i = 0; i < n; i++) {
//		cout << downside[i] << " ";
//	}
//	cout << "\n";
//	cout << "after rotation, robots are on\n";
//	for (int i = 0; i < robotPosition.size(); i++) {
//		cout << robotPosition[i] << " ";
//	}
//	cout << "\n";

}

void move(){
	//from end to start move!
//	cout << "########################\n";
//	cout << "######   ROBOMOVE   ####\n";
//	cout << "########################\n";
	for (int i = 0; i < robotPosition.size(); i++) {
		int position = robotPosition[robotPosition.size() - 1 - i];
		int nextPosition = position + 1;
		if (upside[nextPosition] >= 1 && !robotOn[nextPosition]){
			robotOn[position] = false;
			robotOn[nextPosition] = true;
			upside[nextPosition]--;
			robotPosition[robotPosition.size() - 1 - i]++; //mistake point! .size() - 1 - i not i
			if (upside[nextPosition] == 0)
				zeroDurability++;
			if (nextPosition == offloadPosition){
				robotOn[nextPosition] = false;
			}
		}
	}
	//if last robot on 
	if (robotPosition.size() != 0 && robotPosition[robotPosition.size() - 1] >= offloadPosition)
		robotPosition.pop_back();
//	cout << "after robot moving, robots are on\n";
//	for (int i = 0; i < robotPosition.size(); i++) {
//		cout << robotPosition[i] << " ";
//	}
//	cout << "\n";
}

void robotOnBelt(){
//	cout << "########################\n";
//	cout << "######   ROBOT ON   ####\n";
//	cout << "########################\n";
	if (upside[0] > 0){
		upside[0]--;
		if (upside[0] == 0)
			zeroDurability++;
		robotPosition.push_front(0);
		robotOn[0] = true;
	}
//	cout << "after load on robot, robots are on\n";
//	for (int i = 0; i < robotPosition.size(); i++) {
//		cout << robotPosition[i] << " ";
//	}
//	cout << "\n";
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k = 0;
	cin >> n >> k;
	upside.resize(n);
	downside.resize(n);
	robotOn.resize(n, false);
	offloadPosition = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> upside[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> downside[n - 1 - i];
	}
	while (true){
		stage++;
		rotation();
		move();
		robotOnBelt();
		if (zeroDurability >= k)
			break;
	}
	cout << stage;
	return (0);
}

