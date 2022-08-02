class MyCalendar {
public:
    unordered_map<int, int>m;
    MyCalendar() {
 
    }    
    bool book(int start, int end) {
        for(auto p:m)
        {
            if(!(start>=p.second or p.first>=end))
            {
                return false;
            }
        }
        m[start]=end;
        return true;
        
    }
};

//https://leetcode.com/discuss/explore/june-leetcoding-challenge-2021/1262658/My-Calendar-I-or-Short-and-Easy-Solution-w-Explanation-and-Diagrams-or-O(N)-and-O(LogN)-Solutions

/*
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> check(100);
        for(auto it:ranges)
        {
            for(int i=it[0];i<=it[1];i++)
                check[i]=true;
        }
        
        for(int i=left;i<=right;i++)
            if(!check[i])
                return false;
        return true;
    }
}
*/