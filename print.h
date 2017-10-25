using namespace std;
void show_grid(int grid[][10]){
	cout<<"  ";
	for(int i=0;i<10;i++){
		char ch = 'A' + i;
		cout<<" "<<ch;
	}	
	cout<<endl;
	for(int i=1;i<=10;i++){
		cout<<setw(3)<<setiosflags(ios::left)<<i;
		for(int j=0;j<10;j++){
			if(grid[i-1][j] == 0){
				cout<<"  ";
			}
			else{
				cout<<"X ";
			}
		}
		cout<<endl;
	}
}

void show_hit(int grid[][10]){
	cout<<"  ";
	for(int i=0;i<10;i++){
		char ch = 'A' + i;
		cout<<" "<<ch;
	}	
	cout<<endl;
	for(int i=1;i<=10;i++){
		cout<<setw(3)<<setiosflags(ios::left)<<i;
		for(int j=0;j<10;j++){
			if(grid[i-1][j] == 0){
				cout<<"  ";
			}
			else if(grid[i-1][j] == 1){
				cout<<"X ";
			}
			else{
				cout<<"O ";
			}
		}
		cout<<endl;
	}
}
