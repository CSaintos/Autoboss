CREATE TABLE [dbo].[OrderDetails]
(
	[PONumber] INT NOT NULL,
	[productID] INT NOT NULL,
	[quantityOrdered] INT NOT NULL,

	CONSTRAINT OrderDetails_pk PRIMARY KEY (PONumber, productID),
	CONSTRAINT Invoices_OrderDetails_fk FOREIGN KEY (PONumber)
		REFERENCES Invoices(PONumber),
	CONSTRAINT ProductDetails_OrderDetails_fk FOREIGN KEY (productID)
		REFERENCES ProductDetails(productID)
)
