#pragma once

#include <string>
//Price Cost Profit Quantity
//add ms to insant variable
namespace BusinessLayer {
	class Product {
	private:
		std::string mProductName, mManufacturer, mDescription;
		double mprice, mcost;
		int mQuantityInStock, mProductID;

	public:
		Product(std::string productName, int ProductID, double Price, double Cost,
			int Quantity, std::string Manufacturer);
		
		double getPrice() const;
		double getCost() const;
		double getProfit() const;
		int getQuantity() const;
		int getProductID() const;
		std::string getName() const;
		std::string getManufacturer() const;
		std::string getDescription() const;
		void setPrice(double p);
		void setCost(double c);
		void setQuantity(int q);
		void setProductID(int id);
		void setDescription(std::string s);
		void setproductName(std::string n);


	};
}
