Node* addAtHead(Node* head, const int data) {
    Node* item = new Node;
    
    item->next = head;
    item->data = data;
    
    return item;
}    

void ReversePrint(Node *head)
{
  Node* reversed = NULL;
  Node* curr;
  curr = head;
  while (curr != NULL){
    
      reversed = addAtHead(reversed, curr->data );
      curr = curr->next;
  }  
  
  curr = reversed;
  while (curr != NULL) {
    cout << curr->data << endl;
    curr = curr->next;
  }
}