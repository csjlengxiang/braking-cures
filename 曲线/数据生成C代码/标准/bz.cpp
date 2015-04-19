#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;
#define sz 300005
#define inf 0x7fffffff
#define yl 1.609344
#define myc 3.2808399
vector <pair<double,double> > p, q;
const double D = 0.1;
const double T = 1;
void stepC(double& d, double& v, double& t, double& a)
{
    d = v * t;
    for (double i=0;i<d;i+=D)
        p.pb(mp(i,v));
    p.pb(mp(d,v));
    q.pb(mp(d,v));
    //cout << v * 3.6 << endl;
    cout << "C:" << (d) * myc << endl;
    //cout << p.size() << endl;
}
void stepD(double& d, double& v, double& t, double& a)
{
    double nextd = d + (v + v + a * t) / 2 * t; // 1/2 * a * t^2 + v * t
    double pred = 0;
    if(p.size() != 0)
        pred = p[p.size()-1].F + D;
    cout << p[p.size() - 1].F <<endl;
    for (double i=pred;i<nextd;i+=D)
    {
        double dis = i - d;
        double nv = sqrt(2*a*dis + v*v);
        p.pb(mp(i,nv));
    }
    v = v + a * t;
    p.pb(mp(nextd,v));
    q.pb(mp(nextd,v));
    cout << "D:" << (nextd - d) * myc << endl;
    d = nextd;
    //cout << p.size() << endl;
}
//此处只分成一段，我原本是分成好多段的
void stepE(double& d, double& v, double& t, double& a)
{
    // a->0 use 1, 分成1/T段，每一段 的加速度为 /2
    double nextd = d;
    double tempv = v;
    double tempa = a;
    for (double i=T;i<=t+T/2;i+=T)
    {
        double pa = (a + tempa - i/t*tempa) / 2; //该段平均加速度
        a = tempa - i/t*tempa; //段尾加速度
        nextd += (v + v + pa * T) / 2 * T;
        //cout << i << ": " << pa << endl;
        v = v + pa * T;
        p.pb(mp(nextd, v));
    }
    cout << "E:" << (nextd - d) * myc << endl;
    d = nextd;

    //p.pb(mp(nextd,v));
    q.pb(mp(nextd,v));

    //cout << tempv + tempa / 2 * t << " " << v <<endl;
    //cout << p.size() << endl;
}
void stepF(double& d, double& v, double& t, double& a)
{
    double nextd = d + (v + v + a * t) / 2 * t; // 1/2 * a * t^2 + v * t    double pred = p[p.size()-1].F + D;
    for (double i=d+D;i<nextd;i+=D)
    {
        double dis = i - d;
        double nv = sqrt(2*a*dis + v*v);
        p.pb(mp(i,nv));
    }
    v = v + a * t;
    p.pb(mp(nextd,v));
    q.pb(mp(nextd,v));
    cout << "F:" << (nextd - d) * myc << endl;
    d = nextd;
    //cout << p.size() << endl;
}
void stepG(double& d, double& v, double& t, double& a)
{
    double nextd = d + (v + v + a * t) / 2 * t; // 1/2 * a * t^2 + v * t    double pred = p[p.size()-1].F + D;
    for (double i=d+D;i<nextd;i+=D)
    {
        double dis = i - d;
        double nv = sqrt(2*a*dis + v*v);
        p.pb(mp(i,nv));
    }
    v = v + a * t;
    p.pb(mp(nextd,v));
    q.pb(mp(nextd,v));
    cout << "G:" << (nextd - d) * myc << endl;
    d = nextd;
    //cout << p.size() << endl;
}
void stepHI(double& d, double& v, double& t, double& a)
{
    t = -v / a;
    double nextd = d + (v + v + a * t) / 2 * t; // 1/2 * a * t^2 + v * t    double pred = p[p.size()-1].F + D;
    for (double i=d+D;i<=nextd;i+=D)
    {
        double dis = i - d;
        double nv = sqrt(2*a*dis + v*v);
        p.pb(mp(i,nv));
    }
    p.pb(mp(nextd, 0));
    q.pb(mp(nextd, 0));

    v = v - a * t;

    //cout << nextd <<endl;
    cout << "HI:" << (nextd - d) * myc << endl;
    d = nextd;
    //cout << d * myc << endl;
    //cout << p.size() << endl;
}
void stepJ(double &d)
{
    double nextd = d + 15 / myc;
    for (double i=d+D;i<nextd;i+=D)
    {
        p.pb(mp(i,0));
    }
    p.pb(mp(nextd,0));
    q.pb(mp(nextd, 0));
    cout << "J:" << (nextd - d) * myc << endl;
    d = nextd;
    //cout << p.size() << endl;
}
int main()
{
    p.clear();
    q.clear();
    double d,v,t,a;
    d = 0, v = 400 / 3.6, t = 8, a = 0;
    stepC(d, v, t, a);
    //cout << "C:" << d << " " << v << " " << t << " " << a << endl;
    t = 1, a = 2 * yl / 3.6;//cout << a + v << endl;
    stepD(d, v, t, a);
    //cout << "D:" << d << " " << v << " " << t << " " << a << endl;

    t = 1, a = 2 * yl / 3.6;
    stepE(d, v, t, a);
    //cout << "E:" << d << " " << v << " " << t << " " << a << endl;
    t = 1, a = 0;
    stepF(d, v, t, a);
    //cout << "F:" << d << " " << v << " " << t << " " << a << endl;
    t = 1, a = -1.0 / 2 / 0.8333 / 2; //制动减速度一半, a 单位为(英里/小时^2)
    a = a * yl / 3.6 * 5280 / 3600;
    stepG(d, v, t, a);
    //cout << "G:" << d << " " << v << " " << t << " " << a << endl;
    a = -1.0 / 2 / 0.8333;
    a = a * yl / 3.6 / 3600 * 5280;
    //cout << a << endl;
    stepHI(d, v, t, a);
    //cout << "HI:" << d << " " << v << " " << t << " " << a << endl;

    stepJ(d);

    //q为拐点位置
    for (int i=0;i<q.size();i++)
        cout << q[i].F << " " << q[i].S * 3600 / 1000 << endl;

    cout << "sum:" << d * myc << endl;
    int n;
    cin>>n;

    freopen("out.txt","w",stdout);

    for (int i=0;i<p.size();i++)
        cout << p[i].F << " " << p[i].S * 3600 / 1000 << endl;

}
