

/*
 *  ectest.cpp
 *
 *  a non-interactive test program to test the functions described in ecListFuncs.h
 *
 *    to run it use the command:   ectest
 *
 *  Note: this uses separate compilation.  You put your list code ecListFuncs.cpp
 *  Code in this file should call those functions.
 */

#include <iostream>
#include <string>
#include <algorithm>

#include "ecListFuncs.h"

using namespace std;

/* Prints the linked list.
 * @param linked list of the type ListType.
 */
void printList(ListType list)
{

   if (list == NULL)
   {
      cout << "";
   }

   ListType current = list;

   while (current != NULL)
   {
      cout << current->data << " ";
      current = current->next;
   }
   cout << endl;
}

int main()
{
   // All the input test cases
   string test1 = "";
   string test2 = "-32";
   string test3 = "     -32   ";
   string test = "1 3 2";
   string test4 = "  1 3 2";

   // Building a linked list from the input string.
   ListType list = buildList(test);
   cout << endl;

   // Print empty linked list
   ListType list1 = buildList(test1);
   cout << "Output of buildList (Expected result) : " << endl;
   cout << "Output of buildList (Actual result) : ";
   printList(list1);
   cout << endl;
   cout << "Output of listToString: " << listToString(list1) << endl;
   if (!(listToString(list1) == "()"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   ListType list2 = buildList(test2);
   cout << "Output of buildList (Expected result) : -32" << endl;
   cout << "Output of buildList (Actual result) : ";
   printList(list2);
   cout << endl;
   cout << "Output of listToString: " << listToString(list2) << endl;
   if (!(listToString(list2) == "(-32)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   ListType list3 = buildList(test3);
   cout << "Output of buildList (Expected result) : -32" << endl;
   cout << "Output of buildList (Actual result) : ";
   printList(list3);
   cout << endl;
   cout << "Output of listToString: " << listToString(list3) << endl;
   if (!(listToString(list3) == "(-32)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   ListType list4 = buildList(test4);
   cout << "Output of buildList (Expected result) : 1 3 2" << endl;
   cout << "Output of buildList (Actual result) : ";
   printList(list4);
   cout << endl;
   if (!(listToString(list) == "(1 3 2)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   // Print the newly created linked list from the input string.
   cout << "Output of buildList (Expected result) : 1 3 2" << endl;
   cout << "Output of buildList (Actual result) : ";
   printList(list);
   cout << endl;
   if (!(listToString(list) == "(1 3 2)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   /* Insert values into the linked list at different positions.
    * Print the linked list and its corresponding string.
    */
   // Insert in the middle.
   cout << "Insert 9 in the middle of the list: " << endl;
   insertAt(list, 2, 9);
   cout << "Output of buildList - after insertion: ";
   printList(list);
   cout << "Output of listToString - after insertion: " << listToString(list) << endl;
   cout << endl;
   if (!(listToString(list) == "(1 3 9 2)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   // Insert at the front.
   cout << "Insert 10 at the front of the list: " << endl;
   insertAt(list, 0, 10);
   cout << "Output of buildList - after insertion: ";
   printList(list);
   cout << "Output of listToString - after insertion: " << listToString(list) << endl;
   cout << endl;
   if (!(listToString(list) == "(10 1 3 9 2)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   // Insert at the last.
   cout << "Insert 15 at the end of the list: " << endl;
   insertAt(list, 5, 15);
   cout << "Output of buildList - after insertion: ";
   printList(list);
   cout << "Output of listToString - after insertion: " << listToString(list) << endl;
   cout << endl;
   if (!(listToString(list) == "(10 1 3 9 2 15)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   // Partition the list as per the specified number.
   // Modified original list.
   ListType newList = partitionBy(list, 5);
   cout << "Modified original list: ";
   printList(list);
   cout << "Output of listToString - previous: " << listToString(list) << endl;
   cout << endl;
   if (!(listToString(list) == "(10 9 15)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   // Newly created list after partition.
   cout << "New list: ";
   printList(newList);
   cout << "Output of listToString - new list: " << listToString(newList) << endl;
   cout << endl;
   if (!(listToString(newList) == "(1 3 2)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   // Partition the list as per the specified number.
   // Modified original list.
   ListType list5 = buildList(test); // Create the original list again.
   ListType newList5 = partitionBy(list5, 20);
   cout << "Modified original list: ";
   printList(list5);
   cout << "Output of listToString - previous: " << listToString(list5) << endl;
   cout << endl;
   // All the values are < 20, thus, the original list becomes empty.
   if (!(listToString(list5) == "()"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   // Newly created list after partition.
   cout << "New list: ";
   printList(newList5);
   cout << "Output of listToString - new list: " << listToString(newList5) << endl;
   cout << endl;
   // All the values are < 20, thus, the new list becomes (1 3 2).
   if (!(listToString(newList5) == "(1 3 2)"))
   {
      cout << "FAILED!" << endl;
   }
   cout << endl;

   return 0;
}
