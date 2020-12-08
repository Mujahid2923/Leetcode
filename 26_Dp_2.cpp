
Problem_1 :
-----------
https://leetcode.com/problems/minimum-path-sum/
[1,3,1]
[1,5,1]
[4,2,1]
( 1,1 ) => ( n,n ) minimum sum ( 1 -> 3 -> 1 -> 1 -> 1 == 7 )


class Solution
{
public:
    int minPathSum(vector<vector<int>>& vec)
    {
        int row = vec.size(), col = vec[ 0 ].size() ;
        int dp[ row + 5 ][ col + 5 ] ;
        for( int i = 1 ; i <= row ; i ++ )
        {
            dp[ i + 1 ][ 0 ] = 1e5 ;
        }
        for( int i = 1 ; i <= col ; i ++ )
        {
            dp[ 0 ][ i + 1 ] = 1e5 ;
        }

        for( int i = 1 ; i <= row ; i ++ )
        {
            for( int j = 1 ; j <= col ; j ++ )
            {
                if( i == 1 && j == 1 ) dp[ i ][ j ] =  vec[ i - 1 ][ j - 1 ] ;
                else dp[ i ][ j ] = vec[ i - 1 ][ j - 1 ] + min( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] ) ;
            }
        }

        return dp[ row ][ col ] ;
    }
};

Problem_2 :
-----------
https://leetcode.com/problems/coin-change/

coins = [1,2,5], amount = 11 output - 3 ( 11 = 5 + 5 + 1 )
Write a Function to compute the fewest number of coins that you need to make up that amount.


class Solution
{
public:
    int coinChange(vector<int>& v, int cap )
    {
        int n = v.size() ;
        int dp[ 10005 ] ;
        dp[ 0 ] = 0 ;
        for( int i = 1 ; i <= cap ; i ++ )
        {
            dp[ i ] = 100000 ;
        }
        for( int i = 0 ; i < n ; i ++ )
        {
            for( int j = 1 ; j <= cap ; j ++ )
            {
                if( j >= v[ i ] ) dp[ j ] = min( dp[ j ], 1 + dp[ j - v[ i ] ] ) ;
            }
        }
        if( dp[ cap ] == 100000  ) dp[ cap ] = -1 ;
        return dp[ cap ] ;
    }
};


Problem_3 :
-----------
https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

Rod Cutting

class Solution
{
    int Fun( vector< vector< int > >& dp,  vector<int>& v, int left, int right )
    {
        if( right - left <= 1 ) return 0 ;
        if( !dp[ left ][ right ] )
        {
            dp[ left ][ right ] = INT_MAX ;
            for( int k = left + 1 ; k < right ; k ++ )
            {
                dp[ left ][ right ] = min( dp[ left ][ right ], v[ right ] - v[ left ] + Fun( dp, v, left, k ) + Fun( dp, v, k, right ) ) ;
            }
        }
        return dp[ left ][ right ] ;
    }
public:
    int minCost(int n, vector<int>& v)
    {
        v.push_back( 0 ) ;
        v.push_back( n ) ;
        sort( v.begin(), v.end() ) ;
        vector< vector< int > > dp( 105, vector< int >( 105, 0 ) ) ;
        return Fun( dp, v, 0, v.size() - 1 ) ;
    }
};

Problem_4 :
-----------

Eggdrop
https://leetcode.com/problems/super-egg-drop/

# kn^2
class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        int dp[ 105 ][ 10005 ] = {} ;
        for( int i = 1 ; i <= n ; i ++ ) dp[ 1 ][ i ] = i ;
        for( int i = 1 ; i <= k ; i ++ ) dp[ i ][ 1 ] = 1 ;

        for( int i = 2 ; i <= k ; i ++ )
        {
            for( int j = 2 ; j <= n ; j ++ )
            {
                dp[ i ][ j ] = 1e5 ;
                for( int x = 1 ; x <= j ; x ++ )
                {
                    dp[ i ][ j ] = min( dp[ i ][ j ], 1 + max( dp[ i - 1 ][ x - 1 ], dp[ i ][ j - x ] ) ) ;
                }
            }
        }
        return dp[ k ][ n ] ;
    }
};

