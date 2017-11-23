#include <iostream>
#include <algorithm>
using namespace std;

struct cost
{
	int a, b;
	int c;
	bool operator<(struct cost k)
	{
		return k.c > c;
	}
}cost[100001];

int parent[10001];
long long int sum;

int set_find(int);
void set_union(int, int,int);

int main()
{
    ios_base::sync_with_stdio(false);
    
	long long int v, e;

	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 1; i <= e; i++)
        cin >> cost[i].a >> cost[i].b >> cost[i].c;

	sort(cost + 1, cost + 1 + e);

	for (int i = 1; i <= e; i++)
		set_union(cost[i].a, cost[i].b,i);

	cout << sum << endl;

	return 0;
}

int set_find(int x)
{
	if (parent[x] != x)
		parent[x] = set_find(parent[x]);
	return parent[x];
}

void set_union(int x, int y, int i)
{
	int xroot, yroot;
	xroot = set_find(x);
	yroot = set_find(y);

	if (xroot == yroot)
		return;
	else
	{
		parent[yroot] = xroot;
		sum += cost[i].c;
	}

}