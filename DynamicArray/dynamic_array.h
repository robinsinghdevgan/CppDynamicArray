#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <utility>
#include <set>
#include <vector>
#include <map>

template<class T>
class dynamic_array
{
public:
	unsigned long long length;
	unsigned long long capacity;
	T* arr;
	//constructers
	dynamic_array();
	dynamic_array(unsigned long long size);
	dynamic_array(T copyArray[], unsigned long long n);
	//destructer
	~dynamic_array();

	void print();

	//getters
	unsigned long long size();
	T get_element(unsigned long long index);
	T min_element();
	T max_element();
	std::pair<T, T> min_max();

	//setters
	void set_element(unsigned long long index, T key);

	//removers
	void delete_and_left_shift_elements_to_its_right(unsigned long long index);

	//shift
	void cyclic_right_shift();
	void cyclic_left_shift();

	//partition
	void partition();

	//sort
	void swap(T* a, T* b);
	void selection_sort();
	bool is_sorted();

	//search elements
	std::pair<T, bool> linear_search(T key);
	std::pair<unsigned long long, bool> binary_search(T key);

	//reverse the order
	void reverse();

	//std::vector<T> missing_elements_in_a_sorted_range();
	//std::vector<T> duplicates();

	//set creation and set operations
	void create_set(); //delete duplicate elements in the array
	//array_adt<T>& union_operation(const array_adt<T> & x, const array_adt<T> & y); //returns a new array_adt object xUy
	//array_adt<T>& difference_operation(const array_adt<T> & x, const array_adt<T> & y); //returns a new array_adt object xUy
	dynamic_array<T>* intersection_operation(dynamic_array<T>& y); //returns a new array_adt object xUy

	/*
	*TODO
	*MERGE TWO ARRAYS
	*SET OPERATIONS:
		UNION
		DIFFERENCE
		INTERSECTION
	*FIND
		SINGLE MISSING ELEMENT IN A RANGE
			ARRAY IS SORTED
			ARRAY IS UNSORTED
		MULTIPLE MISSING ELEMENT IN A RANGE
			ARRAY IS SORTED
			ARRAY IS UNSORTED
	*FIND DUPLICATES IN
		SORTED ARRAY
		UNSORTED ARRAY
	*FIND A PAIR OF ELEMENTS WITH SUM k
	*CREATE ARRAY WITH ALL NUMBERS IN A RANGE (SORTED N RANDOM)
	*/
};

#endif // !ARRAY_ADT_H

template<class T>
inline dynamic_array<T>::dynamic_array() { dynamic_array::length = 0; capacity = 0; }

template<class T>
inline dynamic_array<T>::dynamic_array(unsigned long long size) { capacity = size; arr = new T[size]; }

template<class T>
inline dynamic_array<T>::dynamic_array(T copyArray[], unsigned long long n)
{
	length = capacity = n;
	arr = new T[n];
	for (unsigned long long i = 0; i < n; ++i)
		arr[i] = copyArray[i];
}

template<class T>
inline dynamic_array<T>::~dynamic_array() { delete[] arr; }

