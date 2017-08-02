/**********************************
 ** Program Filename: Customer.cpp
 ** Author: reuben youngblom
 ** Date: December 2nd 2016
 ** Description: Customer.cpp.  Takes customer information and puts it through a constructor, and then has get functions for returning the data.  Customer also has the additional function of emptying the cart, which is called after checkout.
 ** Input: Takes input in the form of arguments
 ** Output: This file mostly returns values via get functions
 **********************************/

#include "Customer.hpp"

Customer::Customer(std::string n, std::string a, bool pm)  //constructor that takes passed data as arguments.  name, ID number, and bool holding whether or not customer is a premium member
{
    name = n;
    accountID = a;  //these set the arguments to the appropriate variables
    premiumMember = pm;
}


std::string Customer::getAccountID()  //returns customer ID numbers
{
    return accountID;
}

std::vector<std::string> Customer::getCart()  //returns customer cart, which is a vector
{
    return cart;
}

void Customer::addProductToCart(std::string inCart)  //puts an item in the cart using pushback
{
    cart.push_back(inCart);
}


bool Customer::isPremiumMember()  //checks to see if customer is a premium member
{
    if (premiumMember == true)
    {return true;} //returns true if customer is a permium member and false if not
    
    else
    {return false;}
}


void Customer::emptyCart()  //empties cart vector using vector.clear()
{
    cart.clear();
}

