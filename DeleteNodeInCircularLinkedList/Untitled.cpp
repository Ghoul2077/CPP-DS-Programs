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

Node* initializeCLL() {
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

void printCLL(Node *head) {
   Node *currNode = head;

   if (head == NULL) {
      return;
   }

   do {
      cout << currNode->data << " ";
      currNode = currNode->next;
   } while (currNode != head);
}

Node* deleteAtBeginning(Node *head) {
   Node *temp = head;
   Node *curr = head;

   while(curr->next != head) {
      curr = curr->next;
   }

   curr->next = head->next;
   head = head->next;

   delete(temp);
   return (head);
}

Node* deleteNodeAtIndex(Node *head, int index) {
   if (index == 0) {
      return (deleteAtBeginning(head));
   }

   Node *curr  = head;
   int   count = 0;

   while (curr != head && count != index - 1) {
      curr = curr->next;
      count++;
   }

   if (count == index - 1) {
      Node *temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
   }

   return (head);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Node *head = initializeCLL();
      head = deleteNodeAtIndex(head, 0);
      printCLL(head);
   }

   return (0);
}
