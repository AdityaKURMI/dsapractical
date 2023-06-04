//TOPOLOGICAL
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cout << "Enter the Number of Vertices and Edges :" << endl;
	cin >> n >> m;
	vector<int> graph[n + 1];
	queue<int> q;
	int arr[n + 1] = {0};
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cout << "E1-E2 : ";
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
	}

	for (int i = 0; i < m; i++)
	{
		for (auto child : graph[i])
		{
			arr[child]++;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == 0)
		{
			q.push(i);
		}
	}
	// cout << q.size() << endl;

	while (q.size())
	{
		int x = q.front();
		for (auto child : graph[x])
		{
			arr[child]--;
			if (arr[child] == 0)
				q.push(child);
		}
		q.pop();
		cout << x << " ";
	}
}
