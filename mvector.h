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
		T* _data; 	
		size_t _size;	
		size_t _capacity;

		void reserve(const size_t new_size);
	};

	template<class T> 
	mvector<T>::mvector() : _size(0), _capacity(0) {}

	template<class T>
	mvector<T>::mvector(size_t capacity) : _data(new T[capacity]), _size(0),
	 _capacity(capacity) {}

	 template<class T>
	 mvector<T>::mvector(const mvector<T>& v) : _size(v.size()), 
	 _capacity(v.capacity()), _data(new T[v.capacity()]) {
	 	for(size_t i = 0; i < _size; ++i) {
	 		_data[i] = v[i];
	 	}
	 }

	template<class T>
	mvector<T>::~mvector() {
		delete[] _data;
	}


	template<class T>
	size_t mvector<T>::size() const {
		return _size;
	}

	template<class T>
	size_t mvector<T>::capacity() const {
		return _capacity;
	}

	template<class T>
	bool mvector<T>::empty() const {
		return _size == 0;
	}

	template<class T>
	const T& mvector<T>::operator[](const size_t idx) const {
		return _data[idx];
	}

	template<class T>
	T& mvector<T>::operator[](const size_t idx) {
		return _data[idx];
	}

	template<class T>
	const T& mvector<T>::at(const size_t idx) const{
		if(idx < 0 || idx >= _size) {
			throw std::out_of_range("Invalidate index!");
		}
		return _data[idx];
	}

	template<class T>
	T& mvector<T>::at(const size_t idx) {
		if(idx < 0 || idx >= _size) {
			throw std::out_of_range("Invalidate index!");
		}
		return _data[idx];
	}

	template<class T>
	const T* mvector<T>::begin() const {
		return _data;
	}

	template<class T>
	T* mvector<T>::begin() {
		return _data;
	}

	template<class T>
	const T* mvector<T>::end() const {
		return *(_data + size);
	}

	template<class T>
	T* mvector<T>::end() {
		return _data + _size;
	}

	template<class T>
	void mvector<T>::push_back(const T& value) {
		if(_capacity == 0) {
			reserve(8);
		}
		else if(_size == _capacity) {
			reserve(_capacity * 2);
		}

		_data[_size++] = value;
	}

	template<class T>
	void mvector<T>::insert(const T& value, const T* pos) {
		if(_size == _capacity) {
			resize(_size * 2);
		}

		size_t position = pos - begin();
		T* tmp_data = new T[_capacity];
		_size++;

		for(size_t i = 0; i < position; ++i) {
			tmp_data[i] = _data[i];
		}
		tmp_data[position] = value;
		for(size_t i = position + 1; i < _size; ++i) {
			tmp_data[i] = _data[i - 1];
		}
		delete[] _data;
		_data = tmp_data;
	}

	template<class T>
	void mvector<T>::pop_back() {
		if(_size == 0) {
			return;
		}
		// _data[_size].~T();
		_size--;
	}

	template<class T>
	void mvector<T>::erase(const T* pos) {
		size_t index_erasing_elem = pos - begin();
		T* tmp_data = new T[_capacity];

		for(size_t i = 0; i < index_erasing_elem; ++i) {
			tmp_data[i] = _data[i];
		}	
		// _data[index_erasing_elem].~T();
		for(size_t i = index_erasing_elem + 1; i < _size; ++i) {
			tmp_data[i - 1] = _data[i];
		}
		_data = tmp_data;
		_size--;
	}

	template<class T>
	void mvector<T>::resize(const size_t new_size) {
		if(new_size <= _capacity) {
			std::cerr << "New size is lower then current size. Size not changed."
					  << std::endl;
			return;
		}
		else {
			reserve(new_size);
			for(size_t i = _size; i < new_size; ++i) {
				 _data[i] = T();
			}
		}
	}

	template<class T>
	void mvector<T>::clear() {
		delete[] _data;
		_data = new T[_capacity];
		_size = 0;
	}

	template<class T>
	void mvector<T>::shrink_to_fit() {
		if(_size == _capacity) {
			return;
		}
		_capacity = _size;
		T* tmp_data = new T[_capacity];

		for(size_t i = 0; i < _size; ++i){
			tmp_data[i] = _data[i];
		}
		delete[] _data;
		_data = tmp_data;
	}

	template<class T>
	mvector<T>& mvector<T>::operator=(const mvector<T>& rhs) {
		_size = rhs.size();
		_capacity = rhs.capacity();
		delete[] _data;
		_data = new T[_capacity];

		for(size_t i = 0; i < _size; ++i) {
			_data[i] = rhs[i];
		}

		return *this;
	}

	/*---------- PRIVATE METHODS ----------*/

	template<class T>
	void mvector<T>::reserve(const size_t new_size) {
		if(new_size <= _capacity) {
			std::cerr << "New size is lower then current size. Size not changed."
				 	  << std::endl;
			return;
		}
		else {
			T* new_data = new T[new_size];
			for(size_t i = 0; i < _size; ++i) {
				new_data[i] = _data[i];
			}
			delete[] _data;
			_data = new_data;
			_capacity = new_size;
		}
	}
};

#endif	//_MVECTOR_