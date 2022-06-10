

#include <iostream>
#include <string>
#include <cassert>

// for istringstream
#include <sstream>

#include "ecListFuncs.h"

using namespace std;

// *********************************************************
// Node constructors: do not change
Node::Node(int item)
{
   data = item;
   next = NULL;
}

Node::Node(int item, Node *n)
{
   data = item;
   next = n;
}
// *********************************************************

/* Builds a linked list from a string.
 * @param string consisting of integer values.
 * @return the head of the newly created linked list.
 */
ListType buildList(const string &listString)
{

   ListType emptyList = NULL;

   if (listString == "")
   {
      return emptyList;
   }

   stringstream ss(listString);

   int token;

   ss >> token;

   ListType current = new Node(token);
   ListType head = current;

   while (ss >> token)
   {

      current->next = new Node(token);

      current = current->next;
   }

   return head;
}

/* Converts a linked list to a string and returns it.
 * @param linked list of the type ListType.
 * @return string containing all the elements in the linked list.
 */
string listToString(ListType list)
{

   if (list == NULL)
   {
      return "()";
   }

   string newString = "(";

   Node *current = list;

   while (current->next != NULL)
   {

      newString.append(to_string(current->data));
      newString += " ";
      current = current->next;
   }

   newString.append(to_string(current->data));
   newString.append(")");

   return newString;
}

/* Prepends a node to the linked list (inserts a node in front of the linked list).
 * @param linked list of the type ListType and value of the node to be inserted.
 */
void prepend(ListType &list, int value)
{

   ListType newNode = new Node(value, list);

   newNode->next = list;

   list = newNode;
}

/* Inserts a node into the linked list at the specified position.
 * @param linked list of the type ListType, position (index), and value of the node to be inserted.
 */
void insertAt(ListType &list, int index, int value)
{

   Node *current = list;

   // If index = 0, then prepend to the list.
   if (index == 0)
   {

      prepend(list, value);
   }

   // Otherwise insert at the specified position.
   int countNodes = 0;

   ListType newNode = new Node(value);

   while (current != NULL)
   {

      if (countNodes == index - 1)
      {

         ListType tempNode = current->next;

         current->next = newNode;

         newNode->next = tempNode;

         return;
      }

      current = current->next;
      countNodes++;
   }
}

/* Removes a node from the linked list from the specified position.
 * @param linked list of the type ListType and position of the node to be removed.
 */
void removeNode(ListType &list, int position)
{

   int nodeCount = 0;

   ListType previous = list;
   ListType current = list;

   if (list == NULL)
   {
      return;
   }

   if (position == 0)
   {

      list = previous->next;
      // free(previous);
      delete previous;
      previous = NULL;
      return;
   }

   else
   {

      while (current->next != NULL && nodeCount < position)
      {

         nodeCount++;
         current = previous;
         previous = previous->next;
      }

      if (previous == NULL)
      {
         return;
      }

      else
      {
         current->next = previous->next;
         // free(previous);
         delete previous;
         previous = NULL;
         return;
      }
   }
}

/* Appends a node to the linked list (inserts a node at the end of the linked list).
 * @param linked list of the type ListType and value of the node to be inserted.
 */
void append(ListType &newList, int number)
{

   ListType newNode = new Node(number);

   if (newList == NULL)
   {

      newList = newNode;
      return;
   }

   ListType current = newList;

   while (current->next != NULL)
   {

      current = current->next;
   }

   current->next = newNode;
}

/* Partitions a linked list into 2 seperate linked list: the original linked list and a new linked list containing all the values less than the specified number
 * in the original linked list.
 * @param linked list of the type ListType and value of the node to be considered for the partionining.
 * @return new linked list with all the values in the original linked list that are less than the specified number.
 */
ListType partitionBy(ListType &list, int number)
{

   ListType current = list;

   ListType newList = NULL;

   int countNodes = 0;

   int nodeValue = 0;

   while (current != NULL)
   {

      nodeValue = current->data;

      if (nodeValue < number)
      {

         if (newList == NULL)
         {

            ListType newNode = new Node(nodeValue);

            newList = newNode;
         }

         else
         {
            append(newList, nodeValue);
         }
         current = current->next;
         removeNode(list, countNodes);
      }

      else
      {
         current = current->next;
         countNodes++;
      }
   }

   return newList;
}
