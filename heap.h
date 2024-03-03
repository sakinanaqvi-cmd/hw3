#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> vec;
  int m2; PComparator c2;

  void swap(int index1, int index2);
  int checkGreater(int index1, bool larger);
  void heapifyUp();
  void heapifyDown();

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) {
  c2 = c;
  m2 = m;
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {
  
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp() {
  int par = (curr - 1)/m2;
  int curr = vec.size() - 1;
  bool cond = false;
  if(c2(vec[curr], vec[par]) && curr > 0 && par >= 0) {
    cond = true
  }

  while(cond) {
    swap(curr, par);

    curr = par; //swapping the indexes
    par = (curr - 1)/m2;
  }

}
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown() {
  int curr = 0, newVal;
  bool larger = true;
  if(empty()) 
    return;
  else {
    newVal = checkGreater(curr, larger);
    //check for the greatest value 
    while((curr*m2) + 1 < vec.size() && larger) {
      if(newVal > curr) {
        swap(curr, newVal);
        curr = newVal;
      }

      if(vec.size() <= (curr*m2) + m2) {
        larger = false;
      } 
    }
  }
}
template <typename T, typename PComparator>
int Heap<T,PComparator>::checkGreater(int curr, bool larger) {
  T par = vec[curr];
  T child = par;

  int childLoc = curr;

  for(int i = 1; i <= 2; i++) {
    //continue until each node has been addressed and checked for each level 
    //for the binary tree
    if((curr*2) + i < vec.size())  {
      if(c2(vec[(curr*2) + i], child)) {
        child = vec[(curr*2) + i];
        childLoc =  i + (curr * 2);
      }
    }
  }
  if(par == child || vec.size() <= (curr*2) + 2) 
    larger = false;

  return childLoc;
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  vec.push_back(item);

  //need to heapify up the binary tree
  heapifyUp();
  
}
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Already empty");
  } else {
      //the last value goes to the front 
      T val = vec.back(); //last value 
      vec[0] = val;

      vec.pop_back();

      //need to heapify down through the tree
      heapifyDown();
  }
}
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Already empty");
  } else {
      return vec[0];
  }

}
template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(int index1, int index2) {
   //swap using temporary value
   T temporary = vec[index1];
   vec[index1] = vec[index2];
   vec[index2] = temporary;
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  if(vec.size() != 0) 
    return false;
  else 
    return true;
}
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return vec.size();
}
#endif

