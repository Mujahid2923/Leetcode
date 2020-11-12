Problem_1 :
https://leetcode.com/problems/reverse-linked-list/

Reverse a linked List

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *pre = NULL, *current = head, *post = NULL ;
        while( current )
        {
            post = current -> next ;
            current -> next = pre ;
            pre = current ;
            current = post ;
        }
        return pre ;
    }
};


class Solution
{
public:
    void Reverse( ListNode **head, ListNode* p )
    {
        if( p -> next == nullptr )
        {
            *head = p ;
            return ;
        }

        Reverse( head, p -> next ) ;
        ListNode *q = p -> next ;
        q -> next = p ;
        p -> next = nullptr ;
    }

    ListNode* reverseList(ListNode* head)
    {
        if( head == nullptr ) return head ;
        Reverse( &head, head ) ;
        return head ;
    }
};

Problem_2 :
https://leetcode.com/problems/middle-of-the-linked-list/

Middle of the Linked List

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* temp = head ;
        int cnt = 0 ;
        while( temp )
        {
            temp = temp -> next ;
            cnt ++ ;
        }
        cnt = cnt / 2 ;
        while( cnt )
        {
            head = head -> next ;
            cnt -- ;
        }
        return head ;
    }
};

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head ;
        ListNode* fast = head ;

        while( fast != NULL && fast -> next != NULL )
        {
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }

        return slow ;
    }
};


Problem_3 :
https://leetcode.com/problems/merge-two-sorted-lists/
Merge Two Sorted Lists

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* last = new ListNode() ;
        ListNode* first = last ;

        while( l1 != nullptr && l2 != nullptr )
        {
            if( l1 -> val < l2 -> val )
            {
                last -> next = l1 ;
                last = l1 ;
                l1 = l1 -> next ;
            }
            else
            {
                last -> next = l2 ;
                last = l2 ;
                l2 = l2 -> next ;
            }
        }

        if( l1 != nullptr )
        {
            last -> next = l1 ;
            last = l1 ;
        }

        if( l2 != nullptr )
        {
            last -> next = l2 ;
            last = l2 ;
        }

        first = first -> next ;
        return first ;
    }
};


Problem_4 :
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Remove Nth Node From End of List [1,2,3,4,5], n = 2 => [1,2,3,5] ;

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int cnt = 0, sum = 0 ;
        ListNode* temp = head, *now = head ;
        while( temp )
        {
            cnt ++ ;
            temp = temp -> next ;
        }
        cnt = cnt - n ;
        if( !cnt ) return head -> next ;

        for( int i = 1 ; i < cnt ; i ++ )
        {
            now = now -> next ;
        }
        //ListNode* remove = now -> next ; If they said to dfelete that node
        now -> next = now -> next -> next ;
        //delete remove ;
        return head ;
    }
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *slow = head, *fast = head ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            fast = fast -> next ;
        }
        if( fast == NULL ) return head -> next ;
        while( fast -> next )
        {
            fast = fast -> next ;
            slow = slow -> next ;
        }

        slow -> next = slow -> next -> next ;
        return head ;
    }
};


Problem_5 :
https://leetcode.com/problems/delete-node-in-a-linked-list/

[4,5,1,9], node = 5 => [4,1,9] ;

To Delete node we neet it address, we Do not have address. So we put next value in that
present value and Delete that next address.

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node -> val = node -> next -> val ;
        ListNode* temp = node -> next ;
        node -> next = node -> next -> next ;
        delete temp ;
    }
};

Problem_6 :
https://leetcode.com/problems/add-two-numbers/

Input - Given to Liked List
l1 = [2,4,3], l2 = [5,6,4] Output - [7,0,8] Explanation - 342 + 465 = 807 ;

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int a = 0, b = 0 ;
        vector< int > v, v1, v2 ;
        while( l1 )
        {
            v1.push_back( l1 -> val ) ;
            l1 = l1 -> next ;
        }

        while( l2 )
        {
            v2.push_back( l2 -> val ) ;
            l2 = l2 -> next ;
        }
        v1.push_back( 0 ) ;
        v2.push_back( 0 ) ;

        int siz = max( v1.size(), v2.size() ) ;
        if( v1.size() < siz )
        {
            for( int i = v1.size() ; i < siz ; i ++ ) v1.push_back( 0 ) ;
            reverse( v1.begin(), v1.end() ) ;
        }
        else
        {
            reverse( v1.begin(), v1.end() ) ;
            for( int i = v1.size() ; i < siz ; i ++ ) v1.push_back( 0 ) ;
        }


        if( v2.size() < siz )
        {
            for( int i = v2.size() ; i < siz ; i ++ ) v2.push_back( 0 ) ;
            reverse( v2.begin(), v2.end() ) ;
        }
        else
        {
            reverse( v2.begin(), v2.end() ) ;
            for( int i = v2.size() ; i < siz ; i ++ ) v2.push_back( 0 ) ;
        }

        int ok = 0 ;
        for( int i = siz - 1 ; i >= 0 ; i -- )
        {
            int x = v1[ i ] + v2[ i ] + ok ;
            if( i == 0 && x == 0 ) continue ;
            if( x > 9 )
            {
                ok = 1 ;
                v.push_back( x % 10 ) ;
            }
            else
            {
                v.push_back( x ) ;
                ok = 0 ;
            }
        }

        ListNode* head = new ListNode( v[ 0 ] ) ;
        ListNode* begin = head ;
        for( int i = 1 ; i < v.size() ; i ++ )
        {
            ListNode* temp = new ListNode( v[ i ] ) ;
            begin -> next = temp ;
            begin = temp ;
        }

        return head ;
    }
};
