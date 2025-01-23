#include<bits/stdc++.h>
using namespace std;

int vertices, edge, parent[100], rankk[100];
// Rank indicates depth of the tree


void makeSet()
{
    for(int i = 0; i<vertices; i++)
    {
        parent[i] = i; // nijei nijer parent
        rankk[i] = 0;
    }
}

int find_set(int x)
{
    if(parent[x] == x)   return x;

    else  find_set(parent[x]);
}

int union_sets(int a, int b)
{
    int u, v;

    u = find_set(a);
    v = find_set(b);

    if(u == v) return 0; // already in the same set

    // Not in the same set
    // Union by rank

    if(rankk[u] > rankk[v]) // r2 becomes a child of r1
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        if(rankk[u] == rankk[v])  rankk[v]++;
    }
    return 1;
}



int main()
{
    vertices = 10;
    edge = 7;

    makeSet();

    union_sets(0,1);
    union_sets(0,2);
    union_sets(3,4);
    union_sets(6,7);
    union_sets(6,8);
    union_sets(7,8);
    union_sets(7,9);

    cout << find_set(9) << endl;
    cout << find_set(8) << endl;
    cout << find_set(7) << endl;
    cout << find_set(6) << endl;

    cout << find_set(1) << endl;
    cout << find_set(2) << endl;
    cout << find_set(0) << endl;

    cout << find_set(5) << endl;

    cout << find_set(3) << endl;
    cout << find_set(4) << endl;

    return 0;
}
