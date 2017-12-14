#ifndef _SDK_CHECK_
#define _SDK_CHECK_

class Check
{
	public:
		Check() 
		{
		    for(unsigned int i=0; i<9; i++)
			      {
					          this->_a[i] = 0;
							      }

			    this->_i = 0;
		}

		~Check() {}
		
		void clear();
		int add(int a);
		int todo(int val);
		int valid(int a);
		
	private:
		int _a[9];
		int _i;
};

#endif

