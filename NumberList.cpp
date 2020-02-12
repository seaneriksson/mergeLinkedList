// Implementation file for the NumberList class
#include <iostream>  // For cout
#include "NumberList.h"
using namespace std;

//append a new node
void NumberList::insertNode(int num)
{
   ListNode *newNode;					// A new node
   ListNode *nodePtr;					// To traverse the list
   ListNode *previousNode = nullptr;	// The previous node

   // Allocate a new node and store num there.
   newNode = new ListNode;
   newNode->value = num;

   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to nullptr.
      previousNode = nullptr;

      // Skip all nodes whose value is less than num.
      while (nodePtr != nullptr && nodePtr->value < num)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}


//display the list
void NumberList::printList()
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      cout << nodePtr->value << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
   cout << "" << endl;
}

int NumberList::getLength(NumberList & listToSearch)
{
   int length = 0;

   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Move to the next node.
      nodePtr = nodePtr->next;

      //update the length of the list
      length++;
   }

   return length;

}

int NumberList::getItem(NumberList listToSearch, int itemNumber)
{

   //steps counter to search for number
   int step = 1;

   //node data
   int nodeData = 0;

   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.

    while (nodePtr)
        {
            if (nodePtr->value == itemNumber)
            {
                nodeData = nodePtr->value;

                cout << "The node data is: " << nodeData << endl;
                cout << "The node is at step: " << step << endl;

                break;
            }

            // Move to the next node.
            nodePtr = nodePtr->next;
            //update the length of the list
            step++;
        }

    return nodeData;

}


int NumberList::findItemAtNode(NumberList & listToSearch, int nodeWanted)
{
   //steps counter to search for number
   int step = 1;

   //node data
   int nodeData = 0;

   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.


    while (nodePtr)
        {
            if (step == nodeWanted)
            {
                nodeData = nodePtr->value;

                //cout << "The node data is: " << nodeData << endl;
                //cout << "The node is at step: " << step << endl;
                break;
            }

            // Move to the next node.
            nodePtr = nodePtr->next;
            //update the length of the list
            step++;
        }

    return nodeData;
}

//delete node
void NumberList::deleteNode(int num)
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;

   // Determine if the first node is the one.
   if (head->value == num)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != nullptr && nodePtr->value != num)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}


int NumberList::findSpot(int &spotFound, NumberList & list1, NumberList & list2)
{
    //flag to identify if the item has been found
    bool spotFlag = false;

    int smallerList = 0;

    //store the length to search
    int lengthToSearch = 0;

    //store the length of the list
    int list1Length = list1.getLength(list1);
    int list2Length = list2.getLength(list2);

    //set the length to search
    if (list1Length == list2Length)
    {
        lengthToSearch = list1Length;
    }

    if (list1Length < list2Length)
    {
        lengthToSearch = list1Length;
    }

    if (list2Length < list1Length)
    {
        lengthToSearch = list2Length;
    }

    int list1FirstNode = list1.findItemAtNode(list1, 1);
    int list2FirstNode = list2.findItemAtNode(list2, 1);

    //find which list has the smaller item in the first spot
    if (list1FirstNode < list2FirstNode)
    {
        smallerList = 1;
    }

    if (list2FirstNode < list1FirstNode)
    {
        smallerList = 2;
    }


    //counter used when searching for the item
    int step = 1;

    //search for the merge spot
    if (smallerList == 1)
    {
        while ((step-1) < lengthToSearch)
        {
            int list1NodeVariable = list1.findItemAtNode(list1, step);
            int list2FirstNode = list2.findItemAtNode(list2, 1);
            if (list2FirstNode <= list1NodeVariable)
            {
                spotFlag = true;
                spotFound = step;
                cout << "There's spot! " << spotFound << endl;
                break;
            }
            step++;  //increase the step until the item is found
        }
    }

    return spotFound;
}

int NumberList::compare(NumberList & list1, NumberList & list2, int nodeForList1, int nodeForList2, NumberList & joinedList)
{
    //total length of the merged list
    int totalLength = list1.getLength(list1) + list2.getLength(list2);

    //cout << "Total length: " << totalLength << endl;

    int counter1 = 1;
    int counter2 = 1;
    int counterSum = counter1 + counter2;

    int list1NodeVariable = list1.findItemAtNode(list1, counter1);
    int list2NodeVariable = list2.findItemAtNode(list2, counter2);

    //cout << "List 1 node variable: " << list1NodeVariable << endl;
    //cout << "List 2 node variable: " << list2NodeVariable << endl;

    int smallerNode = 0;
    char c;

    while (counterSum <= totalLength + 1)
    {
        if (list1NodeVariable == 0)
        {
            c = 'O';
        }
        else if (list1NodeVariable < list2NodeVariable)
        {
            c = 'A';
        }

        else if (list1NodeVariable > list2NodeVariable)
        {
            c = 'B';
        }

        else if (list1NodeVariable == list2NodeVariable)
        {
            c = 'C';
        }

        switch (c)
        {
            case 'O':
                joinedList.insertNode(list2NodeVariable);
                counter2++;
                //cout << "switch O called" << endl;
                break;
            case 'A':
                joinedList.insertNode(list1NodeVariable);
                counter1++;
               // cout << "switch a" << endl;
                break;
            case 'B':
                joinedList.insertNode(list2NodeVariable);
                counter2++;
               // cout << "switch b" << endl;
                break;
            case 'C':
                joinedList.insertNode(list1NodeVariable);
                counter1++;
                counter2++;
               // cout << "switch c" << endl;
                break;
            default:
                smallerNode = 0;
        }
        //cout << counter1 << endl;
        //cout << counter2 << endl;

        list1NodeVariable = list1.findItemAtNode(list1, counter1);
        list2NodeVariable = list2.findItemAtNode(list2, counter2);

        //cout << "List 1 node variable: " << list1NodeVariable << endl;
        //cout << "List 2 node variable: " << list2NodeVariable << endl;

        counterSum = counter1 + counter2;

        //cout << "Counter sum: " << counterSum << endl;
    }

}
void NumberList::mergeList(NumberList & joinedList, int num, NumberList & list1, NumberList & list2)
{
/*
    //variable to keep track of what is the smaller list
    int smallerList = 0;

    int list1FirstNode = list1.findItemAtNode(list1, 1);
    int list2FirstNode = list2.findItemAtNode(list2, 1);

    //find which list has the smaller item in the first spot
    if (list1FirstNode < list2FirstNode)
    {
        smallerList = 1;
    }

    if (list2FirstNode < list1FirstNode)
    {
        smallerList = 2;
    }

    //counter for inserting the next node from list 1
    int counter1 = 1;

    //counter for inserting the next node from list 2
    int counter2 = 1;

    //total length of the merged list
    int totalLength = list1.getLength(list1) + list2.getLength(list2);


    if (smallerList = 1)
    {
        while (counter1 < num)
        {
            int numberToInsert = list1.findItemAtNode(list1, counter1);
            //first number go ahead and insert
            if (counter1 == 1)
            {
                joinedList.insertNode(numberToInsert);
            }
            //check to make sure all future numbers are less than the next number
            if (counter1 > 1 && )
            joinedList.insertNode(numberToInsert);
            cout << "counter 1: " << counter1 << endl;
            counter1++;
        }

        while (counter1 < totalLength)
        {
            int numberToInsert = list2.findItemAtNode(list1, counter2);
            joinedList.insertNode(numberToInsert);
            counter1++;
            //counter2++;
        }
    }
*/
}


//destructor
NumberList::~NumberList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }

}
