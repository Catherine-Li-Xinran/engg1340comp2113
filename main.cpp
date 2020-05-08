#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int fishing_function();
int sell_function();
int buy_function();
int quit();

int main()
{
  int experience, level, rod, money, bait, shell, pufferFish, cod, salmon, octopus;

  char filename[100] = "userFile.txt";
  ifstream fin;
  fin.open(filename);

  if (fin.fail()){
    cout << "Error in file opening!" << endl;
    exit(1);
  }

  fin >> experience >> level >> rod >> money >> bait >> shell >> pufferFish >> cod >> salmon >> octopus;

  fin.close();

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

  ofstream fileout(filename.c_str(), ios::out|ios::trunc);
  fileout.close();

  ofstream fout;
  fout.open(filename);

  if (fout.fail()){
    cout << "Error in file opening!" << endl;
    exit(1);
  }

  fout << experience << level << rod << money << bait << shell << pufferFish << cod << salmon << octopus;

  fout.close();

  return 0;
}

//============= BELOW are all subfunctions ===============//

int get_a_fish(){

  srand((unsigned)time(NULL));
  int x;
  x = (rand()%100)+1;

  if (x>=1 && x<=10){
    cout << "A Shell!!!" << endl;
    update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
    update_my_experience();//更新经验，增加这种鱼对应的经验值
    update_my_level();//更新级别
    update_my_rod();//更新钓竿
  }

  if (x>=11 && x<=25){
    cout << "A Puffer Fish!!!" << endl;
    update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
    update_my_experience();//更新经验，增加这种鱼对应的经验值
    update_my_level();//更新级别
    update_my_rod();//更新钓竿
  }

  if (x>=26 && x<=45){
    cout << "A Cod!!!" << endl;
    update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
    update_my_experience();//更新经验，增加这种鱼对应的经验值
    update_my_level();//更新级别
    update_my_rod();//更新钓竿
  }

  if (x>=46 && x<=70){
    cout << "A Salmon!!!" << endl;
    update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
    update_my_experience();//更新经验，增加这种鱼对应的经验值
    update_my_level();//更新级别
    update_my_rod();//更新钓竿
  }

  if (x>=71 && x<=100){
    cout << "An Octopus!!!" << endl;
    update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
    update_my_experience();//更新经验，增加这种鱼对应的经验值
    update_my_level();//更新级别
    update_my_rod();//更新钓竿
  }

  return 0;
}

int get_rubbish(){

  srand((unsigned)time(NULL));
  int x;
  x = (rand()%100)+1;

  if (x>=1 && x<=10){
    cout << "A Wooden Stick..." << endl;
  }

  if (x>=11 && x<=25){
    cout << "A Plastic Bottle..." << endl;
  }

  if (x>=26 && x<=45){
    cout << "A Leather Boot..." << endl;
  }

  if (x>=46 && x<=70){
    cout << "A Bone..." << endl;
  }

  if (x>=71 && x<=100){
    cout << "Carrion..." << endl;
  }

  return 0;
}

