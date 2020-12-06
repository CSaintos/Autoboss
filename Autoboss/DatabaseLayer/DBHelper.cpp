// DBHelper.cpp
#ifndef DBHELPER_H
#include "DBHelper.h"
#endif

using namespace DatabaseLayer;
using namespace std; // place holder

DBHelper::DBHelper() : rc(0), env(0), dbc(0), stmt(0), cbData(0), szData("0")
{}

DBHelper* DBHelper::dbHelper = nullptr;

DBHelper* DBHelper::GetInstance() {
	if (dbHelper == nullptr) {
		dbHelper = new DBHelper();
	}
	return dbHelper;
}

void DBHelper::openDB() {
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
	SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
	rc = SQLDriverConnect(dbc, NULL,
		(SQLWCHAR*)L"DRIVER={ODBC Driver 17 for SQL Server};SERVER=(localdb)\\MSSQLLocalDB;DATABASE=AutobossDB;Trusted=true;", 
		SQL_NTS, NULL, 1024, NULL, SQL_DRIVER_NOPROMPT);
	// Deallocate handles
	if (!SQL_SUCCEEDED(rc)) {
		cout << "Failed to connect to database" << endl;
		SQLFreeHandle(SQL_HANDLE_DBC, &dbc);
		SQLFreeHandle(SQL_HANDLE_ENV, &env);
	}
	else {
		//cout << "Database Connection Success" << endl;
		rc = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
		if (!SQL_SUCCEEDED(rc)) {
			cout << "Failed to allocate stmt handle" << endl;
		}
	}
}

void DBHelper::closeDB() {
	SQLFreeHandle(SQL_HANDLE_STMT, stmt);
	SQLDisconnect(dbc);
	SQLFreeHandle(SQL_HANDLE_DBC, dbc);
	SQLFreeHandle(SQL_HANDLE_ENV, env);
	delete(dbHelper);
}

vector<vector<string>> DBHelper::sqlexec(string sqlstr) {
	wstring str2(sqlstr.length(), L' ');
	copy(sqlstr.begin(), sqlstr.end(), str2.begin());
	vector<vector<string>> vectorString;

	rc = SQLFreeHandle(SQL_HANDLE_STMT, stmt);
	rc = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

	rc = SQLExecDirect(stmt, const_cast<SQLWCHAR*>(str2.c_str()), SQL_NTS);
	if (rc == SQL_NO_DATA_FOUND) {
		cout << "No data was found" << endl;
	}
	if (!SQLSUCCESS(rc)) {
		error_out(stmt, SQL_HANDLE_STMT);
	}
	else {
		for (rc = SQLFetch(stmt); rc == SQL_SUCCESS; rc = SQLFetch(stmt)) {
			int i = 1;
			vector<string> vectorSubString;

			for (int i = 1; rc == SQL_SUCCESS && rc != SQL_NO_DATA; ++i) {
				rc = SQLGetData(stmt, i, SQL_C_CHAR, szData, sizeof(szData), &cbData);
				string str(reinterpret_cast<char*>(szData));
				vectorSubString.push_back(str);
				//cout << str << " "; // place holder
			}
			vectorSubString.pop_back();
			vectorString.push_back(vectorSubString);
			//cout << endl; // place holder
		}
	}

	return vectorString;
}

void DBHelper::error_out(SQLHANDLE handle, SQLINTEGER handleType) {
	SQLINTEGER i = 0;
	SQLINTEGER native;
	SQLWCHAR state[7];
	SQLWCHAR text[256];
	SQLSMALLINT len;

	cout << "SQL query failure" << endl;
	do {
		rc = SQLGetDiagRec(handleType, handle, ++i, state, &native, text, sizeof(text)/2, &len);

		if (SQL_SUCCEEDED(rc)) {
			wcout << state << ":" << i << ":" << native << ":" << text << endl;
		}
	} while (rc == SQL_SUCCESS);
}

void DBHelper::test() {
	dbHelper = GetInstance();
}

