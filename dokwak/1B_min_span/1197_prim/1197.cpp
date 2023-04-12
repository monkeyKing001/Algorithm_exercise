#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

int v, e;
int v1, v2, cost;
int total_edge, total_cost;
int mst[10005];
vector <pair <int, int>>adj_list[10005];
priority_queue
	<
	tuple <int, int, int>, //entry type
	vector<tuple <int, int, int>>, //implement type
	greater<tuple <int, int ,int>> //sorting
	> pq;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; ++i)
	{
		cin >> v1 >> v2 >> cost;
		adj_list[v1].push_back(make_pair(v2, cost));
		adj_list[v2].push_back(make_pair(v1, cost));
		//pq.push(make_tuple(cost, v1, v2));
	}
	int current_v, next_v, cost;
	current_v = 1;
	next_v = adj_list[1][0].first;
	cost = adj_list[1][0].second;
	//find min
	for (int i = 0; i < adj_list[current_v].size(); ++i) {
		int target_v, target_cost;
		target_v = adj_list[current_v][i].first;
		target_cost = adj_list[current_v][i].second;
//		cout << "pushing in pq (cost : "
//			<< target_cost
//			<< ", from v : "
//			<< current_v
//			<< " to "
//			<< adj_list[current_v][i].first
//			<< ")\n";
		pq.push(make_tuple(target_cost, current_v, target_v));
	}
	pq.push(make_tuple(cost, current_v, next_v));
	mst[current_v] = true;
	while (!pq.empty() && total_edge != v - 1)
	{
		tie(cost, current_v, next_v) = pq.top();
//		cout << "current, next, cost : "
//			<< current_v
//			<< ", "
//			<< next_v
//			<< ", "
//			<< cost
//			<< "\n";
		mst[current_v] = true;
		pq.pop();
		if (mst[next_v])
		{
//			cout << next_v << " is already in mst so pass\n";
			continue ;
		}
//		cout << "visiting " << next_v << "\n";
		mst[next_v] = true;
		total_cost += cost;
		total_edge++;
		for (int i = 0; i < adj_list[next_v].size(); ++i)
		{
			int target_v, target_cost;
			target_v = adj_list[next_v][i].first;
			target_cost = adj_list[next_v][i].second;
//			cout << "pushing in pq (cost : "
//				<< target_cost
//				<< ", from v : "
//				<< next_v
//				<< " to "
//				<< adj_list[next_v][i].first
//				<< ")\n";
			pq.push(make_tuple(target_cost, next_v, target_v));
		}
	}
//	for (int i = 1; i <= v; ++i) {
//		cout << i <<"'s group is " << group[i] << "\n";
//	}
	cout << total_cost;
	return (0);
}
