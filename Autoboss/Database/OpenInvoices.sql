CREATE TABLE [dbo].[OpenInvoices]
(
	[PONumber] INT NOT NULL,
	[billTo] VARCHAR(50) NULL,
	[shipTo] VARCHAR(50) NULL,
	[amountPaid] DECIMAL(18,2) NOT NULL,

	CONSTRAINT OpenInvoices_pk PRIMARY KEY (PONumber),
	CONSTRAINT Invoices_OpenInvoices_fk FOREIGN KEY (PONumber)
		REFERENCES Invoices(PONumber)
)
