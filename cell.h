#ifndef _SDK_CELL_
#define _SDK_CELL_

class Cell
{
	public:
		Cell():row(-1),col(-1),block(-1),value(-1),flag(-1)
		{}
		~Cell(){}

	public:
		void setRow(int row);
		int getRow();
		void setCol(int col);
		int getCol();
		void setBlock(int block);
		int getBlock();
		void setValue(int value);
		int getValue();
		void setFlag(int flag);
		int getFlag();

	private:
		int row;
		int col;
		int block;
		int value;
		int flag;
};

#endif

