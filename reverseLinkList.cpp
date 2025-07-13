#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data1, Node *next1) : data(data1), next(next1) {}
    Node(int data1) : data(data1), next(nullptr) {}
};

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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
int main()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    Node *head = nullptr;
    createList(head, arr);
    printList(head);
    Node *newhead = reverseList(head);
    cout << "Reversed List: ";
    head = newhead;
    printList(head);
    return 0;
}
