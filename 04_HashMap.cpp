Problem_1 :
https://leetcode.com/problems/two-sum/

Index of target Sum => Input: [2,7,11,15], target = 9 Output: [0,1]

class Solution
{
public:
    vector<int> twoSum(vector<int>& v, int target)
    {
        vector<int> ans ;
        vector< pair< int, int > > vec ;
        for( int i = 0 ; i < v.size() ; i ++ ) vec.push_back( { v[ i ], i } ) ;
        sort( vec.begin(), vec.end() ) ;
        int i = 0, j = vec.size() - 1 ;

        while( i < j )
        {
            if( ( vec[ i ].first + vec[ j ].first ) == target )
            {
                ans = { vec[ i ].second, vec[ j ].second } ;
                break ;
            }
            else if( ( vec[ i ].first + vec[ j ].first ) < target ) i ++ ;
            else if( ( vec[ i ].first + vec[ j ].first ) > target ) j -- ;
        }
        return ans ;
    }
};

class Solution
{
public:
    vector<int> twoSum(vector<int>& v, int target)
    {
        vector<int> res ;
        map< int, vector< int > > Mp ;
        for( int i = 0 ; i < v.size() ; i ++ )  Mp[ v[ i ] ].push_back( i ) ;

        for( int i = 0 ; i < v.size() ; i ++ )
        {
            int val = target - v[ i ] ;
            if( v[ i ] == val && Mp[ val ].size() >= 2 )
            {
                res = { Mp[ val ][ 0 ],Mp[ val ][ 1 ] } ;
                break ;
            }
            else if( v[ i ] != val && Mp[ val ].size() >= 1 )
            {
                res = { Mp[ val ][ 0 ], i } ;
                break ;
            }
        }
        return res ;
    }
};

Problem_2 :
https://leetcode.com/problems/4sum/

Find all Unique quadruplets where a + b + c + d = target ? ;

class Solution
{
public:
    vector<vector<int>> fourSum( vector<int>& v, int target )
    {
        vector<vector<int>> vec ;
        int n = v.size() ;
        if( n < 4 ) return vec ;
        sort( v.begin(), v.end() ) ;

        for( int i = 0 ; i < n ; i ++ )
        {
            if( i == 0 || v[ i ] != v[ i - 1 ] )
            {
                for( int j = i + 1 ; j < n ; j ++ )
                {
                    if( j == i + 1 || v[ j ] != v[ j - 1 ] )
                    {
                        int k = j + 1, l = n - 1 ;
                        while( k < l )
                        {
                            long sum = v[ i ] + v[ j ] + v[ k ] + v[ l ] ;
                            if( sum == target )
                            {
                                vec.push_back( { v[ i ],v[ j ],v[ k ],v[ l ] } ) ;
                                while( k < l && v[ k ] == v[ k + 1 ] ) k ++ ;
                                while( k < l && v[ l ] == v[ l - 1 ] ) l -- ;
                                k ++, l -- ;
                            }
                            else if( sum > target ) l -- ;
                            else k ++ ;
                        }
                    }
                }
            }
        }
        return vec ;
    }
};

Problem_3 :
https://leetcode.com/problems/longest-consecutive-sequence/

The length of the longest consecutive elements sequence.
[100,4,200,1,3,2] = [1,2,3,4] => 4 ;

class Solution
{
public:
    int longestConsecutive(vector<int>& v)
    {
        int ans = 0 ;
        map< int, int > Mp ;
        sort( v.begin(), v.end() ) ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            Mp[ v[ i ] ] = 1 + Mp[ v[ i ] - 1 ] ;
            ans = max( ans, Mp[ v[ i ] ] ) ;
        }
        return ans ;
    }
};

class Solution
{
public:
    int longestConsecutive(vector<int>& v)
    {
        int ans = 0 ;
        unordered_map< int, int > Mp ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            Mp[ v[ i ] ] = 1 ;
        }
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            if( Mp[ v[ i ] - 1 ] ) continue ;
            else
            {
                int cnt = 0, x = v[ i ] ;
                while( Mp[ x ] ) cnt ++, x ++ ;
                ans = max( ans, cnt ) ;
            }
        }
        return ans ;
    }
};


Problem_4 :
https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

Maximum subarray length where sum will be Equal to zero
{15,-2,2,-8,1,7,10,23} => -2 2 -8 1 7 ;

int maxLen(int v[], int n)
{
    map< int, int > Mp ;
    int sum = 0, val = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        sum += v[ i ] ;
        if( Mp[ sum ] == 0 && sum ) Mp[ sum ] = i + 1 ;
        else val = max( val, ( i + 1 ) - Mp[ sum ] ) ;
    }
    return val ;
}


Problem_5 :
https://www.interviewbit.com/problems/subarray-with-given-xor/

Count the number of subarrays having a given XOR
{4, 2, 2, 6, 4}, 6 => 4 {4, 2}, {4, 2, 2, 6, 4}, {2, 2, 6}, {6}

4 2 2 6 4 , after x-or
4 6 4 2 6
4 6(+1) 4 2( 2 ^ 6 = 4 and 2 more 4 before so +2 ) 6(+1)

int solve(vector<int> &v, int k)
{
    int x = 0, n = v.size(), ans = 0 ;
    map< int, int > Mp ;

    for( int i = 0 ; i < n ; i ++ )
    {
        x = ( x ^ v[ i ] ) ;
        if( x == k ) ans ++ ;

        if( Mp[ x ^ k ] ) ans += Mp[ x ^ k ] ;
        Mp[ x ] ++ ;
    }

    return ans ;
}


Problem_6 :
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Find the length of the longest substring without repeating characters .
"abcabcbb" => The answer is "abc", with the length of 3 ;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map< char, int > Mp ;
        int ans = 0, low = 0 ;
        for( int i = 1 ; i <= s.size() ; i ++ )
        {
            if( Mp[ s[ i - 1 ] ] ) low = max( low, Mp[ s[ i - 1 ] ] ) ;
            ans = max( ans, i - low ) ;
            Mp[ s[ i - 1 ] ] = i ;
        }
        return ans ;
    }
};
