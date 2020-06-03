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
        string in;
        cin>>in;
        int size=in.size();
        int zeros=0,ones=0,i,j;
        int prevzero=0,prevone=0;
        if(in[0]=='1')
        {   
            i=0;
            while(in[i]=='1')
            {prevone++; i++;}
            j=size-1;
            if(in[j]=='0')
            {while(in[j]=='0')
            {prevzero++; j--;}}
            else if(in[j]=='1')
            {while(in[j]=='1')
            {prevone++; j--;}}
            
            for(int k=i;k<=j;k++)
            {
                if(in[k]=='0')
                zeros++;
                else
                ones++;
                //deb(zeros);
                //deb(ones);
            }
        }
        else
        {
            i=0;
            while(in[i]=='0')
            {prevzero++; i++;}
            j=size-1;
            if(in[j]=='0')
            {while(in[j]=='0')
            {prevzero++; j--;}}
            else if(in[j]=='1')
            {while(in[j]=='1')
            {prevone++; j--;}}

            for(int k=i;k<=j;k++)
            {
                if(in[k]=='0')
                zeros++;
                else
                ones++;
            }
        }
        if(zeros==0 && ones==0)
        cout<<0<<endl;
        else if(in[0]==in[size-1] && in[0]=='1')
        {
            if(ones==0)
            cout<<min(prevone,zeros)<<endl;
            if(zeros==0)
            cout<<0<<endl;
        }
         else if(in[0]==in[size-1] && in[0]=='0')
        {
            if(zeros==0)
            cout<<min(prevzero,ones)<<endl;
            if(ones==0)
            cout<<0<<endl;
        }
        else
        cout<< min(zeros,ones)<<endl;
        
    }
    
	return 0;
}