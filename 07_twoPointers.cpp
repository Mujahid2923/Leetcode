Problem_1 :

https://leetcode.com/problems/copy-list-with-random-pointer/

Copy of a Linked List with address of random link List

class Solution
{
public:
    map< Node*, Node* > Mp ;
    Node* copyRandomList(Node* head)
    {
        if( head == NULL ) return NULL ;
        if( Mp[ head ] ) return Mp[ head ] ;

        Mp[ head ] = new Node( head -> val ) ;
        Mp[ head ] -> next = copyRandomList( head -> next ) ;
        Mp[ head ] -> random = copyRandomList( head -> random ) ;

        return Mp[ head ] ;
    }
};


Problem_2 :
https://leetcode.com/problems/3sum/

Given an Array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all Unique triplets in the Array which gives the sum of zero.

class Solution
{
public:
    vector<vector<int>> threeSum( vector<int>& v )
    {
        vector<vector<int>> vec ;
        int n = v.size() ;
        if( n < 3 ) return vec ;
        sort( v.begin(), v.end() ) ;
        for( int i = 0 ; i < n - 2 ; i ++ )
        {
            if( i == 0 || v[ i ] != v[ i - 1 ] )
            {
                int j = i + 1, k = n - 1 ;
                while( j < k )
                {
                    int sum = v[ i ] + v[ j ] + v[ k ] ;
                    if( sum == 0 )
                    {
                        vec.push_back( { v[ i ], v[ j ], v[ k ] } ) ;
                        while( j < k && v[ j ] == v[ j + 1 ] ) j ++ ;
                        while( j < k && v[ k ] == v[ k - 1 ] ) k -- ;
                        j ++, k -- ;
                    }
                    else if( sum > 0 ) k -- ;
                    else j ++ ;
                }
            }
        }
        return vec ;
    }
};


Problem_3 :

https://leetcode.com/problems/trapping-rain-water/

[0,1,0,2,1,0,1,3,2,1,2,1] => 6, the amount of water piller can contain between.

class Solution
{
public:
    int trap(vector<int>& v1)
    {
        int n = v1.size(), ans = 0, mx = 0 ;
        vector<int> v2( n, 0 ) ;

        for( int i = 0 ; i < n ; i ++ )
        {
            mx = max( mx, v1[ i ] ) ; // max from left
            v2[ i ] = mx ;
        }
        mx = 0 ;
        for( int i = n - 1 ; i >= 0 ; i -- )
        {
            mx = max( mx, v1[ i ] ) ; // max from right
            v2[ i ] = min( mx, v2[ i ] ) ; // took minimum btwn left and right
        }
        for( int i = 0 ; i < n ; i ++ ) ans += ( v2[ i ] - v1[ i ] ) ;
        return ans ;
    }
};


Problem_4 :

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Remove Duplicates from Sorted Array
[0,0,1,1,1,2,2,3,3,4] Output - 5, nums = [0,1,2,3,4] ;


class Solution
{
public:
    int removeDuplicates(vector<int>& v)
    {
        if( v.empty() ) return 0 ;
        int idx = 0 ;
        int val = v[ idx ++ ] ;
        for( int i = 1 ; i < v.size() ; i ++ )
        {
            if( v[ i ] != val )
            {
                v[ idx ++ ] = v[ i ] ;
                val = v[ i ] ;
            }
        }
        return idx ;
    }
};


Problem_5 :

https://leetcode.com/problems/max-consecutive-ones/#:~:text=Input%3A%20%5B1%2C1%2C,of%20consecutive%201s%20is%203.

Given a binary Array, Find the maximum number of consecutive 1 in This Array.

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& v)
    {
        int ans = 0, cnt = 0 ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            if( v[ i ] == 1 ) cnt ++ ;
            else cnt = 0 ;
            ans = max( ans, cnt ) ;
        }
        return ans ;
    }
};
