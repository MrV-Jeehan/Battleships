using namespace std;

void game_grid_show(int game_player[][10],int game_comp[][10]){
	cout<<"Your Hit grid : "<<endl;
	show_hit(game_player);
	cout<<"Computer Hit grid : "<<endl;
	show_hit(game_comp);
}

string ship_name(int number)
{
    if(number==1)
        return "Carrier";
    if(number==2)
        return "Battleship";
    if(number==3)
        return "Cruise";
    if(number==4)
        return "Submarine";
    if(number==5)
        return "Destroyer";
}

void play(int grid_comp[][10],int grid_player[][10],int type){
	int game_player[10][10],game_comp[10][10];
	memset(game_player,0,sizeof(game_player));
	memset(game_comp,0,sizeof(game_comp));
    int ship_comp[5]={5,4,3,3,2};
	int ship_player[5]={5,4,3,3,2};
	cout<<"Let's start the game : "<<endl;
	cout<<"Your ship grid : "<<endl;
	show_grid(grid_player);
	game_grid_show(game_player,game_comp);
	int turn =0;
	while(1)
    {
        cout<<"Player make your move, enter a block's address : ";
        string str;
        cin>>str;
        int row = str[1]-'1';
        int col = str[0]-'A';

        if(grid_comp[row][col]==0)
        {
            cout<<"You miss it\n";
            game_comp[row][col]=2;
            game_grid_show(game_player,game_comp);
        }
        else
        {
            cout<<"You Hit it\n";
            game_comp[row][col]=1;
            ship_comp[grid_comp[row][col]-1]--;
            if(ship_comp[grid_comp[row][col]-1]==0)
            {
                cout<<"Enemy's ship "<<ship_name(grid_comp[row][col])<<" is no more :)"<<endl;
            }
            cout<<"Your Hit grid : "<<endl;
            show_hit(game_player);
            cout<<"Computer Hit grid : "<<endl;
            show_hit(game_comp);
        }


        if(ship_comp[0]==0&&ship_comp[1]==0&&ship_comp[2]==0&&ship_comp[3]==0&&ship_comp[4]==0)
        {
            cout<<"Congratulations You won"<<endl;
        }
        else
        {
            cout<<"Now it's computer's turn\n";

            if(type==1)
            {
                int posi_i=rand()%10;
                int posi_j=rand()%10;

                while(game_player[posi_i][posi_j]!=0)
                {
                    posi_i=rand()%10;
                    posi_j=rand()%10;
                }

                if(grid_player[posi_i][posi_j]==0)
                {
                    cout<<"Computer miss it\n";
                    game_player[posi_i][posi_j]=2;
                    game_grid_show(game_player,game_comp);
                }
                else
                {
                    cout<<"Computer Hit it\n";
                    game_player[posi_i][posi_j]=1;
                    ship_player[grid_comp[posi_i][posi_j]-1]--;
                    if(ship_player[grid_comp[posi_i][posi_j]-1]==0)
                    {
                        cout<<"Your ship "<<ship_name(grid_player[posi_i][posi_j])<<" is no more :("<<endl;
                    }
                    game_grid_show(game_player,game_comp);
                }
                if(ship_player[0]==0&&ship_player[1]==0&&ship_player[2]==0&&ship_player[3]==0&&ship_player[4]==0)
                {
                    cout<<"You Lose"<<endl;
                    break;
                }
                else
                    continue;
            }
            else
            {
                pair<int,int > pro_arr[17];

                int k=0;
                for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        if(grid_player[i][j]!=0)
                           pro_arr[k++] = {i,j};
                    }
                }

                int posi_i=pro_arr[turn].first;
                int posi_j=pro_arr[turn++].second;

                cout<<posi_i<<" "<<posi_j<<endl;


                if(grid_player[posi_i][posi_j]==0)
                {
                    cout<<"Computer miss it\n";
                    game_player[posi_i][posi_j]=2;
                    game_grid_show(game_player,game_comp);
                }
                else
                {
                    cout<<"Computer Hit it\n";
                    game_player[posi_i][posi_j]=1;
                    ship_player[grid_comp[posi_i][posi_j]-1]--;
                    if(ship_player[grid_comp[posi_i][posi_j]-1]==0)
                    {
                        cout<<"Your ship "<<ship_name(grid_player[posi_i][posi_j])<<" is no more :("<<endl;
                    }
                    game_grid_show(game_player,game_comp);
                }
                if(ship_player[0]==0&&ship_player[1]==0&&ship_player[2]==0&&ship_player[3]==0&&ship_player[4]==0)
                {
                    cout<<"You Lose"<<endl;
                    break;
                }
                else
                    continue;

            }
            cin.get();
        }
    }
}
