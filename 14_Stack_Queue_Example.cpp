Problem_1 :

https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

Next Smaller Element ( If no next smaller than keep its original value or difference with the smaller value )
[8,4,6,2,3] => [4,2,4,2,3]

class Solution
{
public:
    vector<int> finalPrices( vector<int>& v )
    {
        stack<int> Stk ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            while( !Stk.empty() && v[ Stk.top() ] >= v[ i ] )
            {
                v[ Stk.top() ] = v[ Stk.top() ] - v[ i ] ;
                Stk.pop() ;
            }
            Stk.push( i ) ;
        }
        return v ;
    }
};


Problem_2 :

https://leetcode.com/problems/lru-cache/

["LRUCache","put","get"]
[[1](length of cache ),[2,1]( key,value),[2](what in key 2 )] => [null,null,1] ( output )


class LRUCache
{
    int capacity ;
    list< pair< int, int > > L ;
    map< int, list< pair< int, int > > :: iterator > Mp ;

    void update( int key, int value )
    {
        L.erase( Mp[ key ] ) ;
        L.push_back( { key, value } ) ;
        Mp[ key ] = prev( L.end() ) ;
    }

public:
    LRUCache(int capacity)
    {
        this -> capacity = capacity ;
    }

    int get(int key)
    {
        if( Mp.find( key ) != Mp.end() )
        {
            update( key, Mp[ key ] -> second ) ;
            return Mp[ key ] -> second ;
        }
        else
        {
            return -1 ;
        }
    }

    void put(int key, int value)
    {
        if( Mp.find( key ) != Mp.end() )
        {
            update( key, value ) ;
        }
        else
        {
            L.push_back( { key, value } ) ;
            Mp[ key ] =  prev( L.end() ) ;

            if( Mp.size() > capacity )
            {
                Mp.erase( L.front().first ) ;
                L.pop_front() ;
            }
        }
    }
};

Problem_3 :

https://leetcode.com/problems/largest-rectangle-in-histogram/

Largest Rectangle in Histogram
[2,1,5,6,2,3] => 10

For [3, 7, 8, 4]
Previous Less element [-1, 3, 3, 3]
Next Less element     [-1, 4, 4, -1]

class Solution
{
public:
    int largestRectangleArea(vector<int>& v)
    {
        int n = v.size() ;
        vector< int > left( n ), right( n ) ;
        for( int i = 0 ; i < n ; i ++ )
        {
            left[ i ] = i + 1 ;
            right[ i ] = n - i ;
        }
        stack< int > Stk1, Stk2 ;
        for( int i = 0 ; i < n ; i ++ )
        {
            while( !Stk1.empty() && v[ Stk1.top() ] >= v[ i ] ) Stk1.pop() ;
            if( !Stk1.empty() ) left[ i ] = i - Stk1.top() ;
            Stk1.push( i ) ;
        }

        for( int i = 0 ; i < n ; i ++ )
        {
            while( !Stk2.empty() && v[ Stk2.top() ] >= v[ i ] )
            {
                right[ Stk2.top() ] = i - Stk2.top() ;
                Stk2.pop() ;
            }
            Stk2.push( i ) ;
        }
        int ans = 0 ;
        for( int i = 0 ; i < n ; i ++ )
        {
            ans = max( ans, ( left[ i ] + right[ i ] - 1 ) * v[ i ] ) ;
        }
        return ans ;
    }
};

Problem_4 :

https://leetcode.com/problems/sliding-window-maximum/

[1,3,-1,-3,5,3,6,7], k = 3

[1  3  -1] -3  5  3  6  7 here 3 is maximum
 1 [3  -1  -3] 5  3  6  7 here 3 is maximum
1   3 [-1  -3  5] 3  6  7 here 5 is maximum, Like This way
Output : [3,3,5,5,6,7]

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k)
    {
        multiset< int > S ;
        vector< int > ans ;
        for( int i = 0 ; i < k ; i ++ )
        {
            S.insert( v[ i ] ) ;
        }
        ans.push_back( *prev( S.end() ) ) ;

        for( int i = k ; i < v.size() ; i ++ )
        {
            S.insert( v[ i ] ) ;
            auto it = S.lower_bound( v[ i - k ] ) ;
            S.erase( it ) ;
            ans.push_back( *prev( S.end() ) ) ;
        }

        return ans ;
    }
};


Problem_5 :

https://leetcode.com/problems/min-stack/


class MinStack
{
    vector< int > v1, v2 ;
public:
    MinStack()
    {
        v2.push_back( INT_MAX ) ;
    }

    void push(int x)
    {
        v1.push_back( x ) ;
        v2.push_back( min( v2.back(), x ) ) ;
    }

    void pop()
    {
        v1.pop_back() ;
        v2.pop_back() ;
    }

    int top()
    {
        return v1.back() ;
    }

    int getMin()
    {
        return v2.back() ;
    }
};

Problem_6 :

https://leetcode.com/problems/rotting-oranges/

class Solution
{
    const int fx[ 5 ] = {+1,-1,+0,+0};
    const int fy[ 5 ] = {+0,+0,+1,-1};
    int row, col ;
    int level[ 15 ][ 15 ] ;
    int visited[ 15 ][ 15 ] ;

    bool isvalid( vector<vector<int>>& arr, int x, int y )
    {
        if(x >= 0 && x < row && y >= 0 && y < col && arr[ x ][ y ] == 1 && visited[ x ][ y ] == 0 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void bfs(vector<vector<int>>& arr, int x, int y )
    {
        memset( visited, 0, sizeof visited ) ;

        queue< pair< int, int > > Q ;
        Q.push( { x, y } ) ;
        level[ x ][ y ] = 0 ;

        while( !Q.empty() )
        {
            int a = Q.front().first ;
            int b = Q.front().second ;
            Q.pop() ;

            for( int i = 0 ; i < 4 ; i ++ )
            {
                int xx = a + fx[ i ] ;
                int yy = b + fy[ i ] ;

                if( isvalid( arr, xx, yy ) )
                {
                    level[ xx ][ yy ] = min( level[ xx ][ yy ], level[ a ][ b ] + 1 ) ;
                    visited[ xx ][ yy ] = 1 ;
                    Q.push( { xx, yy } ) ;
                }
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>>& arr)
    {
        row = arr.size(), col = arr[ 0 ].size() ;
        for( int i = 0 ; i < row ; i ++ ) for( int j = 0 ; j < col ; j ++ ) level[ i ][ j ] = INT_MAX ;

        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                if( arr[ i ][ j ] == 2 )
                {
                    bfs( arr, i, j ) ;
                }
            }
        }

        int ans = 0 ;
        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                if( arr[ i ][ j ] == 1 )
                {
                    if( level[ i ][ j ] == INT_MAX  ) return -1 ;
                    ans = max( ans, level[ i ][ j ] ) ;
                }
            }
        }
        return ans ;
    }
};

