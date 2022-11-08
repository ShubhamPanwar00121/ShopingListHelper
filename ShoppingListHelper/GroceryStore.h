#pragma once
#include "Shop.h"
#include "Commodity.h"
class GroceryStore : public Shop
{
public:
	GroceryStore(std::string, std::string, int, int, Commodity, Commodity, Commodity);
	GroceryStore();
	~GroceryStore();
	Commodity BuyFromGroceryStoreint);
	int GetNumberOfOutlets();
	Commodity BuyFromGroceryStore(int);
	enum CommodityTypeEnum
	{
		RICE,
		COLA,
		SOAP
	};

private:
	Commodity rice;
	Commodity cola;
	Commodity soap;
	int outletsCount{ 0 };
};

