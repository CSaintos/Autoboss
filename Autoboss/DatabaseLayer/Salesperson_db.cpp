// Salesperson_db.cpp
#ifndef SALESPERSON_DB_H
#include "Salesperson_db.h"
#endif

using namespace DatabaseLayer;
using namespace BusinessLayer;

Salesperson_db::Salesperson_db()
{}

std::vector<Salesperson> Salesperson_db::getSalespeople() {
	std::vector<std::vector<std::string>> temp = helper.sqlexec("SELECT * FROM dbo.SalesPeople");
	std::vector<std::vector<std::string>>::iterator itr;
	std::vector<Salesperson> empList;

	//*itr = EmployeeID, commission rate, name, total commission, total sales amount
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		empList.push_back(Salesperson(std::vector<Invoice>(),
			std::stoi(contents[0]), 
			std::stod(contents[1]), 
			contents[2], 
			std::stod(contents[3]), 
			std::stod(contents[4])));
	}

	return empList;
}

void Salesperson_db::addSalesperson(Salesperson emp)	{
	//Pseudogang
	std::ostringstream query;
	query << "INSERT INTO SalesPeople(employeeID, commissionRate, [name], totalCommission, totalSalesAmount) ";
	query << "VALUES(";
	query << std::to_string(emp.getEmployeeID()) + ", ";
	query << std::to_string(emp.getCommisionRate()) + ", '";
	query << emp.getEmployeeName() + "', ";
	query << std::to_string(emp.getTotalCommission()) + ", ";
	query << std::to_string(emp.getTotalSalesAmount()) + ")";
	helper.sqlexec(query.str());

	/*--INSERT INTO SalesPeople(employeeID, commissionRate, [name], totalCommission, totalSalesAmount)
		--VALUES(0, 0, '0', 0, 0);*/
}

void Salesperson_db::setCommissionRate(Salesperson emp, double newRate)	{
	//pseu pseu pseudo cooooode
	std::ostringstream query;
	query << "UPDATE SalesPeople SET commissionRate = ";
	query << std::to_string(newRate);
	query << " WHERE employeeID = ";
	query << std::to_string(emp.getEmployeeID()) + ")";
	helper.sqlexec(query.str());
}

void Salesperson_db::test()	{

}