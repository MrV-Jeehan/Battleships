using namespace std;
int front_ui(){
	system("clear");
	cout<<setw(50)<<"**WELCOME TO BATTLESHIP GAME**"<<endl;
	cout<<"Difficulty Level : "<<endl;
	cout<<"(1) Noob"<<endl;
	cout<<"(2) Pro"<<endl;
	cout<<"Set the difficulty : ";
	int diff;
	char ch;
	cin>>ch;
	while(ch!='1' && ch!='2'){
		cout<<"Bro, WTF you got 2 options only, choose appropriately."<<endl;
		cout<<"Choose again now : ";
		cin>>ch;
	}
	diff = ch - '0';
	return diff;
}
