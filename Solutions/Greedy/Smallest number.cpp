	if (s > 9*m or s==0)
	{
		return "-1";
	}
	int res[m];
	s -= 1;
	for (int i=m-1; i>0; i--)
	{
		if (s > 9)
		{
			res[i] = 9;
			s -= 9;
		}
		else
		{
			res[i] = s;
			s = 0;
		}
	}
	res[0] = s + 1; 
	string s="";
	for(int i=0;i<m;i++)
	{
		s.push_back(res[i]+'0');
	}
