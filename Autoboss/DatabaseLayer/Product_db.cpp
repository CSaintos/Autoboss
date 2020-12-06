// Product_db.cpp
#ifndef PRODUCT_DB_H
#include "Product_db.h"
#endif

using namespace DatabaseLayer;

//Product(string productName, int ProductID, double Price, double Cost, int Quantity, string Manufacturer)

Product_db::Product_db() : dbHelper(DBHelper::GetInstance())
{}

std::vector<BusinessLayer::Product> Product_db::getProducts() {
	std::vector<std::vector<std::string>> temp;
	std::vector<BusinessLayer::Product> products;
	std::ostringstream query;

	query << "SELECT [productID], [productName], [MSRP], [cost] ";
	query << "FROM dbo.ProductDetails";

	temp = dbHelper->sqlexec(query.str());

	for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
		auto contents = *itr;
		products.push_back(
			BusinessLayer::Product(
				contents[1],
				std::stoi(contents[0]),
				std::stod(contents[2]),
				std::stod(contents[3]),
				0,
				"",
				""
			)
		);
	}

	return products;
}

BusinessLayer::Product Product_db::getProductDetails(BusinessLayer::Product product) {
	if (product.getProductID() != 0) {
		std::vector<std::vector<std::string>> temp;
		std::ostringstream query;
		BusinessLayer::Product updatedProduct;

		query << "SELECT * ";
		query << "FROM dbo.ProductDetails ";
		query << "WHERE [productID] = " + std::to_string(product.getProductID());

		temp = dbHelper->sqlexec(query.str());

		updatedProduct = BusinessLayer::Product(
			temp[0][1],
			std::stoi(temp[0][0]),
			std::stod(temp[0][4]),
			std::stod(temp[0][5]),
			0,
			temp[0][2],
			temp[0][3]
		);

		return updatedProduct;
	}
	else {
		return BusinessLayer::Product();
	}
}

std::vector<BusinessLayer::Product> Product_db::getLowStock() {
	std::vector<BusinessLayer::Product> lowStock;
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;

	query << "SELECT p.productID, pd.productName, SUM(p.quantityInStock) ";
	query << "FROM dbo.Products p ";
	query << "JOIN dbo.ProductDetails pd ";
	query << "ON p.productID = pd.productID ";
	query << "GROUP BY p.productID, pd.productName ";
	query << "HAVING SUM(p.quantityInStock) < 5 "; // FIXME
	query << "ORDER BY SUM(p.quantityInStock) DESC";

	temp = dbHelper->sqlexec(query.str());

	for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
		auto contents = *itr;
		lowStock.push_back(
			BusinessLayer::Product(
				contents[1],
				std::stoi(contents[0]),
				0.0,
				0.0,
				std::stoi(contents[2]),
				"",
				""
			)
		);
	}

	return lowStock;
}

void Product_db::createProduct(BusinessLayer::Product product) {
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;
	std::ostringstream query2;
	int maxID;

	query2 << "SELECT [productID] ";
	query2 << "FROM dbo.ProductDetails";

	temp = dbHelper->sqlexec(query2.str());

	if (temp.size() == 0) {
		maxID = 0;
	} else {
		query2.str("");
		query2.clear();
		query2 << "SELECT MAX([productID]) ";
		query2 << "FROM dbo.ProductDetails";

		temp = dbHelper->sqlexec(query2.str());

		maxID = std::stoi(temp[0][0]);
	}

	query << "INSERT INTO dbo.ProductDetails (";
	query << "[productID], [productName], [manufacturer], ";
	query << "[description], [MSRP], [cost]) ";
	query << "VALUES (";
	query << std::to_string(maxID + 1) + ", '";
	query << product.getName() + "', '";
	query << product.getManufacturer() + "', '";
	query << product.getDescription() + "', ";
	query << std::to_string(product.getPrice()) + ", ";
	query << std::to_string(product.getCost()) + ")";

	dbHelper->sqlexec(query.str());
}

void Product_db::updateProduct(BusinessLayer::Product product) {
	if (product.getProductID() != 0) {
		std::ostringstream query;

		query << "UPDATE dbo.ProductDetails ";
		query << "SET [productName] = '" + product.getName() + "', ";
		query << "[MSRP] = " + std::to_string(product.getPrice()) + ", ";
		query << "[cost] = " + std::to_string(product.getCost()) + " ";
		query << "WHERE [productID] = " + std::to_string(product.getProductID());

		dbHelper->sqlexec(query.str());
	}
}

void Product_db::test()	{}