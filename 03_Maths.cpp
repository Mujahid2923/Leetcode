priblem_1 :
https://leetcode.com/problems/excel-sheet-column-number/

AB => 28

class Solution
{
public:
    int titleToNumber(string s)
    {
        int ans = 0 ;
        for( int i = 0 ; i < s.size() ; i ++ )
        {
            ans = ( ans * 26 ) + ( s[ i ] - 'A' + 1 ) ;
        }
        return ans ;
    }
};


priblem_2 :
https://leetcode.com/problems/powx-n/submissions/


x        n => x ^ n
2.00000 10 => 1024
2.00000 -2 => 0.25

class Solution
{

    double power( double x, long y )
    {
        if( y == 0 ) return 1 ;
        if( y % 2 == 0 )
        {
            double res = power( x, y / 2 ) ;
            return ( res * res ) ;
        }
        else return x * power( x, y - 1 ) ;
    }

public:
    double myPow(double x, int n)
    {
        long y = n ;
        double ans = power( x, abs( y ) ) ;
        if( n < 0 ) ans = 1 / ans ;
        return ans ;
    }
};


priblem_3 :
https://leetcode.com/problems/majority-element/

The majority element is the element that appears more than n/2 times.
[2,2,1,1,1,2,2] => 2

Boyer Moore Voting Algo

class Solution
{
public:
    int majorityElement( vector< int > &v )
    {
        int val = v[ 0 ], cnt = 1 ;
        for( int i = 1 ; i < v.size() ; i ++ )
        {
            if( v[ i ] == val ) cnt ++ ;
            else cnt -- ;

            if( cnt == 0 )
            {
                cnt = 1 ;
                val = v[ i ] ;
            }
        }
        return val ;
    }
};

priblem_4 :
https://leetcode.com/problems/majority-element-ii/

The majority element is the element that appears more than n/3 times.
[1,1,1,2,2,3,3,3] => [1,3]

class Solution
{
public:
    vector<int> majorityElement(vector<int>& v)
    {
        vector<int> ans ;
        int val1 = -2e9, val2 = -2e9, cnt1 = 0, cnt2 = 0, n = v.size(), x = 0, y = 0 ;
        for( int i = 0 ; i < n ; i ++ )
        {
            if( val1 == v[ i ] ) cnt1 ++ ;
            else if( val2 == v[ i ] ) cnt2 ++ ;
            else if( cnt1 == 0 )
            {
                cnt1 = 1 ;
                val1 = v[ i ] ;
            }
            else if( cnt2 == 0 )
            {
                cnt2 = 1 ;
                val2 = v[ i ] ;
            }
            else
            {
                cnt1 -- ;
                cnt2 -- ;
            }
        }
        for( int i = 0 ; i < n ; i ++ )
        {
            if( v[ i ] == val1 ) x ++ ;
            if( v[ i ] == val2 ) y ++ ;
        }
        if( x > n / 3 ) ans.push_back( val1 ) ;
        if( y > n / 3 ) ans.push_back( val2 ) ;
        return ans ;
    }
};


priblem_5 :
https://leetcode.com/problems/unique-paths/

How many possible path
Input:
m(row) = 3, n(col) = 2
Output: 3
Explanation:
(0, 0) => (row-1, col-1)
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


class Solution
{
    int Fun( int i, int j, int row, int col, vector<vector< int >> &dp )
    {
        if( i == row || j == col ) return 0 ;
        if( i == row - 1 && j == col - 1 ) return 1 ;
        if( dp[ i ][ j ] != -1 ) return dp[ i ][ j ] ;
        return dp[ i ][ j ] = Fun( i + 1, j, row, col, dp ) + Fun( i, j + 1, row, col, dp ) ;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector< vector< int > > dp( m,vector< int >( n, -1 ) ) ;
        return Fun( 0, 0, m, n, dp ) ;
    }
};

priblem_6 :
https://leetcode.com/problems/reverse-pairs/

Number of Pair where i < j and v[ i ] > 2 * v[ j ]

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

