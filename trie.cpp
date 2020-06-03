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
#define takeint(x)		int x;cin>>x;
#define takestring(x)	string x;cin>>x;	
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
	freopen("error.txt", "w", stderr); 
	freopen("output.txt", "w", stdout);

#endif
}
const int N=1e3;
typedef struct tdt
{
	tdt *a[52];
	int info;
}tr;
tr* root;;
void insert(string s)
{
	tr* temp=root;
	for(auto c:s)
	{
		//s=s+20;
		if(c<91)
		{	if(!temp->a[c-'A'])
			{
				temp->a[c-'A']=new tr();
			}
			temp=temp->a[c-'A'];
		}
		else
		{
			if(!temp->a[c-6-'A'])
			{
				temp->a[c-6-'A']=new tr();
				
			}
			temp=temp->a[c-6-'A'];
		}
		
	}
	temp->info=1;
}

bool traverse(string check,tr* root,int id)
{
	
	tr* temp=root;
	for(char c:check)
	{
		if(c<91)
		{
			if(temp->a[c-'A'])
			{
				temp=temp->a[c-'A'];
			}
			else
			{
				return false;
			}
		}
		else
		{
			if(temp->a[c-6-'A'])
			{
				temp=temp->a[c-6-'A'];
			}
			else
			{
				return false;
			}
		}
		
		
		
	}
	return true;
}

int32_t main()
{
	c_p_c();
	vector<string> instrings(N);
	takeint(n);
	for (int i = 0; i < n; i++)
	{
		takestring(a);
		instrings.push_back(a);
	}
	root=new tr();
	for(string s:instrings)
	{
		insert(s);
	}
	takestring(check);
	cout<<(traverse(check,root,0)==true?"present":"not present");

	return 0;
}