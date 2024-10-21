#include <string>
#include "studentRoll.h"
#include <sstream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Student* newStudent = new Student(s);
  Node* newNode = new Node;

  newNode->s = newStudent;
  newNode->next = NULL;

  if (head == NULL) {
      head = tail = newNode;
  } else {
      tail->next = newNode;
      tail = newNode;
  }
}

std::string StudentRoll::toString() const {
  std::stringstream res;
  res << "{";
  Node* cur = this->head;
  while (cur != NULL) {
      res << cur->s->toString();
      cur = cur->next;
      res << ",";
  }

  res << "}";
  return res.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  Node* cur = orig.head;
  while (cur != NULL) {
      insertAtTail(*(cur->s));
      cur = cur->next;
  }
}

StudentRoll::~StudentRoll() {
  Node *cur = this->head;
    while (cur != NULL) {
        Node *temp = cur;
        cur = cur->next;
        delete temp->s;
        delete temp;
    }
  head = tail = NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node *cur = this->head;
  while (cur != NULL) {
      Node *temp = cur;
      cur = cur->next;
      delete temp->s;
      delete temp;
  }
  head = tail = NULL;
  
  Node *cur2 = right.head;
  while (cur2 != NULL) {
      insertAtTail(*(cur2->s));
      cur2 = cur2->next;
    }


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





