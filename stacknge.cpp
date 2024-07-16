#include <bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> &arr)
{
    stack<int> st;
    vector<int> output(arr.size(), -1);
    st.push(0);

    for (int i = 0; i < arr.size(); ++i)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return output;
}

int main()
{

    vector<int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(1);

    vector<int> ans = nge(a);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }

    return 0;
}