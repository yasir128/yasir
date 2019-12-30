#include<iostream>
#include <cstdlib>           // for random
#include <ctime>
using namespace std;
int main(){
	
	cout<<"\n\nGame Look in matrix \n\n";
cout<<"|-----|-----|-----|-----|\n\n";
cout<<"  0,0   0,1   0,2   0,3\n";
cout<<"|-----|-----|-----|-----|\n\n";
cout<<"  1,0   1,1   1,2   1,3\n";                             
cout<<"|-----|-----|-----|-----|";  cout<<" \tIn this game Row,Colum sequence indication\n\n";
cout<<"  2,0   2,1   3,2   4,3\n";
cout<<"|-----|-----|-----|-----|\n\n";
cout<<"  3,0   3,1   3,2   3,3\n";
cout<<"|-----|-----|-----|-----|\n\n";
cout<<"\n\nGame Static Look \n\n";
cout<<"|-----|-----|-----|-----|\n\n";
cout<<"  0,0   0,1  Breeze Pit\n";
cout<<"|-----|-----|-----|-----|\n\n";
cout<<"  1,0   1,1   Pit  Breeze\n";                             
cout<<"|-----|-----|-----|-----|";  cout<<" \tIn this game Row,Colum sequence indication\n\n";
cout<<"  2,0   2,1  Breeze  4,3\n";
cout<<"|-----|-----|-----|-----|\n\n";
cout<<" Player Breeze Pit Breeze\n";
cout<<"|-----|-----|-----|-----|\n\n";

         
         // MultiDimensional array initialization
        int grid_Table[4][4]={{0,1,2,3},{0,1,2,3},{0,1,2,3},{0,1,2,3} };
        int Gold; int breeze; int Stench; int pit; int wumpus[4][4]; int player; int check;
                   // player initial value 
       cout<<"\n Input 'yes' 'to erase this phase and go to the game :";
      string yes;
        cin>>yes;
       if("yes"||"YES"||"Yes")
        {
		system("cls");
		
		cout<<"\n \nPlayer Initial Value : 3rd Row and 0th Colume";
	
		 //set wumpus position  	
 srand((unsigned) time(0));
  int wumpus_row,wumpus_col;
  for (int index_row = 0; index_row < 1;  index_row++) {
  	  wumpus_row = (rand() % 3) + 0;
  } 
    for (int index_col = 0; index_col < 1; index_col++) {
  	  wumpus_col = (rand() % 3) + 0;
  }
  wumpus[wumpus_row][wumpus_col]= grid_Table[wumpus_row][wumpus_col];
 
		cout<<"\n \nWumpus Random Position "<<"Row: "<<wumpus_row<<", Col: "<<wumpus_col;
//for pit (static) 		

	 grid_Table[0][3]=pit;	           //   pit exisit in 0 row and 3rd column
	 grid_Table[1][2]=pit;	           //   pit exisit in 1 row and 2nd column
	 grid_Table[3][2]=pit;             //   pit exisit in 3 row and 2nd column
	 
//for breeze (static)
breeze=grid_Table[0][2];               //   breeze exisit in 0 row and 2nd column    
breeze=grid_Table[1][3];               //   breeze exisit in 1 row and 3rd column    
breeze=grid_Table[1][1];               //   breeze exisit in 1 row and 1st column
breeze=grid_Table[2][2];               //   breeze exisit in 2 row and 2nd column
breeze=grid_Table[3][1];               //   breeze exisit in 3 row and 1st column
breeze=grid_Table[3][3];               //   breeze exisit in 3 row and 3rd column
// for stench place 
for (int stench=0;stench<4;stench++){               
	if(wumpus_row==1){             // if row 1 and column 0 have wumpus then this statement call 
		if(wumpus_col==0){          
	
	 Stench=grid_Table[0][0];
	 Stench=grid_Table[2][0];
	 Stench=grid_Table[1][1];

			}	}
	else if(wumpus_row==0){       // if row 0 and column 0 have wumpus then this statement call 
	if(wumpus_col==0){
	 grid_Table[0][1]=Stench;
	 grid_Table[1][0]=Stench;
	}  
	}
// ----------left side complete
	else if(wumpus_row==0){             // if row 0 and column 1 have wumpus then this statement call 
		if(wumpus_col==1){          
	
	 grid_Table[0][0]=Stench;
	 grid_Table[1][1]=Stench;
	 grid_Table[0][2]=Stench;

			}	}
	else if(wumpus_row==0){       // if row 0 and column 2 have wumpus then this statement call 
	if(wumpus_col==2){
	 grid_Table[0][1]=Stench;
	 grid_Table[1][2]=Stench;


	}  
	}
	// ----------upper side complete

	else if(wumpus_row==1){       // if row 1 and column 3 have wumpus then this statement call 
	if(wumpus_col==3){
	grid_Table[2][3]=Stench;

	}  
	}
	else if(wumpus_row==2){       // if row 2 and column 3 have wumpus then this statement call 
	if(wumpus_col==3){
	 grid_Table[1][3]=Stench;
	 grid_Table[2][2]=Stench;
	grid_Table[3][3]=Stench;

	}  
	}
		// ----------right side complete
	else if(wumpus_row==3){       // if row 3 and column 3 have wumpus then this statement call 
	if(wumpus_col==3){
	 grid_Table[2][3]=Stench;
	}  
	}
	// ----------down side complete
	else if(wumpus_row==2){       // if row 2 and column 2 have wumpus then this statement call 
	if(wumpus_col==2){
	 grid_Table[2][1]=Stench;
	 grid_Table[2][3]=Stench;
	}  
	}
	else if(wumpus_row==1){       // if row 1 and column 1 have wumpus then this statement call 
	if(wumpus_col==1){
	 grid_Table[0][1]=Stench;
	 grid_Table[1][0]=Stench;
	 grid_Table[2][1]=Stench;
	}  
	}
	else if(wumpus_row==2){       // if row 2 and column 1 have wumpus then this statement call 
	if(wumpus_col==1){
	 grid_Table[2][0]=Stench;
	 grid_Table[1][1]=Stench;
	 grid_Table[3][1]=Stench;
	 grid_Table[2][2]=Stench;
	}  
	}
	// ----------center side complete
	
}
//working on Gold 
 srand((unsigned) time(0));                                     //set position of Gold
  int gold_row,gold_col;
  Again:
  for (int index_row = 0; index_row < 1;  index_row++) {
  	  gold_row = (rand() % 3) + 0;
  } 
for (int index_row = 0; index_row < 1;  index_row++) {
  	  gold_col = (rand() % 3) + 0;
  } 	
 // if condition to skip position of gold from location of pit
  if(gold_row==0 && gold_col==3)         //if pit 
  {
	  goto Again;                              
  }
    else if(gold_row==1 && gold_col==2)   //if pit 
  {
  	goto Again;
  }
    else if(gold_row==3 &&gold_col==2)   //if pit 
  {
  	goto Again;
  }
  else if (gold_row==wumpus_row && gold_col==wumpus_col ){               // if wumps position equal to gold position 
  	goto Again;
  }
    else if (gold_row==3 && gold_col==0 ){               // This is player value so gold is to here
  	goto Again;
  }
  else{                                                       // Here set Gold Position
  	 Gold=grid_Table[gold_row][gold_col];                        
  }
  //Player Who Play the Game 
  while(player!=Gold)     //check
  { 
  int player_row=3;
  int player_col=0;
  player=grid_Table[player_row][player_col];         // default value of player
 player_row--;                         //row -1       and  player move to 2rd row 0th column
 if(player==Stench )                     //if stench occure
 {
 	player_row++;                      // player came to his previous place   3rd row and 0th column
 	player_col++;                      //now col 1    and player move to 3rd row 1st column
 	if(player==breeze)                  // if breeze occure
 	{
 	player_col--;	                  // again player came to his place back   3rd row and 0th colum
	 }
	 player_row=player_row+2; 
	 player_col=player_col+1;

	 if(player!=Stench &&player!=breeze)      //if no breeze no stench occur then move upward
	 {
	 	 player_row--;                       // player is on 2nd row and 1st column 
	 
	   player==Gold;        // Player find a gold
	 }
 }
 else if(player==breeze){                                 //if breeze occure
 	player_row++;
 	player_col++;
 		if(player==Stench)
 		{
 			player_col--;	
		 }
		  player_row=player_row+2; 
	 player_col=player_col+1;

	 if(player!=Stench &&player!=breeze)      //if no breeze no stench occur then move upward
	 {
	 	 player_row--;                       // player is on 2nd row and 1st column 
	 }
	   player==Gold;        // Player find a gold
 }
 else if(player!=Stench){
 	player_col++;                          // player is in 2nd  row 1st column
 	if(player!=Stench)                    //if again no stench occure
 	{
 		player_col++;  	                 // player is in 2nd  row 2nd column
 		if(player==Stench&& player==breeze)              // if stench occure with breeze 
	 {
	 	player_col--;                      // player is in 2nd  row 1st column
	 	player_row++;                      // player find Gold 
	 }
	 }
	player_row--;                        // player is in 1st  row 0th column
   player==Gold;        // Player find a gold
 }
                          
 	else if(player==Stench)
 	{
 	player_row++;  	                        // player is in 2nd row 0th column
 	player_col++;
 	 if(player==breeze)
 	 {
 	 player_col--;	                     // 2nd row 1st column
	 player_row++;                       // 3rd row 0th column
	 player_col++;                       // 3rd row 1st column  
	  if(player==breeze){                // if again breeze occure
	  player_col--;                      // 3rd row 0th column
	 
	  player_row=player_row-2;          
	  player_col++;                      // 1st row 1st column
	  } 
	  }
	    player==Gold;        // Player find a gold
	 }
	else if(player==breeze)                 // player is in 1st  row 0th column
 	{
 	player_row++;  	                        
 	player_col++;
 	 if(player==Stench)
 	 {
 	 player_col--;	                     // 2nd row 0st column
	 player_row++;                       // 3rd row 0th column
	 player_col++;                       //3rd row 1st column
	 if(player ==breeze)                 // if again breeze occure
	 {
    player_col--;                       // 3rd row 0th column
    player_row=player_row-2;            //1st row 0th column
     player_col++;                     //1st row 1st column
	   player=Gold;        // Player find a gold
	 }
	  } 
	player_row--;            //it mean again - row and now the player is in 1st row and 0th column  
	 
	 }

    else if(player!=Stench )                          //if onother upper side have no stench or breeze	 
 	{
 	player_row--; 	                       // oth row 0th column
 	if(player==Stench)
	 {
	 	player_row--;             // 1st row and 0th column
	 	player_col++;             //1st row and 1st column
	 	  player=Gold;        // Player find a gold

	if(player==Stench&&player==breeze)
	{
	player_col--;                //1th row  0th column
	player_row++;                 //2nd row  0th column
	player_col++;                 //2nd row  1st column
    player=Gold;                 // Player find a gold

	}
	{
		
	}
	 }
	 }
	 

 }
  	

  }

		} //end of if satement for yes condition
        
        

