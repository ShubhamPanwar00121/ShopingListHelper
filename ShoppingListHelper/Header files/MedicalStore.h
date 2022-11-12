#pragma once
#include "Shop.h"
#include "Commodity.h"
class MedicalStore : public Shop
{
public:
	MedicalStore(std::string, std::string, int, int, Commodity, Commodity, Commodity);
	MedicalStore();
	~MedicalStore();
	Commodity BuyFromMedicalStore(int, float=0.0f);
	Commodity BuyFromMedicalStore(std::string, float=0.0f);
	int getStaffRating();
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
	int staffRating{ 0 };
};

