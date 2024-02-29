#include<bits/stdc++.h>
using namespace std;

struct cmp{
	bool operator() (vector<int> bottom, vector<int> top){
		return (bottom[2] > top[2]);
	}
};

int main(){
    int n, m;
    cin >> n >> m;
	int max = 1000000001;
	vector<vector<pair<int, int>>>g(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		g[u].push_back({v, cost});
	}
	int start, end;
	cin >> start >> end;
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	int cost[n + 1];
	int path[n + 1];
	fill_n(cost, n + 1, max);
	fill_n(path, n + 1, 0);
	cost[start] = 0;
	path[start] = 0;
	vector<int> init(3, 0); init[1] = start;
	pq.push(init);
	while (!pq.empty()) {
		vector<int> now = pq.top();
		pq.pop();
		int now_node = now[1];
		int now_cost = now[2];
		if (cost[now_node] < now_cost)
			continue;
		for (int i = 0; i < g[now_node].size(); i++) {
			int next_node = g[now_node][i].first;
			int next_cost = now_cost + g[now_node][i].second;
			if (cost[next_node] > next_cost){
				vector<int> next(3);
				cost[next_node] = next_cost;
				next[0] = start;
				next[1] = next_node;
				next[2] = next_cost;
				pq.push(next);
				path[next_node] = now_node; 
			}
		}
	}
	int totalCost = cost[end];
	stack<int> pathStack;
	int cur = end;
	pathStack.push(end);
	while (cur != start){
		pathStack.push(path[cur]);
		cur = path[cur];
	}
	cout << totalCost << "\n" << pathStack.size() << "\n";
	while (pathStack.size() != 0){
		cout << pathStack.top() << " ";
		pathStack.pop();
	}
    return (0);
}
