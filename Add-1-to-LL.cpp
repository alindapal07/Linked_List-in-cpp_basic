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

int addOneutil(Node *head)
{
    if (head == nullptr)
        return 1;
    int carry = addOneutil(head->next);
    int sum = head->data + carry;
    head->data = sum % 10;
    return sum / 10;
}

Node *addOne(Node *head)
{
    if (head == nullptr)
        return new Node(1);
    int carry = addOneutil(head);
    if (carry)
    {
        Node *NewNode = new Node(carry);
        NewNode->next = head;
        return NewNode;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 2, 1};
    Node *head = nullptr;
    createList(head, arr);
    cout << "Original List: ";
    printList(head);
    head = addOne(head);
    cout << "List after adding one: ";
    printList(head);
    return 0;
}
