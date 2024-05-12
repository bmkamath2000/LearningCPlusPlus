#include "Game.h"
#include<iostream>
//Empty Constructor                                                                                                                                                                                         
Game::Game()
{

}

void Game::LoadIngredients()
{
  fstream inputStream;
  string line;
  int i;
  //Open file                                                                                                                                                                                               
  inputStream.open(PROJ2_DATA);
  for(i=0;i<PROJ2_SIZE;i++)
    {//get one line                                                                                                                                                                                         
    getline(inputStream, line);
    string name="",type="",ingredient1="",ingredient2="";
    int j=0,len=line.length();
    // split based on ,                                                                                                                                                                                     
    while(line[j]!=',')
    name = name + line[j++];
    j++;
    // split based on ,                                                                                                                                                                                     
    while(line[j]!=',')
    type = type + line[j++];
    j++;
    // split based on ,                                                                                                                                                                                     
    while(line[j]!=',')
    ingredient1 = ingredient1 + line[j++];
    j++;
    // split based on length                                                                                                                                                                                
    while(j<len)
    ingredient2 = ingredient2 + line[j++];
    m_ingredients[i]=Ingredient(name,type,ingredient1,ingredient2,0);
    // add ingredient to shop                                                                                                                                                                               
    m_myShop.AddIngredient(m_ingredients[i]);
    line = "";
  }
cout<< to_string(i)<<" Ingredients Loaded"<< endl;
}
// Has the main Loop                                                                                                                                                                                        
void Game::StartGame()
{
  string name;
  GameTitle();
  cout<< "What is the name of your shop"<< endl;
  cin>> name;
  m_myShop = Shop(name);
  // Create instance of shop                                                                                                                                                                                
  LoadIngredients();
  // Call this just once per run                                                                                                                                                                            
  do
  {
    cout <<"What would you like to do in " << m_myShop.GetName()<< "'s Shop" << endl;

  }while(MainMenu()!=5);
  // Run loop until exit pressed                                                                                                                                                                            
  cout<< "Thanks for playing UMBC Potion Craft";
}

void Game::DisplayIngredients()
{
for(int i=0;i<m_myShop.IngredientCount();i++)
  // Iterate through the ingredients to display                                                                                                                                                             
{
  Ingredient item = m_myShop.GetIngredient(i);
  cout<< (i+1) << "." << m_ingredients[i].m_name << "  " << item.m_quantity << endl; //<< " " << m_ingredients[i].m_type << " " << m_ingredients[i].m_ingredient1 << " " << m_ingredients[i].m_ingredient2 
//<< " " << m_ingredients[i].m_quantity << endl;                                                                                                                                                              
}
}
int Game::MainMenu()
{ int ret_val=0;
  cout<< "1. Display your Shop's Ingredients"<< endl;
  cout<< "2. Search for Natural Ingredients"<< endl;
  cout<< "3. Attempt to merge Ingredients" << endl;
  cout<< "4. See score" << endl;
  cout<< "5. Quit" << endl;
    cin >> ret_val;
    char ch = ' ';
    switch(ret_val)
    //using switch statement for options                                                                                                                                                                    
    {
        case 1:
        DisplayIngredients();
        break;
        case 2:
        SearchIngredients();
        break;
        case 3:
        CombineIngredients();
        ch= m_myShop.GetRank();
        if (ch == 'S'){
          cout << "You have won the game!" << endl;
          return 5;
        }
        break;
        case 4:
        m_myShop.ShopScore();
        break;
        case 5:
        return 5;
        break;
        default: break;
    }
    return ret_val;
}
void Game::SearchIngredients()
{
  int index1;
  int max_rand=0;
  for(int i=0;i<m_myShop.IngredientCount();i++)
  // Iterate through the ingredients to display                                                                                                                                                             
  {
  Ingredient item = m_myShop.GetIngredient(i);
  if(item.m_type=="natural") max_rand++;
  }
  index1=rand() % max_rand;
  // generate rand num from 0 - 9(natural ingredient)                                                                                                                                                       
  int indexInShop = m_myShop.CheckIngredient(m_ingredients[index1]);
  if(indexInShop >= 0) {
    cout << m_ingredients[index1].m_name <<" Found" <<endl;
      m_myShop.IncrementQuantity(m_ingredients[index1]);
  }
}
void Game::CombineIngredients()
{
  int index1,index2;
  RequestIngredient(index1);
  index1--;
  // decrement as list starts from 1                                                                                                                                                                        
  RequestIngredient(index2);
  index2--;
  // decrement as list starts from 1                                                                                                                                                                        
  if(index1 < 0 || index2 < 0 || index1 >= m_myShop.IngredientCount() || index2 >= m_myShop.IngredientCount()) return;
  if(m_myShop.CheckQuantity(m_ingredients[index1],m_ingredients[index2]))
  {
    int indexOfRecipe = SearchRecipes(m_ingredients[index1].m_name,m_ingredients[index2].m_name);
    if(indexOfRecipe >= 0)
    {
    cout<< m_myShop.GetIngredient(index1).m_name<< " Combined with "<<m_myShop.GetIngredient(index2).m_name << " To Make "<< m_myShop.GetIngredient(indexOfRecipe).m_name<< endl;
    m_myShop.DecrementQuantity(m_ingredients[index1]);
    //if combined then decrement by ingredient                                                                                                                                                              
    m_myShop.DecrementQuantity(m_ingredients[index2]);
    m_myShop.IncrementQuantity(m_ingredients[indexOfRecipe]);
    //if combined then increment target output                                                                                                                                                              
    }
    else cout<< m_myShop.GetIngredient(index1).m_name<< " Cant merge with "<<m_myShop.GetIngredient(index2).m_name<< endl;
  }
  else cout<< "You do not have enough "<<m_ingredients[index1].m_name <<" Or "<<m_ingredients[index2].m_name<<" to attempt that merge"<<endl;
}

void Game::RequestIngredient(int &choice)
{
  // Take in index of ingredients(display list if needed)                                                                                                                                                   
  cout << "Which ingredient would you like to merge?"<< endl;
  cout<< "To list known ingredients enter :-1"<< endl;
  cin >> choice;
  if(choice == -1) {
    DisplayIngredients();
    RequestIngredient(choice);
  } else if( choice < -1 || choice >= m_myShop.IngredientCount())
  {
    RequestIngredient(choice);
  }
}

int Game::SearchRecipes(string s1, string s2)
{
int ret_val = -1;

// linear search recipes order of ingredients does not matter                                                                                                                                               
for(int i=0; i<m_myShop.IngredientCount() ; i++)
{
  if(m_ingredients[i].m_ingredient1==s1 && m_ingredients[i].m_ingredient2 == s2)
  return i;
  if(m_ingredients[i].m_ingredient2==s1 && m_ingredients[i].m_ingredient1 == s2)
  return i;
}
return ret_val;
}