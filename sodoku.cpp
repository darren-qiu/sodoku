#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "sodoku.h"

using namespace std;

void SDK::init_from_file()
{
	ifstream fin("1.sdk");
	int val;
	string str;
	int index = 0;
	while(!fin.eof())
	{
		getline(fin,str);
		stringstream strin(str);
		//cout.width(27);
		while(strin >> val)
		{
			set_cell(index++,val);
			//cout << val << " ";
		}
		//cout << endl;
	}
	fin.close();
}

void SDK::disp_cells()
{
	int i=0;
	int val;
	for(;i<81;i++)
	{
		if(i%9 == 0)
		  printf("\n");
		val = cell[i]->getValue();
		printf("%2d ", val );
	}
	printf("\n\n");
}

int SDK::write(int row, int col, int val)
{
	if(0 != _ck.valid(val))
	  return -1;
	if(row<0 || row>9 || col<0 || col>9 )
	  return -2;

	if(0 != check(row,col,val))
	  return -3;
	
	cell[ getcell_index(row,col) ]->setValue(val);
#ifdef DEBUG
	printf("cell[%d]->setValue(%d)\n", getcell_index(row,col), val);
#endif
	return 0;
}

int SDK::gameover()
{
	int i=0;
	for(;i<81;i++)
	{
		if(-1 == cell[i]->getValue())
		  return -1;
	}
	return 0;
}

void SDK::set_cell(int index, int val)
{
	int row = index/9;
	int col = index%9;
	int block = 3*(row/3)+col/3;
	int flag = (0==_ck.valid(val))?0:-1;
	
	cell[index]->setRow(row);
	cell[index]->setCol(col);
	cell[index]->setBlock(block);
	cell[index]->setFlag(flag);
	cell[index]->setValue(val);
}

int SDK::check(int r, int c, int val)
{
	if(0 != check_row(r,val))
	  return -1;
	if(0 != check_col(c,val))
	  return -2;
	if(0 != check_block(r,c,val))
	  return -3;
	return 0;
}

int SDK::check_row(int row,int val)
{
	//cout << "check_row" << endl;
	getcellsofrow(row);
	return _ck.todo(val);
}

int SDK::check_col(int col,int val)
{
	//cout << "check_col" << endl;
	getcellsofcol(col);
	return _ck.todo(val);
}

int SDK::check_block(int row, int col, int val)
{
	//cout << "check_block" << endl;
	getcellsofblock(row,col);
	return _ck.todo(val);
}

int SDK::getcell_index(int row, int col)
{
	return 9*row+col;
}

int SDK::getcellsofrow(int row)
{
	_ck.clear();
	for(unsigned int i=0; i<9; i++)
	{
		_ck.add( (this->cell[ 9*row+i ])->getValue() );
	}
	return 0;
}

int SDK::getcellsofcol(int col)
{
	_ck.clear();
	for(unsigned int i=0; i<9; i++)
	{
		_ck.add( (this->cell[ 9*i+col ])->getValue() );
	}
	return 0;
}

int SDK::getcellsofblock(int row, int col)
{
	//cout << "getcellsofblock," ;
	int i,j;
	int r = 3*(row/3);
	int c = 3*(col/3);
	_ck.clear();
	for(i=0; i<3; i++ )
	{
		for(j=0; j<3; j++)
		{
	//		cout <<  getcell_index(r+i,c+j) << "," 
	//			<<  (this->cell[ getcell_index(r+i,c+j) ])->getValue() << "," ;
			_ck.add( (this->cell[ getcell_index(r+i,c+j) ])->getValue() );
		}
	}
	//cout << endl;
	return 0;
}

