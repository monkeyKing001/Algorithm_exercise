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
	int k;
	cin >> n >> k;
	bool visited[n + 1];
	fill_n(visited, n + 1, false);
	visited[0] = true;
	visited[1] = true;
	int count = 0;
	while (true){
		for (int i = 2; i < n + 1; i++) {
			if (!visited[i]){
				int num = i;
				while (num < n + 1){
					if (!visited[num]){
						count++;
						visited[num] = true;
						if (count == k){
							cout << num;
							return(0);
						}
					}
					num += i;
				}
			}
		}
	}
	return (0);
}

