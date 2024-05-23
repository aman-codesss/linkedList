#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
       ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
   
};
    void insertAtHeat(Node* &head, int d){
        Node* temp = new Node(d);
        temp->next= head;
        head =  temp;
    }
    void insertAtTail(Node* &tail, int d){
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
        
    }
    void print(Node* &head){
        Node* temp = head;
        while(temp!= nullptr){

        cout<<temp->data<<" ";
        temp = temp->next;
        }
        cout<<endl;

    }
    void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
       
        head = head ->next;
        temp->next=nullptr;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        // curr -> next = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}

int main(){
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node* head =  node1;
    Node* tail =  node1;
    // print(head);

    // insertAtHeat(head,12);
    // print(head);
    // insertAtHeat(head,32);
    // print(head);
    // insertAtHeat(head,42);
    // print(head);

    print(tail);

    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,32);
    print(head);
    insertAtTail(tail,42);
    print(head);
    deleteNode(3,head);

    print(head);


}