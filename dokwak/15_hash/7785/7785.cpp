#include <functional>
#include <iterator>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;
//int	main(int argc, char **argv)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int n;
//	string name, log;
//	map <string, int, greater<string>> ent_log;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> name >> log;
////		cout << name << " " << log << "\n";
//		if (log == "enter")
//			ent_log[name] = 1;
//		else if (log == "leave")
//			ent_log[name] = 0;
//	}
//	for (map<string, int>::iterator iter = ent_log.begin(); iter != ent_log.end(); iter++)
//	{
//		if (iter->second == true)
//			cout << iter -> first << "\n";
//	}
//	return (0);
//}

/* version 2*/
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	set<string, greater<string>> ent;
	while (n--)
	{
		string name, log;
		cin >> name >> log;
		if (log == "enter")
			ent.insert(name);
		else
			ent.erase(name);
	}
	for (auto e : ent) cout << e << "\n";
}

