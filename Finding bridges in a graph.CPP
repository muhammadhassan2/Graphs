#include <bits/stdc++.h>
using namespace std;
int num[10005],low[10005],visited[10005],b;
vector<vector<int>> adj(10005);
int timer;
set<int>s;// to store the unique values of the articulation points
void dfs(int v, int p = -1) {
    visited[v] = true;
    num[v] = low[v] = timer++; // initialize the value of the low_link and the number of dfs
    int children=0; // count the number of nodes connected to this vertex
    for (int to : adj[v]) {
        if (to == p) { // check if the child node back to the parent node
        continue;}
        if (visited[to]) {
            low[v] = min(low[v], num[to]); //set the low_link values with the minimum number reachable
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > num[v] && p!=-1){
                    cout<<"Edge Found"<<endl;
            //check that there is no back edge at this node
            // if (p==-1) this mean that this node is the root of the graph
               s.insert(v);

            }
        }
    }

}
int main() {
    int n,e,c=0;
	cin >> n >> e;
	for (int i = 0; i < e; ++i) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
				adj[to].push_back(from);
	}
	for (int i = 1; i <= n; ++i)
		if (visited[i] == 0)
			dfs(i);

	return 0;
}
