class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int>m; 
    MapSum() {}    
    void insert(string key, int val) {
        m[key]=val;
    }    
    int sum(string prefix) {
        int sum = 0;
        int i;
        for(auto p:m)
        {
            string temp = p.first;
            bool x = true;
            for(i=0;i<temp.size();i++)
            {
                if(i<=prefix.size()-1)
                {
                    if(temp[i]!=prefix[i])
                    {
                        x = false;
                        break;
                    }
                }
                else
                    break;                
            }
            if(x and i==prefix.size())
            {
                sum+=p.second;
            }
        }

        return sum;
    }
};
