#include "student.h"
#include <string>
#include <cstring>
#include <sstream>

Student::Student(const char * const name, int perm) {
  this->name = new char[strlen(name)+1];
  strcpy(this->name,name);
  this->perm = perm;
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  this->perm = permNumber;
}

void Student::setName(const char * const name) {
  delete[] this->name;
  this->name = new char[strlen(name)+1];
  strcpy(this->name,name);
}


Student::Student(const Student &orig) {
  this->name = new char[strlen(name)+1];
  strcpy(this->name, orig.getName());
  this->perm = orig.getPerm();
}

Student::~Student() {
  delete[] name;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  delete[] this->name; //data
    this->name = new char[strlen(right.getName()) + 1];
    strcpy(this->name, right.getName());
    this->perm = right.getPerm();

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
    std::stringstream oss;
    oss << "[" << name << "," << perm << "]";
    return oss.str();
}

