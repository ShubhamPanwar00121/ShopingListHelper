#pragma once
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Dairy.h"

using namespace std;

void ToLowerCase(string&);
void SwitchToRequiredCategory(string);
void RetryOrExit();
Dairy DairySelected();
void PrintShopsDetails(int, string, string, int, int);
int GetSelectDairyNumber();
void ShowAvaialbleCommoditiesInSelectedShop(Dairy);
void DisplayCommoditiesDetail(Commodity);
string category{ "" };
