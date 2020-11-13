CREATE TABLE [dbo].[Customers]
(
	[customerID] INT NOT NULL,
	[customerName] VARCHAR(50) NOT NULL,
	[taxRate] FLOAT NOT NULL,
	[suspended] BIT NOT NULL,
	[salesRep] INT NOT NULL,

	CONSTRAINT customers_pk PRIMARY KEY (customerID),
)
