#include <bits/stdc++.h>

using namespace std;
int n, m;
int **g_info;
int diff = INT_MAX;
vector<int> teamBit;

void sol(vector<int> teamBit){
	vector<int> bitOnTeam;
	vector<int> bitOffTeam;
	for (int i = 0; i < teamBit.size(); i++) {
		if (teamBit[i] == 1)
			bitOnTeam.push_back(i);
		else if (teamBit[i] == 0)
			bitOffTeam.push_back(i);
	}
	int bitOnTeamScoreSum = 0;
	int bitOffTeamScoreSum = 0;
	for (int i = 0; i < bitOnTeam.size() && i < bitOffTeam.size(); i++) {
		int bitOnTeamMemberI  = bitOnTeam[i];
		int bitOffTeamMemberI = bitOffTeam[i];
//			cout << bitOnTeamMemberI << " " << bitOffTeamMemberI;
//			cout << "\n";
		for (int j = i + 1; j < bitOnTeam.size() && j < bitOffTeam.size(); j++) {
			int bitOnTeamMemberJ = bitOnTeam[j];
			int bitOffTeamMemberJ = bitOffTeam[j];
			bitOnTeamScoreSum += g_info[bitOnTeamMemberI][bitOnTeamMemberJ];
			bitOnTeamScoreSum += g_info[bitOnTeamMemberJ][bitOnTeamMemberI];
			bitOffTeamScoreSum += g_info[bitOffTeamMemberI][bitOffTeamMemberJ];
			bitOffTeamScoreSum += g_info[bitOffTeamMemberJ][bitOffTeamMemberI];
		}
	}
	diff = min(abs(bitOnTeamScoreSum - bitOffTeamScoreSum), diff);
	if (next_permutation(teamBit.begin(), teamBit.end()))
		sol(teamBit);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g_info = new int*[n];
	for (int i = 0; i < n; i++) {
		g_info[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> g_info[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		if (i <  n / 2)
			teamBit.push_back(0);
		else
			teamBit.push_back(1);
	}
	sol(teamBit);
	cout << diff;
	return (0);
}

