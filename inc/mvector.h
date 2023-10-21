/**
*	@file
*	This is head file of my vector's implementation. There are all methods declaration
*	and their definitions.
**/

#ifndef _MVECTOR_
#define _MVECTOR_

#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>
#include <cstdint>

namespace ns{
	/**
	*	@date 16.09.2020
	*
	*	Implementation of STL container vector for train my skill in
	*	C++ programming and writing code documentation.
	**/
	template<class T>
	class mvector{
	public:
		/**
		*	Default constructor. Constructs an empty container with 0 capasity.
		*	@param none
		**/
		mvector();

		/**
		*	Create an empty vector with an initial capacity.
		*	@param capacity - Initial capacity
		**/
		mvector(size_t capacity);

		/**
		*	Copy constructor. Create a copy of vector.
		*	@param v - vector which will be copy
		**/
		mvector(const mvector<T>& v);

		/**
		*	Destroy all data of vector
		**/
		~mvector();

		/**
		*	@name Capacity
		*	@{
		**/

		/**
		*	Get the size of the current container.
		*	@param none
		*	@return The number of elements in the container
		*	@exception none
		**/
		size_t size() const;

		/**
		*	Get the capasity of the current container.
		*	@param none
		*	@return Number of elements for which memory space is allocated
		*	@exception none
		**/
		size_t capacity() const;

		/**
		*	Return true if the vector is empty.
		*	@param none
		*	@return Return true if the vector is empty, else return false
		*	@exception none
		**/
		bool empty() const;

		/**
		*	@}
		**/

		/**
		*	@name Acces operators and methods
		*	@{
		**/
		/**
		*	Get the element of vector with specified index.
		*	@param idx - index of the element to return
		*	@return constant reference to the requested element
		*	@exception none
		**/
		const T& operator[](const size_t idx) const;

		/**
		*	Get the element of vector with specified index.
		*	@param idx - index of the element to return
		*	@return reference to the requested element
		*	@exception none
		**/
		T& operator[](const size_t idx);

		/**
		*	Get the element of vector with specified index. If index is invalid,
		*	throw exception.
		*	@param idx - index of the element to return
		*	@return constant reference to the requested element
		*	@exception std::out_of_range - if index is invalidate throw exception
		**/
		const T& at(const size_t idx) const;

		/**
		*	Get the element of vector with specified index. If index is invalid,
		*	throw exception.
		*	@param idx - index of the element to return
		*	@return reference to the requested element
		*	@exception std::out_of_range - if index is invalidate throw exception
		**/
		T& at(const size_t idx);

		/**
		*	@}
		**/

		/**
		*	@name Iterators
		*	@{
		**/
		/**
		*	Get an iterator to the first element of a vector.
		*	@param none
		*	@return constant pointer to the first element
		*	@exception none
		**/
		const T* begin() const;

		/**
		*	Get an iterator to the first element of a vector.
		*	@param none
		*	@return pointer to the first element
		*	@exception none
		**/
		T* begin();

		/**
		*	Get an iterator to the element following after last element of the vector.
		*	@param none
		*	@return constant pointer to the element following after last element
		*	@exception none
		**/
		const T* end() const;

		/**
		*	Get an iterator to the element following after last element of the vector.
		*	@param none
		*	@return pointer to the element following after last element
		*	@exception none
		**/
		T* end();
		/**
		*	@}
		**/

		/**
		*	@name Modifiers
		*	@{
		**/
		/**
		*	Insert the element at the end of the vector. If capacity is too small 
		*	for pushing, it will double.
		*	@param value - value for insert
		*	@return none
		*	@exception none
		**/
		void push_back(const T& value);

		/**
		*	Insert the element at the specified position of the vector. 
		*	If capacity is too small for pushing, it will double.
		*	@param value - value for insert
		*	@param pos - pointer before which the content will be inserted
		*	@return none
		*	@exception none
		**/
		void insert(const T& value, const T* pos);

		/**
		*	Erase the element from the end of the vector.
		*	@param none
		*	@return none
		*	@exception none
		**/
		void pop_back();

		/**
		*	Erase the element from the specified position of the vector.
		*	@param pos - pointer to the element to remove
		*	@return none
		*	@exception none
		**/
		void erase(const T* pos);

		/**
		*	Resize vector with saving all elements. If new size is lower current
		*	size then nothing happens.
		*	@param new_size - new size of vector
		*	@return none
		*	@exception none
		**/
		void resize(const size_t new_size);

		/**
		*	Clear data of vector, capacity not change. If vector already cleared,
		*	nothing will happens.
		*	@param none
		*	@return none
		*	@exception none
		**/
		void clear();

		/**
		*	Requests the removal of unused capacity.
		*	@param none
		*	@return none
		*	@exception none
		**/
		void shrink_to_fit();

		/**
		*	@}
		**/

		/**
		*	@name Operators
		*	@{
		**/

		/**
		*	Copy assignment operator. Replaces the contents with a copy 
		*	of the contents of other.
		*	@param rhs - another container to use as data source
		**/
		mvector& operator=(const mvector<T>& rhs);

		/**
		*	@}
		**/

		/**
		*	@name Output methods
		*	@{
		**/
		/**
		*	Operator for outputting a vector to a stream.
		*	@param os - output stream
		*	@param v - vector for output
		*	@return output stream
		*	@exception none
		**/
		friend std::ostream& operator<<(std::ostream& os, const mvector& v) {
		for(size_t i = 0; i < v.size(); ++i){
			os << v[i] << ' ';
		}
		return os;
		/**
		*	@}
		**/
	}

