/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node* next = head;
    if (next)
        next = next->next;
    while (next && head && head != next)
    {
        head = head->next;
        next = next->next;
        if (next)
            next = next->next;
    }
    if (head && next)
        return true;
    return false;
}