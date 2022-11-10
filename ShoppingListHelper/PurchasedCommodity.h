#pragma once
#include "Commodity.h"
class PurchasedCommodity : Commodity
{
public:
	PurchasedCommodity();
	PurchasedCommodity(std::string, float, float, float);
	~PurchasedCommodity();
	float GetPurchasedAmmount();

private:
	float PurchasedAmount{0};
};

