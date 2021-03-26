1) Platform, Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3

bool cmp( pair< int, int > A, pair< int, int > B )
{
    if( A.first < B.first ) return true ;
    else if( A.first == B.first )
    {
        if( A.second > B.second ) return true ;
    }
    return false ;
}

int findPlatform(int arr[], int dep[], int n)
{
    vector< pair< int, int > > vec ;
	for( int i = 0 ; i < n ; i ++ )
	{
	    //cout << arr[ i ] << " " << dep[ i ] << endl ;
	    vec.push_back( { arr[ i ], 1 } ) ;
	    vec.push_back( { dep[ i ], -1 } ) ;
	}
	sort( vec.begin(), vec.end(), cmp ) ;
	int ans = 0, cnt = 0 ;
	for( int i = 0 ; i < vec.size() ; i ++ )
	{
	    //cout << vec[ i ].first << " " << vec[ i ].second << endl ;
	    cnt += vec[ i ].second ;
	    ans = max( ans, cnt ) ;
	}
	return ans ;
}

2) Circuit
#include<bits/stdc++.h>
using namespace std;

ll n, sum ;
string s ;

void Input()
{
    cin >> s ;
}
///    10,!,,&10,,|1,!,,|,!,,|

int Fun( string str )
{
    int cnt = 0 ;
    for( int i = 0 ; i < str.size() ; i ++ )
    {
        if( str[ i ] == '1' || str[ i ] == '0' )
        {
            Stk.push( str[ i ] ) ;
        }
        else
        {
            if( str[ i ] == ',' )
            {
                cnt ++ ;
            }
            else
            {
                if( str[ i ] == '!' && cnt != 1 ) return -1 ;
                if( ( str[ i ] == '&' || str[ i ] == '|' ) && cnt != 2 ) return -1 ;

                cnt = 0 ;
                if( str[ i ] == '!' )
                {
                    if( Stk.empty() ) return -1 ;
                    char a = Stk.top() ;
                    Stk.pop() ;
                    if( a == '1' ) Stk.push( '0' ) ;
                    else Stk.push( '1' ) ;
                }
                else if( str[ i ] == '|' )
                {
                    if( Stk.size() < 2 ) return -1 ;
                    char a = Stk.top() ;
                    Stk.pop() ;
                    char b = Stk.top() ;
                    Stk.pop() ;

                    if( a == '1' || b == '1' ) Stk.push( '1' ) ;
                    else Stk.push( '0' ) ;
                }
                else if( str[ i ] == '&' )
                {
                    if( Stk.size() < 2 ) return -1 ;
                    char a = Stk.top() ;
                    Stk.pop() ;
                    char b = Stk.top() ;
                    Stk.pop() ;

                    if( a == '1' && b == '1' ) Stk.push( '1' ) ;
                    else Stk.push( '0' ) ;
                }
            }
        }
    }
    if( Stk.size() == 1 )
    {
        return Stk.top() - '0' ;
    }
    else
    {
        return -1 ;
    }
}


void Calculation()
{
    string str = "" ;
    for( int i = 0 ; i < s.size() ; i ++ )
    {
        if( s[ i ] == '0' || s[ i ] == '1' )
        {
            str += s[ i ] ;
        }
        else
        {
            if( s[ i ] == ']' )
            {
                if( Stk.empty() )
                {
                    cout << -1 << endl ;
                    return ;
                }
                while( !Stk.empty() )
                {
                    if( Stk.top() == '[' )
                    {
                        Stk.pop() ;
                        break ;
                    }
                    else
                    {
                        str += Stk.top() ;
                        Stk.pop() ;
                    }
                }
            }
            else
            {
                Stk.push( s[ i ] ) ;
            }
        }
    }

    if( !Stk.empty() )
    {
        cout << -1 << endl ;
        return ;
    }

    cout << Fun( str ) << endl ;
}


///  [[|,[&,1,[!,0]],[!,[|,[|,1,0],[!,1]]]]


/// [&,[|,1,0],[!,1]]

