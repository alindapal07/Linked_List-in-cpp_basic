#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data1, Node *next1 = nullptr) : data(data1), next(next1) {}
};
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
void createList(Node *&head, vector<int> arr)
{
    if (arr.empty())
        return;
    head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
}
Node *getIntersectionNode( Node* headA,Node* headB)
{
    if (!headA || !headB)
        return nullptr;
    Node *a = headA;
    Node *b = headB;
    while (a != b)
    {
        a = (a != nullptr) ? a->next : headB;
        b = (b != nullptr) ? b->next : headA;
    }
    return a;
}
int main()
{

    Node *intersect = new Node(8);
    intersect->next = new Node(10);

    Node *headA = new Node(3);
    headA->next = new Node(6);
    headA->next->next = new Node(9);
    headA->next->next->next = intersect;

    // Second list: 4 -> 8 -> 10 (joins at 8)
    Node *headB = new Node(4);
    headB->next = intersect;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    Node *result = getIntersectionNode(headA, headB);
    if (result)
        cout << "Intersection at node with value: " << result->data << endl;
    else
        cout << "No intersection point.\n";

    return 0;
}