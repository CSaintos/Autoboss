CREATE TABLE [dbo].[Warehouses]
(
	[warehouseID] INT NOT NULL,
	[address] VARCHAR(50) NOT NULL,
	[email] VARCHAR(50) NULL,
	[phoneNumber] VARCHAR(50) NULL

	CONSTRAINT Warehouses_pk PRIMARY KEY (warehouseID)
)
