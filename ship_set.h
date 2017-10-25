void set_ship(int grid[][10],int pos_i,int pos_j,int v,int size,int ship){
	if(v==0){
		for(int i=pos_j;i<pos_j+size;i++){
			grid[pos_i][i] = ship;
		}
	}
	else{
		for(int i=pos_i;i<pos_i+size;i++){
			grid[i][pos_j] = ship;
		}
	}
}
