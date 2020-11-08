priblem_1 :
https://leetcode.com/problems/find-the-duplicate-number/

There is only one duplicate number in nums, Return This duplicate number.

class Solution
{
    int findDuplicate(vector<int>& v)
    {
        int mx = 0, idx = 0, n = v.size() ;
        for( int i = 0 ; i < n ; i ++ )
        {
            v[ v[ i ] % n ] += n ;
        }
        for( int i = 0 ; i < n ; i ++ )
        {
            if( v[ i ] > mx )
            {
                mx = v[ i ] ;
                idx = i ;
            }
        }
        return idx ;
    }
}

class Solution
{
    int findDuplicate(vector<int>& v)
    {
        int slow = v[ 0 ] ;
        int fast = v[ 0 ] ;

        do
        {
            slow = v[ slow ] ;
            fast = v[ v[ fast ] ] ;
        }
        while( slow != fast ) ;

        fast = v[ 0 ] ;
        while( slow != fast )
        {
            slow = v[ slow ] ;
            fast = v[ fast ] ;
        }
        return slow ;
    }
}



priblem_2 :
https://leetcode.com/problems/sort-colors/

Sort them in-place so that objects of the same color are adjacent.

class Solution
{

    int Partition( vector<int>& v, int low, int high )
    {
        int pivot = v[ high ] ;
        int idx = low ;
        for( int i = low ; i < high ; i ++ )
        {
            if( v[ i ] <= pivot )
            {
                swap( v[ i ], v[ idx ] ) ;
                idx ++ ;
            }
        }
        swap( v[ idx ], v[ high ] ) ;
        return idx ;
    }

    void QuickSort( vector<int>& v, int low, int high )
    {
        if( low >= high ) return ;
        int index = Partition( v, low, high ) ;
        QuickSort( v, low, index - 1 ) ;
        QuickSort( v, index + 1, high ) ;
    }
public:
    void sortColors(vector<int>& v)
    {
        QuickSort( v, 0, v.size() - 1 ) ;
    }
};


class Solution
{
public:
    void sortColors(vector<int>& v)
    {
        int low = 0, mid = 0, high = v.size() - 1 ;
        while( mid <= high )
        {
            if( v[ mid ] == 0 )
            {
                swap( v[ mid ], v[ low ] ) ;
                low ++, mid ++ ;
            }
            else if( v[ mid ] == 1 )
            {
                mid ++ ;
            }
            else if( v[ mid ] == 2 )
            {
                swap( v[ mid ], v[ high ] ) ;
                high -- ;
            }
        }
    }
};


priblem_3 :
https://leetcode.com/problems/missing-number/

Given an Array nums containing n distinct numbers in the range [0, n],
Return the only number in the range that is missing from the Array.

class Solution
{
public:
    int missingNumber(vector<int>& v)
    {
        int x = ( v.size() * ( v.size() + 1 ) ) / 2 ;
        int y = 0 ;
        for( auto x : v ) y += x ;
        return x - y ;
    }
};


priblem_4 :
https://leetcode.com/problems/merge-sorted-array/

nums1 = [1,2,3,0,0,0], m = 3 nums2 = [2,5,6], n = 3 Output: [1,2,2,3,5,6]


class Solution
{
public:
    void merge(vector<int>& v1, int n, vector<int>& v2, int m )
    {
        int idx = n + m - 1,idx1 = n - 1, idx2 = m - 1 ;
        while( idx1 >= 0 && idx2 >= 0 )
        {
            if( v1[ idx1 ] >= v2[ idx2 ] ) v1[ idx -- ] = v1[ idx1 -- ] ;
            else v1[ idx -- ] = v2[ idx2 -- ] ;
        }

        while( idx1 >= 0 ) v1[ idx -- ] = v1[ idx1 -- ] ;
        while( idx2 >= 0 ) v1[ idx -- ] = v2[ idx2 -- ] ;
    }
};


priblem_5 :
https://leetcode.com/problems/maximum-subarray/
Find the contiguous subarray maximum sum

class Solution
{
public:
    int maxSubArray(vector<int>& v)
    {
        int sum = 0, ans = INT_MIN ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            sum = max( sum + v[ i ], v[ i ] )  ;
            ans = max( ans, sum ) ;
        }
        return ans ;
    }
};

priblem_6 :
https://leetcode.com/problems/merge-intervals/

[[1,3],[1,6],[5,10],[11,18]] => [[1,10],[11,18]]
[[1,4],[2,3]] => [[1,4]]

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& arr)
    {
        vector<vector<int>> vec ;
        int n = arr.size() ;
        sort( arr.begin(), arr.end() ) ;
        arr.push_back( { INT_MAX, INT_MAX } ) ;

        for( int i = 0, j = 0 ; i < n ; i = j )
        {
            int mn = arr[ i ][ 0 ] ;
            int mx = arr[ i ][ 1 ] ;

            for( j = i + 1 ; j < n ; j ++ )
            {
                if( arr[ j ][ 0 ] <= mx ) mx = max( mx, arr[ j ][ 1 ] ) ;
                else break ;
            }
            vec.push_back( { mn, mx } ) ;
        }
        return vec ;
    }
};

