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

int32_t main()
{
	c_p_c();
	w(t)
	{
		string s;
		cin >> s;
		int suf0 = 0, suf1 = 0;
		for(auto &it:s)
		{
			suf0 += (it == '0');
			suf1 += (it == '1');
		}
		int ans = min(suf0, suf1); //Make whole string 0/1
		int pref0 = 0, pref1 = 0;
		for(auto &it:s)
		{
			pref0 += (it == '0'), suf0 -= (it == '0');
			pref1 += (it == '1'), suf1 -= (it == '1');
            deb(pref0);
            deb(pref1);
            deb(suf0);
            deb(suf1);
			//Cost of making string 0*1*
			ans = min(ans, pref1 + suf0);
            deb(ans);
			//Cost of making string 1*0*
			ans = min(ans, pref0 + suf1);
            deb(ans);
		}
		cout << ans << endl;
	}
	return 0;
}