#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

    private: 
        int topVal;
};

template <typename T>
Stack<T>::Stack() {
  topVal = -1;
  
}
template <typename T>
Stack<T>::~Stack() {

}
template <typename T>
bool Stack<T>::empty() const {
 if(topVal == -1) 
  return 1;
 else 
    return 0;
}
template <typename T>
void Stack<T>::push(const T& item) {
  topVal += 1;
  std::vector<T>::push_back(item);
}
template <typename T>
void Stack<T>::pop() {
  if(empty()) {
    throw std::underflow_error("Already Empty");
  } else  {
      std::vector<T>::pop_back();
      topVal--;
  }
}
template <typename T>
const T& Stack<T>::top() const {
  if(empty())
    throw std::underflow_error("Already Empty");
   else 
      return std::vector<T>::back();;
}
template <typename T>
size_t Stack<T>::size() const {
    return std::vector<T>::size();
}


#endif
