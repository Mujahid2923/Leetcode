Problem_1 :

https://leetcode.com/problems/n-queens/


class Solution
{
    bool valid( vector< string > &v, int row, int col, int n )
    {
        for( int i = 0 ; i < n ; i ++ )
        {
            for( int j = 0 ; j < n ; j ++ )
            {
                if( ( i == row ) || ( j == col ) || ( ( i - j ) == ( row - col ) ) || ( ( i + j ) == ( row + col ) ) )
                {
                    if( v[ i ][ j ] == 'Q' ) return false ;
                }
            }
        }
        return true ;
    }

    void Fun( vector< vector< string > > &res, vector< string > &v, int row, int n )
    {
        if( row == n )
        {
            res.push_back( v ) ;
            return ;
        }

        for( int col = 0 ; col < n ; col ++ )
        {
            if( valid( v, row, col, n ) )
            {
                v[ row ][ col ] = 'Q' ;
                Fun( res, v, row + 1, n ) ;
                v[ row ][ col ] = '.' ;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector< string > v( n, string( n, '.' ) ) ;
        vector< vector< string > > res ;
        Fun( res, v, 0, n ) ;
        return res ;
    }
};


Problem_2 :

https://leetcode.com/problems/sudoku-solver/

class Solution
{

    bool valid( vector<vector<char>>& vec, int row, int col, char num )
    {
        for( int i = 0 ; i < 9 ; i ++ )
        {
            if( vec[ row ][ i ] == num ) return false ;
            if( vec[ i ][ col ] == num ) return false ;
            if( vec[ 3 * ( row / 3 ) + ( i / 3 ) ][ 3 * ( col / 3 ) + ( i % 3 ) ] == num ) return false ;
        }
        return true ;
    }

    bool Fun( vector<vector<char>>& vec )
    {
        for( int row = 0 ; row < 9 ; row ++ )
        {
            for( int col = 0 ; col < 9 ; col ++ )
            {
                if( vec[ row ][ col ] == '.' )
                {
                    for( char num = '1' ; num <= '9' ; num ++ )
                    {
                        if( valid( vec, row, col, num ) )
                        {
                            vec[ row ][ col ] = num ;
                            if( Fun( vec ) ) return true ;
                            vec[ row ][ col ] = '.' ;
                        }
                    }
                    return false ;
                }
            }
        }
        return true ;
    }

public:
    void solveSudoku(vector<vector<char>>& vec)
    {
        Fun( vec ) ;
    }
};

Problem_3 :

https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

4(node) 3(m color) 5(edge)
1 2
2 3
3 4
4 1
1 3
your output is:
1 2 3 2 1

#include <bits/stdc++.h>
using namespace std;


bool valid( bool graph[ 101 ][ 101 ], int *color,int n, int v, int clr )
{
    for( int i = 0 ; i < n ; i ++ )
    {
        if( graph[ v ][ i ] && clr == color[ i ] ) return false ;
    }
    return true ;
}

bool Fun( bool graph[101][101], int *color, int m, int n, int v )
{
    if( v == n ) return true ;
    for( int i = 1 ; i <= m ; i ++ )
    {
        if( valid( graph, color, n, v, i ) )
        {
            color[ v ] = i ;
            if( Fun( graph, color, m, n, v + 1 ) ) return true ;
            color[ v ] = 0 ;
        }
    }
    return false ;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[ 101 ] = {0} ;
    if( Fun( graph,color, m, n, 0 ) )
    {
        for( int i = 0 ; i < n ; i ++ ) cout << color[ i ] << " " ;
        return true ;
    }
    else
    {
        cout << "Not M colourable" << endl ;
        return false ;
    }
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        bool graph[ 101 ][ 101 ] ;
        for ( int i = 0; i < n; i++)
        {
            memset( graph[i], 0, sizeof(graph[i]) ) ;
        }

        for ( int i = 0; i < e; i ++ )
        {
            int a, b ;
            cin >> a >> b;
            graph[ a - 1 ][ b - 1 ] = 1 ;
            graph[ b - 1 ][ a - 1 ] = 1 ;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}

Problem_4 :

https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#


4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
DDRDRR DRDDRR
( 0, 0 to n - 1, n - 1 ) Can Go top,down,left,right ;


int visited[ MAX ][ MAX ] ;

void Fun( vector<string>& v,int arr[MAX][MAX], int n, int row, int col, string s )
{
    if( row < 0 || row == n || col < 0 || col == n ) return ;
    if( row == n - 1 && col == n - 1 )
    {
        v.push_back( s ) ;
        return ;
    }
    if( arr[ row ][ col ] && !visited[ row ][ col ] )
    {
        visited[ row ][ col ] = 1 ;
        Fun( v, arr, n, row + 1, col, s + "D" ) ;
        Fun( v, arr, n, row, col + 1, s + "R" ) ;
        Fun( v, arr, n, row - 1, col, s + "U" ) ;
        Fun( v, arr, n, row, col - 1, s + "L" ) ;
        visited[ row ][ col ] = 0 ;
    }
}

vector<string> printPath(int arr[MAX][MAX], int n)
{
    vector<string>v;
    if( !arr[ 0 ][ 0 ] || !arr[ n - 1 ][ n - 1 ] ) return v ;
    Fun( v, arr, n, 0, 0, "" ) ;
    sort( v.begin(), v.end() ) ;
    return v;
}


Problem_5 :

https://leetcode.com/problems/permutations/

[1,2,3] => [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]] ;

class Solution
{
    void Fun( vector<vector<int>>& vec,vector<int>& v,vector<int>& path, vector<int>& visited )
    {
        if( path.size() == v.size() )
        {
            vec.push_back( path ) ;
            return ;
        }

        for( int i = 0 ; i < v.size() ; i ++ )
        {
            if( !visited[ i ] )
            {
                visited[ i ] = 1 ;
                path.push_back( v[ i ] ) ;
                Fun( vec, v, path, visited ) ;
                path.pop_back() ;
                visited[ i ] = 0 ;
            }
        }
    }

public:
    vector<vector<int>> permute( vector<int>& v )
    {
        vector<vector<int>> vec ;
        vector< int > path, visited( v.size(), 0 ) ;
        Fun( vec, v, path, visited ) ;
        return vec ;
    }
};

class Solution
{
    void Fun( vector<vector<int>>& vec,  vector<int>& v, int pos )
    {
        if( pos == v.size() )
        {
            vec.push_back( v ) ;
            return ;
        }

        for( int i = pos ; i < v.size() ; i ++ )
        {
            swap( v[ pos ], v[ i ] ) ;
            Fun( vec, v, pos + 1 ) ;
            swap( v[ pos ], v[ i ] ) ;
        }
    }

public:
    vector<vector<int>> permute( vector<int>& v )
    {
        vector<vector<int>> vec ;
        Fun( vec, v, 0 ) ;
        return vec ;
    }
};

class Solution
{
public:
    vector<vector<int>> permute( vector<int>& v )
    {
        sort( v.begin(), v.end() ) ;
        vector<vector<int>> vec ;
        do
        {
            vec.push_back( v ) ;
        }
        while( next_permutation( v.begin(), v.end() ) ) ;
        return vec ;
    }
};

Problem_6 :

https://leetcode.com/problems/word-break/

class Solution
{
public:
    bool wordBreak(string s, vector<string>& v)
    {
        int n = s.size() ;
        vector< int > dp( n + 1, 0 ) ;
        map< string, int > Mp ;
        for( auto x : v ) Mp[ x ] = 1 ;

        dp[ 0 ] = 1 ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            for( int j = 0 ; j < i ; j ++ )
            {
                if( dp[ j ] )
                {
                    if( Mp[ s.substr( j, i - j ) ] )
                    {
                        dp[ i ] = 1 ;
                        break ;
                    }
                }
            }
        }

        return dp[ n ] ;
    }
};


https://practice.geeksforgeeks.org/problems/word-break-part-2/0#

5
lr m lrm hcdar wk
hcdarlrm
(hcdar lr m)(hcdar lrm)

string s, word ;
int t, siz ;
set< string > st ;
vector< string > v ;

void Fun( string s, int n, string res )
{
    for( int i = 1 ; i <= n ; i ++ )
    {
        string str = s.substr( 0, i ) ;
        if( st.count( str ) )
        {
            if( i == n )
            {
                res += str ;
                v.push_back( res ) ;
                return ;
            }
            else
            {
                Fun( s.substr( i, n - i ), n - i, res + str + " " ) ;
            }
        }
    }
}

int main()
{
    cin >> t ;
    while( t-- )
    {
        cin >> siz ;
        for( int i = 0 ; i < siz ; i ++ )
        {
            cin >> word ;
            st.insert( word ) ;
        }
        cin >> s ;
        Fun( s, s.size(), "" ) ;
        sort( v.begin(), v.end() ) ;
        for( auto x : v ) cout << "(" << x << ")" ;
        cout << endl ;

        st.clear() ;
        v.clear() ;
    }
    return 0;
}
