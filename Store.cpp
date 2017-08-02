/**********************************
 ** Program Filename: Store.cpp
 ** Author: reuben youngblom
 ** Date: December 2nd 2016
 ** Description: Store.cpp.
 ** Input: Takes input in the form of arguments
 ** Output: This file mostly returns values by calling all of the other functions via checkout.  More detailed explanations will be found in comments.
 **********************************/

#include "Store.hpp"
#include <iostream>

void Store::addProduct(Product* p)  //adds product to inventory; needed if product will be accessed later
{
    inventory.push_back (p);   //accomplishes this via push_back
}

void Store::addMember(Customer* c)  //adds member to member vector.  Also necessary if member wants to do things like checkout.
{
    members.push_back (c);  //also uses push_back
}

Product* Store::getProductFromID(std::string pId)  //takes in product ID as argument, and uses it to kick back the associated product
{
    bool testBool = false;  //creates a bool.  Default is false
    int prd;  //this is the product integer that holds the vector position
    
    for(int i=0; i < inventory.size(); i++)  //loops through vector
    {
        prd = i;  //and each time the loop goes through, prd is set to vector position
        
        if(inventory[i]->getIdCode() != pId)  //if product ID is not found....
        {
            testBool = false;  //...bool stays False, and the loop re-iterates (continue)
            continue;
        }
        
        else
            testBool = true;  //But if it is (meaning product was found), bool switches to True
        
        break;  //and the loop ends
    }
    
    if (testBool == true)  //so, if the loop is true, there's a product with a matching ID
    {
        return (inventory[prd]);  //so then, since the loop ended with the prd variable in the proper vector position, I can use that to kick back the proper place in the vector.
    }
    
    else
    {
        return NULL;  //but if bool is still false, no product was matching.  So return NULL
    }
    
}


Customer* Store::getMemberFromID(std::string mId)  //this is basically the same thing but with members and member IDs

{
    
    bool testBool = false;  //create the bool
    int mbr;  //create the vector position holder
    Customer* customerPTR;  //but here, i tried something new.  Created a pointer that I will assign to the vector position address and kick THAT back instead.  No real reason for this, just wanted to try it.
    
    for(int i=0; i < members.size(); i++)  //loops through the vector
    {
        mbr = i;  //and sets mbr equal to vector position every time
        
        if(members[i]->getAccountID() != mId) {  //if no match, keep bool FALSE and continue loop
            testBool = false;
            continue;
        }
        
        else
            testBool = true;  //but if there's a match, set bool to true and break out of the loop
        break;
    }
    
    if (testBool == true)  //so here, if testBool is true, there was a match
    {
        customerPTR = members[mbr];  //so set pointer to proper vector position
        
        return (customerPTR);  //and return that pointer
    }
    else
    {
        return NULL; //but if bool is still false, there was no match, so kick back NULL
    }
}


