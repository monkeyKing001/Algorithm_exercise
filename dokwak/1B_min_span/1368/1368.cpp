#include <tuple>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <queue>

using namespace std;
int p[330];
//vector <tuple <int, int, int>> edge;
int well[330];
int e, v;
//pair<dest, cost>
vector <pair<int, int>> adj_list[330];
priority_queue <
	tuple<int, int, int>, 
	vector<tuple <int, int, int>>,
	greater<tuple<int, int, int>>
>	pq;
vector <int> root;
int total_visited, total_cost;
int visited[330];

int find(int v1)
{
	if (!p[v1])
		return (v1);
	else
		p[v1] = find(p[v1]);
	return (p[v1]);
}

int same_group(int v1, int v2)
{
	int v1_g = find(v1);
	int v2_g = find(v2);
	if (v1_g == v2_g)
		return (1);
	if (v2_g < v1_g)
		swap(v1, v2);
	p[v2] = v1;
	return (0);
}

bool comp_cost(tuple<int, int, int>e_1, tuple<int, int, int>e_2)
{
	return(get<2>(e_1) < get<2>(e_2));
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v;
	for (int i = 1; i <= v; i++)
	{
		int v_w;
		cin >> v_w;
		well[i] = v_w;
	}
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			int cost;
			cin >> cost;
			if (i == j)
				pq.push(make_tuple(well[i], i, j));
//			edge.push_back(make_tuple(i, j, cost));
			else
				adj_list[i].push_back(make_pair(j, cost));
		}
	}
//	sort(edge.begin(), edge.begin() + e);
//	welling
//	for (int i = 1; i <= v; i++)
//	{
//		int vi, vj, channel_cost;
//		vi = i;
//		channel_cost = INT_MAX;
//		for (int j = 0; j < adj_list[i].size(); j++)
//		{
//			vj = adj_list[i][j].first;
//			channel_cost = min(channel_cost, adj_list[i][j].second);
//		}
//		if (channel_cost >= well[vi])
//		{
//			root.push_back(vi);
//			visited[vi] = true;
//			total_visited++;
//			total_cost+= well[vi];
////			cout << "welling " << vi << "\n";
////			cout << "welling cost : " << well[vi] << "\n";
//		}
//	}
	//pq push
	int current_v, next_v, cost;
	while (!pq.empty() || total_visited != v)
	{
		tie(cost, current_v, next_v) = pq.top();
		pq.pop();
		if (current_v == next_v && !visited[current_v])
		{
//			cout << "welling "
//				<< current_v 
//				<< " cost : "
//				<< cost
//				<< "\n";
			total_cost += cost;
			visited[current_v] = true;
			total_visited++;
		}
		else if (current_v != next_v && !visited[next_v])
		{
			total_visited++;
			visited[next_v] = true;
//			cout << next_v <<" has been visited with cost " << cost << "\n";
			total_cost += cost;
		}
		else {
			continue;
		}
		for (int j = 0; j < adj_list[next_v].size(); j++)
		{
			int next_next_v, next_cost;
			next_next_v = adj_list[next_v][j].first;
			next_cost = adj_list[next_v][j].second;
//			cout <<"pushing " 
//				<< next_v 
//				<< " - " 
//				<< next_next_v 
//				<< " with cost " 
//				<< next_cost
//				<<"\n";
			pq.push(make_tuple(next_cost, next_v, next_next_v));
		}
	}
	cout << total_cost;
	return (0);
}
