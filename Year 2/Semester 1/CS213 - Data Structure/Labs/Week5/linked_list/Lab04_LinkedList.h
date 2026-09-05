#ifndef LAB02_LINKEDLIST_V2_H
#define LAB02_LINKEDLIST_V2_H

class Node
{
   public:
      int info;
      Node* next;

      Node(int value);
};

class List
{
   private:
      Node* head;

   public:
      List();
      ~List();

      bool emptyList() const;
      void insertLast(int value);
      void printList() const;

      // ===== STUDENT TASKS =====
      void insertBefore(int target, int value);
      void moveToFront(int value);
      void removeAfter(int value);
};

#endif
