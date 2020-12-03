// Product.h
#pragma once

#ifndef STRING
#include <string>
#define STRING
#endif

//Price Cost Profit Quantity
//add ms to insant variable
namespace BusinessLayer {
	class Product {
	private:
		std::string mProductName, mManufacturer, mDescription;
		double mprice, mcost;

		int mQuantityInStock, mProductID,mQuantityOrdered;


	public:
		Product();
		Product(std::string productName, int ProductID, double Price, double Cost,
			int Quantity,std::string Manufacturer,std::string desription);
		Product(std::string productName, int ProductID, double Price, double Cost,
			int Quantity, std::string Manufacturer,int QuantityOrdered, std::string desription);

		
		double getPrice() const;
		double getCost() const;
		double getProfit() const;
		int getQuantity() const;
		int getQuantityOrdered() const;
		int getProductID() const;
		std::string getName() const;
		std::string getManufacturer() const;
		std::string getDescription() const;
		void setPrice(double p);
		void setCost(double c);
		void setQuantity(int q);
		void setQuantityOrdered(int q);
		void setProductID(int id);
		void setDescription(std::string s);
		void setproductName(std::string n);

	
	};
}

/** 

invoice(product, taxes)
salesperson(sales, salePrices)
sales=0
salesprices
invoice(<Products>,taxes,delivery fee)
total 

Product(cost, price, quantity, QO)
customer pays qo*price
qo(price-cost)
quantity=quantity-qo
qo=0
product->Price
**/
/** 
* Storemanager(password,ListW<warehouse>, List<saleperson>)
* manager()
* totalprofit+= line 45
* Warehouse w1(292902.,209102_)
* Select Warehouse
* Warehouse 1 ,w 2, 3
* manager->getListW
* Vector<WArehouse>
* ListW.append(w1)
* 
*select warehouse
* 
* inventory<product>
* product(3293993)
* 
* MAKE NEW PRODUCT: 
* name 
* price
* yadadada
* Product p(name,price,yadada)
* 
*
**/

