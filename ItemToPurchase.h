#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

/* Type your code here */
class ItemToPurchase {
   public:
      ItemToPurchase();
      ItemToPurchase(string name, int price, int qt, string desc);
      
      void SetName(string name);
      string GetName();
      
      void SetPrice(int price);
      int GetPrice();
      
      void SetQuantity(int qt);
      int GetQuantity();
      
      void SetDescription(string desc);
      string GetDescription();
      
      void PrintItemCost();
      void PrintItemDescription();
      
   private:
      string itemName;
      int itemPrice;
      int itemQuantity;
      string itemDescription; 
};

#endif