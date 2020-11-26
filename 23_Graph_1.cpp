Problem_1 :
-----------

https://leetcode.com/problems/clone-graph/

Clone Graph
class Node
{
public:
    int val;
    vector<Node*> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    Node* dfs( Node* node,  map< int, Node* >& visited )
    {
        Node* u = new Node( node -> val ) ;
        visited[ node -> val ] = u ;

        for( Node* v : node -> neighbors )
        {
            if( visited[ v -> val ] == NULL )
            {
                Node* temp = dfs( v, visited ) ;
                u -> neighbors.push_back( temp ) ;
            }
            else
            {
                u -> neighbors.push_back( visited[ v -> val ] ) ;
            }
        }
        return u ;
    }

public:
    Node* cloneGraph( Node* node )
    {
        if( node == NULL ) return NULL ;
        map< int, Node* > visited ;
        return dfs( node, visited ) ;
    }
};


Problem_2 :
-----------

#Dfs

void dfs( int u )
{
    visited[ u ] = 1 ;
    for( auto v : adj[ u ] )
    {
        if( !visited[ v ] ) dfs( v ) ;
    }
}

#level,start & Finish time :

int cnt = 0 ;
int start[ 200005 ] ;
int finish[ 200005 ] ;
int level[ 200005 ] ;

int dfs( int u, int p, int lev )
{
    start[ u ] = ++ cnt ;
    for( auto v : adj[ u ] )
    {
        if( v != p )
        {
            dfs( v, u, lev + 1 ) ;
        }
    }
    finish[ u ] = ++ cnt ;
    level[ u ] = lev ;
}

dfs( 1, 0, 0 ) ;
level - level[ i ] ;
number of  child -> ( finish[ i ] - start[ i ] ) / 2

#leaf number :

void dfs( int u, int p, int w )
{
    child[ u ] = 0 ;
    int ok = 0 ;
    for( int i = 0 ; i < adj[ u ].size() ; i ++ )
    {
        int v = adj[ u ][ i ] ;
        int val = cost[ u ][ i ] ;
        if( v != p )
        {
            dfs( v, u, val ) ;
            ok ++ ;
            child[ u ] += child[ v ] ;
        }
    }
    if( !ok ) child[ u ] ++ ;
    arr[ u ] = w ;
}


Problem_3 :
-----------

Bfs

void bfs( int s )
{
    queue< int > Q;
    Q.push( s ) ;
    level[ s ] = 0 ;
    visited[ s ] = 1 ;

    while( !Q.empty() )
    {
        int u = Q.front();
        Q.pop();

        for( auto v : adj[ u ] )
        {
            if( !visited[ v ] )
            {
                level[ v ] = level[ u ] + 1 ;
                Q.push( v ) ;
                visited[ v ] = 1 ;
            }
        }
    }
}


Problem_4 :
-----------

Cycle in a Graph

https://leetcode.com/problems/course-schedule/

class Solution
{
    vector< int > adj[ 100005 ] ;
    int visited[ 100005 ] ;
    int detectcycle = 0 ;

    void Cycle( int u )
    {
        visited[ u ] = 1 ;
        for( auto v : adj[ u ] )
        {
            if( !visited[ v ] ) Cycle( v ) ;
            else if( visited[ v ] == 1 )
            {
                detectcycle = 1 ;
                return ;
            }
        }
        visited[ u ] = 2 ;
    }
public:
    bool canFinish(int n, vector<vector<int>>& vec)
    {
        for( int i = 0 ; i < vec.size() ; i ++ )
        {
            adj[ vec[ i ][ 1 ] ].push_back( vec[ i ][ 0 ] ) ;
        }

        for( int i = 0 ; i < n ; i ++ )
        {
            if( !visited[ i ] )
            {
                Cycle( i ) ;
                if( detectcycle ) return false ;
            }
        }

        for( int i = 0 ; i < n ; i ++ )
        {
            if( !visited[ i ] ) return false ;
        }

        return true ;
    }
};

https://leetcode.com/problems/course-schedule-ii/

class Solution
{
    vector< int > adj[ 2005 ] ;
    int detectcycle = 0 ;
    int visited[ 2005 ] ;
    stack< int > Stk ;

    void Cycle( int u )
    {
        visited[ u ] = 1 ;
        for( auto v : adj[ u ] )
        {
            if( !visited[ v ] ) Cycle( v ) ;
            else if( visited[ v ] == 1 )
            {
                detectcycle = 1 ;
                return ;
            }
        }
        visited[ u ] = 2 ;
        Stk.push( u ) ;
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& vec)
    {
        vector<int> v ;
        for( int i = 0 ; i < vec.size() ; i ++ )
        {
            adj[ vec[ i ][ 0 ] ].push_back( vec[ i ][ 1 ] ) ;
        }

        for( int i = 0 ; i < n ; i ++ )
        {
            if( !visited[ i ] )
            {
                Cycle( i ) ;
                if( detectcycle ) return v ;
            }
        }
        for( int i = 0 ; i < n ; i ++ )
        {
            if( !visited[ i ] ) return v ;
        }

        while( !Stk.empty() )
        {
            v.push_back( Stk.top() ) ;
            Stk.pop() ;
        }

        reverse( v.begin(), v.end() ) ; // In top sort reverse doesn't occur

        return v ;
    }
};



