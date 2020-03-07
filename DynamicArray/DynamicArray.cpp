// Array Abstract Data Type.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "dynamic_array.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int* string_to_array(const size_t& length)
{
	string rawInput;
	cin.ignore();
	getline(cin, rawInput);
	int* input_array = new int[length];
	std::stringstream ss(rawInput);
	int i = 0;
	while (ss >> rawInput)
	{
		input_array[i] = stoi(rawInput);
		++i;
	}
	return input_array;
}

int main()
{
	unsigned size;
	cout << "Enter size of first array: ";
	cin >> size;
	cout << "Enter first integer array separated by a space." << endl;
	int* input_array = string_to_array(size);
	dynamic_array<int> a(input_array, size);
	delete[] input_array;
	/*
	cout << "Enter size of second array: ";
	cin >> size;
	cout << "Enter second integer array separated by a space." << endl;
	int* input_array2 = string_to_array();
	array_adt<int, unsigned> b(input_array2, size);
	delete[] input_array2;
	*/

	cout << "\
			1) Print Array\n \
			2) Get Element\n \
			3) Get Minimum\n \
			4) Get Maximum\n \
			5) Get Minimum & Maximum\n \
			6) Set Element\n \
			7) Sort Array\n \
			8) Find Element\n \
			9) Reverse Array\n\
			10) Cyclic Right Shift\n\
			11) Cyclic Left Shift\n\
			12) delete_and_left_shift_elements_to_its_right \n\
			13) Create Set \n\
			14) Find Missing Elements in a sorted range\
			15)";

	cout << "Select an option from the menu\n";
	unsigned input;

	do
	{
		cin >> input;

		switch (input)
		{
		case 1: // 1) Print Array
		{
			cout << "\n1) Print Array\n";
			a.print();
		}
		break;
		case 2: //2) Get Element
		{
			cout << "\n2) Get Element\n";
			cout << "Enter index: ";
			unsigned index;
			cin >> index;
			cout << "Element is : " << a.get_element(index);
		}
		break;
		case 3: //3) Get Minimum
		{
			cout << "\n3) Get Minimum\n";
			cout << "Minimum element is : " << a.min_element();
		}
		break;
		case 4: //4) Get Maximum
		{
			cout << "\n4) Get Maximum\n";
			cout << "Maximum element is : " << a.max_element();
		}
		break;
		case 5: //5) Get Minimum & Maximum
		{
			cout << "\n5) Get Minimum & Maximum\n";
			pair<int, int> p = a.min_max();
			cout << "Minimum element is : " << p.first << " and Maximum element is: " << p.second;
		}
		break;
		case 6: // 6) Set Element
		{
			cout << "\n6) Set Element\n";
			unsigned index = 0;
			int element = 0;
			cout << "Enter index: ";
			cin >> index;
			cout << "Enter element's value: ";
			cin >> element;
			a.set_element(index, element);
		}
		break;
		case 7: //7) Sort Array
		{
			cout << "\n7) Sort Array\n";
			a.selection_sort();
		}
		break;
		case 8: //8) Find Element
		{
			cout << "\n8) Find Element\n";
			int element;
			bool flag = false;
			pair<size_t, bool> res;
			cout << "Enter the element you want to find: ";
			cin >> element;
			if (a.is_sorted())
			{
				res = a.binary_search(element);
				if (res.second)
					flag = true;
			}
			else
			{
				res = a.linear_search(element);
				if (res.second)
					flag = true;
			}
			if (flag == true)
				cout << res.first;
			else
				cout << "Element not found";
		}
		break;
		case 9: // 9) Reverse Array
		{
			cout << "\n9) Reverse Array" << endl;
			a.reverse();
		}break;
		case 10:
		{
			cout << "\n10) Cyclic Right Shift" << endl;
			a.cyclic_right_shift();
		}break;
		case 11:
		{
			cout << "\n11) Cyclic Left Shift" << endl;
			a.cyclic_left_shift();
		}break;
		case 12:
		{
			cout << "\n12) delete_and_left_shift_elements_to_its_right" << endl;
			size_t index;
			cout << "Enter index: ";
			cin >> index;
			a.delete_and_left_shift_elements_to_its_right(index);
		}break;
		case 13:
		{
			cout << "\n13) Create Set\n";
			a.create_set();
		}break;
		case 14:
		{
			cout << "\nmissing_elements_in_a_sorted_range";
			/*std::vector<int> v = a.missing_elements_in_a_sorted_range();
			for (int i : v)
				cout << i << " ";
			cout << "\n";*/
		}break;
		default:
			cout << "Non-Menu item input received, exiting ";
		}
		cout << endl << endl;
	} while (input < 14);
	return 0;
}
