Problem_1 :

https://leetcode.com/problems/reverse-words-in-a-string/
"  Bob    Loves  Alice   " => "Alice Loves Bob" ;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector< string > v ;
        stringstream ss( s ) ;
        string word, str = "" ;
        while( ss >> word )
        {
            v.push_back( word ) ;
        }

        reverse( v.begin(), v.end() ) ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            if( i == v.size() - 1 )
            {
                str += v[ i ] ;
            }
            else
            {
                str += v[ i ] ;
                str += " " ;
            }
        }
        return str ;
    }
};


Problem_2 :

https://leetcode.com/problems/longest-palindromic-substring/

vabba = abba, vababa = ababa ;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size(), start = 0, end = 0, ans = 1 ;

        //created palindromic substring of odd length
        for( int i = 0 ; i < n - 1 ; i ++ )
        {
            int l = i, r = i ;
            while( l >= 0 && r < n )
            {
                if( s[ l ] == s[ r ] ) l --, r ++ ;
                else break ;
            }
            if( r - l - 1 > ans )
            {
                ans = r - l - 1 ;
                start = l + 1, end = r - 1 ;
            }
        }

        //created palindromic substring of even length
        for( int i = 0 ; i < n - 1 ; i ++ )
        {
            int l = i, r = i + 1 ;
            while( l >= 0 && r < n )
            {
                if( s[ l ] == s[ r ] ) l --, r ++ ;
                else break ;
            }
            if( r - l - 1 > ans )
            {
                ans = r - l - 1 ;
                start = l + 1, end = r - 1 ;
            }
        }

        string str = s.substr( start, ans ) ;
        return str ;
    }
};


Problem_3 :

https://leetcode.com/problems/roman-to-integer/
https://leetcode.com/problems/integer-to-roman/

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000


class Solution
{
public:
    int romanToInt(string s)
    {
        int sum = 0 ;
        map< char, int > Mp ;
        Mp[ 'I' ] = 1 ;
        Mp[ 'V' ] = 5 ;
        Mp[ 'X' ] = 10 ;
        Mp[ 'L' ] = 50 ;
        Mp[ 'C' ] = 100 ;
        Mp[ 'D' ] = 500 ;
        Mp[ 'M' ] = 1000 ;
        for( int i = 0 ; i < s.size() ; i ++ )
        {
            sum += Mp[ s[ i ] ] ;
            if( i && Mp[ s[ i - 1 ] ] < Mp[ s[ i ] ] )
            {
                sum -= 2 * Mp[ s[ i - 1 ] ] ;
            }
        }
        return sum ;
    }
};


class Solution
{
public:
    string intToRoman(int n)
    {
        vector< int > v { 1,4,5,9,10,40,50,90,100,400,500,900,1000 } ;
        map< int, string > Mp ;
        Mp[ 1 ] = "I" ;
        Mp[ 4 ] = "IV" ;
        Mp[ 5 ] = "V" ;
        Mp[ 9 ] = "IX" ;
        Mp[ 10 ] = "X" ;
        Mp[ 40 ] = "XL" ;
        Mp[ 50 ] = "L" ;
        Mp[ 90 ] = "XC" ;
        Mp[ 100 ] = "C" ;
        Mp[ 400 ] = "CD" ;
        Mp[ 500 ] = "D" ;
        Mp[ 900 ] = "CM" ;
        Mp[ 1000 ] = "M" ;

        string s = "" ;
        for( int i = 12 ; i >= 0 ; i -- )
        {
            while( n && v[ i ] <= n )
            {
                s += Mp[ v[ i ] ] ;
                n -= v[ i ] ;
            }
        }
        return s ;
    }
};


Problem_4 :

https://leetcode.com/problems/string-to-integer-atoi/

"4193 with words" => 4193
string to valid integer ;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = s.find_first_not_of( ' ' ) ;
        if( i == -1 ) return 0 ;

        long ans = 0, sign = 1 ;

        if( i < s.size() && s[ i ] == '-' || s[ i ] == '+' )
        {
            if( s[ i ++ ] == '-' ) sign = -1 ;
        }
        while( i < s.size() && ( s[ i ] - '0' ) >= 0 && ( s[ i ] - '0' ) <= 9 )
        {
            ans = ans * 10 + ( s[ i ] - '0' ) ;
            if( ( sign * ans ) >= INT_MAX ) return INT_MAX ;
            if( ( sign * ans ) <= INT_MIN ) return INT_MIN ;
            i ++ ;
        }
        return sign * ans ;
    }
};

Problem_5 :

https://leetcode.com/problems/longest-common-prefix/

class Solution
{
public:
    string longestCommonPrefix(vector<string>& v)
    {
        int mn = 0 ;
        string ans = "" ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            mn = max( mn, ( int ) v[ i ].size() ) ;
        }
        for( int idx = 0 ; idx < mn ; idx ++ )
        {
            set < char > st ;
            for( int i = 0 ; i < v.size() ; i ++ )
            {
                st.insert( v[ i ][ idx ] ) ;
            }
            if( st.size() == 1 )  ans += *st.begin() ;
            else break ;
        }
        return ans ;
    }
};


Problem_6 :
https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

Input:
text - "AABAACAADAABAABA" pattern- "AABA" ;
Output - Pattern found at index 0, 9, 12 ;


string text, pattern ;
ll p = 31 ;
ll mod = 1e9 + 9 ;

int main()
{
    cin >> text >> pattern ;
    ll n = text.size(), m = pattern.size() ;
    vector< ll > p_pow( max( n, m ) ) ;

    p_pow[ 0 ] = 1 ;
    for( int i = 1 ; i < (int)p_pow.size() ; i ++ )
    {
        p_pow[ i ] = ( p_pow[ i - 1 ] * p ) % mod ;
    }

    vector< ll > Hash( n + 1, 0 ) ;

    for( int i = 0 ; i < n ; i ++ )
    {
        Hash[ i + 1 ] = ( Hash[ i ] + ( text[ i ] - 'a' + 1 ) * p_pow[ i ] ) % mod ;
    }

    ll pattern_hash = 0 ;
    for( int i = 0 ; i < m ; i ++ )
    {
        pattern_hash = ( pattern_hash + ( pattern[ i ] - 'a' + 1 ) * p_pow[ i ] ) % mod ;
    }

    vector< ll > v ;

    for( int i = 0 ; i <= n - m ; i ++ )
    {
        ll text_hash = ( Hash[ i + m ] - Hash[ i ] + mod ) % mod ;
        if( text_hash == ( pattern_hash * p_pow[ i ] ) % mod ) v.push_back( i ) ;
    }

    for( int i = 0 ; i < v.size() ; i ++ )
    {
        cout << v[ i ] << " " ;
    }

    return 0 ;
}
