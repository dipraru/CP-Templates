#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double
int cs;
void grayCode(int n, vector<int> &cd)
{
    if(n==0) return;
    for(int i=cd.size();i>0;i--) cd.push_back(cd[i-1]|(1<<(n-1)));
    if(cd.empty()) cd.insert(cd.begin(),{0,(1<<(n-1))});
    grayCode(n-1,cd);
}
signed main()
{
    fast
    vector<int> gray_codes;
    grayCode(5,gray_codes);
    return 0;
}