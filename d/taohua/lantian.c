// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>

inherit ROOM;
 
void create()
{
	set("short", "蓝天");
	set("long",@LONG
$WHT$你骑着白雕，举目远眺：$NOR$
$HIC$　　四周是蓝蓝的天，洁白的云在飘；地上的行人看起来象蚂蚁。哇....
好爽啊。你心中有一种感觉：君临天下一览人间小！$NOR$

LONG
);   
	setup();
	replace_program(ROOM);
}
