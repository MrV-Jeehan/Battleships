#include "print.h"
using namespace std;

void game_grid_show(int game_player[][10],int game_comp[][10]){
	cout<<"Your Hit grid : "<<endl;
	show_hit(game_player);
	cout<<"Computer Hit grid : "<<endl;
	show_hit(game_comp);
}

void noob_play(int grid_comp[][10],int grid_player[][10]){
	int game_player[10][10],game_comp[10][10];
	memset(game_player,0,sizeof(game_player));
	memset(game_comp,0,sizeof(game_comp));
	unordered_map<int, vector<int> > player,comp;
	
	cout<<"Let's start the game : "<<endl;
	cout<<"Your ship grid : "<<endl;
	show_grid(grid_player);
	game_grid_show(game_player,game_comp);
	cout<<"Player make your move, enter a block's address : ";
	string str;
	cin>>str;
}
