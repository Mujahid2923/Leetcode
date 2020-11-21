Problem_1 :

https://practice.geeksforgeeks.org/problems/find-nth-root-of-m/0

print an integer denoting Nth root of M If the root is an integer Else print -1.

Given 3 64, Here 4 ^ 3 = 64 . Have to Find that 4 ;

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll t, a, b ;

ll Fun( ll low, ll high )
{
    ll ans = -1 ;
    while( low <= high )
    {
        ll mid = low + ( high - low ) / 2 ;
        ll x = powl( mid, a ) ;
        if( x == b ) return mid ;
        else if( x < b ) low = mid + 1 ;
        else high = mid - 1 ;
    }
    return ans ;
}

int main()
{

    cin >> t ;
    while( t-- )
    {
        cin >> a >> b ;
        cout << Fun( 1, 35000 ) << endl ;
    }

    return 0;
}


Problem_2 :
https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

Median in a matrix

class Solution
{
    int Fun( vector<vector<int>> &arr, int row, int col, int low, int high )
    {
        int ans = 0, md = ( row * col + 1 ) / 2 ;
        while( low <= high )
        {
            int mid = low + ( high - low ) / 2 ;
            int cnt = 0 ;
            for( int i = 0 ; i < row ; i ++ )
            {
                for( int j = 0 ; j < col ; j ++ )
                {
                    if( arr[ i ][ j ] <= mid ) cnt ++ ;
                }
            }

            if( cnt >= md )
            {
                ans = mid ;
                high = mid - 1 ;
            }
            else
            {
                low = mid + 1 ;
            }
        }
        return ans ;
    }

public:
    int median( vector<vector<int>> &arr, int row, int col )
    {
        return Fun( arr, row, col, 1, 10000 ) ;
    }
};

Problem_3 :
https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1#

1 1 2 3 3 => 2 ( Find the single element and rest of others is Double )

class Solution
{
    int Fun( int *arr, int low, int high )
    {
        while( low <= high )
        {
            int mid = low + ( high - low ) / 2 ;
            if( mid % 2 == 0 )
            {
                if( arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1] ) return arr[ mid ] ;
                else if( arr[ mid ] == arr[ mid - 1 ] ) high = mid - 1 ;
                else low = mid + 1 ;
            }
            else
            {
                if( arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1] ) return arr[ mid ] ;
                else if( arr[ mid ] == arr[ mid - 1 ] ) low = mid + 1 ;
                else high = mid - 1 ;
            }
        }
    }

public:
    int findOnce(int arr[], int n)
    {
        return Fun( arr, 0, n - 1 ) ;
    }
};

Problem_4 :
https://leetcode.com/problems/search-in-rotated-sorted-array/

[4,5,6,7,0,1,2], target = 0 At index 4 ;



class Solution
{

    int Fun(vector<int>& v, int low, int high, int x )
    {
        while( low <= high )
        {
            int mid = low + ( high - low ) / 2 ;
            if( x == v[ mid ] ) return mid ;
            if( v[ low ] <= v[ mid ] )
            {
                if( x >= v[ low ] && x <= v[ mid ] ) high = mid - 1 ;
                else low = mid + 1 ;
            }
            else
            {
                if( x >= v[ mid ] && x <= v[ high ] ) low = mid + 1 ;
                else high = mid - 1 ;
            }
        }
        return -1 ;
    }

public:
    int search(vector<int>& v, int x)
    {
        return Fun( v, 0, v.size() - 1, x ) ;
    }
};


Problem_5 :
https://leetcode.com/problems/median-of-two-sorted-arrays/

[1,3,8,9,15] and [7,11,18,19,21,25]
=> [1,3,7,8,9,11,15,18,19,21,25] median is 11

class Solution
{
    double Fun( vector<int> v1, vector<int> v2 )
    {
        double ans ;
        int x = v1.size(), y = v2.size() ;
        int low = 0, high = x ;
        while( low <= high )
        {
            int first = ( low + high ) / 2 ;
            int second = ( x + y + 1 ) / 2 - first ;

            int firstLeft = ( first == 0 ) ? INT_MIN : v1[ first - 1 ] ;
            int firstRight = ( first == x ) ? INT_MAX : v1[ first ] ;

            int secondLeft = ( second == 0 ) ? INT_MIN : v2[ second - 1 ] ;
            int secondRight = ( second == y ) ? INT_MAX : v2[ second ] ;

            if( firstLeft <= secondRight && secondLeft <= firstRight )
            {
                if( ( x + y ) & 1 ) ans = (double)max( firstLeft, secondLeft ) ;
                else ans = ( (double) max( firstLeft, secondLeft ) + min( firstRight, secondRight ) ) / 2 ;
                break ;
            }
            else if( firstLeft > secondRight ) high = first - 1 ;
            else low = first + 1 ;
        }
        return ans ;
    }

public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2)
    {
        if( v1.size() <= v2.size() ) return Fun( v1, v2 ) ;
        else return Fun( v2, v1 ) ;
    }
};


Problem_6 :

https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/

Kth element of two sorted Array.

#include <bits/stdc++.h>
using namespace std;
int t, n1, n2, k, x ;
vector< int > v1, v2 ;

int Fun( int low, int high )
{
    int ans = 0 ;
    while( low <= high )
    {
        int mid = low + ( high - low ) / 2 ;
        int cnt = 0 ;
        for( int i = 0 ; i < n1 ; i ++ ) if( v1[ i ] > mid ) cnt ++ ;
        for( int i = 0 ; i < n2 ; i ++ ) if( v2[ i ] > mid ) cnt ++ ;
        //cout << mid << " " << cnt << endl ;
        if( ( n1 + n2 ) - cnt >= k )
        {
            ans = mid ;
            high = mid - 1 ;
        }
        else low = mid + 1 ;
    }
    return ans ;
}
int main()
{
    cin >> t ;
    while( t-- )
    {
        cin >> n1 >> n2 >> k ;
        int mx = 0 ;
        for( int i = 0 ; i < n1 ; i ++ )
        {
            cin >> x ;
            mx = max( mx, x ) ;
            v1.push_back( x ) ;
        }
        for( int i = 0 ; i < n2 ; i ++ )
        {
            cin >> x ;
            mx = max( mx, x ) ;
            v2.push_back( x ) ;
        }

        cout << Fun( 1, mx ) << endl ;
        v1.clear() ;
        v2.clear() ;
    }
    return 0;
}
