// Salesperson.cpp
#ifndef SALESPERSON_H
#include "Salesperson.h"
#endif

using namespace BusinessLayer;
using namespace std;
Salesperson::Salesperson() : mSoldList(), mEmployeeID(),
mCommissionRate(), mEmployeeName(), mTotalCommission(),
mTotalSalesAmount() {}
Salesperson::Salesperson(vector<Invoice> soldList, int employeeID, float commissionRate, string employeeName,
	double totalCommisionAmount, double totalSalesAmount) : mSoldList(soldList), mEmployeeID(employeeID),
	mCommissionRate(commissionRate), mEmployeeName(employeeName), mTotalCommission(totalCommisionAmount),
	mTotalSalesAmount(totalSalesAmount) {}
vector<Invoice> const Salesperson::getSoldList() const {
	return mSoldList;
}
int Salesperson::getEmployeeID() {
	return mEmployeeID;
}
float Salesperson::getCommisionRate() {
	return mCommissionRate;
}
string Salesperson::getEmployeeName() {
	return mEmployeeName;
}
double Salesperson::getTotalCommission() {
	return mTotalCommission;
}

double BusinessLayer::Salesperson::getTotalSalesAmount()
{
	return mTotalSalesAmount;
}

void BusinessLayer::Salesperson::setCommisionRate(float c)
{
	mCommissionRate = c;
}

void BusinessLayer::Salesperson::setTotalCommission(double d)
{
	mTotalCommission = d;
}

void BusinessLayer::Salesperson::setTotalSalesAmount(double d)
{
	mTotalSalesAmount = d;
}

void BusinessLayer::Salesperson::addCommision(double amount)
{
	double newCom = getCommisionRate() * amount;
	setCommisionRate(newCom);
}

void BusinessLayer::Salesperson::addSales(double sale)
{
	double newTotal = sale + getTotalSalesAmount();
	setTotalSalesAmount(newTotal);
}

void BusinessLayer::Salesperson::addInvoices(std::vector<Invoice>& v, Invoice& i)
{
	v.push_back(i);
}
