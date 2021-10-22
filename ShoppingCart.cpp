#include <iostream>
#include <vector>
#include <string>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart() {
   customerName = "none";
   currentDate = "January 1, 2016";
   //vector < ItemToPurchase > cartItems;
}

ShoppingCart::ShoppingCart(const string& name, string date) {
   customerName = name;
   currentDate = date;
   //vector < ItemToPurchase > cartItems;
}

string ShoppingCart::GetCustomerName() const {
   return customerName;     
}

string ShoppingCart::GetDate() const {
   return currentDate;  
}
void ShoppingCart::AddItem(ItemToPurchase item){
   cartItems.push_back(item);  
}

void ShoppingCart::RemoveItem(string name) {
   for (unsigned int i = 0; i < cartItems.size(); i++) {
      if (cartItems.at(i).GetName() == name) {
         cartItems.erase(cartItems.begin()+i);  
      }
      else
         cout << "Item not found in cart. Nothing removed." << endl; 
   }
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
   for (unsigned int i = 0; i < cartItems.size(); i++) {
      if (cartItems.at(i).GetName() == item.GetName()) {
         if (item.GetPrice() != 0) {
            cartItems.at(i).SetPrice(item.GetPrice());
         }
         
         if (item.GetQuantity() != 0) {
            cartItems.at(i).SetQuantity(item.GetQuantity());
         }
         
         if (item.GetDescription() != "none") {
            cartItems.at(i).SetDescription(item.GetDescription());  
         }
      }
      else {
         cout << "Item not found in cart. Nothing removed." << endl; 
      }
   }  
}
int ShoppingCart::GetNumItemsInCart() {
   int totalQt = 0;
   for (unsigned int i = 0; i < cartItems.size(); i++) {
      totalQt = totalQt + cartItems.at(i).GetQuantity();
   }
   return totalQt;
}
int ShoppingCart::GetCostOfCart() {
   int totalCost = 0;
   for (unsigned int i = 0; i < cartItems.size(); i++) {
      totalCost = totalCost + cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity();
   }
   return totalCost;
   
}
void ShoppingCart::PrintTotal() {
   
   int totalQt = GetNumItemsInCart();
   int totalCost = GetCostOfCart();
   
   if (cartItems.size() == 0)
      cout << "SHOPPING CART IS EMPTY" << endl;
      
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << "Number of Items: " << totalQt << endl << endl;
   for (unsigned int i = 0; i < cartItems.size(); i++) {
      cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" 
      << cartItems.at(i).GetPrice() << " = $" << cartItems.at(i).GetQuantity()*cartItems.at(i).GetPrice() << endl;
   }
   cout << endl;
   cout << "Total: $" << totalCost << endl;
}

void ShoppingCart::PrintDescriptions() {
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << endl;
   cout << "Item Descriptions" << endl;
   
   for (unsigned int i = 0; i < cartItems.size(); i++) {
      cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
   }  
}
      
