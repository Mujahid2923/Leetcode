Problem_1 :

https://leetcode.com/problems/combination-sum/

[2,3,5], target = 8 Output - [[2,2,2,2],[2,3,3],[3,5]] ;

class Solution
{
    void Fun( vector<vector<int>>& vec, vector<int>& v, vector<int>& ans, int pos, int sum, int target )
    {
        if( sum == target )
        {
            vec.push_back( ans ) ;
            return ;
        }
        if( pos == v.size() ) return ;

        if( v[ pos ] + sum <=  target )
        {
            ans.push_back( v[ pos ] ) ;
            Fun( vec, v, ans, pos, sum + v[ pos ], target ) ;
            ans.pop_back() ;
        }
        Fun( vec, v, ans, pos + 1, sum, target ) ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& v, int target)
    {
        vector<vector<int>> vec ;
        vector<int> ans ;
        Fun( vec, v, ans, 0, 0, target ) ;
        return vec ;
    }
};


Problem_2 :

https://leetcode.com/problems/combination-sum-ii/

class Solution
{
    void Fun( map< vector<int>, int >& Mp,vector<vector<int>>& vec, vector<int>& v, vector<int>& ans, int pos, int sum, int target )
    {
        if( sum == target )
        {
            if( !Mp[ ans ] ) vec.push_back( ans ) ;
            Mp[ ans ] = 1 ;
            return ;
        }
        if( pos == v.size() ) return ;

        if( sum + v[ pos ] <= target )
        {
            ans.push_back( v[ pos ] ) ;
            Fun( Mp, vec, v, ans, pos + 1, sum + v[ pos ], target ) ;
            ans.pop_back() ;
        }
        Fun( Mp, vec, v, ans, pos + 1, sum, target ) ;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& v, int target)
    {
        map< vector<int>, int > Mp ;
        vector<vector<int>> vec ;
        vector<int> ans ;
        sort( v.begin(), v.end() ) ;
        Fun( Mp, vec, v, ans, 0, 0, target ) ;
        return vec ;
    }
};

Problem_3 :

https://leetcode.com/problems/palindrome-partitioning/

Input: "aab"
Output:
["aa","b"],["a","a","b"]

class Solution
{
    bool isPalindrome( string str )
    {
        int n = str.size() ;
        for( int i = 0 ; i < n / 2 ; i ++ )
        {
            if( str[ i ] != str[ n - i - 1 ] ) return false ;
        }
        return true ;
    }
    void Fun( vector<vector<string>>&vec, vector<string>& v, string s, int n )
    {
        for( int i = 1 ; i <= n ; i ++ )
        {
            string str = s.substr( 0, i ) ;
            if( isPalindrome( str ) )
            {
                v.push_back( str ) ;
                if( i == n )
                {
                    vec.push_back( v ) ;
                    v.pop_back() ;
                    return ;
                }

                Fun( vec, v, s.substr( i, n - i ), n - i ) ;
                v.pop_back() ;
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> vec ;
        vector<string> v ;
        Fun( vec, v, s, s.size() ) ;
        return vec ;
    }
};


Problem_4 :

https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

Input - N = 4, arr = {1, 5, 11, 5} Output - YES
Explaination - The two parts are {1, 5, 5} and {11}

int Fun( int dp[ 50005 ], int pos, int n, int *arr, int sum )
{
    //cout << pos << " " << sum << endl ;
    if( sum == 0 ) return 1 ;
    if( pos == n ) return 0 ;
    if( dp[ sum ] != -1 ) return dp[ sum ] ;

    int ok = 0 ;
    if( sum - arr[ pos ] >= 0 )
    {
        ok = Fun( dp, pos + 1, n, arr, sum - arr[ pos ] ) ;
    }
    ok = max( ok, Fun( dp, pos + 1, n, arr, sum ) ) ;
    return dp[ sum ] = ok ;
}

class Solution
{
public:
    int equalPartition(int n, int arr[])
    {
        int dp[ 50005 ] ;
        memset( dp, -1, sizeof dp ) ;
        int sum = 0 ;
        for( int i = 0 ; i < n ; i ++ ) sum += arr[ i ] ;
        if( sum & 1 ) return 0 ;
        return Fun( dp, 0, n, arr, sum / 2 ) ;
    }
};



Problem_5 :

https://leetcode.com/problems/permutation-sequence/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string s = "" ;
        for( char ch = '1' ; n ; ch ++, n -- ) s += ch ;

        do
        {
            k -- ;
            if( k == 0 ) break ;
        }
        while( next_permutation( s.begin(), s.end() ) ) ;
        return s ;
    }
};
