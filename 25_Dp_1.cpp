Problem_1 :
-----------
https://leetcode.com/problems/maximum-product-subarray/

Maximum Product Subarray

class Solution
{
public:
    int maxProduct(vector<int>& v)
    {
        int ans = v[ 0 ], last_mn = v[ 0 ], last_mx = v[ 0 ] ;

        for( int i = 1 ; i < v.size() ; i ++ )
        {
            int temp = last_mn ;
            last_mn = min( { v[ i ], last_mn * v[ i ], last_mx * v[ i ] } ) ;
            last_mx = max( { v[ i ], temp * v[ i ], last_mx * v[ i ] } ) ;
            ans = max( ans, last_mx ) ;
        }
        return ans ;
    }
};


Problem_2 :
-----------
https://leetcode.com/problems/longest-increasing-subsequence/

#n^2

class Solution
{
public:
    int lengthOfLIS(vector<int>& v)
    {
        vector< int > arr( 2505, 1 ) ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            int mx = 0 ;
            for( int j = 0 ; j < i ; j ++ )
            {
                if( v[ j ] < v[ i ] ) mx = max( mx, arr[ j ] ) ;
            }
            arr[ i ] += mx ;
        }
        return *( max_element( arr.begin(), arr.end() ) ) ;
    }
};

#nlogn
class Solution
{
    int Fun( vector<int>& v1 )
    {
        vector<int> v2 ;
        v2.push_back( v1[ 0 ] ) ;
        for( int i = 1 ; i < v1.size() ; i ++ )
        {
            if( v1[ i ] > v2.back() )
            {
                v2.push_back( v1[ i ] ) ;
            }
            else
            {
                int pos = lower_bound( v2.begin(),v2.end(), v1[ i ] ) - v2.begin() ;
                v2[ pos ] = v1[ i ] ;
            }
        }
        return v2.size() ;
    }
public:
    int lengthOfLIS(vector<int>& v1)
    {
        return Fun( v1 ) ;
    }
};

Problem_3 :
-----------
https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    int longestCommonSubsequence(string a, string b)
    {
        int dp[ a.size() + 5 ][ b.size() + 5 ] ;
        memset( dp, 0, sizeof dp ) ;

        for( int i = 1 ; i <= a.size() ; i ++ )
        {
            for( int j = 1 ; j <= b.size() ; j ++ )
            {
                if( a[ i - 1 ] == b[ j - 1 ] ) dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ] ;
                else
                {
                    dp[ i ][ j ] = max( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] ) ;
                }
            }
        }
        return dp[ a.size() ][ b.size() ] ;
    }
};

Problem_4 :
-----------

https://leetcode.com/problems/partition-equal-subset-sum/

1 4 5 1 11
1 4 5 1 = 11 and 11, We can divide it into two parts .

class Solution
{
    int Fun( vector< vector<int> >& dp, vector<int>& v, int pos, int sum, int total )
    {
        if( pos == v.size() ) return 0 ;
        if( sum > total ) return 0 ;
        if( sum == total ) return 1 ;
        if( dp[ pos ][ sum ] != -1 ) return dp[ pos ][ sum ] ;
        int r1 = 0, r2 = 0 ;
        if( sum + v[ pos ] <= total )
        {
            r1 = Fun( dp, v, pos + 1, sum + v[ pos ], total ) ;
        }
        r2 = Fun( dp, v, pos + 1, sum, total ) ;
        return dp[ pos ][ sum ] = max( r1, r2 ) ;
    }
public:
    bool canPartition(vector<int>& v)
    {
        int sum = 0 ;
        for( int x : v ) sum += x ;
        if( sum & 1 ) return false ;
        vector< vector<int> > dp( v.size(), vector<int>( sum / 2, -1 ) ) ;
        if( Fun( dp, v, 0, 0, sum / 2 ) ) return true ;
        else return false ;
    }
};

Problem_5 :
-----------
https://leetcode.com/problems/edit-distance/

class Solution
{
public:
    int minDistance(string s1, string s2)
    {
        int row = s1.size(), col = s2.size() ;
        int dp[ row + 5 ][ col + 5 ] ;
        for( int i = 0 ; i <= row ; i ++ ) dp[ i ][ 0 ] = i ;
        for( int i = 0 ; i <= col ; i ++ ) dp[ 0 ][ i ] = i ;

        for( int i = 1 ; i <= row ; i ++ )
        {
            for( int j = 1 ; j <= col ; j ++ )
            {
                if( s1[ i - 1 ] == s2[ j - 1 ] ) dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] ;
                else dp[ i ][ j ] = 1 + min( { dp[ i-1 ][ j-1 ], dp[ i-1 ][ j ], dp[ i ][ j-1 ] } ) ;
            }
        }
        return dp[ row ][ col ] ;
    }
};

Problem_6 :
-----------
https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
7
4 6  1 3 8  4 6
4 10 1 4 18 8 14
0 0  2 2 1  3 5

18( index 4 ) comes from 1 index and 1 index comes from 0 so, 8(4) -> 6(1) -> 4(0)
we can get another array and check from where its coming.

class Solution
{
public:
    int maxSumIS(int arr[], int n)
    {
        vector< int > v( n ), ans( n ) ;
        for( int i = 0 ; i < n ; i ++ )
        {
            ans[ i ] = i ;
            v[ i ] = arr[ i ] ;
        }

        for( int i = 0 ; i < n ; i ++ )
        {
            for( int j = 0 ; j < i ; j ++ )
            {
                if( arr[ j ] < arr[ i ] )
                {
                    if( arr[ i ] + v[ j ] > v[ i ] )
                    {
                        ans[ i ] = j ;
                        v[ i ] = arr[ i ] + v[ j ] ;
                    }
                }
            }
        }
    }
};

Problem_7 :
-----------

https://leetcode.com/problems/burst-balloons/
( https://www.youtube.com/watch?v=uG_MtaCJIrM&ab_channel=TECHDOSE )
Matrix chain multiplication

class Solution
{
public:
    int maxCoins(vector<int>& nums)
    {
        vector< int > v ;
        v.push_back( 1 ) ;
        for( auto x : nums ) v.push_back( x ) ;
        v.push_back( 1 ) ;

        int n = v.size() ;
        int dp[ n ][ n ] ;
        memset( dp, 0, sizeof dp ) ;

        for( int k = 1 ; k < n ; k ++ )
        {
            for( int left = 0 ; left < n - k ; left ++ )
            {
                int right = left + k ;
                for( int i = left + 1 ; i < right ; i ++ )
                {
                    dp[ left ][ right ] = max( dp[ left ][ right ], dp[ left ][ i ] + v[ left ] * v[ i ] * v[ right ] + dp[ i ][ right ] ) ;
                }
            }
        }
        return dp[ 0 ][ n - 1 ] ;
    }
};