void DBHelper::checkAndUpdateEssentials() {
	dbHelper = GetInstance();

	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;

	query << "SELECT * FROM dbo.Credentials";
	temp = dbHelper->sqlexec(query.str());
	query.str("");
	query.clear();
	if (temp.size() == 0) {
		query << "INSERT INTO dbo.Credentials ";
		query << "([Id], [Password]) ";
		query << "VALUES ";
		query << "(1, '0')";
		dbHelper->sqlexec(query.str());
		query.str("");
		query.clear();
	}

	query << "SELECT * FROM dbo.CurrentDate";
	temp = dbHelper->sqlexec(query.str());
	query.str("");
	query.clear();
	if (temp.size() == 0) {
		query << "INSERT INTO dbo.CurrentDate ";
		query << "([Id], [Date]) ";
		query << "VALUES ";
		query << "(1, '2000-01-01')";
		dbHelper->sqlexec(query.str());
		query.str("");
		query.clear();
	}

	query << "SELECT * FROM dbo.BusinessStats";
	temp = dbHelper->sqlexec(query.str());
	query.str("");
	query.clear();
	if (temp.size() == 0) {
		query << "INSERT INTO dbo.BusinessStats ";
		query << "([Id], [Amount]) ";
		query << "VALUES ";
		query << "(1, 0.0)";
		dbHelper->sqlexec(query.str());
		query.str("");
		query.clear();
	}
}

void DBHelper::setCurrentDate(std::string date) {
	dbHelper = GetInstance();
	std::ostringstream query;
	query << "UPDATE dbo.CurrentDate ";
	query << "SET [Date] = " << "'" + date + "'" << " ";
	query << "WHERE [Id] = 1";
	dbHelper->sqlexec(query.str());
}

std::string DBHelper::getCurrentDate() {
	dbHelper = GetInstance();
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;

	query << "SELECT [Date] ";
	query << "FROM dbo.CurrentDate ";
	query << "WHERE [Id] = 1";

	temp = dbHelper->sqlexec(query.str());

	return temp[0][0];
}

std::string DBHelper::getPassword() {
	dbHelper = GetInstance();
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;

	query << "SELECT [Password] ";
	query << "FROM dbo.Credentials ";
	query << "WHERE [Id] = 1";

	temp = dbHelper->sqlexec(query.str());

	return temp[0][0];
}

void DBHelper::setPassword(std::string password) {
	dbHelper = GetInstance();
	std::ostringstream query;
	query << "UPDATE dbo.Credentials ";
	query << "SET [Password] = " << "'" + password + "'" << " ";
	query << "WHERE [Id] = 1";
	dbHelper->sqlexec(query.str());
}

void DBHelper::reset() {
	dbHelper = GetInstance();
	std::ostringstream query, query2, query3, query4, query5, query6,
		query7, query8, query9, query10, query11, query12;

	query12 << "DELETE FROM dbo.BusinessStats";
	query5 << "DELETE FROM dbo.ClosedInvoices";
	query11 << "DELETE FROM dbo.Credentials";
	query10 << "DELETE FROM dbo.CurrentDate";
	query2 << "DELETE FROM dbo.Customers";
	query6 << "DELETE FROM dbo.Invoices";
	query4 << "DELETE FROM dbo.OpenInvoices";
	query << "DELETE FROM dbo.OrderDetails";
	query7 << "DELETE FROM dbo.ProductDetails";
	query3 << "DELETE FROM dbo.Products";
	query9 << "DELETE FROM dbo.SalesPeople";
	query8 << "DELETE FROM dbo.Warehouses";

	dbHelper->sqlexec(query.str());
	dbHelper->sqlexec(query2.str());
	dbHelper->sqlexec(query3.str());
	dbHelper->sqlexec(query4.str());
	dbHelper->sqlexec(query5.str());
	dbHelper->sqlexec(query6.str());
	dbHelper->sqlexec(query7.str());
	dbHelper->sqlexec(query8.str());
	dbHelper->sqlexec(query9.str());
	dbHelper->sqlexec(query10.str());
	dbHelper->sqlexec(query11.str());
	dbHelper->sqlexec(query12.str());
}