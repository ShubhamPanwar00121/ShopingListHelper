#pragma once
#include <string>

class Commodity
{
public:
	Commodity();
	Commodity(std::string, float, float);
	~Commodity();
	std::string GetCommodityName();
	float GetAvaialbleQuantity();
	float GetCommodityCost();
	void SetAvailableQuantity(float);
private:
	std::string name{ "" };
	float availableQuantity{ 0 };
	float cost{ 0 };
};

