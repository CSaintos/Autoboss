// Invoice.h
#pragma once
#include "Product.h"
#include <vector>
#include <string>

#ifndef INVOICE_H
namespace BusinessLayer {
	class Invoice {
	private:
		std::vector<Product> mProductsOrdered;
		int mInvoiceNumber, mPONumber, mInterestApplied;
		float mInterestRate, mDiscountRate;
		double mTotalAmount, mDeliveryCharge, mCurrentAmount, mAmountPaid;
		bool mDiscountApplied, mIsPaid;
		std::string mBillTo, mShipTo, mCloseDate, mOrderDate;
	public:
		Invoice();
		Invoice(std::vector<Product> productsOrdered, int invoiceNum, int poNum, float interestRate, 
			double totalAmount, double deliveryCharge, bool discountApplied, std::string billTo, std::string ShipTo,
			std::string orderDate,double mAmountPaid, std::string closeDate);
		
		
		std::vector<Product> const &getProductsOrdered() const;
		int getPONumber() const;
		int getInvoiceNumber() const;
		float getInterestRate() const;
		float getDiscountRate() const;
		double getTotalAmount() const;
		double getDeliveryCharge() const;
		int getInterestApplied() const;
		bool getDiscountApplied() const;
		bool getIsPaid() const;
		double getCurrentAmount() const;
		std::string getBillTo() const;
		std::string getShipTo() const;
		double getAmountPaid() const;
		std::string getOrderDate() const;
		std::string getCloseDate() const;
		void setCloseDate(std::string cd);
		void setCurrentAmount(double d);
		void setDiscountApplied(bool tf);
		void setIsPaid(bool tf);
		void setInterestApplied(bool tf);
		void setTotalAmount(double d);
		void Payment(double paid);
		void applyRate(float rate, int type);
	};
}
#define INVOICE_H
#endif
