

#include <iostream>
#include <vector>
#include <string>

/*

class Product
{
private:
    std::string idCode;
    std::string title;
    std::string description;
    double price;
    int quantityAvailable;
public:
    Product(std::string id, std::string t, std::string d, double p, int qa);
    std::string getIdCode();
    std::string getTitle();
    std::string getDescription();
    double getPrice();
    int getQuantityAvailable();
    void decreaseQuantity();
};


class Customer
{
private:
    std::vector<std::string> cart;
    std::string name;
    std::string accountID;
    bool premiumMember;
public:
    Customer(std::string n, std::string a, bool pm);
    std::string getAccountID();
    std::vector<std::string> getCart();
    void addProductToCart(std::string);
    bool isPremiumMember();
    void emptyCart();
};


class Store
{
private:
    std::vector<Product*> inventory;
    std::vector<Customer*> members;
public:
    void addProduct(Product* p);
    void addMember(Customer* c);
    Product* getProductFromID(std::string);
    Customer* getMemberFromID(std::string);
    void productSearch(std::string str);
    void addProductToMemberCart(std::string pID, std::string mID);
    void checkOutMember(std::string mID);
};


*/
/****************************************************/

/*
Product::Product(std::string id, std::string t, std::string d, double p, int qa)
{
    
    idCode = id;
    title = t;
    description = d;
    price = p;
    quantityAvailable = qa;
    
}



std::string Product::getIdCode()
{
    return idCode;
}

std::string Product::getTitle()
{
    return title;
}

std::string Product::getDescription()
{
    
    return description;
}

double Product::getPrice()
{
    return price;
}

int Product::getQuantityAvailable()
{
    return quantityAvailable;
}


void Product::decreaseQuantity()
{
    quantityAvailable = (quantityAvailable -1);
}
*/

/*******************************************/
/*

Customer::Customer(std::string n, std::string a, bool pm)
{
    name = n;
    accountID = a;
    premiumMember = pm;
    
}


std::string Customer::getAccountID()
{
    return accountID;
}

std::vector<std::string> Customer::getCart()
{
    return cart;
}

void Customer::addProductToCart(std::string inCart)
{
    cart.push_back(inCart);
}


bool Customer::isPremiumMember()
{
    if (premiumMember == true)
    {return true;}
    
    else
    {return false;}
    
}


void Customer::emptyCart()
{
    cart.clear();
}


*/
/********************************************************************/

