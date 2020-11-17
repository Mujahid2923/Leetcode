Problem_1 :

https://www.interviewbit.com/problems/meeting-rooms/

Minimum number of conference rooms required so that all meetings can be done.
[1, 18] [18, 23] [15, 29] [4, 15] [2, 11] [5, 13] => 4 rooms needed ;

int Solution::solve(vector<vector<int> > &A)
{
    vector< pair< int, int > > vec ;
    for( int i = 0 ; i < A.size() ; i ++ )
    {
        vec.push_back( { A[ i ][ 0 ], 1 } ) ;
        vec.push_back( { A[ i ][ 1 ], -1 } ) ;
    }
    sort( vec.begin(), vec.end() );
    int ans = 0, cnt = 0 ;
    for( int i = 0 ; i < vec.size() ; i ++ )
    {
        cnt += vec[ i ].second ;
        ans = max( ans, cnt ) ;
    }
    return ans ;
}

Problem_2 :

https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

Minimum number of arrows that must be shot to burst all balloons.

[[1,10],[3,9],[4,11],[6,7],[6,9],[8,12],[9,12]] => 2 ;
Here,use 7 to blust 4 balloons [1,10],[3,9],[4,11],[6,7] ;
and 12 to blust 2 ballons [8,12],[9,12] ;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& vec )
    {
        sort( vec.begin(), vec.end() ) ;
        int n = vec.size(), ans = 0 ;
        for( int i = 0, j = 0 ; i < n ; i = j )
        {
            ans ++ ;
            int mx = vec[ i ][ 1 ] ;
            for( j = i + 1 ; j < n ; j ++ )
            {
                if( vec[ j ][ 0 ] > mx ) break ;
                else mx = min( mx, vec[ j ][ 1 ] ) ;
            }
        }
        return ans ;
    }
};

Problem_3 :

https://leetcode.com/problems/coin-change/

Fewest number of coins that you need to make up that amount( Unbound Knapsack )
Coin Change ( unlimited Coins )

Input - coins = [1,2,5], amount = 11 ;
Output - 3 ;
Explanation - 11 = 5 + 5 + 1 ;

class Solution
{
public:
    int coinChange(vector<int>& v, int cap )
    {
        int n = v.size() ;
        int dp[ 10005 ] ;
        dp[ 0 ] = 0 ;
        for( int i = 1 ; i <= cap ; i ++ )
        {
            dp[ i ] = 100000 ;
        }
        for( int i = 0 ; i < n ; i ++ )
        {
            for( int j = 1 ; j <= cap ; j ++ )
            {
                if( j >= v[ i ] ) dp[ j ] = min( dp[ j ], 1 + dp[ j - v[ i ] ] ) ;
            }
        }
        if( dp[ cap ] == 100000  ) dp[ cap ] = -1 ;
        return dp[ cap ] ;
    }
};



Problem_4 :

https://www.geeksforgeeks.org/fractional-knapsack-problem/

Greddy Knapsack or Fractional Knapsack.

N = 3, W = 50 ;
values[] = {60,100,120} ;
weight[] = {10,20,30} ;
Output = 240.00 ;

struct Item
{
    int value;
    int weight;
};

double fractionalKnapsack(int w, Item arr[], int n)
{
    vector< pair< double, int > > vec ;
    for( int i = 0 ; i < n ; i ++ )
    {
        double x = ( double )arr[ i ].value / ( double )arr[ i ].weight ;
        vec.push_back( { x, arr[ i ].weight } ) ;
    }

    sort( vec.rbegin(), vec.rend() ) ;

    double ans = 0 ;

    for( int i = 0 ; i < n ; i ++ )
    {
        if( w >= vec[ i ].second )
        {
            ans += vec[ i ].second * vec[ i ].first ;
            w -= vec[ i ].second ;
        }
        else
        {
            ans += vec[ i ].first * w ;
            break ;
        }
    }
    return ans ;
}

without extra memory ;

bool cmp( Item A, Item B )
{
    double a = ( double )A.value / ( double )A.weight ;
    double b = ( double )B.value / ( double )B.weight ;
    return a > b ;
}


double fractionalKnapsack(int w, Item arr[], int n)
{
    sort( arr, arr + n, cmp ) ;
    double ans = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( w >= arr[ i ].weight )
        {
            ans += arr[ i ].value ;
            w -= arr[ i ].weight ;
        }
        else
        {
            ans += ( ( double )arr[ i ].value / ( double )arr[ i ].weight ) * w ;
            break ;
        }
    }
    return ans ;
}


Problem_5 :

https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

Minimum Number of Platforms Required For a Railway or Bus Station


bool cmp( pair< int, int > A, pair< int, int > B )
{
    if( A.first < B.first ) return true ;
    else if( A.first == B.first )
    {
        if( A.second > B.second ) return true ;
    }
    return false ;
}

int findPlatform(int arr[], int dep[], int n)
{
    vector< pair< int, int > > vec ;
    for( int i = 0 ; i < n ; i ++ )
    {
        vec.push_back( { arr[ i ], 1 } ) ;
        vec.push_back( { dep[ i ], -1 } ) ;
    }
    sort( vec.begin(), vec.end(), cmp ) ;
    int ans = 0, cnt = 0 ;
    for( int i = 0 ; i < vec.size() ; i ++ )
    {
        cnt += vec[ i ].second ;
        ans = max( ans, cnt ) ;
    }
    return ans ;
}

Problem_6 :

https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

The task is to Find the maximum profit and the number of jobs done.( bari sir er tutorial )
N = 4, Jobs = ( id, deadline, profit ) (1,4,20)(2,1,10)(3,1,40)(4,1,30) - Output - 2 60


struct Job
{
    int id;
    int dead;
    int profit;
};


bool cmp( Job A, Job B )
{
    if( A.profit > B.profit ) return true ;
    if( A.profit == B.profit )
    {
        if( A.dead > B.dead ) return true ;
    }
    return false ;
}

pair<int,int> JobScheduling(Job arr[], int n)
{
    sort( arr, arr + n, cmp ) ;
    int sum = 0, mx = 0, cnt = 0 ;
    set< int > st ;
    for( int i = 0 ; i < n ; i ++ ) mx = max( mx, arr[ i ].dead ) ;
    for( int i = 1 ; i <= mx ; i ++ ) st.insert( i ) ;

    for( int i = 0 ; i < n ; i ++ )
    {
        auto it = st.lower_bound( arr[ i ].dead ) ;
        if( it == st.end() ) it -- ;
        if( *it <= arr[ i ].dead )
        {
            cnt ++ ;
            sum += arr[ i ].profit ;
            st.erase( it ) ;
        }
        else
        {
            if( it != st.begin() ) it -- ;
            if( *it <= arr[ i ].dead )
            {
                cnt ++ ;
                sum += arr[ i ].profit ;
                st.erase( it ) ;
            }
        }
        if( st.empty() ) break ;
    }
    return { cnt, sum } ;
}
