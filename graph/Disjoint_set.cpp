#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
private:
    vector<int> rank, parents;

public:
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parents.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parents[i] = i;
        }
    }

    int findUpar(int node) // time complexity log(n) // path compression
    {
        if (node == parents[node])
        {
            return node;
        }
        return parents[node] = findUpar(parents[node]);
    }

    void findUnion(int u, int v)
    {
        // Find ultimate parents
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);

        if (ult_u == ult_v)
            return;

        if (rank[ult_u] < rank[ult_v])
        {
            parents[ult_u] = ult_v;
        }
        else if (rank[ult_u] > rank[ult_v])
        {
            parents[ult_v] = ult_u;
        }
        else
        {
            parents[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

int main()
{
    Disjoint ds(7); // here we have initialized

    if (ds.findUpar(3) == ds.findUpar(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not same\n";
    }

    ds.findUnion(3, 7);

    if (ds.findUpar(3) == ds.findUpar(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not same\n";
    }

    return 0;
}
