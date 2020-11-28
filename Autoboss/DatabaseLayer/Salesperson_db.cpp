// Salesperson_db.cpp
#ifndef SALESPERSON_DB_H
#include "Salesperson_db.h"
#endif

using namespace DatabaseLayer;

Salesperson_db::Salesperson_db()
{}

std::vector<Salesperson> Salesperson_db::getSalespeople() {
	std::vector<std::vector<std::string>> temp = helper.sqlexec("SELECT * FROM OpenInvoices");
	std::vector<std::vector<std::string>>::iterator itr;
	std::vector<Salesperson> empList;

	//*itr = EmployeeID, commission rate, name, total commission, total sales amount
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		//empList.push_back(<InsertSalesmanConstructorHere>);
	}
	employees = empList;
	return empList;
}

void Salesperson_db::addSalesperson(Salesperson emp)	{
	//Pseudogang
	//helper.sqlexec("INSERT INTO SalesPeople(employeeID, commissionRate, [name], totalCommission, totalSalesAmount) VALUES(" + std::to_string(emp.getID) + ", " + std::to_string(emp.getComm) + ", '" + emp.getName() + "', " + std::to_string(getTotalComm) + ", " + std::to_string(getTotalSales) + ");"););

	/*--INSERT INTO SalesPeople(employeeID, commissionRate, [name], totalCommission, totalSalesAmount)
		--VALUES(0, 0, '0', 0, 0);*/
}

void Salesperson_db::setCommissionRate(Salesperson emp, double newRate)	{
	//pseu pseu pseudo cooooode
	//helper.sqlexec("UPDATE SalesPeople SET commissionRate = " + std::to_string(newRate) + " WHERE employeeID = " + emp.getID + ");");
}
