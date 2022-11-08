#pragma once
#include "Shop.h"
#include "Commodity.h"

class Dairy:public Shop
{
public:
	Dairy(std::string, std::string, int, int,Commodity,Commodity,Commodity);
	Dairy();
	~Dairy();
	Commodity BuyFromDairy(int);
	int GetNumberOfCowsOwned();
	enum CommodityTypeEnum
	{
		MILK,
		CURD,
		CHEESE
	};

private:
	Commodity milk;
	Commodity curd;
	Commodity cheese;
	int cowsOwned{ 0 };
};