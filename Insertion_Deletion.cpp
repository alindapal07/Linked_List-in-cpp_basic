#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;   
};

void insertAtBeginning(Node*& head,int val){
    Node* NewNode= new Node();
    NewNode->data=val;
    NewNode->next=head;
    head=NewNode;  
}
void  insertAtTheEnd(Node*& head,int val){
    Node* NewNode= new Node();
    NewNode->data=val;
    NewNode->next=nullptr;
    if(head==nullptr) {
        head=NewNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=NewNode;
}

void printList(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<< "->";
        temp=temp->next;
    }
    cout<<"Null"<<endl; 
}
void deleteNode(Node*& head,int val){
    if(head==nullptr) return;
    if (head->data==val){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    else{
        Node* temp=head;
        while (temp->next!=nullptr && temp->next->data!=val)
        {
            temp=temp->next;
        }
        Node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
        return;
     }
     cout<<"Value not found:Deletion not possible"<<endl;

}
int main()
{
    Node* head=nullptr;
    insertAtBeginning(head,10);
    insertAtBeginning(head,20);
    insertAtTheEnd(head,40);
    insertAtBeginning(head,50);
    insertAtBeginning(head,60);
    insertAtTheEnd(head,70);
    printList(head);
    cout<<"LinkedList After the insertion"<<endl;
    deleteNode(head,50);
    printList(head);
    cout<<"LinkedList After Deletion"<<endl;
    return 0;
}
