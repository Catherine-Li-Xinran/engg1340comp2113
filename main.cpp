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

int fish[5], bait, money, exp, level;
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

  fin >> exp >> level >> money >> bait >> shell >> pufferFish >> cod >> salmon >> octopus;
  fish[0]=shell;
  fish[1]=pufferFish;
  fish[2]=cod;
  fish[3]=salmon;
  fish[4]=octopus;
  fin.close();
  
  menu();//需要分一下，菜单需要重复进入
//   cout << "Here you are at the fish pond."<< endl;
//   cout << "Go fishing: Press 1" << endl;
//   cout << "Go to the market (sell fish): Press 2"<< endl;
//   cout << "Go to the market (buy bait): Press 3"<< endl;
//   cout << "Exit the game: Press 4"<< endl;

//   string input;
//   cin >> string;
//   if (string=="1"){
//     fishing_function();
//   }
//   if (string=="2"){
//     sell_function();
//   }
//   if (string=="3"){
//     buy_function();
//   }
//   if (string=="4"){
//     quit();
//   }

  ofstream fout;
  fout.open(filename);

  if (fout.fail()){
    cout << "Error in file opening!" << endl;
    exit(1);
  }

  fout << exp << " " << level << " " << money << " " << bait << " " <<shell << " " << pufferFish << " " << cod << " " << salmon << " " << octopus;

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

    fout << exp << " " << level << " " << money << " " << bait << " " <<shell << " " << pufferFish << " " << cod << " " << salmon << " " << octopus;

    fout.close();
  }
  
  return 0;
}

//============= BELOW are all subfunctions ===============//
void levelcheck(int exp, int &level){
  if ((exp/100)>=level) {
    cout << "Level up!";
    level+=1;
  }
}

void get_a_fish(int (&fish)[5], int &exp, int level){

  srand((unsigned)time(NULL));
  int x;
  x = (rand()%100)+1;

  if (x>=1 && x<=10){
    cout << "A Shell!!!" << endl;
    fish[0]+=1;
  }

  if (x>=11 && x<=25){
    cout << "A Puffer Fish!!!" << endl;
    fish[1]+=1;
  }

  if (x>=26 && x<=45){
    cout << "A Cod!!!" << endl;
    fish[2]+=1;
  }

  if (x>=46 && x<=70){
    cout << "A Salmon!!!" << endl;
    fish[3]+=1;
  }

  if (x>=71 && x<=100){
    cout << "An Octopus!!!" << endl;
    fish[4]+=1;
  }
  exp+=10;
  levelcheck(exp, level);
}

// int get_a_fish(){

//   srand((unsigned)time(NULL));
//   int x;
//   x = (rand()%100)+1;

//   if (x>=1 && x<=10){
//     cout << "A Shell!!!" << endl;
//     update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
//     update_my_experience();//更新经验，增加这种鱼对应的经验值
//     update_my_level();//更新级别
//     update_my_rod();//更新钓竿
//   }

//   if (x>=11 && x<=25){
//     cout << "A Puffer Fish!!!" << endl;
//     update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
//     update_my_experience();//更新经验，增加这种鱼对应的经验值
//     update_my_level();//更新级别
//     update_my_rod();//更新钓竿
//   }

//   if (x>=26 && x<=45){
//     cout << "A Cod!!!" << endl;
//     update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
//     update_my_experience();//更新经验，增加这种鱼对应的经验值
//     update_my_level();//更新级别
//     update_my_rod();//更新钓竿
//   }

//   if (x>=46 && x<=70){
//     cout << "A Salmon!!!" << endl;
//     update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
//     update_my_experience();//更新经验，增加这种鱼对应的经验值
//     update_my_level();//更新级别
//     update_my_rod();//更新钓竿
//   }

//   if (x>=71 && x<=100){
//     cout << "An Octopus!!!" << endl;
//     update_my_fish();//将这个鱼添加到我的背包里，一会儿好卖
//     update_my_experience();//更新经验，增加这种鱼对应的经验值
//     update_my_level();//更新级别
//     update_my_rod();//更新钓竿
//   }

//   return 0;
// }

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

bool whether_catch_sth(int level){
  int precent = 40-level*10;
  int x=rand()%100+1;
  if (x>=precent){
    return true;
  }
  else
    return false;
}


