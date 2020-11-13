CREATE TABLE [dbo].[Invoices]
(
	[PONumber] INT NOT NULL,
	[invoiceNum] INT NOT NULL,
	[interestRate] FLOAT NOT NULL,
	[discountRate] FLOAT NOT NULL,
	[totalAmount] DECIMAL(18,2) NOT NULL,
	[orderDate] DATE NOT NULL,
	[deliveryCharge] DECIMAL(18,2) NOT NULL,
	[interestApplied] INT NOT NULL,
	[discountApplid] BIT NOT NULL,
	[salesRep] INT NOT NULL,

	CONSTRAINT Invoices_pk PRIMARY KEY (PONumber),
	CONSTRAINT SalesPeople_Invoices_fk FOREIGN KEY (salesRep)
		REFERENCES SalesPeople(employeeID)
)
