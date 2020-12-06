// Invoice.cpp
#ifndef INVOICE_H
#include "Invoice.h"
#endif

using namespace BusinessLayer;
using namespace std;

Invoice::Invoice() : mProductsOrdered(), mInvoiceNumber(), mPONumber(), mInterestRate(), mTotalAmount(), 

mDeliveryCharge(), mDiscountApplied(), mBillTo(), mShipTo(), mOrderDate(),mInterestApplied(),mDiscountRate(),
mCurrentAmount(), mAmountPaid(),mIsPaid(false),mCloseDate(),mSalesRepID(){}

Invoice::Invoice(vector<Product> productsOrdered, int invoiceNum, int poNum, float interestRate, float discountRate,
	double totalAmount, double deliveryCharge, bool discountApplied, string billTo, string ShipTo,
	string orderDate, double amountPaid, string closeDate, int Saleperson,int interestApplied) : 
	mCloseDate(closeDate), mCurrentAmount(totalAmount + deliveryCharge),
	mAmountPaid(amountPaid), mDiscountRate(discountRate), mInterestApplied(interestApplied), mIsPaid(false),
	mProductsOrdered(productsOrdered), mInvoiceNumber(invoiceNum), mPONumber(poNum),
	mInterestRate(interestRate), mTotalAmount(totalAmount), mDeliveryCharge(deliveryCharge), 
	mDiscountApplied(discountApplied), mBillTo(billTo), mShipTo(ShipTo), mOrderDate(orderDate), mSalesRepID(Saleperson)
	 {}

vector<Product> const &Invoice::getProductsOrdered() const{
	return mProductsOrdered;
}
int Invoice::getPONumber() const {
	return mPONumber;
}
int Invoice::getInvoiceNumber() const {
	return mInvoiceNumber;
}
int Invoice::getSalesRepID() const
{
	return mSalesRepID;
}
float Invoice::getInterestRate() const {
	return mInterestRate;
}
float Invoice::getDiscountRate() const {
	return mDiscountRate;
}
double Invoice::getTotalAmount() const {
	return mTotalAmount;
}
double Invoice::getDeliveryCharge() const {
	return mDeliveryCharge;
}
int Invoice::getInterestApplied() const {
	return mInterestApplied;
}
bool Invoice::getDiscountApplied() const {
	return mDiscountApplied;
}
double Invoice::getCurrentAmount() const {
	return mCurrentAmount;
}
bool Invoice::getIsPaid() const {
	return mIsPaid;
}
string Invoice::getBillTo() const {
	return mBillTo;
}
string Invoice::getShipTo() const {
	return mShipTo;
}
double Invoice::getAmountPaid() const {
	return mAmountPaid;
}
string Invoice::getOrderDate() const{
	return mOrderDate;
}
string Invoice::getCloseDate() const {
	return mCloseDate;
}
void Invoice::setCloseDate(string cd){
	mCloseDate.assign(cd,5);
	
}
void Invoice::setCurrentAmount(double d) {
	mCurrentAmount = d;
}

void Invoice::setAmountPaid(double d) {
	mAmountPaid = d;
}

void Invoice::setIsPaid(bool tf) {
	mIsPaid = tf;
}
void Invoice::setDiscountApplied(bool tf){
	mDiscountApplied = tf;
	}
void Invoice::setInterestApplied(bool tf) {
	mInterestApplied = tf;
}
void Invoice::setTotalAmount(double d) {
	mTotalAmount = d;
}
void Invoice::Payment(double paid) {
	mAmountPaid += paid;
	setCurrentAmount(getCurrentAmount() - getAmountPaid());
	if (getCurrentAmount() == 0){
		setIsPaid(true);
	}
}
void Invoice::applyRate(float rate, int type) {
	if (type == 1) {
		double temp = getCurrentAmount() * rate;
		setCurrentAmount(temp+getCurrentAmount());
	}
	else if(type == 0) {
		double temp = getCurrentAmount() * rate;
		setCurrentAmount(getCurrentAmount() - rate);
	}
}