3) Keypad
class Solution 
{

public:
    vector<string> letterCombinations(string s) 
    {
        vector<string> v ;
        if( s.empty() ) return v ;
        
        map< char, string > Mp ;
        Mp[ '2' ] = "abc" ;
        Mp[ '3' ] = "def" ;
        Mp[ '4' ] = "ghi" ;
        Mp[ '5' ] = "jkl" ;
        Mp[ '6' ] = "mno" ;
        Mp[ '7' ] = "pqrs" ;
        Mp[ '8' ] = "tuv" ;
        Mp[ '9' ] = "wxyz" ;
        
        string s1 = Mp[ s[ 0 ] ] ; 
        for( int i = 0 ; i < s1.size() ; i ++ )
        {
            string a = "" ;
            a += s1[ i ] ;
            v.push_back( a ) ;
        }
        
        for( int i = 1 ; i < s.size() ; i ++ )
        {
            vector<string> temp ;
            string a = Mp[ s[ i ] ] ;
            for( int j = 0 ; j < v.size() ; j ++ )
            {
                for( int k = 0 ; k < a.size() ; k ++ )
                {
                    temp.push_back( v[ j ] + a[ k ] ) ;
                }
            }
            v = temp ;
        }
        
        return v ;
    }
};
or
class Solution 
{
    void Fun( map< char, string >& Mp, vector<string>& v,string str, int pos, string s )
    {
        if( pos == str.size() ) 
        {
            v.push_back( s ) ;
            return ;
        }
        
        string s1 = Mp[ str[ pos ] ] ;
        for( int i = 0 ; i < s1.size() ; i ++ )
        {
            Fun( Mp, v, str, pos + 1, s + s1[ i ] ) ;
        }
    }
public:
    vector<string> letterCombinations(string str) 
    {
        vector<string> v ;
        if( str.empty() ) return v ;
        
        map< char, string > Mp ;
        Mp[ '2' ] = "abc" ;
        Mp[ '3' ] = "def" ;
        Mp[ '4' ] = "ghi" ;
        Mp[ '5' ] = "jkl" ;
        Mp[ '6' ] = "mno" ;
        Mp[ '7' ] = "pqrs" ;
        Mp[ '8' ] = "tuv" ;
        Mp[ '9' ] = "wxyz" ;
        
        Fun( Mp, v, str, 0, "" ) ;
        
        return v ;
    }
};

4) largerst number, Input: nums = [3,30,34,5,9] Output: "9534330"
class Solution 
{
public:
    string largestNumber(vector<int>& vec) 
    {
        int n = vec.size() ;
        vector< string > v ;
        for( int i = 0 ; i < n ; i ++ )
        {
            stringstream ss ;
            string s ;
            ss << vec[ i ] ;
            s = ss.str() ;
            v.push_back( s ) ;
        }
        
        for( int i = 0 ; i < n ; i ++ )
        {
            for( int j = i + 1 ; j < n ; j ++ )
            {
                string a = v[ i ] + v[ j ], b = v[ j ] + v[ i ] ;
                
                if( b > a ) swap( v[ i ], v[ j ] ) ;
            }
        }
        
        string ans = "", res = "0" ;
        for( auto x : v ) ans += x ;
        for( int i = 0 ; i < ans.size() ; i ++ ) 
        {
            if( ans[ i ] != '0' ) 
            {
                res = ans.substr( i ) ;
                break ;
            }
        }
       
        return res ;
    }
};
5) Interval List Intersections( LEETCODE )
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        int i = 0, j = 0 ;
        vector<vector<int>> vec ;
        while( i < A.size() && j < B.size() )
        {
            int mn = max( A[ i ][ 0 ], B[ j ][ 0 ] ) ;
            int mx = min( A[ i ][ 1 ], B[ j ][ 1 ] ) ;
            if( mn <= mx ) vec.push_back( { mn, mx } ) ;
            if( A[ i ][ 1 ] < B [ j ][ 1 ] ) i ++ ;
            else if( A[ i ][ 1 ] > B [ j ][ 1 ] ) j ++ ;
            else i ++, j ++ ;
        }
        return vec ;
    }
};

