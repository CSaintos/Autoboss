// Salesperson.h
#pragma once
<<<<<<< HEAD
#include "Invoice.h"
#include <vector>
#include <string>
=======

#ifndef SALESPERSON_H
>>>>>>> 714b4217127f2291be36e237c94dd596c01b2ab6
namespace BusinessLayer {
	class Salesperson {
	private:
		std::vector<Invoice> mSoldList;
		int mEmployeeID;
		float mCommissionRate;
		std::string mEmployeeName;
		double mTotalCommission, mTotalSalesAmount;
	public:
		Salesperson();
		Salesperson(std::vector<Invoice> soldList, int employeeID, float commissionRate, std::string employeeName,
			double totalCommisionAmount, double totalSalesAmount);
		std::vector<Invoice> const getSoldList() const;
		int getEmployeeID();
		float getCommisionRate();
		std::string getEmployeeName();
		double getTotalCommission();
		double getTotalSalesAmount();
		void setCommisionRate(float c);
		void setTotalCommission(double d);
		void setTotalSalesAmount(double d);
		void addCommision(double amount);
		void addSales(double sale);
		void addInvoices(std::vector<Invoice>& v, Invoice& i);
	};
}
#define SALESPERSON_H
#endif