	private:
		T* data_;
		size_t size_;
		size_t capacity_;

		void reserve(size_t new_size);
	};

	template<class T> 
	mvector<T>::mvector() : size_(0), capacity_(0) {}

	template<class T>
	mvector<T>::mvector(size_t capacity) : data_(new T[capacity]), size_(0),
                                           capacity_(capacity) {}

	 template<class T>
	 mvector<T>::mvector(const mvector<T>& v) : size_(v.size()),
                                                capacity_(v.capacity()), data_(new T[v.capacity()]) {
	 	for(size_t i = 0; i < size_; ++i) {
            data_[i] = v[i];
	 	}
	 }

	template<class T>
	mvector<T>::~mvector() {
		delete[] data_;
	}


	template<class T>
	size_t mvector<T>::size() const {
		return size_;
	}

	template<class T>
	size_t mvector<T>::capacity() const {
		return capacity_;
	}

	template<class T>
	bool mvector<T>::empty() const {
		return size_ == 0;
	}

	template<class T>
	const T& mvector<T>::operator[](const size_t idx) const {
		return data_[idx];
	}

	template<class T>
	T& mvector<T>::operator[](const size_t idx) {
		return data_[idx];
	}

	template<class T>
	const T& mvector<T>::at(const size_t idx) const{
		if(idx < 0 || idx >= size_) {
			throw std::out_of_range("Invalidate index!");
		}
		return data_[idx];
	}

	template<class T>
	T& mvector<T>::at(const size_t idx) {
		if(idx < 0 || idx >= size_) {
			throw std::out_of_range("Invalidate index!");
		}
		return data_[idx];
	}

	template<class T>
	const T* mvector<T>::begin() const {
		return data_;
	}

	template<class T>
	T* mvector<T>::begin() {
		return data_;
	}

	template<class T>
	const T* mvector<T>::end() const {
		return *(data_ + size_);
	}

	template<class T>
	T* mvector<T>::end() {
		return data_ + size_;
	}

	template<class T>
	void mvector<T>::push_back(const T& value) {
		if(capacity_ == 0) {
			reserve(8);
		}
		else if(size_ == capacity_) {
			reserve(capacity_ * 2);
		}

        data_[size_++] = value;
	}

	template<class T>
	void mvector<T>::insert(const T& value, const T* pos) {
		if(size_ == capacity_) {
			resize(size_ * 2);
		}

		size_t position = pos - begin();
		T* tmp_data = new T[capacity_];
		size_++;

		for(size_t i = 0; i < position; ++i) {
			tmp_data[i] = data_[i];
		}
		tmp_data[position] = value;
		for(size_t i = position + 1; i < size_; ++i) {
			tmp_data[i] = data_[i - 1];
		}
		delete[] data_;
        data_ = tmp_data;
	}

	template<class T>
	void mvector<T>::pop_back() {
		if(size_ == 0) {
			return;
		}
		// data_[size_].~T();
		size_--;
	}

	template<class T>
	void mvector<T>::erase(const T* pos) {
		size_t index_erasing_elem = pos - begin();
		T* tmp_data = new T[capacity_];

		for(size_t i = 0; i < index_erasing_elem; ++i) {
			tmp_data[i] = data_[i];
		}	
		// data_[index_erasing_elem].~T();
		for(size_t i = index_erasing_elem + 1; i < size_; ++i) {
			tmp_data[i - 1] = data_[i];
		}
        data_ = tmp_data;
		size_--;
	}

	template<class T>
	void mvector<T>::resize(const size_t new_size) {
		if(new_size <= capacity_) {
			std::cerr << "New size is lower then current size. Size not changed."
					  << std::endl;
			return;
		}
		else {
			reserve(new_size);
			for(size_t i = size_; i < new_size; ++i) {
                data_[i] = T();
			}
		}
	}

	template<class T>
	void mvector<T>::clear() {
		delete[] data_;
        data_ = new T[capacity_];
        size_ = 0;
	}

	template<class T>
	void mvector<T>::shrink_to_fit() {
		if(size_ == capacity_) {
			return;
		}
        capacity_ = size_;
		T* tmp_data = new T[capacity_];

		for(size_t i = 0; i < size_; ++i){
			tmp_data[i] = data_[i];
		}
		delete[] data_;
        data_ = tmp_data;
	}

	template<class T>
	mvector<T>& mvector<T>::operator=(const mvector<T>& rhs) {
        size_ = rhs.size();
        capacity_ = rhs.capacity();
		delete[] data_;
        data_ = new T[capacity_];

		for(size_t i = 0; i < size_; ++i) {
            data_[i] = rhs[i];
		}

		return *this;
	}

	/*---------- PRIVATE METHODS ----------*/

	template<class T>
	void mvector<T>::reserve(size_t new_size) {
		if(new_size <= capacity_) {
			std::cerr << "New size is lower then current size. Size not changed."
				 	  << std::endl;
			return;
		}
        T* new_data = reinterpret_cast<T*>(new int8_t[new_size * sizeof(T)]);
        size_t i = 0;
        try {
            for (; i < size_; ++i)
                new(new_data + i) T(data_[i]);
        }
        catch(...){
            for (size_t j = 0; j < i; ++j)
                (new_data + j)->~T();

            delete [] reinterpret_cast<int8_t*>(new_data);
            throw;
        }
        for(size_t k = 0; k < size_; ++k)
            (data_ + k)->~T();
        delete [] reinterpret_cast<int8_t*>(data_);
        data_ = new_data;
        capacity_ = new_size;
        size_ = new_size;
	}
};

#endif	//_MVECTOR_