#include<bits/stdc++.h>
using namespace std;

void permutationString(string &str,int index)
{
    if(index>=str.length())
    {
        cout<<str<<" ";
        return;
    }
    for(int j=index;j<str.length();j++)
    {
        swap(str[index],str[j]);
        permutationString(str,index+1);
        swap(str[index],str[j]);

    }
}

int main()
{
    string str="abc";
    int index=0;
    permutationString(str,index);

    return 0;
}