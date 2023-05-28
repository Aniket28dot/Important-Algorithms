#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define nline '\n'

//Disjoint Set Union by Rank and Path Compression
void makeSet(vector<int> &parent){
    for(int i = 0; i < parent.size(); i++){
        parent[i] = i;
    }
}

int findParent(int node, vector<int>&parent){
    if(node == parent[node]) return node;
    
    //Below is the path compression step, basically we are storing the ultimate parent of a node.
    return parent[node] = findParent(parent[node], parent);
}

void UnionByRank(int v, int u, vector<int> &parent, vector<int> &rank){
    v = findParent(v, parent);
    u = findParent(u, parent);
    
    //below condition is when both nodes belong to the same component (i.e. have same parents) then there is no need to do a Union.
    if(u == v) reutrn;
    
    if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

//Initialize the size of every node as 1 because initially each node is a single component.
void UnionBySize(int v, int u, vector<int> &parent, vector<int> &rank){
    v = findParent(v, parent);
    u = findParent(u, parent);
    
    //below condition is when both nodes belong to the same component (i.e. have same parents) then there is no need to do a Union.
    if(u == v) return;
    
    if(size[v] < size[u]){
        parent[v] = u;
        size[u] += size[v];
    }
    else{
        parent[u] = v;
        size[v] += size[u];
    }
}

int main()
{
    int n; cin >> n;
    vector<int> parent(n), rank(n);
    
    makeSet(parent);
    int m; cin >> m;
    while(m--){
        int a, b; cin >> a >> b;
        UnionByRank(a, b, parent, rank);
    }
    
    //Check if 2 nodes belong to the same component or not.
    int u, v; cin >> u >> v;
    if(findParent(v, parent) == findParent(u, parent)){
        cout << "Belong to the same component" << endl;
    }
    else cout << "Do not belong to the same component";
}

//Possible test cases
//_______Test Case 1_________
// 7
// 6
// 0 1
// 1 2
// 3 4
// 5 6
// 4 5
// 2 6
// 0 6
