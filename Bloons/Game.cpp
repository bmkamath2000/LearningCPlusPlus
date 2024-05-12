#include "Game.h"
Game::Game()
{
    m_curLife = START_LIFE;
m_curMoney = START_MONEY;
m_curRound = START_ROUND;

}
Game::~Game()
{
 
}
void Game::PrintMap()
{
    for(int loc=0;loc<PATH_LENGTH;++loc){
    cout<< "***Location "<< loc+1<<"***"<< endl;
    cout<< "--Monkeys--"<< endl;
    if(m_monkeys.size()==0) cout<< "None" << endl;
    for(uint16_t i=0;i<m_monkeys.size();i++) {
        if(m_monkeys[i]->GetLocation() == loc)
        cout<<"   "<< m_monkeys[i]->GetType()<< " Location:"<<m_monkeys[i]->GetLocation()+1<<" Damage: "<<m_monkeys[i]->GetDamage()<<endl;
    }
    cout<< "<<Bloons>>"<< endl;
    if(m_bloons.size()==0) cout<< "None" << endl;
    for(uint16_t i=0;i<m_bloons.size();i++) {
        if(m_bloons[i]->GetLocation() == loc)
        cout<<"   "<< m_bloons[i]->GetColor()<< " Bloon Health "<<m_bloons[i]->GetHealth()<<endl;
    }
    }
}
void Game::ImproveMonkey()
{

//COST_IMPROVE
}
void Game::BuyMonkey()
{
    int type;
    cout<< "What type of monkey would you like to buy?"<< endl;
    cout<< "1. Dart Monkey" << endl;
    cout<< "2. Boomerang Monkey" << endl;
    cout<< "3. Bomb Monkey" << endl;
    cout<< "4. Cancel" << endl;
    cin>> type;
    PlaceMonkey(type);    
}
void Game::PlaceMonkey(int choice)
{
    int location=0;
    while(location<1||location>3) {
    cout<< "Where would you like to place the new monkey? (1-3)" << endl;
    cin>> location;
    }
    switch(choice)
    {
        case 1: if(m_curMoney> COST_DART) {
                m_monkeys.push_back(new Dart("Dart Monkey",DAMAGE_DART,location-1));
                m_curMoney -=COST_DART; 
                }   break;
        case 2: if(m_curMoney> COST_BOOMERANG) {
                m_monkeys.push_back(new Boomerang("Boomerang Monkey",DAMAGE_BOOM,location-1));
                m_curMoney -=COST_BOOMERANG; 
                }   break;
        case 3: if(m_curMoney> COST_DART){
                m_monkeys.push_back(new Bomb("Bomb Monkey",DAMAGE_BOMB,location-1));
                m_curMoney -=COST_BOMB;
                } break;
        case 4: break;
    }
}
void Game::StartGame()
{
cout<< "Welcome to UMBC Bloons!" << endl;
int choice=0;
while((choice=MainMenu())!=6)
{
    switch(choice)
    {
        case 1:PrintMap(); break;
        case 2:BuyMonkey(); break;
        case 3:ImproveMonkey(); break;
        case 4:PlayRound(); break;
        case 5: Stats(); break;
        default: break;
    }

};
}
int Game::MainMenu()
{
    int choice;
    cout<< "What would you like to do?"<< endl;
    cout<< "1. View Map"<< endl;
    cout<< "2. Buy New Monkey"<< endl;
    cout<< "3. Improve Existing Monkey"<< endl;
    cout<< "4. Progress Round"<< endl;
    cout<< "5. Check Stats"<< endl;
    cout<< "6. Quit"<< endl;
    cin>> choice;
return choice;
}
void Game::Stats()
{
cout << "**CURRENT STATS**"<< endl;
cout<< "Current Round:"<< m_curRound<< endl;
cout <<"Monkeys Working:"<< m_monkeys.capacity()<< endl;
cout <<"Current Money: " << m_curMoney<< endl;
cout<< "Current Life:"<< m_curLife<< endl;
}
void Game::PlayRound()
{
    cout<< "Starting Round "<< m_curRound<< endl;
PopulateBloons();
ResolveBattle();
RemovePopped();
MoveBloons();
CheckPath();
cout<< "Round "<< m_curRound<< " Completed"<< endl;
m_curRound++;

}
void Game::PopulateBloons()
{
        for(int i=0;i<m_curRound;i++){
            Basic *b = new Basic(i,START_BLOON+1);
            m_bloons.push_back(b);
            cout<< "A New "<< b->GetColor()<< " Bloon Appears!"<< endl;  
        }   
}
void Game::ResolveBattle()
{

    for(uint16_t i=0;i<m_monkeys.size();i++) {
        int pops = m_monkeys[i]->Attack(m_bloons);
        m_curMoney += pops;
    }

}
void Game::RemovePopped()
{
for(uint16_t i=0;i<m_bloons.size();i++) {
    if(m_bloons[i]->GetHealth()<=0)
     m_bloons.erase(m_bloons.begin()+i);
}
}
void Game::MoveBloons()
{
    int flag=0;
for(uint16_t i=0;i<m_bloons.size();i++) {
    if(m_bloons[i]->GetLocation()<PATH_LENGTH)
    {
        flag=1;
        m_bloons[i]->SetLocation(m_bloons[i]->GetLocation()+1);
    }
}
if(flag) 
    cout<<"The bloons move along the path"<< endl;
}
void Game::CheckPath()
{
for(uint16_t i=0;i<m_bloons.size();i++) {
    if(m_bloons[i]->GetLocation()==PATH_LENGTH-1)
    {
        m_curLife -= m_bloons[i]->GetHealth();
        m_bloons.erase(m_bloons.begin()+1);
    }
}
}