/*


void Store::addProduct(Product* p)
{
    inventory.push_back (p);
}

void Store::addMember(Customer* c)
{
    members.push_back (c);
}

Product* Store::getProductFromID(std::string pId)
{
    
    bool testBool = false;
    int prd;
    Customer* memPoint;
    
    for(int i=0; i < inventory.size(); i++)
    {
        prd = i;
        
        if(inventory[i]->getIdCode() != pId) {
            testBool = false;
            continue;
        }
        
        else
            testBool = true;
        break;
        
    }
    
    if (testBool == true)
    {
        return (inventory[prd]);
    }
    else
    {return NULL;}
    
}


Customer* Store::getMemberFromID(std::string mId)

{
    
    bool testBool = false;
    int mbr;
    Customer* customerPTR;
    
    for(int i=0; i < members.size(); i++)
    {
        mbr = i;
        
        if(members[i]->getAccountID() != mId) {
            testBool = false;
            continue;
        }
        
        else
            testBool = true;
        break;
        
    }
    
    if (testBool == true)
    {
        
        customerPTR = members[mbr];
        
        return (customerPTR);

    }
    else
    {
        return NULL;}
    
}

void Store::productSearch(std::string str)
{
    
    bool testBool = false;
    
    std::string Cstr = str;
    
    Cstr[0] = toupper(Cstr[0]);
    
    
    for(int i=0; i < inventory.size(); i++)
    {
        if ((inventory[i]->getDescription()).find (Cstr) != std::string::npos)
        {
            std::cout << inventory[i] -> getTitle() << std::endl;
            std::cout << "ID Code: " << inventory[i] -> getIdCode() << std::endl;
            std::cout << "Price: " << inventory[i] -> getPrice() << std::endl;
            std::cout << inventory[i] -> getDescription() << std::endl;
            std::cout << std::endl;
            
            testBool = true;
            
            continue;
        }
        else if ((inventory[i]->getTitle()).find (Cstr) != std::string::npos)
        {
            std::cout << inventory[i] -> getTitle() << std::endl;
            std::cout << "ID Code: " << inventory[i] -> getIdCode() << std::endl;
            std::cout << "Price: " << inventory[i] -> getPrice() << std::endl;
            std::cout << inventory[i] -> getDescription() << std::endl;
            std::cout << std::endl;
            
            testBool = true;
            
            continue;
        }
        
        std::string Lstr = str;
        
        Lstr[0] = tolower(Lstr[0]);
        
        if (testBool == false)
        {
        for(int i=0; i < inventory.size(); i++)
        {
            if ((inventory[i]->getDescription()).find (Lstr) != std::string::npos)
            {
                std::cout << inventory[i] -> getTitle() << std::endl;
                std::cout << "ID Code: " << inventory[i] -> getIdCode() << std::endl;
                std::cout << "Price: " << inventory[i] -> getPrice() << std::endl;
                std::cout << inventory[i] -> getDescription() << std::endl;
                std::cout << std::endl;
                
                testBool = true;
                
                continue;
            }
            else if ((inventory[i]->getTitle()).find (Lstr) != std::string::npos)
            {
                std::cout << inventory[i] -> getTitle() << std::endl;
                std::cout << "ID Code: " << inventory[i] -> getIdCode() << std::endl;
                std::cout << "Price: " << inventory[i] -> getPrice() << std::endl;
                std::cout << inventory[i] -> getDescription() << std::endl;
                std::cout << std::endl;
                
                testBool = true;
                
                continue;
            }
        }
        }
    }
    if (testBool == false)
    {std::cout << "Sorry, search term not found!" << std::endl;
    std::cout << std::endl;}
    
}





void Store::addProductToMemberCart(std::string pID, std::string mID)
{
    bool pIDBool = false;
    bool mIDBool = false;
    int p, m;
    
    for(int i=0; i < inventory.size(); i++)
    {
        p = i;
        if ((inventory[i]->getIdCode()).find (pID) != std::string::npos)
        {
            pIDBool = true;
            break;
        }
        
    }
    
    if (pIDBool == false)
    {std::cout << "Product #" << pID << " not found." << std::endl;
    std::cout << std::endl;}
    
    
    
    for(int i=0; i < members.size(); i++)
    {
        m = i;
        
        if ((members[i]->getAccountID()).find (mID) != std::string::npos)
        {
            mIDBool = true;
            
            break;
        }
        
    }
    
    if (mIDBool == false)
    {std::cout << "Member #" << mID << " not found." << std::endl;
    std::cout << std::endl;
    }
    
    
    
    if ((pIDBool && mIDBool) == true)
    {
        if ((inventory[p] -> getQuantityAvailable()) >= 1)
        {
            
            (members[m])->addProductToCart(inventory[p]->getIdCode());
            
            std::cout << "Product #" << (inventory[p]->getIdCode()) << " added to cart!" << std::endl;
            
        }
        
        else
        {std::cout << "Sorry, product #" << (inventory[p]->getIdCode()) << " is currently out of stock." << std::endl;
        std::cout << std::endl;}
        
    }
    
}

void Store::checkOutMember(std::string mID)
{
    
    bool mIDBool = false;
    int mbn;
    double subtotal;
    double shipping;
    double total;
    
    for(int i=0; i < members.size(); i++)
    {
        mbn = i;
        
        if ((members[i]->getAccountID()).find (mID) != std::string::npos)
        {
            mbn = i;
            mIDBool = true;
            
            break;
        }
        
    }
    
    
    
    Customer* custprt;
    
    custprt = getMemberFromID(mID);
    
    std::vector<std::string> memcart;
    memcart = custprt->getCart();
    
    
    if (mIDBool == false)
    {std::cout << "Member #" << mID << " not found." << std::endl;}
    

    else if (memcart.size() == 0)
    {std::cout << "There are no items in the cart." << std::endl;
    
    std::cout << std::endl;
        std::cout << std::endl;
    }
  
    
    
//for (std::vector<std::string>::iterator i = memcart.begin(); i != memcart.end(); ++i)
 //   { std::cout << *i << std::endl;}
    
    else
    {
        
    //    for (std::vector<std::string>::const_iterator i = ((members[mbn])->getCart()).begin(); i != ((members[mbn])->getCart()).end(); ++i)
        
        for (std::vector<std::string>::iterator i = memcart.begin(); i != memcart.end(); ++i)
            
        {
            
            if ((getProductFromID(*i))->getQuantityAvailable() >= 1)
            {
                std::cout << (getProductFromID(*i))->getTitle() << " — " << (getProductFromID(*i))->getPrice() << std::endl;
                
                (getProductFromID(*i))->decreaseQuantity();
                
                subtotal += (getProductFromID(*i)->getPrice());
                
            }
            
            else
            {
                std::cout << "Sorry, product # " << (getProductFromID(*i))->getIdCode() << ", \"" << (getProductFromID(*i))->getTitle() << "\", is no longer available." << std::endl;
            }
        }
        
        
     
        if (  (members[mbn]->isPremiumMember()) == 0     )
            
        {
            shipping = (subtotal * .07);
            
            
            std:: cout << std::endl;
            
        }
    
        else
        {shipping = 0.0;}
        
        
        
        std::cout << "Subtotal: $" << subtotal << std::endl;
        
        std::cout << "Shipping Cost: $" << shipping << std::endl;
        
        total = (subtotal + shipping);
        
        std::cout << std::endl;
        std::cout << "Total: $" << total << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        
        
        members[mbn]->emptyCart();
        
    }
    
}

*/

