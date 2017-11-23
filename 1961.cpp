#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
#define INF 999999

int main()
{
    ios_base::sync_with_stdio(false);
	int v, e, from, to, c,st,end;
	int cost[1001] = { 0 };
	vector<pair<int, int>> weight[1001];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		cost[i] = INF;

	for (int i = 1; i <= e; i++){
		cin >> from >> to >> c;
		weight[from].push_back(pair<int, int>(c, to));
	}
  cin >> st >> end;

	cost[st] = 0;
	q.push(pair<int, int>(0, st));

	while (q.size()){
		pair<int, int > current = q.top();
		q.pop();

		for (pair<int, int> next : weight[current.second])
			if (cost[next.second] > cost[current.second] + next.first){
				cost[next.second] = cost[current.second] + next.first;
				q.push(pair<int, int>(cost[next.second],next.second));
			}
	}

	cout << cost[end] << '\n';

	return 0;
}
