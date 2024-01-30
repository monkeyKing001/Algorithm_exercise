#include <queue>
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
//template <typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
template <typename T, typename Container, typename Compare>
void printpq(const std::priority_queue<T, Container, Compare> pq) {
//    std::priority_queue<T, Container, Compare> temp = pq; // Create a copy to avoid modifying the original
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";
}

struct desCmp{
	bool operator()(int bottom, int top){
		return (bottom > top);
	}
};

//same with less<int> -> bottom is smaller, top is bigger -> less bottom
struct ascCmp{
	bool operator()(int bottom, int top){
		return (bottom < top);
	}
};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 0;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++) {
		cin >> n;
		priority_queue<int, vector<int>, less<int>> smaller;
//		priority_queue<int, vector<int>, ascCmp> smaller;
		priority_queue<int, vector<int>, greater<int>> bigger;
//		priority_queue<int, vector<int>, desCmp> bigger;
		vector<int> sol;
		int mean = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (num > mean)
				bigger.push(num);
			else
				smaller.push(num);
			//rebalancing
			if (abs((int)(smaller.size() - bigger.size())) >= 2){
				if (smaller.size() > bigger.size()){
					int temp = smaller.top();
					smaller.pop();
					bigger.push(temp);
					mean = smaller.top();
				}
				else{
					int temp = bigger.top();
					bigger.pop();
					smaller.push(temp);
					mean = bigger.top();
				}
			}
//			cout << "smaller\n";
//			printpq(smaller);
//			cout << "bigger\n";
//			printpq(bigger);
			mean = (bigger.size() > smaller.size()) ? bigger.top() : smaller.top();
			if (i % 2 == 0){
				sol.push_back(mean);
			}
		}
		cout << sol.size() << "\n";
		for (int i = 0; i < sol.size(); i++) {
			cout << sol[i];
			if ((i + 1 ) % 10 == 0)
				cout << "\n";
			else
				cout << " ";
		}
		cout << "\n";
	}
	return (0);
}
