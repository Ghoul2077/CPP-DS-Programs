#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
   int   data;
   Node *next;

   Node(int val) {
      data = val;
      next = NULL;
   }
};

Node* initializeLL() {
   int val;

   cin >> val;
   Node *head = NULL;
   Node *curr = head;

   while (val != -1) {
      Node *newNode = new Node(val);

      if (head == NULL) {
         head = newNode;
         curr = newNode;
      } else {
         curr->next = newNode;
         curr       = curr->next;
      }
      cin >> val;
   }

   curr->next = head;

   return (head);
}

void printLL(Node *head) {
   Node *currNode = head;

   if (head == NULL) {
      return;
   }

   do {
      cout << currNode->data << " ";
      currNode = currNode->next;
   } while (currNode != head);
}

Node* insertAtBeginningCircularLinkedList(Node *head, int val) {
   Node *newNode = new Node(val);

   if (head == NULL) {
      newNode->next = newNode;
      return (newNode);
   }

   Node *curr = head;

   newNode->next = head;

   while (curr->next != head) {
      curr = curr->next;
   }

   curr->next = newNode;
   return (newNode);
}

Node* insertAtIndexCircularLinkedList(Node *head, int val, int index) {
   if (index < 0) {
      cout << "Index underflow" << endl;
   }

   if (index == 0) {
      return (insertAtBeginningCircularLinkedList(head, val));
   }

   Node *newNode = new Node(val);
   Node *curr    = head;
   int   count   = 0;

   while (curr->next != head && count != index - 1) {
      curr = curr->next;
      count++;
   }

   if (count == index - 1) {
      Node *temp = curr->next;
      curr->next    = newNode;
      newNode->next = temp;
   } else {
      cout << "Index overflow" << endl;
   }

   return (head);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeLL();
      head = insertAtIndexCircularLinkedList(head, 4, 6);
      printLL(head);
   }

   return (0);
}
