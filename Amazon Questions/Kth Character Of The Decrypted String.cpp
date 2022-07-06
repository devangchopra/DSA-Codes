#include <bits/stdc++.h>
using namespace std;

char kThCharaterOfDecryptedString(string s, long long k){
	//a2b3c12 : -> frequency -> string -> o/p : O(n) and O(n)
	//Logic based : Copmputation based on the lenghts of substrings

	//always use isalpha and isdigit

	long long n = s.size();
	long long i = 0;

	string temp = "";
	long long number = 0;

	while(i<n){

		temp="";
		number=0;


		//Char can be multiple
		while(i<n and isalpha(s[i])){
			temp += s[i];
			i++;
		}

		//Number can be of two - three digit as well
		while(i<n and isdigit(s[i])){
			number = number*10 + (s[i]-'0');
			i++;
		}

		//Logic
		if(k > temp.size() * number){
			k -= number * temp.size();
			//ans will not be in this substring
		}
		else{
			//Less
			long long len = temp.size();
			k = k%len;

			if(k==0){
				return temp[len-1];
			}
			else{
				return temp[k-1];
			}
			break;
		}
	}

	return '\0';
}




//This logic will only work on strings having single digit numbers

/*char kThCharaterOfDecryptedString(string s, long long k){
    //  Write your code here.
    map<int,pair<string,int>>m;

    string temp="";
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            pair<string,int>p;
            p.first = temp;
            p.second = s[i]-'0';
            m.insert({i,p});
            temp = "";
        }
        else{
            temp.push_back(s[i]);
        }
    }

    string ans="";

    for(auto& i:m){
        while(i.second.second--){
            ans += i.second.first;
        }
    }

    k++;

    for(auto& i:ans){
        if(k==0){
            return i;                        
        }
        k--;
    }   

    return '\0'; 
}*/
