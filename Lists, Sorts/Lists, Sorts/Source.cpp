#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
//for convenience
typedef vector<double>::size_type vec_size;
typedef vector<double>::const_iterator iterator_elem;
typedef vector<vector<double>> vec_of_vecs;
//list tools
vector<double> vector_pass_by_reference(vector<double> list)
{
	vector<double>* listptr = &list;
	vector<double> returnlist = *listptr;
	return returnlist;
}
void listprinter(vector<double> list, char separator = ' ')
{
for (iterator_elem i = list.begin(); i != list.end(); i++)
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
vec_of_vecs vector_of_vectors(int num_of_vecs, int length_of_vecs, string list_type = "random")
{
	vec_of_vecs return_vec;
	for (int i=0; i < num_of_vecs; i++)
	{
		return_vec.push_back(listbuilder(length_of_vecs, 0, list_type));
	}
	return return_vec;
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
	vec_size unsortedlistlength = sortinglist.size();
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
	vector<double> sort_list = list;
	vec_size list_size = sort_list.size();
	sort(sort_list.begin(), sort_list.end());
	vec_size midindex = list_size / 2;
	double median = list_size % 2 == 0 ? (sort_list[midindex] + sort_list[midindex + 1]) / 2 : sort_list[midindex];
	return median;
}
int main()
{
	int num, length;
	cout << "Number of random vectors?: ";
	cin >> num;
	cout << "length of random vectors?: ";
	cin >> length;
	vec_of_vecs vecs = vector_of_vectors(num, length);
	vector<double> medians;
	vector<double> means;
	for (vec_size i = 0; i < vecs.size()-1; i++)
	{
		medians.push_back(median(vecs[i]));
		means.push_back(mean(vecs[i]));
	}
	streamsize prec = cout.precision(3);
	cout << setprecision(3) << endl << "STATS" << endl << "Mean of means: " << mean(means) << endl << "Mean of medians: " << mean(medians) << endl << setprecision(prec);
	return 0;
}