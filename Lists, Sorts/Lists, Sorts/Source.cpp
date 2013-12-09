#include <iostream>
#include <iomanip>
#include <vector>
#include "tools.h"
using namespace std;

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