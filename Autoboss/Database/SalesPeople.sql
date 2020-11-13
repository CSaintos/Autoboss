CREATE TABLE [dbo].[SalesPeople]
(
	[employeeID] INT NOT NULL,
	[commissionRate] FLOAT NOT NULL,
	[name] VARCHAR(50) NOT NULL,
	[totalCommission] DECIMAL(18, 2) NOT NULL,
	[totalSalesAmount] DECIMAL(18, 2) NOT NULL,

	PRIMARY KEY (employeeID)
)