int put_down_the_rod()
{
  int a;
  a = whether_catch_sth();//根据钓竿的类型确定，返回true（成功钓上），返回false（什么都没有钓上）

  if (a==false){
    cout << "Sorry, you catch nothing..." << endl;
  }

  if (a==true){
    srand((unsigned)time(NULL));
    int x;
    x = (rand()%10)+1;
    if (x<=8){
      cout << "Congratulate! A fish!!!" << endl;
      get_a_fish();
    }
    if (x>8){
      cout << "Oops..." << endl;
      get_rubbish();
    }
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

  put_down_the_rod();
  update_my_bait();//更新我的鱼饵数量

  while (true)
  {
    cout << "Wanting to fish again?" << endl;
    cout << "Press Y to fish once more" << endl;
    cout << "Press N to back to main page" << endl;

    string input_1;
    cin >> input_1;

    if (input_1=="Y"){
      put_down_the_rod();
      update_my_bait();//更新我的鱼饵数量
    }

    if (input_1=="N"){
      break;
    }
  }

  return 0;
}

//============= Above are fishing_function and its subfunctions ===============//


int sell_fish()
{
  print_my_fish();//打印出背包里所有的鱼和鱼的数量
  cout << "Which fish do you want to sell?" << endl;
  cout << "Press 1 to sell Octopus" << endl;
  cout << "Press 2 to sell Salmon" << endl;
  cout << "Press 3 to sell Cod" << endl;
  cout << "Press 4 to sell Puffer Fish" << endl;
  cout << "Press 5 to sell Shell" << endl;

  string input;
  cin >> input;
  if (input=="1"){
    cout << "You got $ 800 !" << endl;
    update_my_money();//更新我背包里的钱
    update_my_fish();//更新我背包里剩下的鱼
  }
  if (input=="2"){
    cout << "You got $ 900 !" << endl;
    update_my_money();//更新我背包里的钱
    update_my_fish();//更新我背包里剩下的鱼
  }
  if (input=="3"){
    cout << "You got $ 1000 !" << endl;
    update_my_money();//更新我背包里的钱
    update_my_fish();//更新我背包里剩下的鱼
  }
  if (input=="4"){
    cout << "You got $ 1100 !" << endl;
    update_my_money();//更新我背包里的钱
    update_my_fish();//更新我背包里剩下的鱼
  }
  if (input=="5"){
    cout << "You got $ 1200 !" << endl;
    update_my_money();//更新我背包里的钱
    update_my_fish();//更新我背包里剩下的鱼
  }
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

  sell_fish();

  while (true)
  {
    cout << "Wanting to sell another fish?" << endl;
    cout << "Press Y to sell another fish" << endl;
    cout << "Press N to back to main page" << endl;

    string input_1;
    cin >> input_1;

    if (input_1=="Y"){
      sell_fish();
    }

    if (input_1=="N"){
      break;
    }
  }

  return 0;
}

//============= Above are sell_function and its subfunctions ===============//

int buy_bait()
{
  cout << "This is our PRICE LIST:" << endl;
  cout << "1 bait: $ 400" << endl;
  cout << "3 bait: $ 1000" << endl;
  cout << "5 bait: $ 1500" << endl;
  cout << "Press 1 to buy 1 bait" << endl;
  cout << "Press 3 to buy 3 bait" << endl;
  cout << "Press 5 to buy 5 bait" << endl;

  string input;
  cin >> input;

  if (input=="1"){
    update_my_bait();//更新我的鱼饵数量
    cout << "You get 1 bait, and it costs you $ 400" << endl;
    print_my_bait();//打印出我包里的鱼饵数量
    cout << "Welcome your next visit!" << endl;
  }
  if (input=="3"){
    update_my_bait();//更新我的鱼饵数量
    cout << "You get 3 bait, and it costs you $ 1000" << endl;
    print_my_bait();//打印出我包里的鱼饵数量
    cout << "Welcome your next visit!" << endl;
  }
  if (input=="5"){
    update_my_bait();//更新我的鱼饵数量
    cout << "You get 5 bait, and it costs you $ 1500" << endl;
    print_my_bait();//打印出我包里的鱼饵数量
    cout << "Welcome your next visit!" << endl;
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

  buy_bait();

  while (true)
  {
    cout << "Wanting to buy more bait?" << endl;
    cout << "Press Y to buy more" << endl;
    cout << "Press N to back to main page" << endl;

    string input_1;
    cin >> input_1;

    if (input_1=="Y"){
      buy_bait();
    }

    if (input_1=="N"){
      break;
    }
  }

  return 0;
}

//============= Above are buy_function and its subfunctions ===============//

int quit()//我不太清楚是否需要这样的function或者应该怎么写它。。你看看？
{

}
