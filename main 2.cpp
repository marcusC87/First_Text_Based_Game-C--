#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>
#include <unistd.h>

using namespace std;

int main() {

//Welcome the player
cout <<"Welcome to our adventure, what should I call you?"<<endl;

string player1Name ;

cin >> player1Name ;

cout << "I hope you came ready to get your adventure on, " << player1Name << "." << endl;

// Variables

int health = 10 ;

int goblinHealth = 8 ;

int attackPower ;

//setting the battle iterator 
int battleCounter = 0 ; 

char battleChoice;

int weaponChoice;

string weaponChoicestring ;

int attackOne ; 

int attackTwo ;

int attackThree ;

int attackFour ; 

int goblinAttackOne ;

int goblinAttackTwo ;

int goblinAttackThree ;

int goblinAttackFour ;

int blockPowerOne ;

int blockPowerTwo ;

int blockPowerThree ;

int blockPowerFour ;

int blockPower ;

//Seeding the random number generator
srand(time(0)) ;

cout << "The road ahead is treacherous." <<endl;

cout<<"As you turn the corner of the trail, you hear some rustling in the bushes...."<<endl;

//The do while loop for the user's choice to go into battle
do{

  cout<<"press 'y' to investigate or 'n' to run away:"<<endl;

  cin>> battleChoice ;

  if (battleChoice == 'y'){
    cout << player1Name << ", you are truly a brave soul."<<endl;
    cout<< "As you investigate the area, you hear a loud shriek, in front of you as a goblin jumps into your path!!!" <<endl;
    }

  else if(battleChoice == 'n'){
    cout<<"Wow, not much of an adventurer are we, "<<player1Name<<"?"<< endl;
    return 0 ;
    }

  else{
    cout<< player1Name<<", I didn't understand what you said, why don't ya give it another shot." << endl ;
    }
} while ( battleChoice != 'y'); 
      // using the logical not operator

  cout<< "The goblin is licking his lips, I hope"<< endl;
  cout<<"you don't become his next meal!" <<endl;
  cout<<"You remember that in your satchel you have"<< endl;
  cout<<"three different weapons you can defend yourself with"<<endl;

//allows the player to choose a weapon
  cout<<player1Name<<", choose from the following:"<<endl;
  cout<<"[1] A boomerrang."<< endl;
  cout<<"[2] A stick."<< endl;
  cout<<"[3] An automatic machine gun."<< endl;

//in this loop I use a switch statement to choose the weapon
do {
  cout<<"Which will you choose, '1', '2', or '3'."<<endl;
  cin>> weaponChoice;

// inside the switch code block I changed an int to a string
//Not sure if I used the correct technique please advise
  switch(weaponChoice){
    case 1: cout<<"You chose the bommerang!"<<endl;
            cout<<"Very curious choice... we shall see how it serves you."<< endl;
            weaponChoice = 1 ;
            weaponChoicestring = weaponChoice;
            weaponChoicestring = "boomerrang" ;
            break;

    case 2: cout<<"You chose the stick."<<endl;
            cout<<"Seriously, the stick, wow, OK."<<endl;
            weaponChoice = 2 ;
            weaponChoicestring = weaponChoice;
            weaponChoicestring = "stick" ;
            break;

    case 3: cout<<"You chose the automatic machine gun!"<<endl;
            cout<<"I knew you were smart enough to not choose the stick."<<endl;
            weaponChoice = 3 ;
            weaponChoicestring = weaponChoice;
            weaponChoicestring = "automatic machine gun" ;
            break;
  }
} while (weaponChoice > 3 || weaponChoice < 1);
//testing an or statement I had trouble getting the !=  
// operator to work so I ended up using greater than and less than

cout<<player1Name<<", this is the moment of truth..."<<endl;

cout<<"Time to put that "<<weaponChoicestring<<" to the test"<<endl;

cout<< "The goblin rushes at you..." <<endl;
// Battle loop
do{
      //player attack one
      battleCounter ++ ;
      cout<<"You attack with your "<<weaponChoicestring<< "."<< endl;
      attackOne = rand() % 4 ;
      cout<<"Your attack did " << attackOne 
      <<" damage."<< endl;
      goblinHealth -= attackOne ;
    if (goblinHealth < 0){
        cout<<"The goblin is dead."<<endl;
       break ;
      }
    else{
      // Goblin attack one
      cout<<"The goblin's health is now " << goblinHealth<<"."<<endl ;
      cout<< "The goblin attacks with roundhouse attack."<< endl;
      goblinAttackOne = rand() % 4 ;
      blockPowerOne = rand() %  4 ;
      health -= (goblinAttackOne - blockPowerOne) ;
      cout<< "Your health is now "<< health <<endl;
      }

    if(health < 1 || battleCounter > 4 ) break;
    else{
      //player attack two
      battleCounter ++ ;
      cout<<"You attack a second time."<<endl ;
      attackTwo = rand() % 4 ;
      cout<< "You did "<<attackTwo<<" damage."<<endl;
      goblinHealth -= attackTwo ; 
      cout<<"The goblin's health is now " << goblinHealth << "." <<endl;
      }

    if(goblinHealth < 1) break ;
    else {
      // Goblin attack two
      cout<<"Here comes that roundhouse again..."<<endl;
      goblinAttackTwo = rand() % 4 ;
      blockPowerTwo = rand() % 4 ;
      health = goblinAttackTwo - blockPowerTwo ;
      cout<<"Your health is now "<< health<<"." <<endl;
    }

    if (health < 1 || battleCounter > 4) break ;
    else
    {
      // player attack three
      battleCounter ++ ;
      cout<<"Round three!"<<endl;
      cout<<"You attack." << endl;
      attackThree = rand() % 4 ;
      goblinHealth -= attackThree ;
      cout<<"Your attack did "<< attackThree<< " damage and the goblin has "<< goblinHealth << " health left."<< endl;
    }
    if(goblinHealth < 1) break;
    else {

      cout<<"Goblin attacks again!"<< endl;
      goblinAttackThree = rand() % 4 ;
      blockPowerThree = rand() % 4 ;
      health -= goblinAttackThree - blockPowerThree ;
      cout<< "Your health is now "<<health<<"." <<endl;
    }

      if(health < 1 || battleCounter >= 4) break ;

      else{
        battleCounter ++ ;
        cout<<"It is the final round"<<endl;
        cout<<"Attack for the final time"<< endl;
        attackFour = rand() % 4 ;
        cout<<"You did "<<attackFour<<" damage."<<endl;
        cout<<"The goblin's health is now "<<goblinHealth<<"." <<endl;

      if(goblinHealth < 1) break ;

      else{

        cout<<"The goblin is making one last attack."<<endl;
        goblinAttackFour = rand() % 4 ;
        blockPowerFour = rand() % 4 ;
        health -= goblinAttackFour - blockPowerFour ; 
        cout<<"Your health is now "<<health<< "."<<endl;
        }
      if(health < 1 || battleCounter >= 4) break ;
      }
      

  } while (health > 0 || goblinHealth > 0 || battleCounter <= 4);

  if(health > goblinHealth){
    cout<<"Congrats, on your victory, "<<player1Name<<"."<<endl;
  }

  else{
    cout<<"Better luck next time, "<<player1Name<<"."<<endl;
  }
  
  
  return 0 ;
  

}

