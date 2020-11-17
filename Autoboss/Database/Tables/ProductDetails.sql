CREATE TABLE [dbo].[ProductDetails]
(
	[productID] INT NOT NULL,
	[productName] VARCHAR(50) NOT NULL,
	[manufacturer] VARCHAR(50) NOT NULL,
	[description] VARCHAR(50) NULL,
	[MSRP] DECIMAL(18,2) NOT NULL,
	[costPrice] DECIMAL(18,2) NOT NULL,

	CONSTRAINT ProductDetails_pk PRIMARY KEY (productID)
)
