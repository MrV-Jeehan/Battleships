#include<bits/stdc++.h>
#include "front.h"
#include "grid_make.h"
#include "noob_play.h"
#include "pro_play.h"
using namespace std;

int main(){
	int diff;
	diff = front_ui();
	int grid_comp[10][10];
	get_grid_comp(grid_comp);
	int grid_player[10][10];
	get_grid_player(grid_player);
	cout<<"Now that grid is set, Let's start : "<<endl;
	if(diff == 1){
		noob_play(grid_comp,grid_player);	
	}
	else{
		pro_play(grid_comp,grid_player);
	}
	cout<<setw(50)<<"Thank You for playing Battleships"<<endl;
	return 0;
}
