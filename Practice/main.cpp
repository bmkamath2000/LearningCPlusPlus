#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
#define height 20
#define width 20
#define dollar '$'
#define Guess 'G'
#define Baloon 'B'
#define found 'f'
#define impossible '?'
#define north 'n'
#define south 's'
#define east 'e'
#define west 'w'
// function prototypes
void print_map(char map[][height]);
void start_balloon(char map[][height],int output1,int output2); //done
void reset_map(char [][height]); //done
char guess_location(char map[][height],int output1,int output2,int x,int y); //done
char check_direction(int output1,int output2,int x,int y); //done


// No global variables


char check_direction(int output1,int output2,int x,int y) {
    
   if(y > output2)
    return north;
   else if(y < output2)
    return south;
    else if(y == output2)
    {
        if(x > output1)
        return west;
        else if(x < output1)
        return east;
    }
    return impossible;
}
/*
Generate a random position of baloon
set it in map array passed as param
*/
void start_balloon(char map[][height],int output1,int output2)
{
    map[output1][output2] = Baloon;
    return;
}
/*
if Guess is correct return found 
else
Insert G in position guessed in map
return N or E or W or S if guess is wrong
*/
char guess_location(char map[][height],int output1,int output2,int x,int y)
{
    if(output1!=x || output2 != y)
    {
    map[y][x] = Guess;
    return check_direction(output1,output2,x,y);
    }
    return found;
}
void print_map(char map[][height])
{ 
    cout<< "   ";
    for(int i=0;i<width;i++)
    cout<< setw(3)<< i << "  ";
    cout<< endl;
    for (int i = 0; i < height; i++) {
        cout<< setw(3)<< i << "  ";
        for (int k = 0; k < width; k++) {
            if(map[i][k] == dollar || map[i][k] == Guess)
            cout<< map[i][k] <<"    ";
            else cout<< dollar <<"    ";
       }
       cout<< endl;
    }
}
void reset_map(char map1[][height])
{
for (int i = 0; i < height; i++) {
        for (int k = 0; k < width; k++) {
            map1[i][k] = dollar;
        }
    }
    
}
int main() {
    
    
    int choice = 0;
    char map[width][height] = {dollar};
    char returnchar;
    int output1,output2;
    int x,y;
    char ch;
    cout << "Welcome to the Surveillance Balloon Tracker!" << endl;
    cout << "You are searching for the surveillance balloon." << endl;
    
    srand(time(NULL)); //generates random seed val
    output1 = (rand()*(width - 1.0)/RAND_MAX); 
    output2 = (rand()*(height - 1.0)/RAND_MAX);
    cout<<output1<<output2;

    start_balloon(map,output1,output2); 
    for(;choice!=3;) {
        cout << "What would you like to do?" << endl;
        cout << "1. Display Map" << endl;
        cout << "2. Guess Location of Balloon" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch(choice) {
        case 1:    print_map(map);
                break;
        case 2: 
            do{
            cout << "Where would you like look for the balloon?" << endl;
            cout << "Enter the X coordinate (0-"<< width <<"): " << endl;
            cin >> x;
            cout << "Enter the Y coordinate (0-"<< height <<"): " << endl;
            cin >> y;
            }while( x < 0 || x > (width-1) || y < 0 || y >= (height-1));
            // guess the location
            returnchar = guess_location(map,output1,output2,x,y);
            if(returnchar==found) {
            cout<<"You found the baloon!"<< endl;
            cout<<"Would you like to play again?(y/n)"<<endl;
            cin >> ch;
            
            if(ch=='Y'||ch=='y')
            {   reset_map(map);
                output1 = (rand()*(width - 1.0)/RAND_MAX); 
                output2 = (rand()*(height - 1.0)/RAND_MAX);
                cout<<output1<<output2;
                start_balloon(map,output1,output2);
            }
            else if(ch=='N'||ch=='n') 
            choice=3;
            } else 
                {
                 cout<<"You didn't find the baloon"<<endl;
                 if (returnchar==north)
                 cout << "Baloon is north of your guess"<<endl;
                 else if(returnchar == south)
                 cout << "Baloon is south of your guess"<<endl;
                 else if (returnchar == east)
                 cout << "Baloon is east of your guess"<<endl;
                 else if (returnchar == west)
                 cout << "Baloon is west of your guess"<<endl;
                }
                break;
        case 3:
            //exit
            cout<< "Exiting"<< endl;
            break;
        default:
            cout << "Please choose again" << endl;
        }
    }
    return 0;
}
