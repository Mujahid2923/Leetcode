Problem_1 :
-----------
https://leetcode.com/problems/binary-tree-level-order-traversal/
#bfs

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> vec ;
        if( root == NULL ) return vec ;
        int level = 0 ;
        vector< int > adj[ 10005 ] ;
        queue< pair< TreeNode*, int > > Q ;
        Q.push( { root, 0 } ) ;
        while( !Q.empty() )
        {
            pair< TreeNode*, int > temp = Q.front() ;
            Q.pop() ;

            level = max( level,temp.second ) ;
            adj[ temp.second ].push_back( temp.first -> val ) ;

            if( temp.first -> left != NULL ) Q.push( { temp.first -> left, temp.second + 1 } ) ;
            if( temp.first -> right != NULL ) Q.push( { temp.first -> right, temp.second + 1 } ) ;
        }

        for( int i = 0 ; i <= level ; i ++ )
        {
            vector<int> v ;
            for( auto x : adj[ i ] ) v.push_back( x ) ;
            vec.push_back( v ) ;
        }
        return vec ;
    }
};

Problem_2 :
-----------
https://leetcode.com/problems/maximum-depth-of-binary-tree/

#Depth

class Solution
{
    int Fun( TreeNode* root )
    {
        if( !root ) return 0 ;
        return 1 + max( Fun( root -> left ), Fun( root -> right ) ) ;
    }
public:
    int maxDepth(TreeNode* root)
    {
        return Fun( root ) ;
    }
};


Problem_3 :
-----------
https://leetcode.com/problems/diameter-of-binary-tree/
https://www.youtube.com/watch?v=ey7DYc9OANo&ab_channel=VivekanandKhyade-AlgorithmEveryDay

#Diameter

class Solution
{
public:

    int Height( TreeNode* root )
    {
        if( root == nullptr ) return -1 ;
        return 1 + max( Height( root -> left ), Height( root -> right ) ) ;
    }

    int Fun( TreeNode* root )
    {
        if( root == nullptr ) return 0 ;
        int Lheight = Height( root -> left ) ;
        int Rheight = Height( root -> right ) ;
        return max( Lheight + Rheight + 2, max( Fun( root -> left ), Fun( root -> right ) ) ) ;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        return Fun( root ) ;
    }
};

Problem_4 :
-----------
https://leetcode.com/problems/balanced-binary-tree/

class Solution
{
public:

    int Height( TreeNode* root )
    {
        if( root == nullptr ) return 0 ;
        return 1 + max( Height( root -> left ), Height( root -> right ) ) ;
    }

    int Fun( TreeNode* root )
    {
        if( root == nullptr ) return 1 ;
        int Lheight = Height( root -> left ) ;
        int Rheight = Height( root -> right ) ;
        return max( Lheight + Rheight + 1, max( Fun( root -> left ), Fun( root -> right ) ) ) ;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        return Fun( root ) - 1 ;
    }
};

Problem_5 :
-----------
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
#LCA

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if( !root ) return root ;
        if( root == p || root == q ) return root ;

        TreeNode* L = lowestCommonAncestor( root -> left, p, q ) ;
        TreeNode* R = lowestCommonAncestor( root -> right, p, q ) ;

        if( L == NULL && R == NULL ) return NULL ;
        if( L != NULL && R != NULL ) return root ;
        return L ? L : R ;
    }
};

Problem_6 :
-----------
https://leetcode.com/problems/same-tree/
#SameTree

class Solution
{
    bool Fun( TreeNode* p, TreeNode* q )
    {
        if( !p && !q ) return true ;
        if( ( !p || !q ) || ( p -> val != q -> val ) ) return false ;
        return Fun( p -> left, q -> left ) && Fun( p -> right, q -> right ) ;
    }

public:
    bool isSameTree( TreeNode* p, TreeNode* q )
    {
        return Fun( p, q ) ;
    }
};
