  #ifndef HEAP_H
  #define HEAP_H
  #include <functional>
  #include <stdexcept>
  #include <vector>
  #include <iostream>
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
    void heapify();
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
  void Heap<T,PComparator>::heapify() {
    //start by splitting it in half and then checking everything 
    int children[m2];
    for(int i = (vec.size() - 1)/2; i >= 0; i--) {
      int parent = i;
      for(int j = 0; j < m2; j++) {
        children[j] = (m2 * parent) + (j + 1);
      }
      for(int j = 0; j < m2; j++) {
        if(children[j] < vec.size()) {
          if(c2(vec[children[j]], vec[parent]))
            swap(children[j], parent);
        }
      }
    } 
  }
  template <typename T, typename PComparator>
  void Heap<T,PComparator>::push(const T& item) {
    vec.push_back(item);

    //need to heapify the binary tree
    heapify();
    
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

        //need to heapify through the tree
        heapify();
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

