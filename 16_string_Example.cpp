Problem_1 :

Z algorithm

https://www.youtube.com/watch?v=uFPSFsOlklE&ab_channel=faadcoder

int arr[ 1000006 ] ;

void calculateZ( string s )
{
    ll left = 0, right = 0 ;
    for( int i = 1 ; i < s.size() ; i ++ )
    {
        if( i > right )
        {
            left = right = i ;
            while( right < s.size() && s[ right ] == s[ right - left ] )
            {
                right ++ ;
            }
            arr[ i ] = right - left ;
            right -- ;
        }
        else
        {
            int j = i - left ;
            if( i + arr[ j ] <= right )
            {
                arr[ i ] = arr[ j ] ;
            }
            else
            {
                left = i ;
                while( right < s.size() && s[ right ] == s[ right - left ] )
                {
                    right ++ ;
                }
                arr[ i ] = right - left ;
                right -- ;
            }
        }
    }
}


int main()
{
    string text = "aaabcxyzaaaabczaaczaaczabbaaaaaabc" ;
    string pattern = "aaabc" ;
    string s = pattern + "$" + text ;
    calculateZ( s ) ;

    for( int i = 0 ; i < s.size() ; i ++ )
    {
        if( arr[ i ] == pattern.size() )
        {
            cout << i - pattern.size() - 1 << " " ;
            v.pb( i - pattern.size() - 1 ) ;
        }
    }
    return 0 ;
}


Problem_2 :

https://www.youtube.com/watch?v=GTJr8OvyEVQ&ab_channel=TusharRoy-CodingMadeSimple
https://www.youtube.com/watch?v=KG44VoDtsAA&ab_channel=TusharRoy-CodingMadeSimple
Kmp algorithm

int arr[ 100005 ] ;

void creatingArray( string pattern )
{
    int j = 0, i = 1 ;
    while( i < pattern.size() )
    {
        if( pattern[ j ] == pattern[ i ] )
        {
            arr[ i ] = j + 1 ;
            i ++, j ++ ;
        }
        else
        {
            if( j != 0 ) j = arr[ j - 1 ] ;
            else arr[ i ] = 0, i ++ ;
        }
    }
}

bool check( string text, string pattern )
{
    creatingArray( pattern ) ;
    int i = 0, j = 0 ;
    while( i < text.size() && j < pattern.size() )
    {
        if( text[ i ] == pattern[ j ] )
        {
            i ++, j ++ ;
        }
        else
        {
            if( j != 0 ) j = arr[ j - 1 ] ;
            else i ++ ;
        }
        if( j == pattern.size() ) return true ;
    }

    return false ;
}

int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    if( check( s1, s2 ) ) cout << "Found" << endl ;
    else cout << "Not Found" << endl ;
    return 0 ;
}


Problem_3 :

https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

Add charater in any index to make it palindrome.
"mbadm" => "mbdadbm" ( 2 extra character needed)

class Solution
{
public:
    int minInsertions(string s1)
    {
        string s2 = s1 ;
        int n = s1.size() ;
        reverse( s2.begin(), s2.end() ) ;
        int dp[ n + 5 ][ n + 5 ] ;
        memset( dp, 0, sizeof dp ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            for( int j = 1 ; j <= n ; j ++ )
            {
                if( s1[ i - 1 ] == s2[ j - 1 ] )
                {
                    dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ] ;
                }
                else
                {
                    dp[ i ][ j ] = max( dp[ i - 1 ][ j ],dp[ i ][ j - 1 ] ) ;
                }
            }
        }

        return n - dp[ n ][ n ] ;
    }
};


Problem_4 :

https://leetcode.com/problems/valid-anagram/

s = "anagram", t = "nagaram" => Yes Anagram as both contains same character

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort( s.begin(),s.end() ) ;
        sort( t.begin(),t.end() ) ;
        if( s == t ) return true ;
        else return false ;
    }
};



Problem_5 :

https://leetcode.com/problems/count-and-say/


class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1" ;
        for( int j = 2 ; j <= n ; j ++ )
        {
            string str = "" ;
            int cnt = 1 ;
            for( int i = 0 ; i < s.size() ; i ++ )
            {
                if( ( i == s.size() - 1 ) || ( s[ i ] != s[ i + 1 ] ) )
                {
                    str += to_string( cnt ) ;
                    str += s[ i ] ;
                    cnt = 1 ;
                }
                else cnt ++ ;
            }
            s = str ;
        }
        return s ;
    }
};


Problem_6 :

https://leetcode.com/problems/compare-version-numbers/

"1.2"
"1.10"
Here first 1 and 1 Equal
Then compare the integer value and 10 is Greater than 2 ;

class Solution
{
public:
    int compareVersion(string s1, string s2)
    {
        vector< string > v1, v2 ;
        string str1 = "", str2 = ""  ;
        for( int i = 0 ; i < s1.size() ; i ++ )
        {
            if( i == s1.size() - 1 ) str1 += s1[ i ] ;
            if( s1[ i ] == '.' || ( i == s1.size() - 1 ) )
            {
                string s = "" ;
                for( int j = 0 ; j < str1.size() ; j ++ )
                {
                    if( str1[ j ] != '0' )
                    {
                        s = str1.substr( j, str1.size() ) ;
                        break ;
                    }
                }

                if( !s.empty() ) v1.push_back( s ) ;
                else v1.push_back( "0" ) ;

                str1 = "" ;
            }
            else
            {
                str1 += s1[ i ] ;
            }
        }

        for( int i = 0 ; i < s2.size() ; i ++ )
        {
            if( i == s2.size() - 1 ) str2 += s2[ i ] ;
            if( s2[ i ] == '.' || ( i == s2.size() - 1 ) )
            {
                string s = "" ;
                for( int j = 0 ; j < str2.size() ; j ++ )
                {
                    if( str2[ j ] != '0' )
                    {
                        s = str2.substr( j, str2.size() ) ;
                        break ;
                    }
                }

                if( !s.empty() ) v2.push_back( s ) ;
                else v2.push_back( "0" ) ;

                str2 = "" ;
            }
            else
            {
                str2 += s2[ i ] ;
            }
        }


        int n = max( v1.size(), v2.size() ) ;
        for( int i = v1.size() ; i < n ; i ++ ) v1.push_back( "0" ) ;
        for( int i = v2.size() ; i < n ; i ++ ) v2.push_back( "0" ) ;

        for( int i = 0 ; i < n ; i ++ )
        {
            string a = v1[ i ] ;
            string b = v2[ i ] ;
            if( a.size() > b.size() ) return 1 ;
            else if( a.size() < b.size() ) return -1 ;
            else
            {
                if( a > b ) return 1 ;
                else if( a < b ) return -1 ;
            }
        }
        return 0 ;
    }
};