void Store::productSearch(std::string str)  //searches for products based on keyword.  Is case-insensitive
{
    
    bool testBool = false;  //created a test bool just like above. Helps me easily create conditionals at the end of each code segment
    
    std::string Cstr = str;  //created a string and set equal to argument.
    
    
    Cstr[0] = toupper(Cstr[0]);  //i used an auxillary string so I could manipulate it. Here, I turn the first letter into uppercase and run the search that way:
    
    for(int i=0; i < inventory.size(); i++)  //iterate through the inventory
    {
        if ((inventory[i]->getDescription()).find (Cstr) != std::string::npos)  //I check for a match by seeing if the Cstr is found in the descriptions and checking against npos.  if something is found...
        {
            std::cout << inventory[i] -> getTitle() << std::endl;  //i print the relevant info by calling get functions and outputting them
            std::cout << "ID Code: " << inventory[i] -> getIdCode() << std::endl;
            std::cout << "Price: " << inventory[i] -> getPrice() << std::endl;
            std::cout << inventory[i] -> getDescription() << std::endl;
            std::cout << std::endl;  //this is just a blank line for ease of reading
            
            testBool = true;  //sets bool equal to true
            
            continue;  //and restarts the loop
        }
        
        else if ((inventory[i]->getTitle()).find (Cstr) != std::string::npos)  //this is the same as above, but it checks the titles instead of descriptions, still with the first letter uppercase.
        {
            std::cout << inventory[i] -> getTitle() << std::endl;  //and prints the info if a match is found
            std::cout << "ID Code: " << inventory[i] -> getIdCode() << std::endl;
            std::cout << "Price: " << inventory[i] -> getPrice() << std::endl;
            std::cout << inventory[i] -> getDescription() << std::endl;
            std::cout << std::endl;
            
            testBool = true;  //and sets bool equal to true
            
            continue;  //and continues
        }
        
        std::string Lstr = str;  //here, I make a new string and set it equal to original argument
        
        Lstr[0] = tolower(Lstr[0]);  //and set the first letter to be lowercase so I can test those
        
        if (testBool == false)  //here, I check only if testBool is FALSE (so, if no uppercase matches have been found)
        {
            for(int i=0; i < inventory.size(); i++)  //  same as above.  loops through
            {
                if ((inventory[i]->getDescription()).find (Lstr) != std::string::npos)  //checks for matches in descriptions
                {
                    std::cout << inventory[i] -> getTitle() << std::endl;
                    std::cout << "ID Code: " << inventory[i] -> getIdCode() << std::endl;  //and prints matches, if there are any
                    std::cout << "Price: " << inventory[i] -> getPrice() << std::endl;
                    std::cout << inventory[i] -> getDescription() << std::endl;
                    std::cout << std::endl;
                    
                    testBool = true;  //sets bool to true if so
                    
                    continue;  //and restarts loop
                }
                
                else if ((inventory[i]->getTitle()).find (Lstr) != std::string::npos)  //here, same as above but I'm looking for matches in the titles (lowercase)
                {
                    std::cout << inventory[i] -> getTitle() << std::endl;  //and printing if I find any
                    std::cout << "ID Code: " << inventory[i] -> getIdCode() << std::endl;
                    std::cout << "Price: " << inventory[i] -> getPrice() << std::endl;
                    std::cout << inventory[i] -> getDescription() << std::endl;
                    std::cout << std::endl;
                    
                    testBool = true;  //sets bool to true
                    
                    continue;  //and continues loop
                }
            }
        }
    }
    
    if (testBool == false)  //if no matches are found, testBool will still be False
    {
        std::cout << "Sorry, search term not found!" << std::endl;  //so print "nothing found" message
        std::cout << std::endl;
    }
    
}





void Store::addProductToMemberCart(std::string pID, std::string mID)  //this adds a product to the member's cart IF both product and member are found.  Takes product and member IDs.
{
    bool pIDBool = false;  //product bool.  Tracks whether product is found
    bool mIDBool = false;  //member bool.  tracks whether member is found
    int p, m;  //keeps track of vector position for product and members
    
    for(int i=0; i < inventory.size(); i++)  //product is first.  Search is similar to above: loops through vector and searches for a match
    {
        p = i;  //keeps track of vector position
        
        if ((inventory[i]->getIdCode()).find (pID) != std::string::npos)  //if match is found...
        {
            pIDBool = true;  //bool is set to true
            break;  // break out of the loop so 'p' stays recording the proper vector position
        }
    }
    
    if (pIDBool == false) //if entire loop goes through and nothing matches, bool will still be false
    {
        std::cout << "Product #" << pID << " not found." << std::endl;  //so print not found message
        std::cout << std::endl;  //this is for readibility
    }
    
    for(int i=0; i < members.size(); i++)  //next, look for members.  loop through vector
    {
        m = i;  //keeps track of vector position
        
        if ((members[i]->getAccountID()).find (mID) != std::string::npos)  //if match is found....
        {
            mIDBool = true;  //members bool is set to TRUE
            
            break; //and break out of the loop to keep 'm' in the right position
        }
    }
    
    if (mIDBool == false)  //if no match, bool will still be false
    {
        std::cout << "Member #" << mID << " not found." << std::endl;  //so print not found message
        std::cout << std::endl;  //for readibility
    }
    
    
    if ((pIDBool && mIDBool) == true) //at this point, IF both product and member bools are TRUE (i.e. both found matches).....

    {
        if ((inventory[p] -> getQuantityAvailable()) >= 1)  //make sure there is more than one in stock.  If there is....
        {
            (members[m])->addProductToCart(inventory[p]->getIdCode());  //add it to member cart.  proper member is noted by calling the 'm' position is members vector and adding product that's in the 'p'position of the vector
            
            std::cout << "Product #" << (inventory[p]->getIdCode()) << " added to cart!" << std::endl;  //this is a confirmation message.  Wasn't in the direction, but I think it's nice to have confirmation.  Maybe chalk it up to a stylistic choice?
        }
        
        else  //but if there's NOT at least one of the product in stock....
        {
            std::cout << "Sorry, product #" << (inventory[p]->getIdCode()) << " is currently out of stock." << std::endl;   //print out of stock message.  This will print after an instance of the product goes into the cart if that was the last one left.
            std::cout << std::endl;
        }
        
    }
    
}



