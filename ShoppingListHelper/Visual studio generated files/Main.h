#pragma once
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Dairy.h"
#include "GroceryStore.h"
#include "MedicalStore.h"
#include "PurchasedCommodity.h"

using namespace std;

void ToLowerCase(string&);
void SwitchToRequiredCategory(string);
void RetryOrExit();
Dairy DairySelected();
GroceryStore GroceryStoreSelected();
MedicalStore MedicalStoreSelected();
void PrintShopsDetails(int, string, string, int, int);
int GetSelectShopNumber();
void ShowAvaialbleCommoditiesInSelectedShop(Dairy,bool=false);
void ShowAvaialbleCommoditiesInSelectedShop(GroceryStore,bool=false);
void ShowAvaialbleCommoditiesInSelectedShop(MedicalStore,bool=false);
void DisplayCommoditiesDetail(Commodity);
void SwitchToSelectedShop();
void Purchaser(Commodity, Shop);
void MakeTextFileAndExit();
void StartFunc();
void AddDoublicateComodities();
