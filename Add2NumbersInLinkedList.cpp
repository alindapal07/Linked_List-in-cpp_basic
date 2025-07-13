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

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummyNode = new Node(0);
    Node *current = dummyNode;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr | carry != 0)
    {
        int sum = carry;
        if (l1 != nullptr)
        {
            sum = sum + l1->data;
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            sum = sum + l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }
    return dummyNode->next;
}

Node *CreateList(vector<int> arr)
{
    Node *head = new Node(arr[0], nullptr);
    Node *current = head;
    for (int i = 1; i < arr.size(); i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << "->";
        current = current->next;
    }

    cout << "nullptr" << endl;
    return;
}

int main()
{

    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    Node *head1 = CreateList(arr1);
    Node *head2 = CreateList(arr2);
    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);
    Node *result = addTwoNumbers(head1, head2);
    cout << "Result: ";
    printList(result);

    return 0;
}