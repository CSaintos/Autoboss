CREATE TABLE [dbo].[Customers]
(
	[customerID] INT NOT NULL,
	[customerName] VARCHAR(50) NOT NULL,
	[taxRate] FLOAT NOT NULL,
	[suspended] BIT NOT NULL,
	[salesRep] INT NOT NULL,

	CONSTRAINT Customers_pk PRIMARY KEY (customerID),
	CONSTRAINT SalesPeople_Customers_fk FOREIGN KEY (salesRep)
		REFERENCES SalesPeople(employeeID)
)
