#ifndef GUARD_Vec
#define GUARD_Vec
#include <cstddef>
#include <memory>

template <class T> class Vec {
public:
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef std::size_t size_type;
  typedef T value_type;
  typedef T& reference;
  typedef const T& const_reference;
  typedef std::ptrdiff_t difference_type;

  // Constructors
  Vec() {
    create();
  }
  explicit Vec(size_type n, const T& val) {
    create(n,val);
  }
  /***** RULE OF THREE BEGIN *****/
  // Destructor
  ~Vec() {
    uncreate();
  }
  // Copy constructor
  Vec(const Vec& v) {
    create(v.begin(),v.end());
  }
  // Assignment operator
  Vec& operator=(const Vec& rhs) {
    if (&rhs != this) {
      uncreate();
      create(rhs.begin(),rhs.end());
    }
    return *this;
  }

  /***** RULE OF THREE END *****/

  // Other operators
  T& operator[](size_type i) {
    return data[i];
  }
  const T& operator[](size_type i) const {
    return data[i];
  }
  // Iterator methods
  iterator begin() {
    return data;
  }
  const_iterator begin() const {
    return data;
  }
  iterator end() {
    return avail;
  }
  const_iterator end() const {
    return avail;
  }
  // size
  size_type size() {
    return avail-data;
  }
  // push_back
  void push_back(const T& val) {
    if (avail == limit) {
      grow();
    }
    unchecked_append(val);
  }

private:
  iterator data;
  iterator limit;
  iterator avail;
  std::allocator<T> alloc;

  void create();
  void create(size_type n, const T& val);
  void create(const_iterator b, const_iterator e);

  void uncreate();
  void grow();
  void unchecked_append(const T& val);

  
};

template <class T>
void Vec<T>::create() {
  // Do nothing for now
  data = NULL;
  avail = NULL;
  limit = NULL; 
}

template <class T>
void Vec<T>::create(size_type n, const T& val) {
  data = alloc.allocate(n);
  avail = data + n;
  limit = avail;
  std::uninitialized_fill(data,limit,val);
}
template <class T>
void Vec<T>::create(const_iterator b,const_iterator e) {
  data = alloc.allocate(e-b);
  avail = std::uninitialized_copy(b,e,data);
  limit = avail;
}


template <class T>
void Vec<T>::uncreate() {
  if (data) {
    // Destroy constructed
    iterator it = avail;
    while (it != data) {  
      it--;
      alloc.destroy(it);
    }
    // Deallocate all
    alloc.deallocate(data,limit-data);    
  }
  data = NULL;
  avail = NULL;
  limit = NULL;
}

template <class T>
void Vec<T>::grow() {
  size_type new_size = std::max(2*(limit-data),ptrdiff_t(1));
  // Allocate and copy existing elements
  iterator new_data = alloc.allocate(new_size);
  iterator new_avail = std::uninitialized_copy(data,avail,new_data);

  // Return the old space
  uncreate();

  data = new_data;
  avail = new_avail;
  limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
  alloc.construct(avail,val);
  avail++;
}


#endif
