#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
   itemName = "none";
   itemPrice = 0;
   itemQuantity = 0;
   itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string name, int price, int qt, string desc) {
   itemName = name;
   itemPrice = price;
   itemQuantity = qt;
   itemDescription = desc;
}

void ItemToPurchase::SetName(string name) {
   itemName = name;
}

void ItemToPurchase::SetPrice(int price) {
   itemPrice = price;  
}

void ItemToPurchase::SetQuantity(int qt) {
   itemQuantity = qt;  
}

void ItemToPurchase::SetDescription(string desc) {
   itemDescription = desc; 
}


string ItemToPurchase::GetName() {
   return itemName;
}

int ItemToPurchase::GetPrice() {
   return itemPrice;  
}

int ItemToPurchase::GetQuantity() {
   return itemQuantity;  
}

string ItemToPurchase::GetDescription() {
   return itemDescription;
}

void ItemToPurchase::PrintItemCost() {
   cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity*itemPrice << endl; 
}

void ItemToPurchase::PrintItemDescription() {
   cout << itemName << ": " << itemDescription << endl;
}