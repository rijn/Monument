#include <iostream>
#include <unordered_map>

struct RandomListNode {
    int             label;
    RandomListNode *next, *random;
    RandomListNode( int x ) : label( x ), next( NULL ), random( NULL ) {
    }
};

RandomListNode *copyRandomList( RandomListNode *head ) {
    if ( head == NULL ) return NULL;

    std::unordered_map<RandomListNode *, RandomListNode *> m;
    std::unordered_map<RandomListNode *, RandomListNode *> mr;

    RandomListNode *old_curr = head;
    RandomListNode *new_head = new RandomListNode( head->label );
    RandomListNode *new_curr = new_head;
    while ( old_curr != NULL ) {
        if ( old_curr->next != NULL ) {
            new_curr->next = new RandomListNode( old_curr->next->label );
        }

        m[old_curr] = new_curr;
        mr[new_curr] = old_curr;

        old_curr = old_curr->next;
        new_curr = new_curr->next;
    }

    new_curr = new_head;
    while ( new_curr != NULL ) {
        new_curr->random = m[mr[new_curr]->random];
        new_curr         = new_curr->next;
    }

    return new_head;
}

int main() {
    auto n1  = new RandomListNode( 1 );
    auto n2  = new RandomListNode( 2 );
    auto n3  = new RandomListNode( 3 );
    auto n4  = new RandomListNode( 4 );
    auto n5  = new RandomListNode( 5 );
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    auto solution = copyRandomList( n1 );

    std::cout << solution->label << std::endl;

    return 0;
}
