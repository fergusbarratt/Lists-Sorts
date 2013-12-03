#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void swap_elems(vector<int> list, int index1, int index2)
{
	int a = list.at(index2);
	list.at(index2) = list.at(index1);
	list.at(index1) = a;
}
vector<int> listbuilder(int length, char forwards = 'n')
{
	vector<int> returnlist;
	if (forwards == 'y')
	{
		for (int i = 0; i <= length; i++)
		{
			returnlist.push_back(i);
		}
	}
	else
	{
		for (int i = length; i >= 0; i--)
		{
			returnlist.push_back(i);
		}
	}
	return returnlist;
}
vector<int> bubblesort(vector<int> unsortedlist)
{

}
/*void listprinter1(vector<int> list, char separator = ' ')
{
for (vector<int>::const_iterator i = list.begin(); i != list.end(); i++)
{
cout << *i << separator;
}
cout << "\n";
}*/
void listprinter(vector<int> list, char separator = ' ')
{
	for (int i = 0; i <= list.size() - 1; i++)
	{
		cout << list.at(i) << separator;
	}
	cout << "\n";
}
int main()
{
	vector<int> list1 = listbuilder(10, 'n');
	listprinter(list1);
	bubblesort(list1);
	listprinter(list1);
	return 0;
}