#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;
    while (n > 0){
        string s = "";
        int temp = n;
        while (temp > 0)
        {
            s += (temp % 10) + '0';
            temp /= 10;
        }
        sort(s.rbegin(), s.rend());
        int curr = s[0] - '0';
        n -= curr;
        count++;
    }
    cout << count << endl;
    return 0;
}