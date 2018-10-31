#ifndef DRVCALC_H
#define DRVCALC_H

#include <vector>
#include <string>
#include <cmath>
#include <thread>
using namespace std;

class DRVCalc
	{
	vector<pair<double,double>> * _distributionRange;

public:
	DRVCalc();
	~DRVCalc();

	void setDistributionRange(const vector<pair<double, double>> & distribRange);

	double getMathExpectation() const;
	double getMathExpectation(uint16_t exp) const;

	double getDispersion() const;

	double getRmsDeviation() const;

	double getInitialMoment(uint16_t order) const;

	double getMiddleMomentThirdOrder() const;
	double getMiddleMomentFourthOrder() const;

	vector<pair<double, double>> & getCurrentDistribRange() const;
	};

#endif //DRVCALC_H