void Store::checkOutMember(std::string mID)  //check out function
{
    
    bool mIDBool = false;  //sets Member ID bool to false
    int mbn;  //keeps track of vector position for members
    double subtotal;  //subtotal variable
    double shipping; //shipping variable
    double total;  //grand total variable
    
    for(int i=0; i < members.size(); i++)  //first, loops through the members vector to match ID with member
    {
        
        if ((members[i]->getAccountID()).find (mID) != std::string::npos)  //if member is found....
        {
            mbn = i;  //sets mbn to proper vector position
            mIDBool = true;  //and sets bool to true
            
            break;  //and break out of the loop
        }
    }
    
    
    
    Customer* custprt;  //creates customer pointer
    
    custprt = getMemberFromID(mID);  //and sets that equal to member pointer via getMemberFrom ID
    
    std::vector<std::string> memcart;  //this creates a new vector
    memcart = custprt->getCart();  //and this puts the member cart into it
    
    
    if (mIDBool == false)  //so, if no member match is found, bool will be false.  In that case:
    {std::cout << "Member #" << mID << " not found." << std::endl;}  //print No Match message
    
    
    else if (memcart.size() == 0)  //similarly, if cart is empty....
    {std::cout << "There are no items in the cart." << std::endl;  //print empty cart message
        
        std::cout << std::endl;
        std::cout << std::endl;  //these are for readibility
    }
    
    
    else  //BUT, if there is stuff in the cart and member has been found....
    {
        
        for (std::vector<std::string>::iterator i = memcart.begin(); i != memcart.end(); ++i)   //loop through the member's cart (memcart is that member's cart vector)
            
        {
            if ((getProductFromID(*i))->getQuantityAvailable() >= 1)  //IF there is at least one available...
            {
                std::cout << (getProductFromID(*i))->getTitle() << " — " << (getProductFromID(*i))->getPrice() << std::endl;  //print out the info, showing that it got calculated
                
                (getProductFromID(*i))->decreaseQuantity(); //and decrease available quantity
                
                subtotal += (getProductFromID(*i)->getPrice());  //and add the price to the running subtotal
                
            }
            
            else  //but, if there is NOT at least one left, print message stating that it's no longer available
            {
                std::cout << "Sorry, product # " << (getProductFromID(*i))->getIdCode() << ", \"" << (getProductFromID(*i))->getTitle() << "\", is no longer available." << std::endl;
            }
        }
        
        
        
        if ((members[mbn]->isPremiumMember()) == 0)  //checks if member is a premium member
            
        {
            shipping = (subtotal * .07);  //if not (i.e. bool is FALSE), shipping is 7% of subtotal
            
            std:: cout << std::endl;  //this is for readability
        }
        
        else  //but if they are a premium member, shipping is free
        {
            shipping = 0.0;
        }
        
        
        
        std::cout << "Subtotal: $" << subtotal << std::endl;  //this prints out subtotal, shipping, and then adds them together for the total....
        
        std::cout << "Shipping Cost: $" << shipping << std::endl;
        
        total = (subtotal + shipping);
        
        std::cout << std::endl;
        std::cout << "Total: $" << total << std::endl;   //...which is printed here
        std::cout << std::endl;
        std::cout << std::endl;
        
        
        members[mbn]->emptyCart();  //lastly, the cart of that member is emptied.
        
    }
}


