#ifndef STACK_H
#define STACK_H

class Stack{
public:
  Stack();
  Stack& operator<< (int value); // push
  Stack& operator>>(int& toSave); // pop
  Stack& operator= (const Stack& other); 
  int operator[](int index) const;
  bool operator<(const Stack& other) const;
  bool operator==(const Stack& other) const;
  bool isEmpty() const;
  ~Stack();
private:
  int capacity;
  int size;
  int *data;
};

#endif // STACK_H