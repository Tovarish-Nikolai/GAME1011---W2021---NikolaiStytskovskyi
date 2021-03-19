#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

bool isPalindrome(string line, int pos)
{
	if (pos == line.length() / 2)
		return true;
	if (line[pos] == line[line.length() - 1 - pos])
		return isPalindrome(line, pos + 1);
	else
		return false;
}

void reverseString(string line, int pos)
{
	char a, b;

	if (pos != line.length() / 2)
	{
		a = line[pos], b = line[line.length() - 1 - pos];

		line[pos] = b, line[line.length() - 1 - pos] = a;

		return reverseString(line, pos + 1);
	}
	else 
		cout << line << endl;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortInt(int arr[],int size,int pos)
{
	if (pos < size)
	{
		if (arr[pos] > arr[pos + 1])
		{
			swap(&arr[pos], &arr[pos + 1]);
			sortInt(arr, size, pos + 1);
		}
		else
		{
			sortInt(arr, size, pos + 1);
		}
	}
	else if (pos = size)
			sortInt(arr, size - 1, 0);
}

int main()
{
	srand(time(NULL));

	int choice;
	do
	{
		system("CLS");

		cout << " LAB 4 | Recursive Functions" << endl;
		cout << "\n\n\n\n 1. [Check Palindromacy]\n 2. [Sort int array]\n 3. [Reverse a string]\n 4. [EXIT]" << endl;

		cin >> choice;
	
		if (choice == 1)
		{
			cin.ignore();
			system("CLS");

			string line;

			cout << " Enter a word or a sentence to check if it's a palindrome. (please, only in lower case)" << endl;
			getline(cin, line);

			if (isPalindrome(removeSpaces(line), 0))
				cout << "\n Actually is a palindrome." << endl;
			else
				cout << "\n Not a palindrome, oh well." << endl;

			system("pause");
		}

		else if (choice == 2)
		{
			system("CLS");

			int size;

			cout << " Enter an amount of integers to generate (keep it small, stack overflow's a thing)" << endl;
			cin >> size;

			int* arr;
			arr = new int[size];

			for (int i = 0; i < size; i++)
				arr[i] = rand() % 26;

			cout << "\n Unsorted array: ";
			for (int i = 0; i < size; i++)
				cout << arr[i] << ' ';

			sortInt(arr, size - 1, 0);

			cout << "\n\n Sorted array:   ";
			for (int i = 0; i < size; i++)
				cout << arr[i] << ' ';

			system("pause");
		}
		else if (choice == 3)
		{
			system("CLS");
			cin.ignore();
			string line;

			cout << " Please, enter a string to reverse it." << endl;
			getline(cin, line);

			cout << '\n' << line << " | "; reverseString(line, 0);
			
			system("pause");
		}
	} while (choice != 4);
	return 0;
}