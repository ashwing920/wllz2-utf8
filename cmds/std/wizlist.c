//  wizlist.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list;
	string str;
	string *admin = ({}), *arch = ({}), *wizard = ({}),
	*apprentice = ({}), *immortal = ({}), *unknown = ({});
	int i;

	str = "本泥潭目前的巫师有：\n";
	str += WHT"─────────────────────────────────\n"NOR;
	list = SECURITY_D->query_wizlist();

	for( i = 0; i < sizeof( list ); i++ ) {
		switch( SECURITY_D->get_status( list[i] ) ) {
		case "(admin)": admin += ({ list[i] });	break;
		case "(arch)":	arch += ({ list[i] });	break;
		case "(wizard)":wizard += ({ list[i] });break;
		case "(apprentice)":apprentice += ({ list[i] });break;
		case "(immortal)":immortal += ({ list[i] });break;
		default:unknown += ({ list[i] });
		}
	}

	str += HIW "【 天  神 】";
	if( admin )
	for( i = 0; i < sizeof( admin ); i++ ) {
		str += sprintf("　%-8s%s", capitalize(admin[i]),(i % 5 == 4 ) ? "\n\t\t\t" : "");
	}
	str += "\n"HIY"【 龙  神 】";
	if( arch )
	for( i = 0; i < sizeof( arch ); i++ ) {
		str += sprintf("　%-8s%s", capitalize(arch[i]),(i % 5 == 4 ) ? "\n\t\t\t" : "");
	}
	str += "\n"YEL"【 神  仙 】";
	if( wizard )
	for( i = 0; i < sizeof( wizard ); i++ ) {
		str += sprintf("　%-8s%s", capitalize(wizard[i]),(i % 5 == 4 ) ? "\n\t\t\t" : "");
	}
	str += "\n"HIM"【 天  仙 】";
	if( apprentice )
	for( i = 0; i < sizeof( apprentice ); i++ ) {
		str += sprintf("　%-8s%s", capitalize(apprentice[i]),(i % 5 == 4 ) ? "\n\t\t\t" : "");
	}
	str += "\n"CYN"【 小天仙 】";
	if( immortal )
	for( i = 0; i < sizeof( immortal ); i++ ) {
		str += sprintf("　%-8s%s", capitalize(immortal[i]),(i % 5 == 4 ) ? "\n\t\t\t" : "");
	}
	str += NOR + WHT"\n─────────────────────────────────\n"NOR;
	write( str + NOR + "\n" );
	return 1;
}

int help(object me)
{
write(@HELP

指令格式：wizlist

用途：列出目前所有的巫师名单。

HELP
     );
     return 1;
}
