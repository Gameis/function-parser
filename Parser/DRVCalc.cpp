#include "DRVCalc.h"



DRVCalc::DRVCalc()
	{
	}


DRVCalc::~DRVCalc()
	{
	}


void DRVCalc::setDistributionRange(const vector<pair<double, double>> & distribRange)
	{
	_distributionRange = new vector<pair<double, double>>();
	_distributionRange->assign(distribRange.begin(),distribRange.end());
	}
