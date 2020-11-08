priblem_1 :
https://leetcode.com/problems/set-matrix-zeroes/

0 1 2 0
3 4 5 2
1 3 1 5

Output:
0 0 0 0
0 4 5 0
0 3 1 0

///space used = row * col

class Solution
{
    int row, col ;
    int visited[ 205 ][ 205 ] ;
    void Fun( vector<vector<int>>& arr, int x, int y )
    {
        for( int i = 0 ; i < row ; i ++ )
        {
            if( arr[ i ][ y ] ) visited[ i ][ y ] = 1 ;
            arr[ i ][ y ] = 0 ;
        }
        for( int i = 0 ; i < col ; i ++ )
        {
            if( arr[ x ][ i ] ) visited[ x ][ i ] = 1 ;
            arr[ x ][ i ] = 0 ;
        }
    }

public:
    void setZeroes( vector<vector<int>>& arr )
    {
        memset( visited, 0, sizeof visited ) ;
        row = arr.size(), col = arr[ 0 ].size() ;
        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                if( arr[ i ][ j ] == 0 && visited[ i ][ j ] == 0 )
                {
                    Fun( arr, i, j ) ;
                }
            }
        }
    }
};


///space used = row + col
class Solution
{
public:
    void setZeroes( vector<vector<int>>& arr )
    {
        int row = arr.size(), col = arr[ 0 ].size() ;
        vector< int > R( row, 1 ), C( col, 1 ) ;
        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                if( arr[ i ][ j ] == 0 )
                {
                    R[ i ] = 0 ;
                    C[ j ] = 0 ;
                }
            }
        }
        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                if( R[ i ] == 0 || C[ j ] == 0 )
                {
                    arr[ i ][ j ] = 0 ;
                }
            }
        }
    }
};


///space used = O( 1 )

1 1 1 1
1 0 1 1
1 1 0 1
0 0 0 1

class Solution
{
public:
    void setZeroes( vector<vector<int>>& arr )
    {
        int col0 = 1, row = arr.size(), col = arr[ 0 ].size() ;
        for( int i = 0 ; i < row ; i ++ )
        {
            if( arr[ i ][ 0 ] == 0 ) col0 = 0 ;
            for( int j = 1 ; j < col ; j ++ )
            {
                if( arr[ i ][ j ] == 0 ) arr[ i ][ 0 ] = arr[ 0 ][ j ] = 0 ;
            }
        }

        for( int i = row - 1 ; i >= 0 ; i -- )
        {
            for( int j = col - 1 ; j >= 1 ; j -- )
            {
                if( arr[ i ][ 0 ] == 0 || arr[ 0 ][ j ] == 0 )
                {
                    arr[ i ][ j ] = 0 ;
                }
            }
            if( col0 == 0 ) arr[ i ][ 0 ] = 0 ;
        }
    }
};


priblem_2 :
https://leetcode.com/problems/pascals-triangle/

[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]

class Solution
{
public:
    vector< vector< int > > generate( int row )
    {
        vector< vector< int > > vec ;

        if( row == 0 ) return vec ;
        if( row >= 1 ) vec.push_back( { 1 } ) ;
        if( row >= 2 ) vec.push_back( { 1, 1 } ) ;

        for( int i = 2 ; i < row ; i ++ )
        {
            vector< int > v ;
            for( int j = 0 ; j <= i ; j ++ )
            {
                if( j == 0 || j == i ) v.push_back( 1 ) ;
                else v.push_back( vec[ i - 1 ][ j - 1 ] + vec[ i - 1 ][ j ] ) ;
            }
            vec.push_back( v ) ;
        }
        return vec ;
    }
};

For getting one row
https://leetcode.com/problems/pascals-triangle-ii/

class Solution
{
public:
    vector<int> getRow( int n )
    {
        vector<int> v ;
        long res = 1 ;
        v.push_back( res ) ;
        for( int i = 0 ; i < n ; i ++ )
        {
            res *= ( n - i ) ;
            res /= ( i + 1 ) ;
            v.push_back( res ) ;
        }
        return v ;
    }
};


priblem_3 :
https://leetcode.com/problems/next-permutation/

[1,3,5,4,2] => [1,4,2,3,5]
[3,2,1] => [1,2,3]

In Brute Force solution we just next_permutation the Vector and got the Greater value.

Normally 1 2 3 4 5 But If 1 3 | 5 4 2 Then we get the Break point
and from that 2 4 5 we take next bigger value of 3( as it is said to take next larger value )
then Reverse the next full part.
If the largest then 3 2 1, take the smaller part 1 2 3

