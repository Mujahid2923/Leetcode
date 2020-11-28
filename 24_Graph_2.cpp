Problem_1 :
-----------


SSC

vector< int > adj[ 1000 ],radj[ 1000 ],result[ 1000 ] ;
int visited1[ 1000 ],visited2[ 1000 ] ;
stack< int > st ;

void dfs( int u )
{
    visited1[ u ] = 1 ;
    for( int i = 0 ; i < adj[ u ].size() ; i ++ )
    {
        int v = adj[ u ][ i ] ;
        if( visited1[ v ] == 0 )
        {
            dfs(v);
        }
    }
    st.push( u ) ;
}

void dfs2( int u,int mark )
{
    result[ mark ].pb( u ) ;
    visited2[ u ] = 1 ;
    for( int i = 0 ; i < radj[ u ].size() ; i ++ )
    {
        int v = radj[ u ][ i ] ;
        if( visited2[ v ] == 0 )
        {
            dfs2( v, mark ) ;
        }
    }
}

int main()
{
    int node, edge, a, b ;
    cin >> node >> edge ;
    for( int i = 0 ; i < edge ; i ++ )
    {
        cin >> a >> b ;
        adj[ a ].pb( b ) ;
        radj[ b ].pb( a ) ;
    }

    for( int i = 1 ; i <= node ; i ++ )
    {
        if( visited1[ i ] == 0 )
        {
            dfs( i ) ;
        }
    }

    int mark = 0 ;
    while( !st.empty() )
    {
        int u = st.top() ;
        st.pop() ;
        if( visited2[ u ] == 0 )
        {
            mark ++ ;
            dfs2( u, mark ) ;
        }
    }

    cout << "There are " << mark << " component" << endl;
    for( int i = 1 ; i <= mark ; i ++ )
    {
        for( int j = 0 ; j < result[ i ].size() ; j ++ )
        {
            cout << result[ i ][ j ] << " " ;
        }
        cout << endl ;
    }
    return 0;
}


Problem_2 :
-----------

https://leetcode.com/problems/network-delay-time/
Dijkstra

class Solution
{
    vector< int > adj[ 105 ], cost[ 105 ] ;
    int dist[ 105 ] ;

    void Dijkstra( int s )
    {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq ;
        pq.push( { 0, s } ) ;
        dist[ s ] = 0 ;

        while( !pq.empty() )
        {
            int u = pq.top().second ;
            pq.pop() ;

            for( int i = 0 ; i < adj[ u ].size() ; i ++ )
            {
                int v = adj[ u ][ i ] ;
                if( cost[ u ][ i ] + dist[ u ] < dist[ v ] )
                {
                    dist[ v ] = cost[ u ][ i ] + dist[ u ] ;
                    pq.push( { dist[ v ], v } ) ;
                }
            }
        }
    }

public:
    int networkDelayTime(vector<vector<int>>& vec, int n, int s)
    {
        for( int i = 0 ; i <= n ; i ++ ) dist[ i ] = 1e6 ;
        for( int i = 0 ; i < vec.size() ; i ++ )
        {
            int u = vec[ i ][ 0 ] ;
            int v = vec[ i ][ 1 ] ;
            int w = vec[ i ][ 2 ] ;
            adj[ u ].push_back( v ) ;
            cost[ u ].push_back( w ) ;
        }

        Dijkstra( s ) ;
        int ans = -1 ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            if( dist[ i ] == 1e6 ) return -1 ;
            ans = max( ans, dist[ i ] ) ;
        }
        return ans ;
    }
};



https://leetcode.com/problems/cheapest-flights-within-k-stops

Source to destination Using k number of nodes.
If not reachable using k node return -1 ;

typedef pair<pair<int, int>, int>  pii ;
class Solution
{
    vector< int > adj[ 105 ], cost[ 105 ] ;

