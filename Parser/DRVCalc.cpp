#include "DRVCalc.h"



DRVCalc::DRVCalc()
	{
	_distributionRange = nullptr;
	}


DRVCalc::~DRVCalc()
	{
	if(_distributionRange != nullptr)
		{
		delete _distributionRange;
		_distributionRange = nullptr;
		}
	}


void DRVCalc::setDistributionRange(const vector<pair<double, double>> & distribRange)
	{
	_distributionRange = new vector<pair<double, double>>();
	_distributionRange->assign(distribRange.begin(),distribRange.end());
	}


double DRVCalc::getMathExpectation() const
	{
	return getMathExpectation(1);
	}


double DRVCalc::getMathExpectation(const uint16_t exp) const
	{
	double expectation = 0;
	for (auto & el : *_distributionRange)
		{
		expectation += (exp != 1? pow(el.first,exp) : el.first) * el.second;
		}
	return expectation;
	}


double DRVCalc::getDispersion() const
	{
	return getMathExpectation(2) - pow(getMathExpectation(), 2);
	}


double DRVCalc::getRmsDeviation() const
	{
	return sqrt(getDispersion());
	}


double DRVCalc::getInitialMoment(const uint16_t order) const
	{
	return getMathExpectation(order);
	}


double DRVCalc::getMiddleMomentThirdOrder() const
	{
	double v1, v2, v3;
	thread t1([this,&v1]{v1 = this->getMathExpectation(1);});
	thread t2([this,&v2]{v2 = this->getMathExpectation(2);});
	thread t3([this,&v3]{v3 = this->getMathExpectation(3);});
	t1.join();
	t2.join();
	t3.join();

	return v3 - 3 * v1 * v2 + 2 * pow(v1, 3);
	}


double DRVCalc::getMiddleMomentFourthOrder() const
	{
	double v1, v2, v3, v4;
	thread t1([this, &v1] {v1 = this->getMathExpectation(1); });
	thread t2([this, &v2] {v2 = this->getMathExpectation(2); });
	thread t3([this, &v3] {v3 = this->getMathExpectation(3); });
	thread t4([this, &v4] {v4 = this->getMathExpectation(4); });
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return v4 - 4 * v1 * v3 + 6 * v1 * v1 * v2 - 3 * pow(v1, 4);
	}


vector<pair<double, double>> & DRVCalc::getCurrentDistribRange() const
	{
	return *_distributionRange;
	}
