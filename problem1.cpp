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
#define for(i, n) for(i=0; i<n; i++)
#define For(i, k, n) for(i=k; i<n; i++)
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
        int n,count,i;
        cin>>n>>count;
        vi elements;
        int odds=0,evens=0;
        for(i,n)
        {
            int a;
            cin>>a;
            elements.pb(a);
            if(a%2==0)
            evens++;
            else
            {
                odds++;
            }
        }
        int even_ptr=count-1,odd_ptr=1;
        string finalanswer="No";
        while(odd_ptr<=count)
        {
            if(even_ptr<=evens && odd_ptr<=odds)
            {
                finalanswer="Yes";
                break;
            }
            odd_ptr+=2;
            even_ptr-=2;
        }
        cout<<finalanswer<<endl;
    }

	return 0;
}