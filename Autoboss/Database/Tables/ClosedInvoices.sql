CREATE TABLE [dbo].[ClosedInvoices]
(
	[PONumber] INT NOT NULL,
	[closeDate] DATE NOT NULL,

	CONSTRAINT ClosedInvoices_pk PRIMARY KEY (PONumber),
	CONSTRAINT Invoices_ClosedInvoices_fk FOREIGN KEY (PONumber)
		REFERENCES Invoices(PONumber)
)
