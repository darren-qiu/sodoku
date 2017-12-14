#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include "sodoku.h"

using namespace std;

void usage()
{
	cout << endl;
	cout << "Set\t" << "ROW COL VALUE" << endl;
	cout << endl;
}

int main()
{
	string cmd;
	
	printf("\nHello Sodoku! Please Go! On!\n");

	SDK sdk = SDK();
	sdk.init_from_file();
	sdk.disp_cells();
	
	while(0 != sdk.gameover())
	{
		cout << ">>>------> " ;
		cmd.clear();
		getline(cin,cmd);
		if( cmd == "?" )
		{
			usage();
		}
		else if( cmd == "flash" )
		{
		}
		else if(  cmd == "last" )
		{
		}
		else
		{
			int r,c,v;
			stringstream strin(cmd);
			strin >> r >> c >> v;
			int ret = sdk.write(r,c,v);
			if( 0 == ret )
			{
				sdk.disp_cells();
			} else {
				cout << endl;
				cout << "Sorry, You are wrong!" << endl;
				cout << endl;
			}
		}

	}
	
	return 0;
}

