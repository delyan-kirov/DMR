#ifndef QUEUE_H
#define QUEUE_H

namespace Queue {

template <typename T> struct List {
  T data;        // Data stored in the node
  List<T> *next; // Pointer to the next node
};

template <typename T> struct Queue {
  // Deleted copy constructor and assignment operator
  Queue(const Queue &) = delete;
  Queue &operator=(const Queue &) = delete;
  ~Queue() = delete;

  // Static method to get the singleton instance
  static Queue<T> &getInstance() {
    static Queue<T>
        instance; // Guaranteed to be destroyed and instantiated on first use
    return instance;
  }

  // Add an item to the queue
  void enque(const T &t) {
    auto *ptr = new List<T>; // Create a new node
    ptr->data = t;           // Set the data
    ptr->next = nullptr;     // The next pointer is null

    if (end != nullptr) {
      end->next = ptr; // Link the new node
    } else {
      begin = ptr; // If the queue was empty, set begin
    }
    end = ptr; // Update the end to the new node
  }

  // Remove the first item from the queue
  void deque() {
    if (isEmpty()) {
      return;
    }

    List<T> *temp = begin; // Keep a pointer to the beginning
    begin = begin->next;   // Move begin to the next element

    // If the queue is now empty, reset end to nullptr
    if (begin == nullptr) {
      end = nullptr;
    }

    delete temp; // Free the memory for the dequeued node
  }

  // Peek at the front value without removing it
  T *peek() const {
    return isEmpty()
               ? nullptr
               : &(begin->data); // Return a pointer to the data or nullptr
  }

  // Check if the queue is empty
  bool isEmpty() const { return begin == nullptr; }

private:
  List<T> *begin; // Pointer to the front of the queue
  List<T> *end;   // Pointer to the end of the queue
  // Constructor
  Queue() : begin(nullptr), end(nullptr) {}
};
} // namespace Queue

namespace Event {}

#endif // QUEUE_H
