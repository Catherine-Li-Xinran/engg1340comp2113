#include <iostream>
using namespace std;

int main()
{
  cout << "Welcome to this game!" << endl;
  cout << "Here you are at the fish pond."<< endl;
  cout << "Go fishing: Press 1" << endl;
  cout << "Go to the market (sell fish): Press 2"<< endl;
  cout << "Go to the market (buy bait): Press 3"<< endl;
  cout << "Exit the game: Press 4"<< endl;

  string input;
  cin >> string;
  if (string=="1"){
    fishing_function();
  }
  if (string=="2"){
    sell_function();
  }
  if (string=="3"){
    buy_function();
  }
  if (string=="4"){
    quit();
  }

  return 0;
}
