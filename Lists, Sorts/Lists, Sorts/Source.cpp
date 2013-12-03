#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
//list tools
void listprinter(vector<double> list, char separator = ' ')
{
for (vector<double>::const_iterator i = list.begin(); i != list.end(); i++)
{
cout << *i << separator;
}
cout << "\n";
}
vector<double> listbuilder(int length, int start = 1, string type = "fsequential", int rand_interval_start = 0, int rand_interval_end = 100, double increment = 1)
{
	vector<double> returnlist;
	if (type == "fsequential")
		{
			for (int i = start; i <= length; i=i+increment)
			{
				returnlist.push_back(i);
			}
		}
	else if (type == "rsequential")
		{
			for (int i = length; i >= start; i = i - increment)
			{
				returnlist.push_back(i);
			}
		}
	else if (type == "random")
	{
		//rand() modulo end of range added to beginning of range. skewed towards low numbers
		for (int i = start; i <= length; i++)
		{
			returnlist.push_back(((rand() % rand_interval_end) + rand_interval_start));
		}
		return returnlist;
	}
	else
	{
		for (int i = 0; i <= length; i++)
		{
			returnlist.push_back(0);
		}
		return returnlist;
	}
	return returnlist;
}
vector<double> vector_pass_by_reference(vector<double> list)
{
	vector<double>* listptr = &list;
	vector<double> returnlist = *listptr;
	return returnlist;
}
//element tools
vector<double> swap_elems(vector<double> list, int index1, int index2)
{
	vector<double> swapped_list = vector_pass_by_reference(list);
	int a = swapped_list.at(index2);
	swapped_list.at(index2) = swapped_list.at(index1);
	swapped_list.at(index1) = a;
	return swapped_list;
}
bool bigger_than(double a, double b)
{
	if (a > b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//sorting tools
bool sorted(vector<double> list)
{
	vector<double> testlist = vector_pass_by_reference(list);
	for (int i = 0; i < list.size() - 1; i++)
	{
		if (bigger_than(testlist.at(i), testlist.at(i + 1)))
		{
			return false;
		}
	}
	return true;
}
vector<double> bubblesort(vector<double> unsortedlist)
{
	vector<double> sortinglist = vector_pass_by_reference(unsortedlist);
	int unsortedlistlength = sortinglist.size();
	while (sorted(sortinglist) == false)
	{
		for (int i = 0; i < unsortedlistlength - 1; i++)
		{
			if (bigger_than(sortinglist.at(i), sortinglist.at(i + 1)))
			{
				sortinglist = swap_elems(sortinglist, i, i + 1);
			}
		}
	}
	return sortinglist;
}

//averages
double mean(vector<double> list)
{
	double sum = 0;
	for (int i = 0; i < list.size() - 1; i++)
	{
		sum += list.at(i);
	}
	return sum / (list.size() - 1);
}
double median(vector<double> list)
{
	return bubblesort(list).at(list.size() / 2);
}
double mode(vector<double> list)
{
	vector<double> sorted_list = bubblesort(list);
	int mode = 0;
	int count = 0;
	for (int i = 0; i < sorted_list.size() - 1, i++)
	{
		if (sorted_list.at(i) == sorted_list.at(i + 1))
		{
			count += 1;
		}
		else
		{
		}
	}
	return mode;
}
int main()
{
	vector<double> list1 = listbuilder(1000, 1, "random");
	listprinter(list1);
	cout << "enter for stats ";
	cin.get();
	cout << "\nsorted \n";
	listprinter(bubblesort(list1));
	cout << "\nmean: " << mean(list1) << "\nmedian: " << ' ' << median(list1) << "\n";
	return 0;
}