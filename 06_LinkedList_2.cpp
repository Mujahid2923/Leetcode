Problem_1 :
https://leetcode.com/problems/intersection-of-two-linked-lists/

4 1
      8 3 5
5 6 1

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *A = headA, *B = headB, *ans = nullptr ;
        while( A != B )
        {
            if( A ) A = A -> next ;
            else A = headB ;
            if( B ) B = B -> next ;
            else B = headA ;
        }
        return A ;
    }
};


Problem_2 :
https://leetcode.com/problems/palindrome-linked-list/

1 2 2 1, palindrome or not ;


class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode *slow = head, *fast = head ;

        while( fast && fast -> next )
        {
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }

        ListNode *pre = nullptr, *post = nullptr, *current = slow ;
        while( current )
        {
            post = current -> next ;
            current -> next = pre ;
            pre = current ;
            current = post ;
        }

        while( pre )
        {
            if( pre -> val != head -> val ) return false ;
            pre = pre -> next ;
            head = head -> next ;
        }
        return true ;
    }
};

Problem_3 :

https://leetcode.com/problems/reverse-nodes-in-k-group/

[1,2,3,4,5], k = 2 ;
Output [2,1,4,3,5]

2 length Reverse here and If length is Less than 2, keep that as it is .

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int cnt = 0 ;
        ListNode* temp = head ;
        while( temp )
        {
            temp = temp -> next ;
            cnt ++ ;
        }

        ListNode *pre = NULL, *post = NULL, *current = head ;
        ListNode *t1 = NULL, *t2 = head, *newhead = NULL ;

        while( cnt >= k )
        {
            for( int i = 0 ; i < k ; i ++ )
            {
                post = current -> next ;
                current -> next = pre ;
                pre = current ;
                current = post ;
            }

            if( newhead == NULL ) newhead = pre ;
            if( t1 ) t1 -> next = pre ;
            t2 -> next = current ;

            t1 = t2 ;
            t2 = current ;
            pre = NULL ;
            cnt -= k ;
        }
        return newhead ;
    }
};


Problem_4 :
https://leetcode.com/problems/linked-list-cycle/

cycle or not ;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if( head == NULL ) return false ;
        ListNode *slow = head, *fast = head -> next ;

        while( slow != fast )
        {
            if( fast == NULL || fast -> next == NULL ) return false ;
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }
        return true ;
    }
};


Problem_5 :
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

doubly link List with previous, next and child ;

class Solution
{
public:
    Node* flatten(Node* head)
    {
        Node *pre = NULL, *current = NULL, *start = NULL ;
        stack< Node* > Stk ;
        if( head ) Stk.push( head ) ;

        while( !Stk.empty() )
        {
            pre = current ;
            current = Stk.top() ;
            Stk.pop() ;

            if( current -> next ) Stk.push( current -> next ) ;
            if( current -> child ) Stk.push( current -> child ) ;

            current -> child = NULL ;
            current -> prev = pre ;

            if( pre ) pre -> next = current ;
            else start = current ;
        }

        return start ;
    }
};



Problem_6 :
https://leetcode.com/problems/rotate-list/

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if( head == NULL ) return head ;
        int cnt = 0 ;
        ListNode* temp = head ;
        while( temp )
        {
            cnt ++ ;
            temp = temp -> next ;
        }
        k = cnt - k % cnt ;

        ListNode* current = head ;
        for( int i = 0 ; i < k ; i ++ )
        {
            current = current -> next ;
        }

        ListNode* start = new ListNode() ;
        ListNode* begin = start ;
        while( current )
        {
            ListNode* temp = new ListNode( current -> val ) ;
            start -> next = temp ;
            start = temp ;
            current = current -> next ;
        }

        for( int i = 0 ; i < k ; i ++ )
        {
            ListNode* temp = new ListNode( head -> val ) ;
            start -> next = temp ;
            start = temp ;
            head = head -> next ;
        }

        return begin -> next ;
    }
};

Problem_7 :
https://leetcode.com/problems/copy-list-with-random-pointer/

Copy of a Linked List with address of random link List

class Solution
{
public:
    map< Node*, Node* > Mp ;
    Node* copyRandomList(Node* head)
    {
        if( head == NULL ) return NULL ;
        if( Mp[ head ] ) return Mp[ head ] ;

        Mp[ head ] = new Node( head -> val ) ;
        Mp[ head ] -> next = copyRandomList( head -> next ) ;
        Mp[ head ] -> random = copyRandomList( head -> random ) ;

        return Mp[ head ] ;
    }
};