    int Dijkstra( int s, int d, int k )
    {
        priority_queue< pii, vector<pii>, greater<pii> > pq ;
        pq.push( { { 0, s }, k } ) ;

        while( !pq.empty() )
        {
            pii val = pq.top() ;
            pq.pop() ;
            int w = val.first.first ;
            int u = val.first.second ;
            int remain_node = val.second ;
            if( u == d ) return w ;

            if( remain_node )
            {
                for( int i = 0 ; i < adj[ u ].size() ; i ++ )
                {
                    int v = adj[ u ][ i ] ;
                    pq.push( { { w + cost[ u ][ i ], v }, remain_node - 1 } ) ;
                }
            }
        }
        return -1 ;
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& vec, int s, int d, int k)
    {
        for( int i = 0 ; i < vec.size() ; i ++ )
        {
            int u = vec[ i ][ 0 ] ;
            int v = vec[ i ][ 1 ] ;
            int w = vec[ i ][ 2 ] ;
            adj[ u ].push_back( v ) ;
            cost[ u ].push_back( w ) ;
        }

        return Dijkstra( s, d, k + 1 ) ;
    }
};


Problem_3 :
------------

Bellman Ford( used in weighted graph and used to detect weather there is a negative cycle or not but can not give ans in negative cycle )

/// Main Code
bool Bellmanford( int s )
{
    for( int i = 1 ; i <= n ; i ++ ) dist[ i ] = INT_MAX ;
    dist[ s ] = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++  )
        {
            ll u = j ;
            for( int k = 0 ; k < adj[ u ].size() ; k ++ )
            {
                ll v = adj[ u ][ k ] ;
                ll w = cost[ u ][ k ] ;
                if( dist[ u ] + w < dist[ v ] ) dist[ v ] = dist[ u ] + w ;
            }
        }
    }

    for( int j = 1 ; j <= n ; j ++  )
    {
        ll u = j ;
        for( int k = 0 ; k < adj[ u ].size() ; k ++ )
        {
            ll v = adj[ u ][ k ] ;
            ll w = cost[ u ][ k ] ;
            if( dist[ u ] + w < dist[ v ] ) return false ; /// Negative cycle
        }
    }
    return true ; // All ok
}


Problem_4 :
------------

https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

FloydWarshall ( All Pair shortest path)

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>>& vec, int x)
    {
        int dist[ n ][ n ] ;
        for( int i = 0 ; i < n ; i ++ )
        {
            for( int j = 0 ; j < n ; j ++ )
            {
                dist[ i ][ j ] = INT_MAX ;
            }
        }

        for( int idx = 0 ; idx < vec.size() ; idx ++ )
        {
            int i = vec[ idx ][ 0 ] ;
            int j = vec[ idx ][ 1 ] ;
            int w = vec[ idx ][ 2 ] ;
            dist[ i ][ j ] = dist[ j ][ i ] = w ;
        }

        for( int k = 0 ; k < n ; k ++ )
        {
            for( int i = 0 ; i < n ; i ++ )
            {
                for( int j = 0 ; j < n ; j ++ )
                {
                    if( dist[ i ][ k ] != INT_MAX && dist[ k ][ j ] != INT_MAX )
                    {
                        if( dist[ i ][ k ] + dist[ k ][ j ] < dist[ i ][ j ] )
                        {
                            dist[ i ][ j ] =  dist[ i ][ k ] + dist[ k ][ j ] ;
                        }
                    }
                }
            }
        }

        int ans = INT_MAX, node = INT_MAX ;

        for( int i = 0 ; i < n ; i ++ )
        {
            int cnt = 0 ;
            for( int j = 0 ; j < n ; j ++ )
            {
                if( i != j && dist[ i ][ j ] <= x ) cnt ++ ;
            }

            if( cnt <= ans )
            {
                node = i ;
                ans = cnt ;
            }
        }
        return node ;
    }
};



Problem_5 :
------------

Minumum Spanning tree( MST ) Kruskal

typedef pair< int, pair<int,int>> pii ;

int parent[ 105 ] ;

vector < pii > vec ;

int Find( int r )
{
    if( r == parent[ r ] ) return r ;
    else return parent[ r ] = Find( parent[ r ] ) ;
}

int kruskal( int n )
{
    for( int i = 1 ; i <= n ; i ++ ) parent[ i ] = i ;

    int cnt = 0, sum = 0 ;

    for( int i = 0 ; i < vec.size() ; i ++ )
    {
        int u = Find( vec[ i ].second.first ) ;
        int v = Find( vec[ i ].second.second ) ;
        if( u != v )
        {
            parent[ u ] = v ;
            sum += vec[ i ].first ;
            cnt ++ ;
            if( cnt == n - 1 ) break ;
        }
    }
    return sum ;
}
