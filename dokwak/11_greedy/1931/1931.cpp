#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#define START first
#define END second

using namespace std;
int n;
bool comp(pair <int, int> table1, pair <int, int> table2)
{
	if (table1.END == table2.END)
		return (table1.START < table2.START);
	return (table1.END < table2.END);
}
pair <int, int> find_min_time(vector <pair<int, int> > time_table, int start_time)
{
	return (time_table[0]);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <pair <int, int> > time_table;
	int current_time = 0;
	long long time_sum;
	int meeting_num = 0;
	for (int i = 0; i < n; ++i)
	{
		int start, end;
		cin >> start >> end;
		time_table.push_back(make_pair(start, end));
	}
	//sort time_table
	sort(time_table.begin(), time_table.end(), comp);
//	for (int i = 0; i < n; ++i)
//	{
//		cout << "time_table[" << i <<"]: "<<time_table[i].START << " ~ " << time_table[i].END << endl;
//	}
	for (int i = 0; i < n; ++i) 
	{
		if (current_time <= time_table[i].START)
		{
			meeting_num++;
			current_time = time_table[i].END;
//			cout << "adding time_table[" << i <<"]: "<<time_table[i].START << " ~ " << time_table[i].END << endl;
		}
	}
	cout << meeting_num;
	return (0);
}
