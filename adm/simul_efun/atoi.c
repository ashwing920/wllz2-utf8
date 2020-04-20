// atoi.c
#include <ansi.h>

int atoi(string str)
{
	int v;
	if( !stringp(str) || !sscanf(str, "%d", v) ) return 0;
	return v;
}

string itoa(int n)
{
        return sprintf( "%d", n );
}
// 返回规定的空格数
string space(int n)
{
        return sprintf( "%" + itoa( n ) + "s", "" );
}

