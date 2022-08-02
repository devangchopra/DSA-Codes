class Solution {
public:

    int find(int i, int* parent)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i], parent);
    }

    void unite(int x, int y, int* parent, int* rank)
    {
        int s1 = find(x, parent);
        int s2 = find(y, parent);

        if (s1 != s2)
        {
            if (rank[s1] > rank[s2])
                swap(s1, s2);
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }

        return;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        //Alice and Bob
        int* parentA;
        int* parentB;

        int* rankA;
        int* rankB;

        int ans = 0;

        parentA = new int[n + 1];
        parentB = new int[n + 1];
        rankB = new int[n + 1];
        rankA = new int[n + 1];

        

        for (int i = 0; i < n + 1; i++)
        {
            parentA[i] = -1;
            parentB[i] = -1;
            rankA[i] = 1;
            rankB[i] = 1;
        }

        vector<pair<int, int>> v[3];

        for (auto i : edges)
        {
            int x = i[1];
            int y = i[2];

            int pos = i[0];
            pos--;

            v[pos].push_back({x, y});
        }

        //Start from maximum
        //Both can travel
        for (auto i : v[2])
        {
            int s1 = find(i.first, parentA);
            int s2 = find(i.second, parentA);

            if (s1 == s2)
            {
                ans++;
                continue;
            }

            if (s1 != s2)
            {
                unite(s1, s2, parentA, rankA);
                unite(s1, s2, parentB, rankB);
            }
        }

        for (auto i : v[0])
        {
            int s1 = find(i.first, parentA);
            int s2 = find(i.second, parentA);

            if (s1 == s2)
            {
                ans++;
                continue;
            }

            if (s1 != s2)
            {
                unite(s1, s2, parentA, rankA);
            }
        }

        for (auto i : v[1])
        {
            int s1 = find(i.first, parentB);
            int s2 = find(i.second, parentB);

            if (s1 == s2)
            {
                ans++;
                continue;
            }

            if (s1 != s2)
            {
                unite(s1, s2, parentB, rankB);
            }
        }

        int s1 = find(1, parentA);
        int s2 = find(1, parentB);

        if (rankA[s1] == n and rankB[s2] == n)
        {
            return ans;
        }

        return -1;

    }
};






-------------------------------
Udemy P31 

#include<bits/stdc++.h>
using namespace std;

int find(int i, int* parent)
{
    if (parent[i] == -1)
        return i;

    return parent[i] = find(parent[i], parent);
}

void unite(int x, int y, int* parent, int* rank)
{
    int s1 = find(x, parent);
    int s2 = find(y, parent);

    if (s1 != s2)
    {
        if (rank[s1] > rank[s2])
            swap(s1, s2);
        parent[s1] = s2;
        rank[s2] += rank[s1];
    }

    return;
}

int maxNumEdgesToRemove(int n, vector<vector<int>> edges) {
    int* parentA;
    int* parentB;

    int* rankA;
    int* rankB;

    int ans = 0;

    parentA = new int[n + 1];
    parentB = new int[n + 1];
    rankB = new int[n + 1];
    rankA = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        parentA[i] = -1;
        parentB[i] = -1;
        rankA[i] = 1;
        rankB[i] = 1;
    }

    vector<pair<int, int>> v[3];

    for (auto i : edges)
    {
        int x = i[1];
        int y = i[2];

        int pos = i[0];
        pos--;

        v[pos].push_back({x, y});
    }

    //Start from maximum
    //Both can travel
    for (auto i : v[2])
    {
        int s1 = find(i.first, parentA);
        int s2 = find(i.second, parentA);

        if (s1 == s2)
        {
            ans++;
            continue;
        }

        if (s1 != s2)
        {
            unite(s1, s2, parentA, rankA);
            unite(s1, s2, parentB, rankB);
        }
    }

    for (auto i : v[0])
    {
        int s1 = find(i.first, parentA);
        int s2 = find(i.second, parentA);

        if (s1 == s2)
        {
            ans++;
            continue;
        }

        if (s1 != s2)
        {
            unite(s1, s2, parentA, rankA);
        }
    }

    for (auto i : v[1])
    {
        int s1 = find(i.first, parentB);
        int s2 = find(i.second, parentB);

        if (s1 == s2)
        {
            ans++;
            continue;
        }

        if (s1 != s2)
        {
            unite(s1, s2, parentB, rankB);
        }
    }

    int s1 = find(1, parentA);
    int s2 = find(1, parentB);

    if (rankA[s1] == n and rankB[s2] == n)
    {
        return ans;
    }

    return -1;



}