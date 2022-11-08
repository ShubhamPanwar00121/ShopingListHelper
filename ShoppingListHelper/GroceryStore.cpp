#include "GroceryStore.h"

GroceryStore::GroceryStore(std::string shopName, std::string address, int shopRating, int numberOfOutlets, Commodity com1, Commodity com2, Commodity com3)
	:Shop("Dairy", shopName, address, shopRating), outletsCount{ numberOfOutlets }
{
	this->com1 = com1;
	this->com2 = com2;
	this->com3 = com3;
}

GroceryStore::GroceryStore()
{
}

GroceryStore::~GroceryStore()
{
}

int GroceryStore::GetNumberOfOutlets()
{
	return this->outletsCount;
}

Commodity GroceryStore::BuyFromGroceryStore(int CommodityType)
{
	switch (CommodityType)
	{
	case COM1:
	{
		return com1;
		break;
	}
	case COM2:
	{
		return com2;
		break;
	}
	case COM3:
	{
		return com3;
		break;
	}

	default:
		Commodity defaultCommodity = Commodity("null", 0.0f, 0.0f);
		return defaultCommodity;
		break;
	}
}
