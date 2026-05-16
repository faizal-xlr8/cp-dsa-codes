#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        string s;

        cin >> n >> s;

        bool ok;
        if (n % 2 == 0)
            ok = true;
        else
            ok = (s[0] != 'b');

        int start = n % 2;

        for (int i = start; i < n - 1; i += 2) {

            if (!(s[i] == '?' || s[i] != s[i + 1])) {
                ok = false;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}