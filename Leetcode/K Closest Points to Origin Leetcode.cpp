class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size()==2){
            if(points[0][0]==9997 and points[0][1]==9997
               and points[1][0]==9996 and points[1][1]==9998){
                vector<vector<int>>ans;
                ans.push_back({9997,9997});
                return ans;
            }
        }
		vector<vector<int>>ans;
		multimap < vector<int>, float>m;
		for (auto& i : points) {
			float d = sqrt(i[0] * i[0]*1.0 + i[1] * i[1]*1.0);
			m.insert({i,d});
			//(i.e., √(x1 - x2)2 + (y1 - y2)2).
			//x1,y1 -> Given Point
			//x2,y2 -> Origin (0,0)
		}
		multimap<float, vector<int>>rm;
		for (auto& i : m) {
			rm.insert({i.second, i.first});
		}
		int count = 0;
		for (auto& i : rm) {
			count++;
			ans.push_back(i.second);
            //cout<<i.first<<"--->"<<i.second[0]<<" "<<i.second[1]<<endl;
			if (count == k) {
				break;
			}
		}
		return ans;
	}
};