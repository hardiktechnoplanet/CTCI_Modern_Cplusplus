/**
 * @brief Zero Matrix
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are
 * set to O.
 *
 * @file ZeroMatrix.cpp
 * @author Hardik Garg
 */
#include<bits/stdc++.h>

using namespace std;

void print(vector<vector<int> >& mat)
{
	size_t num_rows=mat.size();
	size_t num_cols=mat.at(0).size();
	for(size_t i=0;i<num_rows;++i)
	{
		cout<<endl;
		for(size_t j=0;j<num_cols;++j)
		{
			cout<<mat[i][j]<<"\t";
		}
	}
}

void nullifyCol(vector<vector<int> >& mat,size_t col, size_t N)
{
	for(size_t i=0;i<N;++i)
	{
		mat[i][col]=0;
	}
}

void nullifyRow(vector<vector<int> >& mat,size_t row, size_t N)
{
	for(size_t i=0;i<N;++i)
	{
		mat[row][i]=0;
	}
}
void zeroMatrix(vector<vector<int> >& mat)
{
	//test case
	if(mat.empty())
	return;
	
	size_t num_rows=mat.size();
	size_t num_cols=mat.at(0).size();
	
	//row and col vector keep record of 0 entry in the mat
	vector <bool> row (num_rows);
	vector <bool> col(num_cols);
	
	for(size_t i=0;i<num_rows;++i)
	{
		for(size_t j=0;j<num_cols;++j)
		{
			if(mat[i][j]==0)
			{
				row.at(i)=true;
				col.at(j)=true;
			}
		}
	}
	
	//make the row 0
	for(size_t i=0;i<row.size();++i){
	if(row.at(i))
	nullifyRow(mat,i,num_rows);
	}
	
	//make the col 0
	for(size_t i=0;i<col.size();++i){
	if(col.at(i))
	nullifyCol(mat,i,num_cols);
	}
}

int main(int argc, char** argv) {
	vector <vector<int> > mat;
	vector <int> mat_helper;
	
	mat_helper.push_back(1);
	mat_helper.push_back(2);
	mat_helper.push_back(3);
	mat.push_back(mat_helper);
	mat_helper.clear();
	
	mat_helper.push_back(4);
	mat_helper.push_back(0);
	mat_helper.push_back(6);
	mat.push_back(mat_helper);
	mat_helper.clear();
	
	mat_helper.push_back(7);
	mat_helper.push_back(8);
	mat_helper.push_back(9);
	mat.push_back(mat_helper);
	mat_helper.clear();
	
    zeroMatrix(mat);
    print(mat);
 
	return 0;
}

