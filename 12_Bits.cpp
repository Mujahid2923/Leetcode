Problem_1 :

https://leetcode.com/problems/power-of-two

8 = 1 0 0 0
7 = 0 1 1 1
------------
0 = 0 0 0 0

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return ( n > 0 && ( n & ( n - 1  ) ) == 0 ) ;
    }
};

Problem_2 :

https://leetcode.com/problems/counting-bits/

[0,1,1,2,1,2] number of 1 till 5

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector< int > v( n + 1, 0 ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            v[ i ] = v[ i / 2 ] + i % 2 ;
        }
        return v ;
    }
};

Problem_3 :

https://leetcode.com/problems/divide-two-integers/

Divide without division sign .
10 / 3 = 3 ;


class Solution
{
public:
    int divide(int p, int q)
    {
        if( p == INT_MIN && q == -1 ) return INT_MAX ;
        long a = p, b = q,negative = 1, ans = 0 ;

        if( ( a > 0 && b > 0 ) || ( a < 0 && b < 0 )  ) negative = 0 ;
        a = abs( a ) ;
        b = abs( b ) ;

        while( a >= b )
        {
            long x = 0 ;
            while( a >= ( b << x ) )
            {
                a -= ( b << x ) ;
                ans += ( 1 << x ) ;
                x ++ ;
            }
        }

        return ( negative == 0 ) ? ans : -ans ;
    }
};


Problem_4 :

https://leetcode.com/problems/subsets/

nums = [1,2,3]
Output - [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]] ;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& v)
    {
        vector<vector<int>> vec ;
        int n = v.size() ;
        for( int i = 0 ; i < ( 1 << n ) ; i ++ )
        {
            vector< int > v1 ;
            for( int j = 0 ; j < n ; j ++ )
            {
                if( i & ( 1 << j ) )
                {
                    v1.push_back( v[ j ] ) ;
                }
            }
            vec.push_back( v1 ) ;
        }
        return vec ;
    }
};



Problem_5 :

https://www.geeksforgeeks.org/find-significant-set-bit-number/

MSB( left most bit )

int setBitNumber(int n)
{
    // Suppose n is 273 (binary is 100010001). It does following 100010001 | 010001000 = 110011001
    n |= n >> 1;

    // This makes sure 4 bits (From MSB and including MSB) are set. It does following 110011001 | 001100110 = 111111111
    n |= n >> 2;

    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    // Increment n by 1 so that there is only one set bit which is just before original MSB. n now becomes 1000000000
    n = n + 1;

    // Return original MSB after shifting. n now becomes 100000000
    return (n >> 1);
}


LSB( right most bit )

int lsb = n & ( -n ) ;



Problem_6 :

https://www.techiedelight.com/find-square-number-without-using-multiplication-division-operator/

Find square of a number without Using multiplication or division operators.

#If n is even, it can be written as

  n = 2x
  n^2 = (2x)^2 = 4x^2

#If n is odd, it can be written as

  n = 2x + 1
  n^2 = (2x + 1)^2 = 4x^2 + 4x + 1

=> here x is half of n


int square( int n )
{
    // Base case
    if (n == 0) return 0;

    // Handle negative number
    n = abs( n ) ;

    // Get floor(n/2) using right shift
    int x = n >> 1;


    if ( n & 1 ) return ((square(x) << 2) + (x << 2) + 1);
    else return (square(x) << 2);
}