// https://www.youtube.com/watch?v=iOaRjDT0vjc&t=49s&ab_channel=BackToBackSWE
// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

#klogn
class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        int dp[ 10005 ][ 105 ] = {} ;

        int i = 0 ;
        while( dp[ i ][ k ] < n )
        {
            i ++ ;
            for( int x = 1 ; x <= k ; x ++ )
            {
                dp[ i ][ x ] = dp[ i - 1 ][ x ] + dp[ i - 1 ][ x - 1 ] + 1 ;
            }
        }

        return i ;
    }
};


Problem_5 :
-----------
https://leetcode.com/problems/word-break/
Given a non-Empty String s and a dictionary wordDict containing a List of non-Empty words,
determine If "s" can be segmented into a space-separated sequence of one or more dictionary words.

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
            for( int j = i - 1 ; j >= 0 ; j -- )
            {
                if( dp[ j ] )
                {
                    //cout << j << " " << s.substr( j, i - j ) << endl ;
                    if( Mp[ s.substr( j, i - j ) ] )
                    {
                        //cout << s.substr( j, i - j ) << " " << j << " " << i << endl ;
                        dp[ i ] = 1 ;
                        break ;
                    }
                }
            }
        }

        return dp[ n ] ;
    }
};

Problem_6 :
-----------
Palindorming Patrition
https://leetcode.com/problems/palindrome-partitioning/
Return all possible palindrome partitioning of s.

class Solution
{
    bool isPalindrome( string str )
    {
        int n = str.size() ;
        for( int i = 0 ; i < n / 2 ; i ++ )
        {
            if( str[ i ] != str[ n - i - 1 ] ) return false ;
        }
        return true ;
    }

    void Fun( vector<vector<string>>&vec, vector<string>& v, string s, int n )
    {
        for( int i = 1 ; i <= n ; i ++ )
        {
            string str = s.substr( 0, i ) ;
            if( isPalindrome( str ) )
            {
                v.push_back( str ) ;
                if( i == n )
                {
                    vec.push_back( v ) ;
                    v.pop_back() ;
                    return ;
                }

                Fun( vec, v, s.substr( i, n - i ), n - i ) ;
                v.pop_back() ;
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> vec ;
        vector<string> v ;
        Fun( vec, v, s, s.size() ) ;
        return vec ;
    }
};

https://leetcode.com/problems/palindrome-partitioning-ii/
"banana"
=> "b" | "anana" ( 1 Partition )

https://www.youtube.com/watch?v=WPr1jDh3bUQ&ab_channel=IDeserve // Learn from there

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size() ;
        int palindrome[ 2005 ][ 2005 ] = {} ;

        for( int i = 0 ; i < n ; i ++ ) /// For one length
        {
            palindrome[ i ][ i ] = 1 ;
        }

        for( int i = 0 ; i < n - 1 ; i ++ ) /// For two length
        {
            if( s[ i ] == s[ i + 1 ] ) palindrome[ i ][ i + 1 ] = 1 ;
        }

        for( int len = 3 ; len <= n ; len ++ ) /// For three to n length
        {
            for( int i = 0 ; i <= n - len ; i ++ )
            {
                int j = i + len - 1 ;
                if( s[ i ] == s[ j ] && palindrome[ i + 1 ][ j - 1 ] ) palindrome[ i ][ j ] = 1 ;
            }
        }

        int arr[ 2005 ] ;
        for( int i = 0 ; i < n ; i ++ ) arr[ i ] = INT_MAX ;

        for( int i = 0 ; i < n ; i ++ )
        {
            if( palindrome[ 0 ][ i ] ) arr[ i ] = 0 ;
            else
            {
                for( int j = 0 ; j < i ; j ++ )
                {
                    if( palindrome[ j + 1 ][ i ] )
                    {
                        arr[ i ] = min( arr[ i ], 1 + arr[ j ] ) ;
                    }
                }
            }
        }

        return arr[ n - 1 ] ;

    }
};
