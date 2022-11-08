#pragma once
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Dairy.h"
#include "GroceryStore.h"
#include "MedicalStore.h"

using namespace std;

void ToLowerCase(string&);
void SwitchToRequiredCategory(string);
void RetryOrExit();
Dairy DairySelected();
GroceryStore GroceryStoreSelected();
MedicalStore MedicalStoreSelected();
void PrintShopsDetails(int, string, string, int, int);
int GetSelectShopNumber();
void ShowAvaialbleCommoditiesInSelectedShop(Dairy);
void ShowAvaialbleCommoditiesInSelectedShop(GroceryStore);
void ShowAvaialbleCommoditiesInSelectedShop(MedicalStore);
void DisplayCommoditiesDetail(Commodity);
string category{ "" };
