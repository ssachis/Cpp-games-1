#include <iostream>
#include<fstream>//read write file
#include<ctime>//seed a random function function
#include<string>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;

void draw_board(){
     cout<<"------";cout<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j   <3;j++){
            cout<<board[i][j]<<"|";
        }cout<<endl;
        cout<<"------";cout<<endl;
    }
}
void placeMarker(int slot){
    
    int row,col;
    if(slot%3==0){
        row=slot/3-1;
        col=2;
    }else{
        row=slot/3;
        col=slot%3-1;
    }
  
  board[row][col]=current_marker;
}
int winner(){
   
   for(int i=0;i<3;i++){
       if (board[i][0]==board[i][1] && board[i][1]==board[i][2]){
           return current_player;
       }
        if (board[0][i]==board[1][i] && board[2][i]==board[1][i]){
           return current_player;
       }
   }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){
           return current_player;
       }
    
     if (board[0][2]==board[1][1] && board[1][1]==board[2][0]){
           return current_player;
       }
       return 0;
}
void swap(){
    if(current_marker=='X'){
        current_marker='O';
    }else{
        current_marker='X';
    }
     if(current_player==1){
        current_player=2;
    }else{
        current_player=1;
    }
}
void tic_tac_toe(){
     draw_board();
    cout<<"player one,choose marker";
    current_player=1;
    char marker1;
    cin >>marker1;
    int win;
    current_marker=marker1;
    
    for(int i=0;i<9;i++){
        int slot;
        cout<<"Its player"<<current_player<<"'s turn ,mark your turf";
        cin>>slot;
          placeMarker(slot);
             draw_board();
          win=winner();
          if(win==1){
              cout<<"player one won!Congratulations!";
              break;
          }
            if(win==2){
                cout<<"player two won!Congratulations!";
                break;
          }
            
       
          swap();
          
    }
    if(win==0){
        cout<<"aw it is a tie";
    }
    
}
void hang_man(){
       char start{};

cout<<"lets play Hangman!"<<endl;
cout<<" __________ "<<endl;
cout<<"|     |     "<<endl;
cout<<"|     o    "<<endl;
cout<<"|    /0\\   "<<endl;
cout<<"|   / o \\  "<<endl;
cout<<"|    / \\   "<<endl;
cout<<"|   /   \\  "<<endl;
cout<<"Press a key to start"<<endl;
cin>>start;
//GAME
//set variables used throughout game


int attempts{7};
string Word;//word to be guessed
string WordList[99];//array of 100 strings
//get random word
srand(time(NULL));//creates a random seed used to get a random word from the array above
ifstream RandomWord;//file stream reads in the word
RandomWord.open("words.txt");
 for(int i=0;i<90;i++){
    RandomWord>>WordList[i];//filling the array with words from the list
    //cout<<WordList[i]<<endl; for testing
 }

int RandomNum=rand()%100;//returns a random num btw 0 to 99
Word=WordList[RandomNum];
//cout<<Word<<endl;
//RandomWord.close();
string MysteryWord(Word.length(),'*');


cout<<"The mystery word is "<<MysteryWord<<endl;

char c;

bool l=true;
bool win=false;
char arr[Word.length()]{};

while(attempts!=-1 && win==false){
        bool not_found =true;
    cout<<"guess a letter";
    cin>>c;
    for(int i=0;i<Word.length();i++){
        if(c==Word[i]){


                       MysteryWord[i]=c;

not_found=false;
                    }


                    }
                    cout<<  MysteryWord<<endl;



if(MysteryWord==Word){
    cout<<"WoW you guessed it!";
    win=true;
}
if(not_found==true){


    switch(attempts){
     case 7:
cout<<" __________ "<<endl;
cout<<"|     |     "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
    attempts--;
    break;

     case 6:
cout<<" __________ "<<endl;
cout<<"|     |     "<<endl;
cout<<"|     o     "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
    attempts--;
         break;
     case 5:
cout<<" __________ "<<endl;
cout<<"|     |     "<<endl;
cout<<"|     o     "<<endl;
cout<<"|     0     "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
 attempts--;
         break;
     case 4:
cout<<" __________ "<<endl;
cout<<"|     |     "<<endl;
cout<<"|     o     "<<endl;
cout<<"|    /0     "<<endl;
cout<<"|   /       "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
       attempts--;
         break;
     case 3:
cout<<" __________ "<<endl;
cout<<"|     |     "<<endl;
cout<<"|     o    "<<endl;
cout<<"|    /0\\   "<<endl;
cout<<"|   /   \\  "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
      attempts--;
         break;
     case 2:
cout<<" __________ "<<endl;
cout<<"|     |     "<<endl;
cout<<"|     o    "<<endl;
cout<<"|    /0\\   "<<endl;
cout<<"|   / o \\  "<<endl;
cout<<"|           "<<endl;
cout<<"|           "<<endl;
        attempts--;
         break;
     case 1:
cout<<" __________ "<<endl;
cout<<"|     |     "<<endl;
cout<<"|     o    "<<endl;
cout<<"|    /0\\   "<<endl;
cout<<"|   / o \\  "<<endl;
cout<<"|    /      "<<endl;
cout<<"|   /       "<<endl;
        attempts--;
         break;
     case 0:
cout<<" __________ "<<endl;
cout<<"|     |     "<<endl;
cout<<"|     o    "<<endl;
cout<<"|    /0\\   "<<endl;
cout<<"|   / o \\  "<<endl;
cout<<"|    / \\   "<<endl;
cout<<"|   /   \\  "<<endl;
cout<<"UH OH GAME OVER!";
         attempts=-1;
         break;
     default:
        cout<<"error";


    }


}
}
}
int main(){
    int choice;
    cout<<"heyy!lets play:), enter 1 for hangman and 2 for tic tac toe"<<endl;
    cin>>choice;
    switch(choice){
        
        case 1:
        hang_man();
        break;
        case 2:
        tic_tac_toe();
        break;
    }
}
