#include<iostream>
#include<vector>
using namespace std;
struct Node{
 public:
   int data;
   Node* next;
   Node* prev;
};

//Create doubly LinkedList from a given array//
Node* CreateDoublyLinkedList(int arr[],int size){
    if(size==0) return nullptr;
    Node*head=new Node();
    head->data=arr[0];
    head->next=nullptr;
    head->prev=nullptr;
    Node* temp=head;
    for (int i = 1; i < size; i++)
    {
      Node* NewNode= new Node();
      NewNode->data=arr[i];
      NewNode->next=nullptr;
      NewNode->prev=temp;
      temp->next=NewNode;
      temp=NewNode;
    }
    return head;
}

Node* insertAtTheBeginning(Node*& head,int val){
    Node* temp=head;
    Node*NewNode=new Node();
    NewNode->data=val;
    NewNode->prev=nullptr;
    NewNode->next=temp;
    temp->prev=NewNode;
    head=NewNode;
    return head;
}

Node* InsertionAtTheEnd(Node*& head,int val){
    Node* temp=head;
    Node* NewNode=new Node();
    NewNode->data=val;
    NewNode->next=nullptr;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
    NewNode->prev=temp;
    temp->next=NewNode;
    return head;
}

Node* InsertionAfternthNode(Node*& head,int val,int pos,int size){
    Node* temp=head;
    Node* NewNode=new Node();
    NewNode->data=val;
    if (pos>size+1)
    {
       cout<<"Position exceeded:Please Give a valid position:"<<endl;
       return nullptr;
    }
    if (pos==size+1)
    {
    InsertionAtTheEnd(head,val);
    }
    
    if (pos==1)
    {
        insertAtTheBeginning(head,val);
    }
    
    for (int i = 0; i < pos-2; i++)
    {
      temp=temp->next;
    }
    NewNode->next=temp->next;
    temp->next->prev=NewNode;
    temp->next=NewNode;
    NewNode->prev=temp;
    return head;
}

    
void deleteNodeLinkedList(Node*& head,int val){
   if (head==nullptr) return;
   if (head->data==val)
   {
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    delete temp;
    return;
   }
   else
   { Node* temp=head;
   while (temp!=nullptr && temp->data!=val)
   {
    temp=temp->next;
   }
   Node* TODELETE=temp;
   temp->prev->next=temp->next;
   temp->next->prev=temp->prev;
   delete TODELETE; 
   return;
   }
   cout<<"Value not found for DELETE:"<<endl;
   return;
}


void reverseList(Node*& head){
    Node* temp=nullptr;
    Node* current=head;
   if (current==nullptr|| current->next==nullptr) return;
   
    while (current!=nullptr)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if (temp!=nullptr)
    {
        head=temp->prev;
    }
    return;
    
}
void displayLinkedList(Node* head){
    Node* temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;   
}


int main(){
    int arr[]={2,3,6,8,1,9,0,4,5,63,87};//Given array to trasfer into a doubly LinkedList
    int size= sizeof(arr)/sizeof(arr[0]);//Finding The size of the given array
    Node* head=CreateDoublyLinkedList(arr,size);//Creating Doubly LinkedList from an array
    displayLinkedList(head);//Displaying LinkedList after creating
    insertAtTheBeginning(head,97);//Insertion at the beginning
    displayLinkedList(head);//LinkedList after insertion at the beginning
    InsertionAtTheEnd(head,77);//Insertion at the End 
    displayLinkedList(head);//Displaying LinkedList after the insertion AT The End
    InsertionAfternthNode(head,67,5,size);//specially designed for insertion any node in LinkedList at a particular position//
    displayLinkedList(head);
    deleteNodeLinkedList(head,4);//Delete Node of linkedList by Value//
    displayLinkedList(head);
    reverseList(head); //Operation for reverse the linkedlist
    displayLinkedList(head);//Displaying after the reverse operation//

    return 0;
}

