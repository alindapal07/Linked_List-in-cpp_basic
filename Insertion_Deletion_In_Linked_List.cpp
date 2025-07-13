#include<iostream>
#include<vector>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    } 
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};


void removeHead(Node*& head){
    if(head==nullptr){
        cout<<"The list is empty"<<endl;
        return;
    }
    Node* temp=head;
     head=head->next; 
     delete temp;
}

void linkedlistTraverse(Node* head){
    Node* temp=head;
    if(head==nullptr){
        cout<<"The linked list is empty"<<endl;
        return;
    }
    else{
       while (head!=nullptr)
       {
        cout<<head->data<<"->";
        head=head->next;
       }
       cout<<"nullptr"<<endl;
    }
    return;
}

int main(){
    vector<int> arr={2,6,4,8,9};
    Node* head= new Node(arr[0],nullptr);
    Node* current=head;
    for (int i = 1; i <arr.size(); i++)
    {
        current->next= new Node(arr[i]);
        current=current->next;
    }
    current=head;
    //Created linked list successfully Now let's traverse:
    linkedlistTraverse(head);
    removeHead(head);
    linkedlistTraverse(head);

            

    return 0;
}