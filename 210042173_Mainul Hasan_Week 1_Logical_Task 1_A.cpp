#include <bits/stdc++.h>
using namespace std;
vector<int> v[2000]; // this code can handle maximum 2000 nodes
void lessgoo(int visited[])
{
    queue<int> q;
    q.push(0); // start from 0
    while (!q.empty())
    {
        int node = q.front(); // first one from the serial
        for (int i = 0; i < v[node].size(); i++)
        {
            if (visited[v[node][i]]) // already visited
            {
                continue;
            }

            visited[v[node][i]] = 1;
            q.push(v[node][i]);
        }
        q.pop(); // visit complete
    }
}
int main()
{
    int n, a, b;
    int num = -1; // num of nodes
    cin >> n;     // num of edges
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        num = max(max(a, b)+1, num); // analyzing num of nodes. In ques, num=7.
    }
    int visited[num] = {1, 0};
    lessgoo(visited);
    sort(visited, visited + num);
    visited[0] == 0 ? cout << "false" : cout << "true";
}
