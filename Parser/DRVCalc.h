#ifndef DRVCALC_H
#define DRVCALC_H

#include <vector>
#include <string>

using namespace std;

class DRVCalc
	{
	vector<pair<double,double>> * _distributionRange;

public:
	DRVCalc();
	~DRVCalc();

	void setDistributionRange(const vector<pair<double, double>> & distribRange);


	};

#endif //DRVCALC_H