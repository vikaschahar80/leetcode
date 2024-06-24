class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<pair<string,string>> v(n);
        for(int i=0;i<n;++i)
        {
            string a=strs[i];
            sort(a.begin(),a.end());
            v[i]={a,strs[i]};
        }
        sort(v.begin(),v.end());
        vector<vector<string>> ans;
        ans.push_back({v[0].second});
        for(int i=1;i<n;++i)
        {
            if(v[i].first==v[i-1].first)
                ans[ans.size()-1].push_back(v[i].second);
            else
                ans.push_back({v[i].second});
        }
        return ans;
    }
};