int put_down_the_rod(int &bait)
{ 
  if (bait <1){
    cout << "Sorry, you don't have enough baits, go to buy one first!" << endl;
    return 0;
  }
  else {
    bait-=1;
  }

  int a;
  a = whether_catch_sth(level);//根据钓竿的类型确定，返回true（成功钓上），返回false（什么都没有钓上）

  if (a==false){
    cout << "Sorry, you catch nothing...(Fishing can upgrade your fishing rod!)" << endl;
  }

  if (a==true){
    srand((unsigned)time(NULL));
    int x;
    x = (rand()%10)+1;
    if (x<=8){
      cout << "Congratulations! ";
      get_a_fish(fish, exp, level);
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

  put_down_the_rod(bait);
  // update_my_bait();//更新我的鱼饵数量

  while (true)
  {
    cout << "Want to fish again?" << endl;
    cout << "Press Y to fish once more" << endl;
    cout << "Press N to back to main page" << endl;

    string input_1;
    cin >> input_1;

    if (input_1=="Y"){
      put_down_the_rod(bait);
      //update_my_bait();//更新我的鱼饵数量
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

int sell_fish(int (&fish)[5], int &money)
{
  print_my_fish(fish);//打印出背包里所有的鱼和鱼的数量
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
    // cout << "You got $ 1200 !" << endl;
    // update_my_money();//更新我背包里的钱
    // update_my_fish();//更新我背包里剩下的鱼
  }
  if (fish[input1]>=input2){
    fish[input1]=fish[input1]-input2;
    money=money+input2*price;
    cout << "You got " << input2*price << ",now you have "<< money <<". " << endl;
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

  sell_fish(fish,money);

  while (true)
  {
    cout << "Wanting to sell another fish?" << endl;
    cout << "Press Y to sell another fish" << endl;
    cout << "Press N to back to main page" << endl;

    string input_1;
    cin >> input_1;

    if (input_1=="Y"){
      sell_fish(fish, money);
    }

    if (input_1=="N"){
      menu();
      break;
    }
  }

  return 0;
}

//============= Above are sell_function and its subfunctions ===============//
int buy_bait(int &money, int &bait)
{
  cout << "You have " << bait << " baits.";
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
  if ((input*price)<=money){
    money=money-input*price;
    bait+=input;
    cout << "You got " << input << "bait(s), now you have " << bait << "bait(s)." << endl;
  }
  else{
    cout << "You don't have enough money!" << endl;
  }
  return 0;

}
// int buy_bait()
// {
//   cout << "This is our PRICE LIST:" << endl;
//   cout << "1 bait: $ 400" << endl;
//   cout << "3 bait: $ 1000" << endl;
//   cout << "5 bait: $ 1500" << endl;
//   cout << "Press 1 to buy 1 bait" << endl;
//   cout << "Press 3 to buy 3 bait" << endl;
//   cout << "Press 5 to buy 5 bait" << endl;

//   string input;
//   cin >> input;

//   if (input=="1"){
//     update_my_bait();//更新我的鱼饵数量
//     cout << "You get 1 bait, and it costs you $ 400" << endl;
//     print_my_bait();//打印出我包里的鱼饵数量
//     cout << "Welcome your next visit!" << endl;
//   }
//   if (input=="3"){
//     update_my_bait();//更新我的鱼饵数量
//     cout << "You get 3 bait, and it costs you $ 1000" << endl;
//     print_my_bait();//打印出我包里的鱼饵数量
//     cout << "Welcome your next visit!" << endl;
//   }
//   if (input=="5"){
//     update_my_bait();//更新我的鱼饵数量
//     cout << "You get 5 bait, and it costs you $ 1500" << endl;
//     print_my_bait();//打印出我包里的鱼饵数量
//     cout << "Welcome your next visit!" << endl;
//   }

//   return 0;

// }


int buy_function()
{
  cout << "Welcome to our bait shop!" << endl;
  cout << "You can buy more bait with discount!" << endl;

  string input = "0";
  while (input!= "1"){
    cout << "Press 1 to buy some bait." << endl;
    cin >> input;
  }

  buy_bait(money, bait);

  while (true)
  {
    cout << "Wanting to buy more bait?" << endl;
    cout << "Press Y to buy more" << endl;
    cout << "Press N to back to main page" << endl;

    string input_1;
    cin >> input_1;

    if (input_1=="Y"){
      buy_bait(money,bait);
    }

    if (input_1=="N"){
      menu();
      break;
    }
  }

  return 0;
}

//============= Above are buy_function and its subfunctions ===============//


