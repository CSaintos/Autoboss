#pragma once
#include <string>
//Price Cost Profit Quantity
//add ms to insant variable
namespace BusinessLayer {
	class Product {
	private:
		std::string mProductName, mManufacturer, mDescription;
		double mprice, mcost;
		int mquantityInStock, mproductID;

	public:
		Product(std::string productName, int ProductID, double Price, double Cost,
			double Profit,  int Quantity,std::string Manufacturer);
		void setPrice(double p);
		double getPrice() const;
		double getCost() const;
		double getProfit() const;
		void setDescription(std::string s);


	};
}
