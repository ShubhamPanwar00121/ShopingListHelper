#pragma once
#include "Shop.h"
#include "Commodity.h"
class MedicalStore : public Shop
{
public:
	MedicalStore(std::string, std::string, int, int, Commodity, Commodity, Commodity);
	MedicalStore();
	~MedicalStore();
	Commodity BuyFromMedicalStore(int);
	int getStaffRating();
	enum CommodityTypeEnum
	{
		PERASITAMOL,
		COMBIFLAME,
		NOFLUE
	};
private:
	Commodity perasitamol;
	Commodity combiflame;
	Commodity noflue;
	int staffRating{ 0 };
};

