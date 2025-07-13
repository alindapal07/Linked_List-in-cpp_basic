#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data1, Node *next1 = nullptr) : data(data1), next(next1) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void palindromeList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "List is empty or has only one element, no palindrome check needed." << endl;
        return;
    }

    // Step 1: Find the middle
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    Node* secondhalf = reverseList(slow);
    Node* copysecondhalf = secondhalf;
    Node* firsthalf = head;

    // Step 3: Compare both halves
    while (copysecondhalf != nullptr) {
        if (firsthalf->data != copysecondhalf->data) {
            cout << "The list is NOT a palindrome." << endl;
            return;
        }
        firsthalf = firsthalf->next;
        copysecondhalf = copysecondhalf->next;
    }

    // Optional: Restore the list
    reverseList(secondhalf);

    cout << "The list IS a palindrome." << endl;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void createList(Node*& head, vector<int> arr) {
    if (arr.empty()) return;
    head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 1};
    Node* head = nullptr;
    createList(head, arr);
    cout << "Original List: ";
    printList(head);
    palindromeList(head);
    return 0;
}
