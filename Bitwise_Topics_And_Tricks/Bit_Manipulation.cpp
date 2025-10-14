#include<bits/stdc++.h>
using namespace std;
void check_Odd_Even(int n)
{
    if(n&1) cout << "Odd" << endl;
    else cout << "Even" << endl;
}
int getIthBit(int n,int i)
{
    int temp=1<<i;
    return (temp&n)>0?1:0;
}
void clearIthBit(int &n,int i)
{
    int temp=~(1<<i);
    n=n&temp;
}
void setIthBit(int &n, int i)
{
    int temp=1<<i;
    n=n|temp;
}
void updateIthBit(int &n, int i,int bit)
{
    clearIthBit(n,i);
    int temp=bit<<i;
    n=n|temp;
}
void clearLastIBits(int &n, int i)
{
    int temp=(-1<<i);
    n=n&temp;
}
void clearRangeOfBits(int &n, int i, int j)
{
    int a=(-1<<(j+1));
    int b=(1<<i)-1;
    int temp=a|b;
    n=n&temp;
}
void ReplaceBits(int &n, int i, int j, int m)
{
    clearRangeOfBits(n,i,j);
    int mask=m<<i;
    n|=mask;
}
void checkPowerOfTwo(int n)
{
    if(n&(n-1)==0) cout << "Power of 2" << endl;
    else cout << "Not power of 2" << endl;
}
int countBits(int n)
{
    int count=0;
    while(n>0)
    {
        int lastBit=n&1;
        count+=lastBit;
        n=n>>1;
    }
    return count;
}
int countBitsHack(int n)
{
    int count=0;
    while(n>0) n&=(n-1), count++;
    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << getIthBit(n,2) << endl;
    clearIthBit(n,2);
    cout << n << endl;
    setIthBit(n,2);
    cout << n << endl;
    updateIthBit(n,1,1);
    cout << n << endl;
    clearLastIBits(n,2);
    cout << n << endl;
    clearRangeOfBits(n,1,2);
    cout << n << endl;
    cout << countBitsHack(11) << endl;
}