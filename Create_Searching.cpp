#include<iostream>
#include <vector>
using namespace std;


struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
          data=data1;
          next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
 int searchForVal(Node* head,int val){
    Node* temp=head;
    while((temp!=nullptr))
    {
      if(temp->data==val) return 1;
      temp=temp->next;
    }
    return 0;
 }
int main(){
    vector<int> arr = {2, 3, 4, 5};
    Node* head=new Node(arr[0],nullptr);
    Node* current=head;
     for(int i=1;i<=arr.size();i++){
        current->next=new Node(arr[i]);
        current=current->next;
     }
     current=head;

     //print the linked list

     while ((current->next!=nullptr))
     {
        cout<<current->data<<"->";
        current=current->next;
     }
     cout<<"nullptr"<<endl;
     //completed
     int result=searchForVal(head,4);
     cout<<result<<";";
    return 0;
}