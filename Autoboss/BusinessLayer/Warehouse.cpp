#include "product.h"
#include <vector>
using namespace std;
vector<Product> inventory;
Product prod(2,43,4,"hello",3);
void appendInventory(vector<Product>& v, Product p) {
	v.push_back(p);
}




