#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double
typedef long double ld;
const ld eps=1e-12;
struct point{
    long double x,y;
    point(){x=y=0;}
    point(ld _x, ld _y):x(_x),y(_y){}
};
inline point operator+(const point &a, const point &b){ return {a.x + b.x, a.y + b.y}; }
inline point operator-(const point &a, const point &b){ return {a.x - b.x, a.y - b.y}; }
inline point operator*(const point &a, ld k){ return {a.x * k, a.y * k}; }
inline point operator/(const point &a, ld k){ return {a.x / k, a.y / k}; }
inline bool operator==(const point &a,const point &b){ return (fabsl(a.x-b.x)<=eps && fabsl(a.y-b.y)<=eps); }

ld dot(point a, point b){ return a.x*b.x+a.y*b.y;}
ld cross(point a, point b){return a.x*b.y-a.y*b.x;}
ld len2(point a){return dot(a,a);}
ld len(point a){return sqrtl(len2(a));}
ld points_dist(point a, point b){return len(b-a);}
ld point_to_line(point p, point l1, point l2){ return ((len(l2-l1)<=eps)?points_dist(p,l1):fabsl(cross(l2-l1,p-l1))/len(l2-l1));}
ld point_to_line(point p, ld A, ld B, ld C){return fabsl(A*p.x+B*p.y+C)/hypotl(A,B);}
ld point_to_ray(point p, point rst, point rmd)
{
    if(dot(rmd-rst,p-rst)<=eps) return points_dist(p,rst);
    return point_to_line(p,rst,rmd);
}
ld point_to_segment(point p, point sg1, point sg2)
{
    if(dot(sg2-sg1,p-sg1)<=eps) return points_dist(p,sg1);
    return point_to_ray(p,sg2,sg1);
}
point intersect_point(ld A1, ld B1, ld C1, ld A2, ld B2, ld C2)
{
    ld D=A1*B2-A2*B1;
    ld x=(B1*C2-B2*C1)/D;
    ld y=(C1*A2-A1*C2)/D;
    return {x,y};
}
bool lie_on_the_line(point p, point l1, point l2)
{
    return fabsl(cross(l2-l1,p-l1))<=eps;
}
bool lie_on_the_ray(point p, point rst, point rmd)
{
    point v = rmd - rst;
    point w = p - rst;
    if (fabsl(cross(v, w)) > eps * len(v) * max(1.0L, len(w))) return false;
    if (dot(v, w) < -eps * len(v) * len(v)) return false;
    return true;
}

point intersect_point(point l1, point l2, point l3, point l4)
{
    ld A1=l1.y-l2.y, B1=l2.x-l1.x, C1=l1.x*l2.y-l1.y*l2.x;
    ld A2=l3.y-l4.y, B2=l4.x-l3.x, C2=l3.x*l4.y-l3.y*l4.x;
    return intersect_point(A1, B1, C1, A2, B2, C2);
}
bool check_parallel(point l1, point l2, point l3, point l4)
{
    point f=l2-l1, s=l4-l3;
    ld nf=len(f), ns=len(s);
    if(fabsl(f.x*s.y-f.y*s.x)<=eps*nf*ns) return true;
    return false;
}
signed main()
{
    fast
    
    return 0;
}