class Solution
{
public:
    int reversePairs(vector<int>& v)
    {
        int ans = 0 ;
        map< long, long > Mp ;
        orderset< pair< long, long > > S ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            int idx = S.order_of_key( { 2LL * v[ i ], Mp[ 2LL * v[ i ] ] + 1 } ) ;
            ans += (int)S.size() - idx ;
            Mp[ v[ i ] ] ++ ;
            S.insert( { v[ i ], Mp[ v[ i ] ] } ) ;
        }
        return ans ;
    }
};


class Solution
{

    void Merge( vector<int>& v, int low, int mid, int high, int &sum )
    {

        /// 12 19 25 40   2 6 9


        1st :
        int j = mid + 1 ;
        for( int i = low ; i <= mid ; i ++ )
        {
            while( j <= high && v[ i ] > ( 2LL * v[ j ] ) ) j ++ ;
            sum += ( j - ( mid + 1 ) ) ;
        }
        1(12) 3(19) 3(25) 3(40) ( 1st part comparing with 2nd )

        2nd :
        for( int i = mid + 1 ; i <= high ; i ++ )
        {
            int pos = upper_bound( v.begin()+ low, v.begin() + mid + 1 , 2LL * v[ i ] ) - v.begin() ;
            sum += ( ( mid + 1 ) - pos ) ;
        }
        4(2) 3(6) 3(9) ( 2nd part comparing with 1st )


        vector< int > temp ;
        int left = low, right = mid + 1 ;

        while( left <= mid && right <= high )
        {
            if( v[ left ] <= v[ right ] ) temp.push_back( v[ left ++ ] ) ;
            else temp.push_back( v[ right ++ ] ) ;
        }
        while( left <= mid ) temp.push_back( v[ left ++ ] ) ;
        while( right <= high ) temp.push_back( v[ right ++ ] ) ;
        for( int i = 0 ; i < temp.size() ; i ++ )
        {
            v[ low ++ ] = temp[ i ] ;
        }
    }

    void mergesort( vector<int>& v, int low, int high, int &sum )
    {
        if( low >= high ) return ;
        int mid = low + ( high - low ) / 2 ;
        mergesort( v, low, mid, sum ) ;
        mergesort( v, mid + 1, high, sum ) ;
        Merge( v, low, mid, high, sum ) ;
    }

public:
    int reversePairs(vector<int>& v)
    {
        int sum = 0 ;
        mergesort( v, 0, v.size() - 1, sum ) ;
        return sum ;
    }
};

Problem_7 :
https://leetcode.com/problems/greatest-common-divisor-of-strings/

Given two strings s1 and s2,
Return the largest String x such that x Divides both s1 and s2.

class Solution
{
    int Gcd( int a, int b )
    {
        if( b == 0 ) return a ;
        return Gcd( b, a % b ) ;
    }

public:
    string gcdOfStrings( string s1, string s2 )
    {
        int n1 = s1.size(), n2 = s2.size() ;
        int x = Gcd( n1, n2 ) ;
        string s = s1.substr( 0, x ) ;
        for( int i = 0 ; i < n1 ; i += x )
        {
            string str = s1.substr( i, x ) ;
            if( str != s ) return "" ;
        }
        for( int i = 0 ; i < n2 ; i += x )
        {
            string str = s2.substr( i, x ) ;
            if( str != s ) return "" ;
        }
        return s ;
    }
};

Problem_8 : Puzzles
https://www.geeksforgeeks.org/puzzles/#C++Puzzles


priblem_extra :
https://leetcode.com/problems/factorial-trailing-zeroes/

Trailing zeros

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int cnt = 0 ;
        while( n )
        {
            cnt += n / 5 ;
            n /= 5 ;
        }
        return cnt ;
    }
};

Gcd :

int Gcd( int a, int b )
{
    if( b == 0 ) return a ;
    return Gcd( b, a % b ) ;
}

Extended Euclidean Gcd :

int ExtendedGcd( int a, int b, int& x, int& y )
{
    if (b == 0)
    {
        x = 1 ;
        y = 0 ;
        return a ;
    }

    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d ;
}

