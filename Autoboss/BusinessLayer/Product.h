#pragma once
#include <string>
//Price Cost Profit Quantity
//add ms to insant variable
namespace BusinessLayer {
	class Product {
	private:
		std::string name;
		double price, cost, profit;
		int quantity;

	public:
		Product(double Price, double Cost, double Profit, std::string Name, int Quantity);
		void setPrice(double p);
		double getPrice() const;

	};
}
