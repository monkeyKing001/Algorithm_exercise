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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int lastEvenTime = 0;
	vector<int> score(3, 0);
	vector<int> totalWinningTime(3, 0);
	vector<int> lastWinningTime(3, 0);
	int winningTeam = -1;
	for (int i = 0; i < n; i++) {
		int team;
		cin >> team;
		score[team]++;
		string info;
		cin >> info;
		string min;
		string sec;
		int timeInSec = 0;
		stringstream ss(info);
		getline(ss, min, ':');
		getline(ss, sec);
//		cout << "min, sec : "  << min <<", " << sec << "\n";
		timeInSec += stoi(sec);
		timeInSec += (60 * stoi(min));
		//turnover to 1
		if (score[1] > score[2] && winningTeam != 1){
			winningTeam = 1;
			lastWinningTime[1] = timeInSec;
//			cout << "turn over to 1 in " << timeInSec << "\n";
		}
		//turnover to 2
		if (score[2] > score[1] && winningTeam != 2){
			winningTeam = 2;
			lastWinningTime[2] = timeInSec;
//			cout << "turn over to 2 in " << timeInSec << "\n";
		}
		//even
		if (score[2] == score[1]){
			if (winningTeam == 1)//update team 1
			{
				totalWinningTime[1] += timeInSec - lastWinningTime[1];
			}
			else if (winningTeam == 2){
				totalWinningTime[2] += timeInSec - lastWinningTime[2];
			}
			winningTeam = -1;
			lastEvenTime = timeInSec;
//			cout << "tie in " << timeInSec << "\n";
		}
	}
	int endTime = 60 * 48;
	//team1
//	cout << totalWinningTime[1] / 60 << ":" << totalWinningTime[1] % 60 <<"\n";
	if (score[1] > score[2]){
		totalWinningTime[1] += endTime - lastWinningTime[1];
	}
	else if (score[1] < score[2]){
		totalWinningTime[2] += endTime - lastWinningTime[2];
	}
	printf("%02d:%02d\n", totalWinningTime[1] / 60, totalWinningTime[1] % 60);
	//team2
	printf("%02d:%02d\n", totalWinningTime[2] / 60, totalWinningTime[2] % 60);
	return (0);
}

