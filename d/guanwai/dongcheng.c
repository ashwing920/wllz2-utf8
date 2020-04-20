// guanwai/dongcheng.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com


inherit ROOM;

void create()
{
	set("short", "东城");
	set("long", @LONG
这里是用黄土铺就的街道，街上的行人不多，看起来很冷清。偶尔有
几个身着异域服饰的行人走过，看起来是满族，鲜祖的居民。西面传来嘈
杂的叫卖声。南面是一排黄泥垒成的土房，里面有嬉笑的声音。
LONG
);
	set("exits", ([
		"west"	  : __DIR__"jishi",
		"south"	 : __DIR__"tuyaoguan",
		"east"	  : __DIR__"xuedi1",
		"northeast" : __DIR__"huandi1",
	]));
	set("outdoors", "guanwai");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east"){ 
		me->receive_damage("qi",30);
	tell_object(me,"一股刺骨的寒风吹过，你只觉得浑身的血液都快被冻住了！\n");
	}
	return 1;
}
