#include <stdio.h>
#include "check.h"

void Check::clear()
{
	int i=0; 
	for(; i<9; i++)
	{
		_a[i] = 0;
	}
	_i = 0;
}

int Check::valid(int a)
{
	if(a<1||a>9)
	  return -1;
	else
	  return 0;
}

int Check::add(int a)
{
	if(_i > 8) 
	  return -1;
	if(0 != valid(a))
	  return 0;
	_a[ _i++ ] = a;
	return 0;
}

int Check::todo(int val)
{
	//printf("_i=%d,",_i);
	int i;
	for(i=0; i<_i; i++)
	{
		//printf("%d:%d,",i,val);
		if(_a[i] == val)
		{
			return -1;
		}
	}
	//printf("\n");
	return 0;
}