/*************************************************************************/

#include "Store.hpp"
#include <iostream>

int main()
{
    
    
    //test classes
    
    Product blackCherry ("100", "Black Cherry", "One Gallon of Black Cherry Frozen Yogurt", 5.99, 7);
    Product vanilla ("200", "Vanilla", "One Gallon of vanilla Frozen Yogurt", 5.99, 12);
    Product phishFood ("300", "phish Food", "One Gallon of phish Food Frozen Yogurt", 7.99, 2);
    Product tart ("400", "Tart", "One Gallon of Tart Frozen Yogurt", 3.99, 10);
    Product banana ("500", "Banana", "One Gallon of Banana Frozen Yogurt", 2.99, 1);
    Customer wynter ("Wynter", "937", true);
    Customer reuben ("Reuben", "222", false);
    Customer lincoln ("Lincoln", "404", true);
    Customer lauren ("Lauren", "088", false);
    
    Store froYay;
    
    
    
    std::cout << vanilla.getPrice() << std::endl;
    std::cout << blackCherry.getDescription() << std::endl;
    std::cout << phishFood.getQuantityAvailable() << std::endl;
    tart.decreaseQuantity();
    std::cout << tart.getQuantityAvailable() << std::endl;
    
    /***********************************/
    
    wynter.addProductToCart("400");
    wynter.addProductToCart("400");
    wynter.addProductToCart("200");
    
    /************************************/
    
    froYay.addProduct(&vanilla);
    froYay.addProduct(&blackCherry);
    froYay.addProduct(&tart);
    froYay.addProduct(&banana);
    froYay.addProduct(&phishFood);
    froYay.addMember(&wynter);
    froYay.addMember(&reuben);
    froYay.addMember(&lincoln);
    
    
    froYay.getProductFromID("200");
    froYay.getProductFromID("300");
    froYay.getProductFromID("400");
    
    froYay.getMemberFromID("222");
    froYay.getMemberFromID("322");
    froYay.getMemberFromID("937");
    
    std::cout << "Product Search" << std::endl;
    
    froYay.productSearch("Cherry");
    std::cout << std::endl;
    froYay.productSearch("Phish");
    std::cout << std::endl;
    froYay.productSearch("fgfd");
    std::cout << std::endl;
    froYay.productSearch("gallon");
    std::cout << std::endl;
    
    /*************************************************/
    
    std::cout << "Reuben" << std::endl;
    
    froYay.addProductToMemberCart("200", "222");
    froYay.addProductToMemberCart("500", "222");
    froYay.addProductToMemberCart("400", "222");
    froYay.addProductToMemberCart("500", "222");
    froYay.addProductToMemberCart("400", "222");
    
    
    std::cout << "Wynter" << std::endl;
    
    froYay.addProductToMemberCart("200", "937");
    froYay.addProductToMemberCart("500", "937");
    froYay.addProductToMemberCart("402", "937");
    froYay.addProductToMemberCart("401", "937");
    froYay.addProductToMemberCart("400", "937");
    froYay.addProductToMemberCart("500", "937");
    froYay.addProductToMemberCart("400", "939");
    
    
    
    std::cout << "checkout" << std::endl;
    
    froYay.checkOutMember("222");
    froYay.checkOutMember("404");
    froYay.checkOutMember("937");
    
    return 0;
}
