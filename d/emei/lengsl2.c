//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: lengsl2.c 冷杉林

inherit ROOM;

void create()
{
	set("short","冷杉林");
	set("long",@LONG
这是一片遮天蔽日的冷杉林。数人也合抱不过来的冷杉树簇在一块，
棵棵枝繁叶茂，象一蓬蓬巨伞般伸向天空，把阳光遮得丝毫也无。看地上
厚厚的枯枝烂叶，显然游客很少踏足此处。
LONG
);
	set("exits",([ 
		"east"	  : __DIR__"bashisipan1",
		"northdown" : __DIR__"lengsl1",
		"southwest" : __DIR__"lengsl3",
	]));

	setup();
	replace_program(ROOM);
}
