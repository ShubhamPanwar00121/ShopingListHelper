#pragma once
#include "Shop.h"
#include "Commodity.h"
class GroceryStore : public Shop
{
public:
	GroceryStore(std::string, std::string, int, int, Commodity, Commodity, Commodity);
	GroceryStore();
	~GroceryStore();
	Commodity BuyFromGroceryStore(int);
	int GetNumberOfOutlets();
	enum CommodityTypeEnum
	{
		COM1,
		COM2,
		COM3
	};

private:
	Commodity com1;
	Commodity com2;
	Commodity com3;
	int outletsCount{ 0 };
};

