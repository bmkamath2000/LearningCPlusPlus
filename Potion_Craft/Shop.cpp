//File: Shop.cpp                                                                
//Project: CMSC 202 Project 2, Spring 2023                                      
//Author: Rajshree Pani                                                         
//Date: 3/14/23                                                                 
//Section: 32                                                                   
//E-mail: rpani1@umbc.edu                                                       
//Description: This is a part of the PotionCraft Project @ UMBC.                

#include "Shop.h"
#include <fstream>
#include <string>
#include <cmath>

Shop::Shop()
{//constructor intialization                                                    
  m_numIngredients =0;
    m_shopRank = 'F';
}

Shop::Shop(string name)
{//parameterized constructor                                                    
  m_shopName = name;
}

string Shop::GetName()
{//getter for name                                                              
  return m_shopName;
}

void Shop::SetName(string name)
{//setter for name                                                              
  m_shopName = name;
}

int Shop::CheckIngredient(Ingredient ingre)
{
    //Search ingredient name                                                    
    int ret_val=-1;
    //iterator used to go through array                                         
    for(int i=0;i<m_numIngredients;i++)
    {
       if(m_myIngredients[i].m_name == ingre.m_name)
       {
        return i;
       }
    }
return ret_val;
}
void Shop::AddIngredient(Ingredient ingre)
{
        // Populate ingredients in shop with 0 qty                              
        m_myIngredients[m_numIngredients].m_name = ingre.m_name;
        m_myIngredients[m_numIngredients].m_ingredient1 = ingre.m_ingredient1;
        m_myIngredients[m_numIngredients].m_ingredient2 = ingre.m_ingredient2;
        m_myIngredients[m_numIngredients].m_type = ingre.m_type;
        m_myIngredients[m_numIngredients].m_quantity = 0;
        m_numIngredients++;
}

void Shop::IncrementQuantity(Ingredient ingre)
{
    // Check ingredient exists(return index), increment qty                     
    int index = CheckIngredient(ingre);
    if(index>=0)
    {    m_myIngredients[index].m_quantity++;
    }
}
bool Shop::DecrementQuantity(Ingredient ingre)
{
    bool ret_val=false;
    int index = CheckIngredient(ingre);
    // Check ingredient exists(return index), decrement qty                     
    if(m_myIngredients[index].m_quantity > 0) {
        m_myIngredients[index].m_quantity--;
        return true;
    }
return ret_val;
}

bool Shop::CheckQuantity(Ingredient ingre1, Ingredient ingre2)
{
  // Check both ingredients and return true if they can be merged               
    bool ret_val = false;
    int index1 = CheckIngredient(ingre1);
    int index2 = CheckIngredient(ingre2);
    if(index1!= -1 && m_myIngredients[index1].m_quantity>0 && index2!= -1&& m_m\
yIngredients[index2].m_quantity>0)
    {
        return true;
    }
return ret_val;
}
Ingredient Shop::GetIngredient(int index)
{
    return m_myIngredients[index];
}
void Shop::CalcRank()
{

  float score;
  int iscore;
  int count=0;
  //count number of ingredients with non zero quantity                          
  for(int i=0;i<m_numIngredients;i++)
    {
      if(m_myIngredients[i].m_quantity>0)
        count++;
    }
  //to convert integers to float multiplication by 1.0                          
  score = count*1.0 / m_numIngredients;

  iscore = floor(score*100);

  //if else blocks for checking rank                                            
  if(iscore>=0 && iscore<RANK_D)
    m_shopRank = 'F';
  else if(iscore>=RANK_D && iscore<RANK_C)
    m_shopRank = 'D';
  else if(iscore>=RANK_C && iscore<RANK_B)
    m_shopRank = 'C';
  else if(iscore>=RANK_B && iscore<RANK_A)
    m_shopRank = 'B';
  else if(iscore>=RANK_A && iscore<RANK_S)
    m_shopRank = 'A';
  else if(iscore==RANK_S)
    m_shopRank = 'S';

}
char Shop::GetRank()
// Calcrank and return shop rank                                                
{
    CalcRank();
    return m_shopRank;
}

int Shop::IngredientCount()
{
  return m_numIngredients;
}
void Shop::ShopScore()
{
// can use cout here only                                                                                                                                                                                   
    CalcRank();
    float score;
    int iscore;
    int count=0;
    for(int i=0;i<m_numIngredients;i++)
    // count number of ingredients with non zero quantity                                                                                                                                                   
    {
        if(m_myIngredients[i].m_quantity>0)
            count++;
    }
    score = count*1.0 / m_numIngredients;
    // to convert integers to float multiplication by 1.0                                                                                                                                                   

    iscore = floor(score*100);
    // score in integer                                                                                                                                                                                     

    cout<< "        ***The Potion Shop***"<<endl;
    cout<< "        Owned by "<< m_shopName<<endl;
    cout<< "        There are "<<m_numIngredients<<" available products"<<endl;
    cout<< "        This shop has "<<count<<" Products available in stock"<<endl;
    cout<< "        Which is "<< iscore <<"%"<<endl;
    cout<< "        Shop Rank: "<< m_shopRank<< endl;
 }
