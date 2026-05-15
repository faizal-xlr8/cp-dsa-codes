#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {

    int t;
    cin >> t;
    while (t--)
    {
        
        ll l, a, b;
        cin >> l >> a >> b;
        vector <ll> nums;
        for (int i = 0; i < l; ++i)
        nums.push_back(i);
        ll maxVal = -1;
        for (int i = 0; i < l; ++i)
        {
            maxVal = max(maxVal, nums[(a  + b) % l] );
            a = a + b;
        }
       cout << maxVal << endl;

    }
}