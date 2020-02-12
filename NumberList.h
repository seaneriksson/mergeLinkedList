// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      int value;           // The integer value in this node
      ListNode *next;  // To point to the next node
   };

   ListNode *head;            // List head pointer


public:
   // Constructor
   NumberList()
      { head = nullptr;}

   // Destructor
   ~NumberList();

   // Linked list operations
   void insertNode(int);
   int getLength(NumberList & listToSearch);
   int getItem(NumberList listToSearch, int itemNumber);
   int findItemAtNode(NumberList & listToSearch, int nodeWanted);
   void deleteNode(int);
   void printList();
   void mergeList(NumberList & joinedList, int num, NumberList & list1, NumberList & list2);
   int findSpot(int &spotFound, NumberList & list1, NumberList & list2);
   int compare(NumberList & list1, NumberList & List2, int nodeForList1, int nodeForList2, NumberList & joinedList);

   //data in node
   int nodeData = 0;
   //variable to keep track of what node is being compared



};
#endif