Problem_5 :
-----------

Topological Sort

#Indegree_Bfs

Use one of three
queue< int > Q ; // as usual
priority_queue< int,vector<int>,greater<int> > PQ ; // If said to sort according to priority of small to big
priority_queue< int > PQ ; // If said to sort according to priority of big to small

vector< int > ans ;
int arr[ 100000 ] ;
int visited[ 100000 ] ;

Input()
{
    cin >> n ;
    for( int i = 1 ; i < n ; i ++ )
    {
        cin >> a >> b ;
        adj[ a ].push_back( b ) ;
        arr[ b ] ++ ;
    }
}

Calculation()
{
    for( int i = 1 ; i <= n ; i ++ )
    {
        if( arr[ i ] == 0 )
        {
            visited[ i ] = 1 ;
            Q.push( i ) ;
            ans.push_back( i ) ;
        }
    }

    while( !Q.empty() )
    {
        int u = Q.front() ;
        Q.pop() ;

        for( auto v : adj[ u ] )
        {
            arr[ v ] -- ;
            if( arr[ v ] == 0 && visited[ v ] == 0 )
            {
                visited[ v ] = 1 ;
                Q.push( v ) ;
                ans.push_back( v ) ;
            }
        }
    }

    for( int i = 1 ; i <= n ; i ++ )
    {
        if( arr[ i ] != 0 ) cout << "Cycle" << endl ;
    }

    for( auto x : ans ) cout << x << " " ;
}

#Dfs

Same as problem-4 part-2 except Reverse in the Vector .




Problem_6 :
-----------

https://leetcode.com/problems/number-of-islands/

Number of Island
can go adjacent lands horizontally or vertically.
["1","1","0","0","0"]
["1","1","0","0","0"]
["0","0","1","0","0"]
["0","0","0","1","1"]
=> 3


class Solution
{
    int row, col ;
    int visited[ 305 ][ 305 ] ;

    bool isValid( vector<vector<char>>& arr, int x, int y )
    {
        if( x >= 0 && x < row && y >= 0 && y < col && !visited[ x ][ y ] && arr[ x ][ y ] == '1' )
        {
            visited[ x ][ y ] = 1 ;
            return true ;
        }
        return false ;
    }

    void bfs(vector<vector<char>>& arr, int x, int y )
    {
        queue< pair< int, int > > Q ;
        Q.push( { x, y } ) ;
        visited[ x ][ y ] = 1 ;
        while( !Q.empty() )
        {
            int xx = Q.front().first, yy = Q.front().second ;
            Q.pop() ;
            if( isValid( arr, xx + 1, yy ) ) Q.push( { xx + 1, yy } ) ;
            if( isValid( arr, xx - 1, yy ) ) Q.push( { xx - 1, yy } ) ;
            if( isValid( arr, xx, yy + 1 ) ) Q.push( { xx, yy + 1 } ) ;
            if( isValid( arr, xx, yy - 1 ) ) Q.push( { xx, yy - 1 } ) ;
        }
    }

public:
    int numIslands(vector<vector<char>>& vec)
    {
        row = vec.size(), col = vec[ 0 ].size() ;
        int cnt = 0 ;
        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                if( vec[ i ][ j ] == '1' && !visited[ i ][ j ] )
                {
                    cnt ++ ;
                    bfs( vec, i, j ) ;
                }
            }
        }
        return cnt ;
    }
};


Problem_7 :
-----------

https://leetcode.com/problems/is-graph-bipartite/

Is Graph Bipartite?

class Solution
{
    vector< int > adj[ 105 ] ;
    int visited[ 105 ] ;
    int bicolorable = 0 ;

    void bfs( int s )
    {
        queue< int > Q ;
        Q.push( s ) ;
        visited[ s ] = 1 ;

        while( !Q.empty() )
        {
            int u = Q.front() ;
            Q.pop() ;

            for( auto v : adj[ u ] )
            {
                if( !visited[ v ] )
                {
                    Q.push( v ) ;
                    if( visited[ u ] == 1 ) visited[ v ] = 2 ;
                    else visited[ v ] = 1 ;
                }

                if( visited[ u ] == visited[ v ] )
                {
                    bicolorable = 1 ;
                    return ;
                }
            }
        }
    }

public:
    bool isBipartite(vector<vector<int>>& vec)
    {
        int n = vec.size() ;
        for( int i = 0 ; i < n ; i ++ )
        {
            for( auto x : vec[ i ] )
            {
                adj[ i ].push_back( x ) ;
            }
        }

        for( int i = 0 ; i < n ; i ++ )
        {
            if( !visited[ i ] )
            {
                bfs( i ) ;
                if( bicolorable ) return false ;
            }
        }
        return true ;
    }
};
