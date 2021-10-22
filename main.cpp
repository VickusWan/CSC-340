#include <iostream>
#include <string>

#include "ShoppingCart.h"

void printMenu() {
   
cout << "MENU" << endl;
cout << "a - Add item to cart" << endl;
cout << "d - Remove item from cart" << endl;
cout << "c - Change item quantity" << endl;
cout << "i - Output items' descriptions" << endl;
cout << "o - Output shopping cart" << endl;
cout << "q - Quit" << endl << endl;
cout << "Choose an option:" << endl;
}

int main() {
   
   char input;
   
   string customerName;
   string date;
   
   cout << "Enter customer's name:" << endl;
   getline(cin, customerName);
   cout << "Enter today's date:" << endl << endl;
   getline(cin, date);
      
   
   ShoppingCart cart(customerName, date);
   cout << "Customer Name: " << cart.GetCustomerName() << endl;
   cout << "Today's Date: " << cart.GetDate() << endl << endl;

   cin >> input;
   cin.ignore();
   printMenu();
   while (input != 'q') {
      
      switch (input) {
         
         case 'a': {
            
            string name;
            int price;
            int qt;
            string desc;
            
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
               
            cout << "Enter the item description:" << endl;
            getline(cin, desc);
            
            cout << "Enter the item price:" << endl;
            cin >> price;
            
            cout << "Enter the item quantity:" << endl << endl;
            cin >> qt;
            cin.ignore();
            
            ItemToPurchase item(name, price, qt, desc);
            cart.AddItem(item);
            break;
         }

         case 'd': {
         
            string name;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, name);
            cart.RemoveItem(name);
            break;
         }
         case 'c': {
            string name;
            int qt;
            ItemToPurchase item;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the new quantity:" << endl;
            cin >> qt;
            
            item.SetName(name);
            item.SetQuantity(qt);
            cart.ModifyItem(item);
            break;
         }
         case 'i': {
            cart.PrintDescriptions();
            break;
         }
         case 'o': {
            cart.PrintTotal();
            cout << endl;
            break;
         }
      } 
      printMenu();
      cin >> input;
   }
      
   return 0;  
}