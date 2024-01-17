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
	long minute = 1;
	long hourMinutes = 60 * minute;
	long dayMinutes = 24 * hourMinutes;
	long dayInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	long totalOneYearMinutes = 0;
	map<string, int> mon;
	mon.insert({"January" , 1}); mon.insert({"February" , 2}); mon.insert({"March" , 3}); mon.insert({"April" , 4});
	mon.insert({"May" , 5}); mon.insert({"June" , 6}); mon.insert({"July" , 7}); mon.insert({"August" , 8});
	mon.insert({"September" , 9}); mon.insert({"October" , 10}); mon.insert({"November" , 11}); mon.insert({"December" , 12});
	string buf;
	getline(cin, buf);
	stringstream ss(buf);
	string month, day, year, hour, minutes;
	getline(ss, month, ' ');
	getline(ss, day, ',');
	ss.ignore();
	getline(ss, year, ' ');
	getline(ss, hour, ':');
	getline(ss, minutes, '\n');
	int month_i = mon[month], day_i = stoi(day), year_i = stoi(year), hour_i = stoi(hour), minutes_i = stoi(minutes);
//	cout << month_i << "\n";
//	cout << day_i << "\n";
//	cout << year_i << "\n";
//	cout << hour_i << "\n";
//	cout << minutes_i << "\n";
	long pastMinutes = 0;
	bool leapYear = (year_i % 400 == 0 || (year_i % 4 == 0 && year_i % 100 != 0)) ? true : false;
	//past month
	if (leapYear){
//		cout << "leap Year!\n";
		dayInMonth[2] = 29;
	}
	for (int i = 0; i <= 12; i++) {
		totalOneYearMinutes += dayInMonth[i] * dayMinutes;
	}
	for (int i = 1; i < month_i; i++) {
		pastMinutes += dayInMonth[i] * dayMinutes;
	}
	//cur day
	pastMinutes += (day_i - 1) * dayMinutes;
	pastMinutes += hour_i * hourMinutes;
	pastMinutes += minutes_i;
	cout.precision(10);
	double sol = (double)(((double)pastMinutes / (double)totalOneYearMinutes) * 100);
	//cout << sol; //WRONG
	printf("%.20lf\n", sol); //AC
	return (0);
}
