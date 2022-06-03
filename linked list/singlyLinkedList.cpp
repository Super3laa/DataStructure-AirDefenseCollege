#include <iostream>
using namespace std;

struct node {
  string data;
  node *next;
};
void insertNodeAtFirst(node **Head , node *newNode){
  newNode->next = *Head;
  *Head = newNode;
}
void insertNodeAtEnd(node **Head , node *newNode){
  node *temp = *Head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}
void insertNodeAtIndex(node **Head , node *newNode, int n){
  node *temp = *Head;
  for (int i = 0 ; i < n-1 ; i++){
    if(temp->next == NULL){
      cout<<"index out of list boundries"<<endl;
      return;
    }
    temp = temp->next;
  }
  newNode->next = temp->next;  
  temp->next = newNode;
}

void printNodes(node *Head){
  node *temp = Head;
  while (temp != NULL){
    cout<<temp->data<<endl;
    temp = temp->next;
  }
}

int main() {
  node *Head , *Node1, *Node2;
  Head = new node;
  Node1 = new node;
  Node2 = new node;

  Head->data = "A";
  Node1->data = "B";
  Head->next = Node1;
  Node2->data = "C";
  Node1->next = Node2;
  Node2->next = NULL; 

  node *newNode1 ; 
  newNode1 = new node;
  newNode1->data = "alpha";
  insertNodeAtFirst(&Head,newNode1);
  
  node *newNode2 ; 
  newNode2 = new node;
  newNode2->data = "D";
  insertNodeAtEnd(&Head,newNode2);

  node *newNode3 ; 
  newNode3 = new node;
  newNode3->data = "BC";
  insertNodeAtIndex(&Head,newNode3,3);
  
  printNodes(Head);
  
  return 0;
}
