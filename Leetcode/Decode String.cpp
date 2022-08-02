class Solution {
public:
    int numDecodings(string s) 
    {

    	int n = s.size();

    	int ans = n;

    	if(s.find('*')==-1)
    	{
            if(n!=1)
            {
                for(int i=0;i<n-1;i++)
                {
                    int d1=s[i]-48;
                    int d2=s[i+1]-48;
                    if(calc*10+d2<=26 and calc*10+d2>=1)
                    {
                        ans++;
                    }
                }
            }

        }
            
    		
    	else
    	{
    		//I need to consider all
    		int index = s.find('*');
    		int temp=1;
            int rep = 49;
            if(n!=1)
            {
                while(temp<=9)
                {
                    s[index]=char(rep);
                    rep++;                              
                    for(int i=0;i<n-1;i++)
                    {
                        int d1=s[i]-48;
                        int d2=s[i+1]-48;
                        if(calc*10+d2<=26 and calc*10+d2>=1)
                        {
                            ans++;
                        }
                    }
                    temp++;
                
                }
            }
            return ans;
        }
    		
    }	

    
};