6) Single Number ( I, II, III )
(I) every element appears twice except for one. Find that single one.
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ans = 0 ;
        for( int i = 0 ; i < nums.size() ; i ++ ) ans = ( ans ^ nums[ i ] ) ;
        return ans ;
    }
};
(II)  every element appears three times except for one.
class Solution {
public:
    int singleNumber(vector<int>& v) 
    {
        int one = 0, two = 0 ;
        for( auto x : v )
        {
            one = ( one ^ x ) & ( ~two ) ;
            two = ( two ^ x ) & ( ~one ) ;
        }
        return one ;
    }
};
(III) exactly two elements appear only once.Input : [1,2,1,3,2,5] Output: [3,5]
class Solution {
public:
    vector<int> singleNumber(vector<int>& v) 
    {
        int sum = 0 ;
        for( auto x : v ) sum ^= x ;
        int lowbit = sum & ( -sum ) ;
        int a = 0, b = 0 ;
        for( auto x : v )
        {
            if( x & lowbit ) a ^= x ;
            else b ^= x ;
        }
        vector<int> ans{ a, b } ;
        return ans ;
    }
};

7) Sort Stack Using Anouthe Stack, 1 2 3 4 5
void SortedStack :: sort()
{
   stack<int> Stk;
   while( !s.empty() )
   {
       int x = s.top() ;
       s.pop() ;
       while( !Stk.empty() && x > Stk.top() )
       {
           s.push( Stk.top() ) ;
           Stk.pop() ;
       }
       Stk.push( x ) ;
   }
   while( !Stk.empty() )
    {
        cout << Stk.top() << " " ;
        Stk.pop() ;
    }
}
8) Diagonal sum of spiral matrix.
void Calculation()
{
    ll x = 3, sum = 1, add = 2 ;
    while( x <= ( n * n ) )
    {
        sum += ( x + ( x + add ) + ( x + 2LL * add ) + ( x + 3LL * add ) ) ;
        x += 3LL * add + ( add + 2 ) ;
        add += 2 ;
    }
    cout << sum << endl ;
}

9) Same like Word Ladder, But have to print all possible combination.
"hit" -> "hot" -> "dot" -> "dog" -> "cog", "hit" -> "hot" -> "lot" -> "log" -> "cog"
class Solution {
  map < string, int > Mp, visited;
  map < string, set < string > > adj;
  void bfs(string src, string des, set < string > &st) {
    queue < string > Q;
    Q.push(src);
    visited[src] = 1;
    while (!Q.empty()) {
      string temp = Q.front();
      Q.pop();
      string s = temp;

      for (int i = 0; i < s.size(); i++) {
        char ch1 = s[i];
        for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
          if (ch1 == ch2) continue;
          s[i] = ch2;
          if (st.count(s)) {
            if (!visited[s]) {
              visited[s] = visited[temp] + 1;
              Q.push(s);
              adj[temp].insert(s);
            }
            if (1 + visited[temp] == visited[s]) {
              adj[temp].insert(s);
            }
          }
          s[i] = ch1;
        }
      }
    }
  }

  void Fun(string src, string des, vector < vector < string >> & vec, vector < string > & v) {
    v.push_back(src);
    if (src == des) {
      vec.push_back(v);
      v.pop_back();
      return;
    }

    for (auto s: adj[src]) {
      Fun(s, des, vec, v);
    }
    v.pop_back();
  }

  public:
    vector < vector < string >> findLadders(string src, string des, vector < string > & ans) {
      vector < vector < string >> vec;
      vector < string > v;
      set < string > st(ans.begin(), ans.end());
      if (!st.count(des)) return vec;
      st.insert(des);
      bfs(src, des, st);

      Fun(src, des, vec, v);
      return vec;
    }
};
10) Snake Ladder Probelm
using namespace std;

int n, a, b ;
vector< int > adj[ 40 ] ;
int level[ 40 ] ;
map< int, int > Mp ;

