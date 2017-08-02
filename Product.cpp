/**********************************
 ** Program Filename: Product.cpp
 ** Author: reuben youngblom
 ** Date: December 2nd 2016
 ** Description: Product.cpp.  Takes product information and puts it through a constructor, and then has get functions for returning the data.  Also has the additional function of decreasing the quantity available by 1 each time it is called, which will be once per product instance in checkout.
 ** Input: Takes input in the form of arguments
 ** Output: This file mostly returns values via get functions
 **********************************/

#include "Product.hpp"



Product::Product(std::string id, std::string t, std::string d, double p, int qa)  //constructor.  Takes product paramters as arguments
{
    
    idCode = id;  //sets the passed argument data to the appropriate variables
    title = t;
    description = d;
    price = p;
    quantityAvailable = qa;
    
}



std::string Product::getIdCode()  //returns ID code for a product
{
    return idCode;
}

std::string Product::getTitle()  //returns product title
{
    return title;
}

std::string Product::getDescription()  //returns product description
{
    return description;
}

double Product::getPrice()  //returns product price
{
    return price;
}

int Product::getQuantityAvailable()  //returns quantity available at the moment
{
    return quantityAvailable;
}


void Product::decreaseQuantity()  //this fuction decreases the quantity available by 1 per each time it is called
{
    quantityAvailable = (quantityAvailable -1);
}


