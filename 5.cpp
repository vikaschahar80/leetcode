#include <bits/stdc++.h> 
void reverse(string &strng ,int i,int j){
	if(i>j)
		return ;
	swap(strng[i],strng[j]);
	i++;
	j--;
	reverse(strng,i,j);
}
string reverseString(string str)
{
	reverse(str,0,str.length()-1);
	return str;
}
