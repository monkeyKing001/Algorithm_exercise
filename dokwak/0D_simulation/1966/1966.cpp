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
#define priority first
#define idx second

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++) {
		int number = 0, target = 0;
		cin >> number >> target;
		queue<pair<int, int>> q;
		priority_queue<int> pri;
		for (int i = 0; i < number; i++) {
			int input = 0;
			cin >> input;
			q.push({input, i});
			pri.push(input);
		}
		int count = 0;
		while (q.size() != 0){
			pair<int, int> curEnt = q.front();
			q.pop();
			//poping
			if (curEnt.priority == pri.top()){
				pri.pop();
				count++;
				if (curEnt.idx == target){
					cout << count << "\n";
					break;
				}
			}
			else
				q.push(curEnt);
		}
	}
	return (0);
}

