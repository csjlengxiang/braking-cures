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
#define D 0.05
vector <pair<double,double> > p,ret;

double f(double &d, double v1, double v2, double a)
{
    v1 = v1 / 3.6;
    v2 = v2 / 3.6;
    double nextd = d + (v1*v1-v2*v2)/2/a;
    int pred = 0;
    if(p.size()!=0)
        pred = p[p.size()-1].F + D;

    for (double i=pred;i<nextd;i+=D)
    {
        double dis = i - d;

        double nv = sqrt(-2*a*dis + v1*v1);
        p.pb(mp(i,nv));
        //cout << i << " " << nv * 3.6<< endl;
        //while(1);
    }
    p.pb(mp(nextd, v2));
    //cout << nextd << " " << v2 * 3.6 << endl;
    d = nextd;

}
int main()
{
    freopen("a.txt","r",stdin);
    freopen("out.txt","w",stdout);
    p.clear();
    double v;
    cin>>v;
    double a,b;
    for (int i=0;i<=400;i+=5)
    {
        cin>>a>>b;
        ret.pb(mp(a,b));
    }
    //cout << p.size() << endl;
    sort(ret.begin(),ret.end());
    reverse(ret.begin(),ret.end());
    double d = 0;

    for (int j=0;j<ret.size()-1;j++)
    {
        if (v<=ret[j].F && v>=ret[j+1].F)
        {
            for (int i=j;i<ret.size()-1;i++)
            {
                f(d, v, ret[i+1].F, (ret[i+1].S+ret[i+1].S)/2);
                v = ret[i+1].F;
            }
            for (int i=0;i<p.size();i++)
                printf("%.3lf %.3lf\n",p[i].F ,p[i].S*3.6);
            break;
        }
    }
}
