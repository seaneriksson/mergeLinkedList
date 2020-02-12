// This program demonstrates a simple append
// operation on a linked list.
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
   //spot where merge will begin
   int spotFound = 0;

   //keep track of node spot
   int nodeForList1;
   int nodeForList2;

   // Create NumberList objects.
   NumberList list1;
   NumberList list2;
   NumberList joinedList;


   // insert some values to list 1
   list1.insertNode(1);
   list1.insertNode(2);
   list1.insertNode(3);
   list1.insertNode(5);

   // insert some values to list 2
   list2.insertNode(4);
   list2.insertNode(6);
   list2.insertNode(7);
   list2.insertNode(8);
   list2.insertNode(9);


   //print list 1
   cout << "List 1 is: " << endl;
   list1.printList();

   //print list 2
   cout << "List 2 is: " << endl;
   list2.printList();

//   list1.findSpot(spotFound, list1, list2);

   //call the merge function
//   joinedList.mergeList(joinedList, spotFound, list1, list2);

   list1.compare(list1, list2, nodeForList1, nodeForList2, joinedList);
   //print the merged list
   cout << "The merged list is: " << endl;
   joinedList.printList();

   return 0;
}