void Reset()
{
    for( int i = 0 ; i <= 30 ; i ++ )
    {
        level[ i ] = 100 ;
        adj[ i ].clear() ;
        for( int j = i + 1 ; j <= i + 6 ; j ++ ) adj[ i ].push_back( j ) ;
        sort( adj[ i ].begin(), adj[ i ].end() ) ;
    }
    Mp.clear() ;
}


void Input()
{
    cin >> n ;
    for( int i = 0 ; i < n ; i ++ )
    {
        cin >> a >> b ;
        Mp[ a ] = b ;
        adj[ a ].push_back( b ) ;
    }
}


int bfs( int s, int d )
{
    queue< pair< int, int > > Q ;
    Q.push( { s, 0 } ) ;
    level[ s ] = 0 ;
    while( !Q.empty() )
    {
        pair< int, int > temp = Q.front() ;
        Q.pop() ;
        int u = temp.first ;

        for( auto v : adj[ u ] )
        {
            if( v == Mp[ u ] )
            {
                level[ v ] = min( level[ v ], level[ u ] ) ;
                Q.push( { v, temp.second } ) ;
            }
            else
            {
                level[ v ] = min( level[ v ], level[ u ] + 1 ) ;
                Q.push( { v, temp.second + 1 } ) ;
            }
            //cout << u << " " << v << " " << level[ v ] << endl ;
        }
        adj[ u ].clear() ;
    }
    return level[ d ] ;
}

void Calculation()
{
    int ans = bfs( 1, 30 ) ;
    cout << ans << endl ;
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int T = 1 ;
    cin >> T ;
    while( T-- ) solve() ;
    return 0 ;
}

11) LCA
vector < int > adj[ 100005 ] ;

int n ;
ll parent[ 100005 ] ;
ll level[ 100005 ] ;
ll arr[ 100005 ][ 25 ] ;


void Reset()
{
    memset( arr, -1, sizeof arr ) ;
}

void Input()
{
    cin >> n ;
    for( int i = 1, x, y ; i < n ; i ++ )
    {
        cin >> x >> y ;
        adj[ x ].pb( y ) ;
        adj[ y ].pb( x ) ;
    }
}

void dfs( int u, int p, int lev )
{
    parent[ u ] = p ;
    level[ u ] = lev ;
    for( auto v : adj[ u ] )
    {
        if( v != p ) dfs( v, u, lev + 1 ) ;
    }
}

void build()
{
    for( int i = 0 ; i < n ; i ++ )
    {
        arr[ i ][ 0 ] = parent[ i ] ;
    }

    for( int j = 1 ; ( 1 << j ) < n ; j ++ )
    {
        for( int i = 0 ; i < n ; i ++ )
        {
            if( arr[ i ][ j - 1 ] != -1 )
            {
                arr[ i ][ j ] = arr[ arr[ i ][ j - 1 ] ][ j - 1 ] ;
            }
        }
    }
}

int query( int p, int q )
{
    if( level[ p ] < level[ q ] ) swap( p, q ) ;

    int log = 1 ;
    while( 1 )
    {
        if( ( 1 << ( log + 1 ) ) > level[ p ]  ) break ;
        log ++ ;
    }

    for( int i = log ; i >= 0 ; i -- )
    {
        if( level[ p ] - ( 1 << i ) >= level[ q ] ) p = arr[ p ][ i ] ;
    }

    if( p == q ) return p ;

    for( int i = log ; i >= 0 ; i -- )
    {
        if( arr[ p ][ i ] != -1 && arr[ p ][ i ] != arr[ q ][ i ] )
        {
            p = arr[ p ][ i ] ;
            q = arr[ q ][ i ] ;
        }
    }
    return parent[ p ] ;
}

void Calculation()
{
    dfs( 0, -1, 0 ) ;
    build() ;
    int p, q ;
    cin >> p >> q ;
    cout << query( p, q ) << endl ;
}


void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int t ;
    //cin >> t ;
    t = 1 ;
    while( t-- ) solve() ;
    return 0 ;
}
