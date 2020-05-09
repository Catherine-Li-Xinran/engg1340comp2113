#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int fishing_function();
int sell_function();
int buy_function();
int quit();
int menu();

struct player {
  int money;
  int exp;
  int level;
  int bait;
};
player p1={};

int fish[5];//, bait, money, exp, level;
int shell, pufferFish, cod, salmon, octopus;
char filename[100] = "userFile.txt";

int main()
{
  //file in


  ifstream fin;
  fin.open(filename);

  if (fin.fail()){
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  fin >> p1.exp >> p1.level >> p1.money >> p1.bait >> octopus >> salmon >> cod >> pufferFish >> shell;
  fish[0]=octopus;
  fish[1]=salmon;
  fish[2]=cod;
  fish[3]=pufferFish;
  fish[4]=shell;
  fin.close();

  menu();

  ofstream fout;
  fout.open(filename);

  if (fout.fail()){
    cout << "Error in file opening!" << endl;
    exit(1);
  }

  fout << p1.exp << " " << p1.level << " " << p1.money << " " << p1.bait << " " <<shell << " " << pufferFish << " " << cod << " " << salmon << " " << octopus;

  fout.close();
  return 0;
}

int menu(){
  cout << "Here you are at the fish pond."<< endl;
  cout << "Go fishing: Press 1" << endl;
  cout << "Go to the market (sell fish): Press 2"<< endl;
  cout << "Go to the market (buy bait): Press 3"<< endl;
  cout << "Exit the game: Press 4"<< endl;

  string input;
  cin >> input;
  if (input=="1"){
    fishing_function();
  }
  if (input=="2"){
    sell_function();
  }
  if (input=="3"){
    buy_function();
  }

  else if (input=="4"){
    ofstream fout;
    fout.open(filename);

    if (fout.fail()){
      cout << "Error in file opening!" << endl;
      exit(1);
    }

    fout << p1.exp << " " << p1.level << " " << p1.money << " " << p1.bait << " " <<shell << " " << pufferFish << " " << cod << " " << salmon << " " << octopus;

    fout.close();
  }

  return 0;
}

//============= BELOW are all subfunctions ===============//
void levelcheck(player &p1){
  if ((p1.exp/100)>=p1.level) {
    p1.level+=1;
    cout << "Level up! Now you are Level " << p1.level << "!" << endl;
  }
}

void get_a_fish(int (&fish)[5], player &p1){

  srand((unsigned)time(NULL));
  int *i = new int;
  *i = (rand()%100)+1;

  if (*i>=1 && *i<=10){
    cout << "An Octopus!!!" << endl;
    fish[0]+=1;
  }

  if (*i>=11 && *i<=25){
    cout << "A Salmon!!!" << endl;
    fish[1]+=1;
  }

  if (*i>=26 && *i<=45){
    cout << "A Cod!!!" << endl;
    fish[2]+=1;
  }

  if (*i>=46 && *i<=70){
    cout << "A Puffer Fish!!!" << endl;
    fish[3]+=1;
  }

  if (*i>=71 && *i<=100){
    cout << "A Shell!!!" << endl;
    fish[4]+=1;
  }
  p1.exp+=10;
  levelcheck(p1);
  delete i;
}

int get_rubbish(){

  srand((unsigned)time(NULL));
  int *i = new int;
  *i = (rand()%100)+1;

  if (*i>=1 && *i<=10){
    cout << "A Wooden Stick..." << endl;
  }

  if (*i>=11 && *i<=25){
    cout << "A Plastic Bottle..." << endl;
  }

  if (*i>=26 && *i<=45){
    cout << "A Leather Boot..." << endl;
  }

  if (*i>=46 && *i<=70){
    cout << "A Bone..." << endl;
  }

  if (*i>=71 && *i<=100){
    cout << "Carrion..." << endl;
  }
  delete i;

  return 0;
}

bool whether_catch_sth(player p1){
  int precent = 40-p1.level*10;
  int *i = new int;
  *i = (rand()%100)+1;

  if (*i>=precent){
    delete i;
    return true;
  }
  else
    delete i;
    return false;
}


int put_down_the_rod(player &p1)
{
  if (p1.bait <1){
    cout << "Sorry, you don't have enough baits, go to buy one first!" << endl;
    return 0;
  }
  else {
    p1.bait-=1;
  }

  bool *a = new bool;
  *a = whether_catch_sth(p1);

  if (*a==false){
    cout << "Sorry, you catch nothing...(Fishing can upgrade your fishing rod!)" << endl;
  }

  if (*a==true){
    srand((unsigned)time(NULL));
    int x;
    int *i = new int;
    *i = (rand()%10)+1;
    if (*i<=8){
      cout << "Congratulations! ";
      get_a_fish(fish, p1);
    }
    if (*i>8){
      cout << "Oops..." << endl;
      get_rubbish();
    }
    delete i,a;
  }
  return 0;
}

int fishing_function()
{

  cout << "Welcome to our fish pond!" << endl;
  cout << "Wish you good luck!" << endl;
  string input = "0";
  while (input!= "1"){
    cout << "Press 1 to put down the rod." << endl;
    cin >> input;
  }

  put_down_the_rod(p1);
  // update_my_bait();//

  while (true)
  {
    cout << "Want to fish again?" << endl;
    cout << "Press Y to fish once more" << endl;
    cout << "Press N to back to main page" << endl;

    string input_1;
    cin >> input_1;

    if (input_1=="Y"){
      put_down_the_rod(p1);
      //update_my_bait();//
    }

    if (input_1=="N"){
      menu();
      break;
    }
  }

  return 0;
}

//============= Above are fishing_function and its subfunctions ===============//
void print_my_fish(int fish[]){
  cout << "You have:" << endl;
  cout << "Octopus: " << fish[0] << endl;
  cout << "Salmon: " << fish[1] << endl;
  cout << "Cod: " << fish[2] << endl;
  cout << "Puffer Fish:" << fish[3] << endl;
  cout << "Shell: " << fish[4] << endl;

}

int sell_fish(int (&fish)[5], player &p1)
{
  print_my_fish(fish);//
  cout << "Please tell me what fish you want to sell and the number:" << endl;
  cout << "Press 0 to sell Octopus" << endl;
  cout << "Press 1 to sell Salmon" << endl;
  cout << "Press 2 to sell Cod" << endl;
  cout << "Press 3 to sell Puffer Fish" << endl;
  cout << "Press 4 to sell Shell" << endl;
  cout << "e.g. input 0 2 and you will sell 2 Octopus." << endl;
  int input1, input2, price;
  cin >> input1 >> input2;
  if (input1==0){
    price=800;
  }
  if (input1==1){
    price=900;
  }
  if (input1==2){
    price=1000;
  }
  if (input1==3){
    price=1100;
  }
  if (input1==4){
    price=1200;
  }
  if (fish[input1]>=input2){
    fish[input1]=fish[input1]-input2;
    p1.money=p1.money+input2*price;
    cout << "You got " << input2*price << ",now you have "<< p1.money <<". " << endl;
  }
  else
  cout << "You don't have enough fish!";
  return 0;
}

int sell_function()
{
  cout << "Welcome to our fish shop!" << endl;
  cout << "Let me see what fish you caught~" << endl;
  string input = "0";
  while (input!= "1"){
    cout << "Press 1 to sell your fish." << endl;
    cin >> input;
  }

  sell_fish(fish, p1);

  while (true)
  {
    cout << "Wanting to sell another fish?" << endl;
    cout << "Press Y to sell another fish" << endl;
    cout << "Press N to back to main page" << endl;

    string input_1;
    cin >> input_1;

    if (input_1=="Y"){
      sell_fish(fish, p1);
    }

    if (input_1=="N"){
      menu();
      break;
    }
  }

  return 0;
}

//============= Above are sell_function and its subfunctions ===============//
int buy_bait(player &p1)
{
  cout << "You have " << p1.bait << " baits.";
  cout << "This is our PRICE LIST:" << endl;
  cout << "1~9 bait: $400/bait" << endl;
  cout << "10~49 bait: $360/bait (10% discount)" << endl;
  cout << "50 bait or more: $320/bait (20% discount)" << endl;
  cout << "Please enter the number of bait you want to buy:" << endl;

  int input, price;
  cin >> input;
  if (input>=1 && input <=9){
    price = 400;
  }
  else if  (input>=10 && input <=49){
    price = 360;
  }
  else if (input>=50){
    price = 320;
  }
  if ((input*price)<=p1.money){
    p1.money=p1.money-input*price;
    p1.bait+=input;
    cout << "You got " << input << "bait(s), now you have " << p1.bait << "bait(s)." << endl;
  }
  else{
    cout << "You don't have enough money!" << endl;
  }
  return 0;

}


int buy_function()
{
  cout << "Welcome to our bait shop!" << endl;
  cout << "You can buy more bait with discount!" << endl;

  string input = "0";
  while (input!= "1"){
    cout << "Press 1 to buy some bait." << endl;
    cin >> input;
  }

  buy_bait(p1);

  while (true)
  {
    cout << "Wanting to buy more bait?" << endl;
    cout << "Press Y to buy more" << endl;
    cout << "Press N to back to main page" << endl;

    string input_1;
    cin >> input_1;

    if (input_1=="Y"){
      buy_bait(p1);
    }

    if (input_1=="N"){
      menu();
      break;
    }
  }

  return 0;
}

//============= Above are buy_function and its subfunctions ===============//
