#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main() {
  //main variables
  string userInput;
  bool isBin=true;
  bool quit=false;
  char hex1;
  char hex2;
  int counter=0;
  while(toupper(userInput[0])!='Q'){
    counter=0;
//user input and verification done in as a do-while loop
    do{
      cout<<"Enter an 8-bit binary number ('q' to quit) : ";
      cin>>userInput;
      cout<<endl;
      isBin=true;
      if(toupper(userInput[0])=='Q'){
        isBin=true;
        quit=true;
        break;
      }
      //checks for correct size
      if((userInput.size())!=8){
        cout<<"Error: Not 8 digits"<<endl;
        isBin=false;
        
      }
      //checks for 1s and 0s
      for(int i=0;i<userInput.size();i++){
        if(userInput[i]!='1'&&userInput[i]!='0'){
          cout<<"Error: Only 1's and 0's permitted"<<endl;
          isBin=false;
        }
      }
      cout<<endl;
      }while(isBin==false);
      if(quit==true){
        cout<<"Ending Program...";
        break;
      }
    
//converts the right hand byte into its decimal value.
  for(int i=7; i>=4;i--){
    if(userInput[i]=='1'){
      counter=counter+pow(2,7-i);
    }

  }
//under 9, decimal and hexadecimal are the same, however I am converting to ascii here as I am using a char variable. 
  if(counter<=9){
    hex1=48+counter;
  }
//all other values(over 9) are represented as A-F rather than 10-15, so I used the same method as above to adjust the char value into the ascii alphabet
  else{
    hex1=55+counter;
  }

  //process from above is repeated for the left hand byte of the binary number
  counter = 0;
  for(int i = 3; i >= 0; i--){
    if(userInput[i] == '1'){
      counter=counter+(pow(2,3-i));
    }
  }

  if(counter<=9){
    hex2=48+counter;
  }

  else{
    hex2=55+counter;
  }

  cout<<"The binary number "<< userInput <<" is "<<hex2<<hex1<<" in hexadecimal."<<endl;
  }
}