class Solution
{
public:
    void nextPermutation(vector<int>& v)
    {
        int idx1 = 0, idx2 = 0, n = v.size() ;
        for( int i = n - 1 ; i > 0 ; i -- )
        {
            if( v[ i - 1 ] < v[ i ] )
            {
                idx1 = i - 1 ;
                break ;
            }
        }

        for( int i = n - 1 ; i > idx1 ; i -- )
        {
            if( v[ i ] > v[ idx1 ] )
            {
                idx2 = i ;
                break ;
            }
        }

        swap( v[ idx1 ], v[ idx2 ] ) ;

        if( !idx1 && !idx2 )
        {
            reverse( v.begin(), v.end() ) ;
        }
        else
        {
            reverse( v.begin() + idx1 + 1, v.end() ) ;
        }
    }
};


priblem_4 :
https://leetcode.com/problems/global-and-local-inversions/

1 2 0 3
here 1 > 0 and 2 > 0, total 2 global ( left side of any index Greater than )
and 2 > 0, tatal 1 local ( immediate left index Greater )
As not Equal so False

class Solution
{
public:
    bool isIdealPermutation(vector<int>& v)
    {
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            if( abs( v[ i ] - i ) > 1 ) return false ;
        }
        return true ;
    }
};


class Solution
{
    void Merge( vector<int>& v, int low, int mid, int high, int& sum )
    {
        int inv_cnt = 0 ;
        int n1 = mid - low + 1 ;
        int n2 = high - mid ;
        int L[ n1 ], R[ n2 ] ;
        int idx1 = 0, idx2 = 0, i = 0, j = 0, k = low ;
        for( int i = low ; i <= mid ; i ++ ) L[ idx1++ ] = v[ i ] ;
        for( int i = mid + 1 ; i <= high ; i ++ ) R[ idx2++ ] = v[ i ] ;

        while( i < n1 && j < n2 )
        {
            if( L[ i ] <= R[ j ] ) v[ k ++ ] = L[ i ++ ] ;
            else
            {
                sum += ( n1 - i ) ;
                v[ k ++ ] = R[ j ++ ] ;
            }
        }
        while( i < n1 ) v[ k ++ ] = L[ i++ ] ;
        while( j < n2 ) v[ k ++ ] = R[ j++ ] ;
    }

    void mergersort( vector<int>& v, int low, int high, int& sum )
    {
        if( low >= high ) return ;
        int mid = low + ( high - low ) / 2 ;
        mergersort( v, low, mid, sum ) ;
        mergersort( v, mid + 1, high, sum ) ;
        Merge( v, low, mid, high, sum ) ;
    }

public:
    bool isIdealPermutation(vector<int>& v)
    {
        int cnt = 0, sum = 0 ;
        for( int i = 1 ; i < v.size() ; i ++ )
        {
            if( v[ i ] < v[ i - 1 ] ) cnt ++ ;
        }
        mergersort( v, 0, v.size() - 1, sum ) ;

        return ( sum == cnt ) ;
    }
};


priblem_5 :
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

One transiction, buy then sell, Get maximum profit
[7,1,5,3,6,4] => 5 ( buy day 2( 1 ) and sell day 5( 6 ) with 5 profit )

class Solution
{
public:
    int maxProfit(vector<int> &v )
    {
        int ans = 0, val = 1e6 ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            val = min( val, v[ i ] ) ;
            ans = max( ans, v[ i ] - val ) ;
        }
        return ans ;
    }
};

priblem_6 :
https://leetcode.com/problems/rotate-image/

[1,2,3]
[4,5,6]
[7,8,9]

then tronspose ( row become col and col become row ) by swapping corner (4,2),(3,7) etc
[1,4,7]
[2,5,8]
[3,6,9]

Output:
reversing row element
[7,4,1]
[8,5,2]
[9,6,3]

class Solution
{
public:
    void rotate(vector<vector<int>>& arr)
    {
        int n = arr.size() ;
        for( int i = 0 ; i < n ; i ++ )
        {
            for( int j = i ; j < n ; j ++ )
            {
                swap( arr[ i ][ j ], arr[ j ][ i ] ) ;
            }
        }

        for( int i = 0 ; i < n ; i ++ )
        {
            for( int j = 0 ; j < n / 2 ; j ++ )
            {
                swap( arr[ i ][ j ], arr[ i ][ n - j - 1 ] ) ;
            }
        }
    }
};

