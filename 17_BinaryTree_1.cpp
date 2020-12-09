Problem_1 :
-----------
https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution
{
    void Fun( vector< int >& v, TreeNode* root )
    {
        if( root == NULL ) return ;
        Fun( v, root -> left ) ;
        v.push_back( root -> val ) ;
        Fun( v, root -> right ) ;
    }


public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector< int > v ;
        Fun( v, root ) ;
        return v ;
    }
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector< int > v ;
        stack< TreeNode* > Stk ;

        while( root || !Stk.empty() )
        {
            while( root )
            {
                Stk.push( root ) ;
                root = root -> left ;
            }

            root = Stk.top() ;
            Stk.pop() ;

            v.push_back( root -> val ) ;
            root = root -> right ;
        }
        return v ;
    }
};

Problem_2 :
-----------
https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution
{
    vector<int> v ;
    void Fun( TreeNode* root )
    {
        if( !root ) return ;
        v.push_back( root -> val ) ;
        Fun( root -> left ) ;
        Fun( root -> right ) ;
    }

public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        Fun( root ) ;
        return v ;
    }
};


class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector< int > v ;
        stack< TreeNode* > Stk ;

        while( !Stk.empty() || root )
        {
            while( root )
            {
                v.push_back( root -> val ) ;
                Stk.push( root ) ;
                root = root -> left ;
            }

            root = Stk.top() ;
            Stk.pop() ;
            root = root -> right ;
        }

        return v ;
    }
};

Problem_3 :
-----------
https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution
{
    vector<int> v ;
    void Fun( TreeNode* root )
    {
        if( !root ) return ;
        Fun( root -> left ) ;
        Fun( root -> right ) ;
        v.push_back( root -> val ) ;
    }
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        Fun( root ) ;
        return v ;
    }
};



class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector< int > v ;
        stack< TreeNode* > Stk ;

        while( !Stk.empty() || root )
        {
            while( root )
            {
                v.push_back( root -> val ) ;
                Stk.push( root ) ;
                root = root -> right ;
            }

            root = Stk.top() ;
            Stk.pop() ;
            root = root -> left ;
        }

        reverse( v.begin(), v.end() ) ;

        return v ;
    }
};

Problem_4 :
-----------
https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#Left_side_view

void Fun( Node* root, int level, vector<int>& v )
{
    if( !root ) return ;
    if( v.size() <= level ) v.push_back( root -> data ) ;
    Fun( root -> left, level + 1, v ) ;
    Fun( root -> right, level + 1, v ) ;
}

vector<int> leftView( Node *root )
{
    vector<int> v ;
    Fun( root, 0, v ) ;
    return v ;
}


https://leetcode.com/problems/binary-tree-right-side-view/

#Right_side_view

class Solution
{
    void Fun( TreeNode* root, int level, vector<int>& v )
    {
        if( !root ) return ;
        if( v.size() <= level ) v.push_back( root -> val ) ;
        Fun( root -> right, level + 1, v ) ;
        Fun( root -> left, level + 1, v ) ;
    }
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> v ;
        Fun( root, 0, v ) ;
        return v ;
    }
};


Problem_5 :
-----------
https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
https://www.youtube.com/watch?v=V7alrvgS5AI&ab_channel=VivekanandKhyade-AlgorithmEveryDay

vector <int> bottomView(Node *root)
{
    queue< pair< int, Node* > > Q ;
    if( root ) Q.push( { 0, root } ) ;
    map< int, int > Mp ;

    while( !Q.empty() )
    {
        pair< int,Node* > temp = Q.front() ;
        Q.pop() ;
        Mp[ temp.first ] = temp.second -> data ;
        if( temp.second -> left ) Q.push( { temp.first - 1, temp.second -> left } ) ;
        if( temp.second -> right ) Q.push( { temp.first + 1, temp.second -> right } ) ;
    }
    vector< int > v ;
    for( auto x : Mp )
    {
        v.push_back( x.second ) ;
    }
    return v ;
}

Problem_6 :
-----------

https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
https://www.youtube.com/watch?v=c3SAvcjWb1E&ab_channel=VivekanandKhyade-AlgorithmEveryDay

vector <int> topView(struct Node *root)
{
    queue< pair< int, Node* > > Q ;
    if( root ) Q.push( { 0, root } ) ;
    map< int, Node* > Mp ;
    while( !Q.empty() )
    {
        pair< int,Node* > temp = Q.front() ;
        Q.pop() ;
        if( Mp[ temp.first ] == nullptr ) Mp[ temp.first ] = temp.second ;
        if( temp.second -> left ) Q.push( { temp.first - 1, temp.second -> left } ) ;
        if( temp.second -> right ) Q.push( { temp.first + 1, temp.second -> right } ) ;
    }

    vector< int > v ;
    for( auto x : Mp )
    {
        v.push_back( x.second -> data ) ;
    }
    return v ;
}
