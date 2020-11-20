#include "BIZHelper.h"
#include "Warehouse.h"
#include "Product.h"
#include <string>
#include <iostream>
using namespace std;
using namespace BusinessLayer;

int main() {
	vector<Product> i;
	Warehouse ware(i, 28);
	Product pro("christian is a capper", 29292, 3.4,1.2,5,"louis INC");
	ware.appendInventory(i, pro);
	for (vector<Product>::iterator itr2 = i.begin(); itr2 != i.end(); itr2++) {
		cout << itr2->getCost() << endl;
	}
}