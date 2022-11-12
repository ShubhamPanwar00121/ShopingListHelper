#pragma once
#include "Commodity.h"
class PurchasedCommodity : public Commodity
{
public:
	PurchasedCommodity();
	PurchasedCommodity(std::string, float, float, float);
	~PurchasedCommodity();
	float GetPurchasedAmmount();
	void SetPurchasedAmount(float);

private:
	float PurchasedAmount{0};
};

