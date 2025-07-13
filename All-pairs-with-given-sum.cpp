#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void insertEnd(Node* &head ,int val)
{
    Node* newHead = new Node(val);
    if (!head)
    {
        head=newHead;
        return;
    }
    Node* temp = head;
    while (temp->next)
    {
        temp=temp->next;
        temp->next= newHead;
        newHead->prev =temp;
    }
    
}

void findPairsWithSum(Node* head, int target)
{   
    if (!head) return ;
    
    Node* left = head;
    Node* right = head;

    // Move right to the last node
    while (right->next)
        right = right->next;

    bool found = false;

    while (left && right && left != right && left->prev != right)
    {
        int sum = left->data + right->data;

        if (sum == target)
        {
            cout << "(" << left->data << ", " << right->data << ")\n";
            found = true;
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }

    if (!found)
        cout << "No pairs found with sum " << target << endl;
}

    

    

//driver code
int main() {
    Node* head = nullptr;

    // Insert sorted data
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);
    insertEnd(head, 8);
    insertEnd(head, 9);

    int target = 7;

    cout << "Pairs with sum " << target << ":\n";
    findPairsWithSum(head, target);

    return 0;
}