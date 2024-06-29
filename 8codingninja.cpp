#include <bits/stdc++.h> 
void solve(string str,string output,int i,vector<string> &ans){
	if(i>=str.length()){
		if(output.length()>0){
			ans.push_back(output);
		}
		return;
	}
	solve(str,output,i+1,ans);

	output.push_back(str[i]);
	solve(str,output,i+1,ans);
}
vector<string> subsequences(string str){
	vector<string> ans;
	string output = "";
	int index = 0;
	solve(str,output,index,ans);
	return ans;
	
}
