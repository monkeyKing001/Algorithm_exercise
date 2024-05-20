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
	queue<string> arr[n];
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string sentence;
		getline(cin, sentence, '\n');
//		cout << "sentence : " << sentence << "\n";
		stringstream ss(sentence);
		string chunk;
		int count = 0;
		while (getline(ss, chunk, ' ')){
//			cout << "chunk " << count << " : " << chunk << "\n";
			arr[i].push(chunk);
			count++;
		}
	}
	string targetFullSentence;
	getline(cin, targetFullSentence, '\n');
	stringstream ss (targetFullSentence);
//	cout << targetFullSentence << "\n";
	string chunk;
	while (getline(ss, chunk, ' ')){
		for (int i = 0; i < n; i++) {
			if (arr[i].front() == chunk){
				arr[i].pop();
				break;
			}
			if (i == n - 1){
				cout << "Impossible\n";
				return (0);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i].size() != 0){
			cout << "Impossible\n";
			return (0);
		}
	}
	cout << "Possible\n";
	return (0);
}
