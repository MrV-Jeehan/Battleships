#include "ship_set.h"
#include "print.h"
using namespace std;

void get_grid_comp(int grid[][10]){
	int n=10,size;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			grid[i][j] = 0;
		}
	}
	for(int i=1;i<=5;i++){
		//Setting ships
		switch(i){
			case 1: 		//Carrier ship
				size = 5;
				break;
			case 2:		//Battleship
				size = 4;
				break;
			case 5:		//Destroyer ship
				size = 2;
				break;
			default: 		//Cruiser and Submarine
				size = 3;
		}
		int v= rand() % 2;		//Setting whether to place ship horizontally or vertically
		int pos_i,pos_j;
		if(v==0){
			bool overlap=false;
			do{
				overlap = false;
				 pos_i = rand() % 10;		//Setting position in case of horizontal placing
		 		 pos_j = rand() % (10-size);
		 		 for(int i=0;i<pos_j+size;i++){
		 		 	if(grid[pos_i][i] == 1){
		 		 		overlap = true;
		 		 		break;
		 		 	}
		 		 }
			}
			while(overlap); 	 	
		}
		else{
			bool overlap=false;
			do{
				overlap = false;
				 pos_i = rand() % (10-size);		//Setting position in case of vertical placing
		 		 pos_j = rand() % (10);
		 		 for(int i=0;i<pos_i+size;i++){
		 		 	if(grid[i][pos_j] == 1){
		 		 		overlap = true;
		 		 		break;
		 		 	}
		 		 }
			}
			while(overlap); 
		}
		set_ship(grid,pos_i,pos_j,v,size,i);
	}
}	

void get_grid_player(int grid[][10]){
	int n=10;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			grid[i][j] = 0;
		}
	}
	cout<<"Enter 1 to set ships randomly, 2 to set ships manually : ";
	int choice;
	cin>>choice;
	if(choice == 1){
		get_grid_comp(grid);
		cout<<"Ships placed, your final grid : "<<endl;
		show_grid(grid);
	}
	else{
		cout<<"Rules to place the ships :"<<endl;
		cout<<"1) Ship can be placed continuoslly."<<endl;
		cout<<"2) No two ships can overlap."<<endl;
		cout<<"3) Only starting block and vertical or horizontal position is to be entered."<<endl;
		cout<<endl<<"List of Ships:"<<endl;
		cout<<"1- Carrier (Size: 5)"<<endl;
		cout<<"2- Battleship (Size: 4)"<<endl;
		cout<<"3- Cruise (Size: 3)"<<endl;
		cout<<"4- Submarine (Size: 3)"<<endl;
		cout<<"5- Destroyer (Size: 2)"<<endl;
		cout<<"Please start to enter now : "<<endl;
		for(int i=1;i<=5;i++){
			show_grid(grid);
			int size;
			string ship;		
			switch(i){
				case 1:
					ship = "Carrier";
					size = 5;
					break;
				case 2:
					ship = "Battleship";
					size = 4;
					break;
				case 3:
					ship = "Cruise";
					size = 3;
					break;
				case 4:
					ship = "Submarine";
					size = 3;
					break;
				case 5:
					ship = "Destroyer";
					size = 2;
					break;
			}
			cout<<"Enter the position of "<<ship<<" of size "<<size<<" : ";
			string pos;
			cin>>pos;
			cout<<"Want to place it vertically? 1-Yes,2-No : ";
			int ver;
			cin>>ver;
			bool v = false;
			if(ver==1){
				v=true;
			}
			set_ship(grid,pos[1]-'1',pos[0]-'A',v,size,i);
			system("clear");
		}
		cout<<"Final Grid : "<<endl;
		show_grid(grid);
	}
}

