Problem_1 :

https://www.hackerearth.com/practice/notes/stacks-and-queues/

Problem_2 :

BFS

void bfs( int s )
{
    queue< int > Q ;
    Q.push( s ) ;
    visited[ s ] = 1 ;

    while( !Q.empty() )
    {
        int u = Q.front();
        Q.pop();

        for( auto v : adj[ u ] )
        {
            if( !visited[ v ] )
            {
                Q.push( v ) ;
                visited[ v ] = 1 ;
            }
        }
    }
}

Problem_3 :

https://leetcode.com/problems/implement-stack-using-queues/

class MyStack
{
public:
    int arr[ 105 ] ;
    int idx = -1 ;
    MyStack()
    {

    }

    void push(int x)
    {
        arr[ ++idx ] = x ;
    }

    int pop()
    {
        int val = arr[ idx ] ;
        idx -- ;
        return val ;
    }

    int top()
    {
        return arr[ idx ] ;
    }

    bool empty()
    {
        if( idx == -1 ) return true ;
        else return false ;
    }
};


Problem_4 :


https://leetcode.com/problems/implement-queue-using-stacks/


class MyQueue
{
    stack< int > Stk1 ;
public:

    MyQueue()
    {

    }

    void push(int x)
    {
        Stk1.push( x ) ;
    }

    int pop()
    {
        stack< int > Stk2 ;
        while( !Stk1.empty() )
        {
            Stk2.push( Stk1.top() ) ;
            Stk1.pop() ;
        }
        int x = Stk2.top() ;
        Stk2.pop() ;
        while( !Stk2.empty() )
        {
            Stk1.push( Stk2.top() ) ;
            Stk2.pop() ;
        }
        return x ;
    }

    int peek()
    {
        stack< int > Stk2 ;
        while( !Stk1.empty() )
        {
            Stk2.push( Stk1.top() ) ;
            Stk1.pop() ;
        }
        int x = Stk2.top() ;
        while( !Stk2.empty() )
        {
            Stk1.push( Stk2.top() ) ;
            Stk2.pop() ;
        }
        return x ;
    }

    bool empty()
    {
        return Stk1.empty() ;
    }
};


Problem_5 :

https://leetcode.com/problems/valid-parentheses

"()[]{}" => true

class Solution
{
public:
    bool isValid( string s )
    {
        stack< char > Stk ;
        int ans = true ;
        for( int i = 0 ; i < s.size() ; i ++ )
        {
            if( s[ i ] == '(' || s[ i ] == '{' || s[ i ] == '[' )
            {
                Stk.push( s[ i ] ) ;
            }
            else
            {
                if( Stk.empty())
                {
                    ans = false ;
                    break ;
                }
                else if( Stk.top() == '(' )
                {
                    if( s[ i ] != ')' )
                    {
                        ans = false ;
                        break ;
                    }
                    Stk.pop() ;
                }
                else if( Stk.top() == '{' )
                {
                    if( s[ i ] != '}' )
                    {
                        ans = false ;
                        break ;
                    }
                    Stk.pop() ;
                }
                else if( Stk.top() == '[' )
                {
                    if( s[ i ] != ']' )
                    {
                        ans = false ;
                        break ;
                    }
                    Stk.pop() ;
                }
            }
        }
        if( !Stk.empty() ) ans = false ;
        return ans ;
    }
};


Problem_6 :

Next Greater Eleement =>

https://leetcode.com/problems/next-greater-element-i

[4, 1, 2],[1, 3, 4, 2] => [-1, 3, -1]

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2)
    {
        map< int, int > Mp ;
        stack< int > Stk ;
        for( int i = 0 ; i < v2.size() ; i ++ )
        {
            while( !Stk.empty() && Stk.top() < v2[ i ] )
            {
                Mp[ Stk.top() ] = v2[ i ] ;
                Stk.pop() ;
            }
            Stk.push( v2[ i ] ) ;
        }
        for( int i = 0 ; i < v1.size() ; i ++ ) v1[ i ] = ( Mp[ v1[ i ] ] == 0 ? -1 : Mp[ v1[ i ] ] ) ;
        return v1 ;
    }
};

https://leetcode.com/problems/next-greater-element-ii/

[5,4,3,2,1] => [-1,5,5,5,5]

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int>& v)
    {
        int n = v.size() ;
        int arr[ n + 5 ] ;
        for( int i = 0 ; i < n ; i ++ ) arr[ i ] = -1 ;
        stack< int > Stk ;
        for( int i = 0 ; i < 2 * n ; i ++ )
        {
            while( !Stk.empty() && v[ Stk.top() ] < v[ i % n ] )
            {
                arr[ Stk.top() ] = v[ i % n ] ;
                Stk.pop() ;
            }
            Stk.push( i % n ) ;
        }

        for( int i = 0 ; i < n ; i ++ ) v[ i ] = arr[ i ] ;
        return v ;
    }
};


https://leetcode.com/problems/next-greater-element-iii/

12443322 => 13222344
( 1 2,4 4 3 3 2 2 ) previous lowest larger was 3 and Swap with This. the to get minimum Sort and Reverse the value ;

12222333 => 12223233
12134461 => 12134614

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        vector< long > v ;
        int val = n ;
        while( val )
        {
            v.push_back( val % 10 ) ;
            val /= 10 ;
        }

        stack< int > Stk ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            int val = v[ i ] ;
            if( !Stk.empty() && v[ Stk.top() ] > v[ i ] )
            {
                int pos = 0 ;
                while( !Stk.empty() && v[ Stk.top() ] > v[ i ] )
                {
                    pos = Stk.top() ;
                    Stk.pop() ;
                }
                swap( v[ i ], v[ pos ] ) ;
                sort( v.begin(), v.begin() + i ) ;
                reverse( v.begin(), v.begin() + i ) ;
                break ;
            }
            Stk.push( i ) ;
        }

        long ans = 0 ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            ans += v[ i ] * powl( 10, i ) ;
        }
        return ( ans == n || ans >= INT_MAX ) ? -1 : ans ;
    }
};


class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string( n ) ;
        next_permutation( s.begin(), s.end() ) ;
        if( stol( s ) > n && stol( s ) < INT_MAX ) return stoi( s ) ;
        else return -1 ;
    }
};
