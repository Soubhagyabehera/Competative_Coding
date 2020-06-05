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
#define takeint(x)      int x;cin>>x;
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
    freopen("error.txt","r",stderr);
#endif
}
vector<int> parent;
vector<pair<int,int>> l;
int find(int i)
{
    if(parent[i]==-1)
    return i;

    find(parent[i]);
}
void unio(int x,int y)
{
    int a=find(x);
    int b=find(y);
    deb(a);
    deb(b);
    parent[a]=b;
}
bool DetectCycle()
{
   
    for(auto i:l)
    {
        int x=find(i.first);
        int y=find(i.second);
        deb(x);
        deb(y);
        if(x==y)
        return true;
        else
        unio(x,y);
    }
    return false;
}
int32_t main()
{
	c_p_c();
    takeint(n);
    //l.resize(n);
    parent.resize(n);
    fill(parent.begin(),parent.end(),-1);
    for (int i = 0; i < n; i++)
    {
        int a,b;
        read(a,b);
        //deb(l[i]);
        l.push_back({a,b});
    }
    cout<<(DetectCycle()==true?"cycle present":"cycle not present");
    
	return 0;
}