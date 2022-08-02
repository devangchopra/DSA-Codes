--------------------------------------------------------
Accepted Solution
//Smallest matrix formed will contain maximum number
//So task is to find min matrix size
//Therefore scan in ops and find min


class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
			int x = m;   
		int y = n;
		for (auto i : ops)
		{
			x = min(x, i[0]);
			y = min(y, i[1]);
		}
		return x * y;
	}
};

------------------------------------------------------------------
TLE O(n*n)

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {

		map<pair<int, int>, int> index;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				index.insert({{i, j}, 0});
			}
		}

		pair<int, int> p = {0, 0};
		for (auto v : ops)
		{
			p = {v[0] - 1, v[1] - 1};


			auto it = index.begin();
			while (it != index.end())
			{
				if (it->first.first <= p.first and it->first.second <= p.second)
				{
					it->second++;
				}
				it++;
			}
		}

		multimap<int, pair<int, int>, greater<int>> revIndex;

		for (auto i : index)
		{
			revIndex.insert({i.second, {i.first.first, i.first.second}});
		}

		int ans = 0;
		int count = 1;

		auto i = revIndex.begin();
		ans = i->first;

		if(ans==0)
			return (m*n);
		else
		{
			for(auto i:revIndex)
			{
				if(i.first==ans)
					count++;
			}
		}

		return count;
	}
};



-------------------------------------------------
Rather than using it you can use this

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {

		map<pair<int, int>, int> index;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				index.insert({{i, j}, 0});
			}
		}
        
        for(auto& i:index)
        {
            i.second++;
        }

        for(auto i:index)
        {
            cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
        }
        return 0;
	}
};

--------------------------------------------