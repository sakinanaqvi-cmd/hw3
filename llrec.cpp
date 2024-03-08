#include "llrec.h"
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if(!head) {
      smaller = nullptr;
      larger = nullptr;
      return;
    }
    if(head->val <= pivot) {
        smaller = head; 
        //assign head to the next value (prepping for recursion)
        head = head ->next;
        //set the next value to null of smaller since address we don't know
        //in general helps move the node from one place to another 
        smaller->next = NULL;
        llpivot(head, smaller->next, larger, pivot);
     } else if(head->val > pivot) {
        larger = head;
        head = head ->next;
        larger->next = NULL;
        llpivot(head, smaller, larger->next, pivot);
     } 
}