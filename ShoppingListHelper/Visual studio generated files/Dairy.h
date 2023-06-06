#pragma once
#include "Shop.h"
#include "Commodity.h"

class Dairy:public Shop
{
public:
	Dairy(std::string, std::string, int, int,Commodity,Commodity,Commodity);
	Dairy();
	~Dairy();
	Commodity BuyFromDairy(int, float=0.0f);
	Commodity BuyFromDairy(std::string, float=0.0f);
	int GetNumberOfCowsOwned();
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
	int cowsOwned{ 0 };
};