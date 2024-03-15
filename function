//////////////////////////////////
////////////// V1 ////////////////
//////////////////////////////////
void flipRow(vector<vector<int>>& matrix,int num){
    int temp=0;
    for (int i=0;i<matrix[0].size()/2;i++){
        temp=matrix[num][i];
        matrix[num][i]=matrix[num][matrix[0].size()-1-i];
        matrix[num][matrix[0].size()-1-i]=temp;
    }
}

void flipColumn(vector<vector<int>>& matrix,int num){
    int temp=0;
    for (int i=0;i<matrix[0].size()/2;i++){
        temp=matrix[i][num];
        matrix[i][num]=matrix[matrix[0].size()-1-i][num];
        matrix[matrix[0].size()-1-i][num]=temp;
    }
}

int flippingMatrix(vector<vector<int>> matrix) { // calc sum and flip the matrix if it was passed by address
    int dimenzija=matrix[0].size();
    int dmin1=dimenzija-1;    
    
        for(int i=0;i<dimenzija/2;i++)
            for(int j=0;j<dimenzija/2;j++){
                
                if( matrix[i][j]>=matrix[dmin1-i][dmin1-j] && matrix[i][j]>=matrix[i][dmin1-j] &&  matrix[i][j]>=matrix[dmin1-i][j] ){//do nothing
                }               
                else if ( matrix[dmin1-i][dmin1-j]>matrix[i][j] && matrix[dmin1-i][dmin1-j]>matrix[i][dmin1-j] && matrix[dmin1-i][dmin1-j]>matrix[dmin1-i][j] ){
                    flipColumn(matrix,dmin1-j);
                    
                    for(int k=0;k<dimenzija/2;k++){
                        if(matrix[dimenzija-1-(dmin1-i)][k]>matrix[dimenzija-1-(dmin1-i)][dimenzija-1-k])
                            flipColumn(matrix,k);
                        
                    }
                    
                    flipRow(matrix,dimenzija-1-(dmin1-i));
                    
                    for(int k=0;k<dimenzija/2;k++){
                        if(matrix[dmin1-i][k]>matrix[dimenzija-1-(dmin1-i)][k])
                            flipColumn(matrix,k);
                    }
                    
                    
                }
                else if( matrix[i][dmin1-j]>=matrix[dmin1-i][dmin1-j] &&  matrix[i][dmin1-j]>=matrix[dmin1-i][j] && matrix[i][dmin1-j]>matrix[i][j] ) {
                    for(int k=0;k<dimenzija/2;k++){
                        if(matrix[dimenzija-1-(dmin1-i)][k]>matrix[dimenzija-1-(dmin1-i)][dimenzija-1-k])
                            flipColumn(matrix,k);
                        
                    }
                    
                    flipRow(matrix,dimenzija-1-(dmin1-i));
                    
                    for(int k=0;k<dimenzija/2;k++){
                        if(matrix[dmin1-i][k]>matrix[dimenzija-1-(dmin1-i)][k])
                            flipColumn(matrix,k);
                    }
                }
                else if( matrix[dmin1-i][j]>=matrix[dmin1-i][dmin1-j] && matrix[dmin1-i][j]>matrix[i][dmin1-j] && matrix[dmin1-i][j]>matrix[i][j] ) {
                    for(int k=0;k<dimenzija/2;k++){
                        if(matrix[k][j]>matrix[dmin1-k][j])
                            flipRow(matrix,k);
                            
                    }
                    
                    flipColumn(matrix,j);
                    
                    for(int k=0;k<dimenzija/2;k++){
                        if(matrix[k][dmin1-j]>matrix[k][j])
                            flipRow(matrix,k);
                            
                    }
                    
                    
                }
                        
                        
            }                      
    
    unsigned long long int zbir=0;
    for(int i=0;i<dimenzija/2;i++)
        for(int j=0;j<dimenzija/2;j++){
            zbir+=matrix[i][j];
        }
    
    return zbir;
    
}

//////////////////////////////////
////////////// V2 ////////////////
//////////////////////////////////
int flippingMatrix(vector<vector<int>> matrix) { // calc sum without actually flipping anything
	int dimenzija=matrix[0].size();
    int dmin1=dimenzija-1;
	int sum=0;
	
	for(int i=0;i<dimenzija/2;i++)
		for(int j=0;j<dimenzija/2;j++){
			if( matrix[i][j]>=matrix[dmin1-i][dmin1-j] && matrix[i][j]>=matrix[i][dmin1-j] &&  matrix[i][j]>=matrix[dmin1-i][j] ) sum+=matrix[i][j];
			else if ( matrix[dmin1-i][dmin1-j]>matrix[i][j] && matrix[dmin1-i][dmin1-j]>matrix[i][dmin1-j] && matrix[dmin1-i][dmin1-j]>matrix[dmin1-i][j] ) sum+=matrix[dmin1-i][dmin1-j];
			else if( matrix[i][dmin1-j]>=matrix[dmin1-i][dmin1-j] &&  matrix[i][dmin1-j]>=matrix[dmin1-i][j] && matrix[i][dmin1-j]>matrix[i][j] ) sum+=matrix[i][dmin1-j];
			else if( matrix[dmin1-i][j]>=matrix[dmin1-i][dmin1-j] && matrix[dmin1-i][j]>matrix[i][dmin1-j] && matrix[dmin1-i][j]>matrix[i][j] ) sum+=matrix[dmin1-i][j];
		}
		
	return sum;
}
