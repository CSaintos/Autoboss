// Salesperson_db.cpp
#ifndef SALESPERSON_DB_H
#include "Salesperson_db.h"
#endif

using namespace DatabaseLayer;
using namespace BusinessLayer;

Salesperson_db::Salesperson_db() : dbHelper(DBHelper::GetInstance())
{}

std::vector<BusinessLayer::Salesperson> Salesperson_db::getSalespeople() {
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM dbo.SalesPeople");
	std::vector<Salesperson> salespeople;

	for (auto itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		auto contents = *itr1;
		salespeople.push_back(
			Salesperson(
				std::vector<BusinessLayer::Invoice>(), // sold list
				std::stoi(contents[0]), // employee ID
				std::stof(contents[1]), // commission rate
				contents[2], // employee name
				std::stod(contents[3]), // total commission
				std::stod(contents[4]) // total sales
			)
		);
	}

	return salespeople;
}

void Salesperson_db::setCommissionRate(BusinessLayer::Salesperson salesperson) {
	if (salesperson.getEmployeeID() != 0) {
		std::ostringstream query;

		query << "UPDATE SalesPeople ";
		query << "SET commissionRate = ";
		query << std::to_string(salesperson.getCommisionRate()) + " ";
		query << "WHERE employeeID = ";
		query << std::to_string(salesperson.getEmployeeID());

		dbHelper->sqlexec(query.str());
	}
}

void Salesperson_db::addSalesperson(BusinessLayer::Salesperson salesperson) {
	dbHelper = DBHelper::GetInstance();
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;
	std::ostringstream query2;
	int maxID;

	query2 << "SELECT [employeeID] ";
	query2 << "FROM dbo.SalesPeople";

	temp = dbHelper->sqlexec(query2.str());

	if (temp.size() == 0) {
		maxID = 0;
	} else {
		query2.str("");
		query2.clear();
		query2 << "SELECT MAX([employeeID]) ";
		query2 << "FROM dbo.SalesPeople";

		temp = dbHelper->sqlexec(query2.str());

		maxID = std::stoi(temp[0][0]);
	}

	query << "INSERT INTO SalesPeople ";
	query << "([employeeID], [commissionRate], [name], [totalCommission], [totalSalesAmount]) ";
	query << "VALUES(";
	query << std::to_string(maxID + 1) + ", ";
	query << std::to_string(salesperson.getCommisionRate()) + ", '";
	query << salesperson.getEmployeeName() + "', ";
	query << "0.0, ";
	query << "0.0)";

	dbHelper->sqlexec(query.str());
}

void Salesperson_db::test()	{}