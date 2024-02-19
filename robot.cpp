#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{ 
   //-|----------------------------------------------------------------------
   //-| Declare variables
   //-|----------------------------------------------------------------------
   bool Activated = false; //starting robot in off position
   
   int
   x, y,               //current position
   xmax, ymax,         //max values
   x_start, y_start,    //starting position
   NumMoves,          //total number of moves
   BadMoves,          //number of bad moves
   Denied,           //number of denied moves
   NumL, NumR, NumU, NumD, //number of up moves in each direction
   activemoves,           //moves that resulted in the robot moving
   battery;              //amount of power the robot has
    
   string robotName;  //name of robot

   char d;           //move direction(LRUD)

   //-|----------------------------------------------------------------------
   //-| Print the copyright notice to screen.
   //-|----------------------------------------------------------------------
   cout << endl << "ROBOT004 (c) 2023, montsJ210" << endl << endl; 

   //-|----------------------------------------------------------------------
   //-| 1.) Enter name of robot from keyboard.
   //-|----------------------------------------------------------------------
   cout << endl << "Enter robot name: ";
   cin >> robotName;

   //-|----------------------------------------------------------------------
   //-| 2.) Enter the max X and Y values from keyboard.
   //-|----------------------------------------------------------------------
   cout << endl << "Enter max X and max Y: ";
   cin >> xmax >> ymax;

   //-|----------------------------------------------------------------------
   //-| 3.) Display the max and minimum values of the grid.
   //-|----------------------------------------------------------------------
   cout << endl << "Robot " << robotName <<" ON GRID ( 0, 0 ) to ( " << xmax <<", " <<ymax<<").";

   //-|----------------------------------------------------------------------
   //-| 4.) Initializing Counter With Zero
   //-|----------------------------------------------------------------------
   NumL = 0;
   NumR = 0;
   NumU = 0;
   NumD = 0;
   BadMoves = 0;
   NumMoves = 0;
   Denied = 0;
   activemoves = 0;

   //-|----------------------------------------------------------------------
   //-| 5.) Prompt for commmand from keyboard and do action accordingly
   //-|----------------------------------------------------------------------
   cout <<endl<< endl << "Enter command [S LRUD W P T]: ";
   do
   {
    cin >> d;

   switch(d)
   {
     case 'S':
     {
      Activated = true;
      cout << endl << "Enter power level: ";
      cin >> battery;
      cout << endl << "Enter start position: X and Y: ";
      cin>> x_start >> y_start;
      if(x_start<0 || y_start<0)
      {
       x_start=0;
       y_start=0;
      }
      x = x_start;
      y = y_start;
      break;
     }
     
     case 'P':
      cout << endl <<"Robot "<< robotName << " POWER LEVEL = "<< battery;
      break;
   
     case 'W':
      cout <<endl<<"Robot " <<robotName << "AT (" << x <<", " <<y<<")";
      break;
     

     case 'T':
      cout << endl << "Robot "<< robotName<< " TERMINATED at ("<<x <<", "<<y<<"), POWER LEVEL = "<<battery <<endl;
      Activated = false;
      break;
     
     case 'R':
     if(x < xmax)
     {
      NumR++;
      x++;
      battery--;
      activemoves++;
      break;
     }
     else
     {
     cout << endl << d << " MOVE DENIED ..." << endl;
     battery-=2;
     Denied++;
     break;
     }

     case 'L':
     if(x > 0)
     {
      NumL++;
      x--;
      battery--;
      activemoves++;
      break;
     }
     else
     {
     cout << endl << d << " MOVE DENIED ..." << endl;
     battery -=2;
     Denied++;
     break;
     }

     case 'U':
     if(y < ymax)
     {
      NumU++;
      y++;
      battery--;
      activemoves++;
      break;
     }
     else
     {
     cout << endl << d << " MOVE DENIED ..." << endl;
     battery -=2;
     Denied++;
     break;
     }

     case 'D':
     if(y > 0)
     {
      NumD++;
      y--;
      battery--;
      activemoves++;
      break;
     }
     else
     {
     cout << endl << d << " MOVE DENIED ..." << endl;
     battery -=2;
     Denied++;
     break;
     }
     
     default:
     cout << endl<< "BAD MOVE " << "'" <<d <<"'"<< endl;
     BadMoves++;
     break;
    }}while(Activated && d != 'T' && battery >0);

   //-|----------------------------------------------------------------------
   //-|6.) Display the number of times each type of move occured. 
   //-|----------------------------------------------------------------------
   cout << endl <<"#BAD_COMMANDS = " << BadMoves << endl ;
   cout << endl <<"#LEFT MOVES = " << NumL <<endl;
   cout << endl <<"#RIGHT MOVES = " << NumR <<endl;
   cout << endl <<"#UP MOVES = " << NumU << endl;
   cout << endl <<"#DOWN MOVES = " << NumD <<endl;
   cout << endl <<"#DENIED MOVES = " << Denied <<endl;
   cout << endl << activemoves << " SUCCESSFUL MOVES" <<endl;    

   //-|----------------------------------------------------------------------
   //-| 7.) Print the copyright notice to screen.
   //-|----------------------------------------------------------------------
   cout << endl  << endl<< "ROBOT003 (c) 2024, montsJ210" << endl << endl<< endl; 
  
   return 0;
   
}//main
