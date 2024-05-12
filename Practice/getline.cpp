#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//macro definitions
#define MAX_NAME_LEN 60 // Maximum len of your name can't be more than 60
#define MAX_ADDRESS_LEN 120 // Maximum len of your address can't be more than 120
#define MAX_ABOUT_LEN 250 // Maximum len of your profession can't be more than 250

int main () {
char y_name[MAX_NAME_LEN], y_address[MAX_ADDRESS_LEN], about_y[MAX_ABOUT_LEN];
fstream inputStream;
string line;
cout << "Enter your name: ";
inputStream.open("proj2_data.txt");
inputStream>> line;
cout<< "First Line of file:"<<line;
return 0;
}
