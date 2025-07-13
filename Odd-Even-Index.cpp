#include <iostream>
#include <vector>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *createList(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

Node *OddEvenIndexArrange(Node *&head)
{
    Node *main = head;
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return main;
}

int main()
{
    vector<int> arr = {2, 4, 3, 5, 6, 7, 9};
    Node *head = createList(arr);
    cout << "The given Linked List is :" << endl;
    printList(head);
    head = OddEvenIndexArrange(head);
    cout << "The Linked List after rearranging odd and even indexed nodes is :" << endl;
    printList(head);
    return 0;
}