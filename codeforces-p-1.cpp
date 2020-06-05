#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}
template<typename... T>
void write(T&&... args) { //rvalue reference is new to C++
	((cout << args << " "), ...);
}
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
const int m=1e18;
map<int,int> cache;
int gnas=true;
int calcOperations(int initial,int final,int ans)
{
    //deb(ans);
    if(initial==final)
    return ans;
    if(gnas==false || initial==m)
    return -1;
    if(initial<final)
    {
        int a=m,b=m,c=m;
        bool flag=true;
        if(initial*2<=final)
        {
            a=calcOperations(initial*2,final,ans+1);
            flag=false;
        }
        if(initial*4<=final)
        {
            b=calcOperations(initial*4,final,ans+1);
            flag=false;
        }
        if(initial*8<=final)
        {
         c=calcOperations(initial*8,final,ans+1);
         flag=false;
        }
        if(flag)
            gnas=false;
        // deb(initial);
        // deb(a);
        // deb(b);
        // deb(c);
        return min(a,min(b,c));
    }
    else if(initial>final)
    {
        int a=m,b=m,c=m;
        bool flag=true;
        if(initial%2==0)
             {a=calcOperations(initial/2,final,ans+1);flag=false;}
        if(initial%4==0)
             {b=calcOperations(initial/4,final,ans+1);flag=false;}
        if(initial%8==0)
             {c=calcOperations(initial/8,final,ans+1); flag=false;}
        if(flag)
            gnas=false;
        deb(initial);
        deb(a);
        deb(b);
        deb(c);
        return min(a,min(b,c));

    }
}
int32_t main()
{
	c_p_c();
    w(t)
    {
        int initial,final;
        cin>>initial>>final;
        // deb(initial);
        // deb(final);
        int banda=calcOperations(initial,final,0);
        cout<<(banda==m?-1:banda)<<endl;
    }
	return 0;
}