template<class T>
inline void dynamic_array<T>::print()
{
	std::cout << "|| ";
	for (unsigned long long i = 0; i < length; ++i)
		std::cout << arr[i] << " ";
	std::cout << " ||";
	for (unsigned long long i = length; i < capacity; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

//getters

template<class T>
inline unsigned long long dynamic_array<T>::size() { return length; }

template<class T>
inline T dynamic_array<T>::get_element(unsigned long long index)
{
	if (index > 0 && index < length)
		return arr[index];
	std::cout << "Index out of bounds.\n";
	return T();
}

template<class T>
inline T dynamic_array<T>::min_element()
{
	T min = 0;
	if (length)
	{
		min = arr[0];
		for (unsigned long long i = 1; i < length; ++i)
			if (arr[i] < min)
				min = arr[i];
	}
	return min;
}

template<class T>
inline T dynamic_array<T>::max_element()
{
	T max = 0;
	if (length)
	{
		max = arr[0];
		for (unsigned long long i = 1; i < length; ++i)
			if (arr[i] > max)
				max = arr[i];
	}
	return max;
}

template<class T>
inline std::pair<T, T> dynamic_array<T>::min_max()
{
	T min, max;
	if (length)
	{
		max = min = arr[0];
		for (unsigned long long i = 1; i < length; ++i)
		{
			if (arr[i] > max)
				max = arr[i];
			if (arr[i] < min)
				min = arr[i];
		}
	}
	return std::pair<T, T>(min, max);
}

template<class T>
inline void dynamic_array<T>::set_element(unsigned long long index, T key)
{
	if (index > 0 && index < length)
	{
		arr[index] = key;
		return;
	}
	std::cout << "Index out of bounds.\n";
}

template<class T>
inline void dynamic_array<T>::delete_and_left_shift_elements_to_its_right(unsigned long long index)
{
	if (!(index > 0 && index < length))
		return;
	arr[index] = 0;
	for (unsigned long long i = index; i < length - 1; ++i)
		arr[i] = arr[i + 1];
	arr[length - 1] = 0;
	--length;
}

template<class T>
inline void dynamic_array<T>::cyclic_right_shift()
{
	T temp = arr[length - 1];
	for (unsigned long long i = length - 2; i != static_cast<unsigned long long>(-1); --i)
	{
		arr[i + 1] = arr[i];
	}
	arr[0] = temp;
}

template<class T>
inline void dynamic_array<T>::cyclic_left_shift()
{
	T temp = arr[0];
	for (unsigned long long i = 0; i < length - 1; ++i)
	{
		arr[i] = arr[i + 1];
	}
	arr[length - 1] = temp;
}

template<class T>
inline void dynamic_array<T>::partition()
{
	T pivot = arr[0];
	unsigned long long pivot_pos = 0;
	for (unsigned long long i = 1; i < size(); ++i)
	{
		if (arr[i] < pivot)
		{//swap pivot pos with i
			arr[pivot_pos] = arr[i];
			arr[i] = pivot;
		}
	}
}

template<class T>
inline void dynamic_array<T>::swap(T* a, T* b) { T temp = *a; *a = *b; *b = temp; }

template<class T>
inline void dynamic_array<T>::selection_sort()
{
	for (unsigned long long i = 0, size = length - 1; i < size; ++i)
	{
		unsigned long long k, j;
		k = i;
		j = i + 1;
		T min = arr[i];
		while (j < length)
		{
			if (arr[j] < min)
				k = j;
			++j;
		}
		swap(&arr[i], &arr[k]); //k is now points to the min ele, swap with i
	}
}

template<class T>
inline bool dynamic_array<T>::is_sorted()
{
	for (unsigned long long i = 0; i < length - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

template<class T>
inline std::pair<T, bool> dynamic_array<T>::linear_search(T key)
{
	for (unsigned long long i = 0; i < length; ++i)
		if (arr[i] == key)
			return std::pair<T, bool>(i, true);
	return std::pair<T, bool>(0, false);
}

template<class T>
inline std::pair<unsigned long long, bool> dynamic_array<T>::binary_search(T key)
{
	unsigned long long low, mid, high;
	low = 0;
	high = length - 1;
	while (low <= high) {
		//mid = (low+high)/2;
		mid = (low + high) >> 1;
		if (arr[mid] == key)
			return std::pair<unsigned long long, bool>(mid, true);
		else if (arr[mid] < key) //unsigned long long int falls into cycle as, 0-1 leads to 4294967235
		{
			if (mid == 0) break; high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return std::pair<unsigned long long, bool>(0, false);
}

template<class T>
inline void dynamic_array<T>::reverse()
{
	unsigned i = 0, j = length - 1;
	while (i < j && j > 0)
	{
		swap(&arr[i], &arr[j]);
		++i, --j;
	}
}
/*template<class T>
inline std::vector<T> dynamic_array<T>::missing_elements_in_a_sorted_range()
{
	T diff = arr[0];
	std::vector<T> result;
	for (unsigned long long i = 0, last_element; i < length; ++i)
	{
		T ith_value = arr[i];
		if ((ith_value - diff) > i)
		{
			for (unsigned long long j = last_element; j < i; ++j)
				result.push_back();
			diff = ith_value;
		}
		last_element = i;
	}
	return result;
}*/
/*template<class T>
inline std::vector<T> dynamic_array<T>::duplicates()
{
	map<T> m;
	for (unsigned long long i = 0; i < length; ++i)
	{
		if (m.find(arr[i]) == m.end())
		{
			m
		}
		m[arr[i]]
	}
	return std::vector<T>();
}*/
template<class T>
inline void dynamic_array<T>::create_set()
{
	std::cout << "Finding and removing all duplicates.\n";
	std::set<T> s;
	s.insert(arr[0]);
	for (unsigned long long i = 1; i < length; ++i)
	{
		if (s.find(arr[i]) != s.end())
			delete_and_left_shift_elements_to_its_right(i);
		s.insert(arr[i]);
	}
}
template<class T>
inline dynamic_array<T>* dynamic_array<T>::intersection_operation(dynamic_array<T>& y)
{
	unsigned long long i, k;
	bool is_y_sorted = y.is_sorted();

	//create a local array of size of x
	T* temp = new T[length];

	for (i = 0, k = 0; i < length; ++i)
	{
		if (is_y_sorted)
		{
			if (y.binary_search(this->arr[i]).second)
				temp[k++] = arr[i];
		}
		else if (y.linear_search(this->arr[i]).second)
			temp[k++] = arr[i];
		else //value not in y
			continue;
	}

	dynamic_array<T>* z(new dynamic_array<T>(k));
	for (i = 0; i < k; ++i)
	{
		z->arr[i] = temp[i];
	}
	delete[] temp;
	//z.print();
	return z;
}
