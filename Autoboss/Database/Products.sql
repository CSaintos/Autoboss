CREATE TABLE [dbo].[Products]
(
	[warehouseID] INT NOT NULL,
	[productID] INT NOT NULL,
	[quantityInStock] INT NOT NULL,

	CONSTRAINT Products_pk PRIMARY KEY (warehouseID, productID),
	CONSTRAINT Warehouses_Products_fk FOREIGN KEY (warehouseID)
		REFERENCES Warehouses(warehouseID),
	CONSTRAINT ProductDetails_Products_fk FOREIGN KEY (productID)
		REFERENCES ProductDetails(productID)
)
