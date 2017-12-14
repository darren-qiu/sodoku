#ifndef _SDK_SDK_
#define _SDK_SDK_

#include <cstddef>
#include "cell.h"
#include "check.h"

class SDK
{
	public:
		SDK()
		{
				for(unsigned int i=0; i<81; i++)
				{
					cell[i] = new Cell();
				}
				_ck = Check();
		}
		
		~SDK()
		{
				for(unsigned int i=0; i<81; i++)
				{
					delete cell[i];
				}
		}
		
	public:
		void init_from_file();
		void disp_cells();

		int write(int row, int col, int val);
		int gameover();
		
	private:
		void set_cell(int index, int val);
		
		int check(int row, int col, int val);
		int check_row(int row, int val);
		int check_col(int col, int val);
		int check_block(int row, int col, int val);

		int getcell_index(int row,int col);
		int getcellsofrow(int row);
		int getcellsofcol(int col);
		int getcellsofblock(int row, int col);

	private:
		Cell * cell[81];
		Check  _ck;
};

#endif

