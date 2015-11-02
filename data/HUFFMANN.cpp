#include <bits/stdc++.h>
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back 
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define test()  int t; cin>>t; while(t--)
#define fi first
#define se second
#define el "\n"
#define ll long long
#define ull unsigned ll
#define TRACE
using namespace std;

//FILE *fin = freopen("input.txt","r",stdin);
//FILE *fout = freopen("output.txt","w",stdout);

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MAXN 200009

map <string, char> mymap;

struct node {
    int freq;
    char ch;
    node* left;
    node* right;
 
    node( char c = ' ', int f = -1 )
    {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
 
    node( node* c1, node* c2 )
    {
        ch = ' ';
        freq = c1 -> freq + c2 -> freq;
        left = c1;
        right = c2;
    }
 
    bool operator ()( const node& l, const node &r)
    {
        if(l.freq==r.freq)
            return l.ch<r.ch;
        return l.freq <r.freq;
    }
 
    void traverse( string code = "" ) const;
 
};
 
void node::traverse( string code ) const
{
    if( left ) 
    {
        left->traverse( code + '1' );
        right->traverse( code + '0' );
    } 
    else 
    {
        //cout << ch << "\t" << freq << "\t" << code << el;
        //cout <<"\""<<code << "\",";
        //cout << "\""<<code <<"\",";
        mymap[code]=ch;
    }
}
 
int main() 
{
    test()
    {
        mymap.clear();
        string str;
        int i,j,k,a,b,n,cnt;
        string s,temp,ans;
        char c;
        cin>>n;
        priority_queue< node, vector<node>, node > q;
        for(int i=0;i<n;i++)
        {
            cin>>c>>cnt;
            q.push(node(c,cnt));
        }
        while( q.size() != 1 ) 
        {
            node *left = new node( q.top() );
            q.pop();
            node *right = new node( q.top() );
            q.pop();
            q.push( node( left, right ) );
        }
        q.top().traverse();
        
        // Decryption
        
        map <string, char> :: iterator it;
        cin >> s;
     
        temp = "";
        ans = "";
        for( i = 0; i < s.size(); i++ ) 
        {
            temp += " ";
            temp[temp.size()-1] = s[i];
            it = mymap.find(temp);
            if( it != mymap.end() ) 
            {
                c = mymap[temp];
                ans += " ";
                ans[ans.size()-1] = c;
                temp = "";
            }
        }
        cout << ans << endl;
    }
    return 0;
}
 
