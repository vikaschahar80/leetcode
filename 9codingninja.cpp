#include<algorithm>
void solve(string str,int i,vector<string> &ans){
    if(i>=str.size()){
        ans.push_back(str);
        return;
    }
    for(int j= i;j<str.size();j++){
        swap(str[i],str[j]);
        solve(str,i+1,ans);

        swap(str[i],str[j]);
    }
}
vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    int index = 0;
    solve(str,index,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
