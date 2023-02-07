#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int pq[100001] = {};
int pq_size = 0;

void see()
{
	cout << "pq : ";
	for (int i = 0; i < pq_size; i++)
		cout << pq[i] << ", ";
	cout << "\n";
}


void swap(int src, int dest)
{
	int temp = pq[src];
	pq[src] = pq[dest];
	pq[dest] = temp;
}

void update()
{
	int pos = 0;
	int r = (pos * 2) + 2;
	int l = (pos * 2) + 1;
	while (pq[pos] && (pq[r] || pq[l]))
	{
		int m = pq[pos];
		int next_pos = pos;
//		cout << "pq[pos] ,pq[r] : " << m << ", " << pq[r] << "\n";
//		cout << "pq[pos] ,pq[l] : " << m << ", " << pq[l] << "\n";
		if (pq[r] && pq[r] < m)
		{
//			cout << "pq[pos] ,pq[r] : " << m << ", " << pq[r] << "\n";
			m = min(pq[pos], pq[r]);
			next_pos = r;
		}
		if (pq[l] && pq[l] < m)
		{
//			cout << "pq[pos] ,pq[l] : " << m << ", " << pq[l] << "\n";
			m = min(pq[pos], pq[l]);
			next_pos = l;
		}
		if (next_pos == pos || next_pos > 100000)
			break;
		int temp = pq[pos];
		pq[pos] = m;
		pq[next_pos] = temp;
		pos = next_pos;
		r = (pos * 2) + 2;
		l = (pos * 2) + 1;
	}
}
//array implement -> find empty index! that's all

void push(int val)
{
	int pos = pq_size;
	int parent = (pos - 1 ) / 2;
	pq[pos] = val;
	while (pos)
	{
		if (pq[pos] >= pq[parent])
			break;
		if (pq[pos] < pq[parent])
		{
			swap(pos, parent);
			pos = parent;
			parent = (pos - 1) / 2;
		}
	}
//	cout << "pushed " << val << "\n";
	pq_size++;
//	see();
}

void pop()
{
	int pos = 0;
	int r, l;
	int first_pri = pq[0];
	int last_pri = pq[pq_size - 1];
	pq[0] = last_pri;
	pq[pq_size - 1] = 0;
//	cout << "poping " << pq[0] << "\n";
	cout << first_pri << "\n";
	pq_size = (pq_size > 0) ?  pq_size - 1 : 0;
//	cout << "before updating\n";
//	see();
//	cout << "after updating\n";
	update();
//	see();
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << pq[i] << "\n";
//	}
	for (int i = 0; i < n; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 0)
		{
//			cout << "pop out!\n";
			pop();
		}
		else
		{
			push(cmd);
//			cout << "push " << cmd << "\n";
		}
	}
	return (0);
}

