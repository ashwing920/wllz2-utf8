//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: lianhuashi.c 莲花石

inherit ROOM;

void create()
{
	set("short","莲花石");
	set("long",@LONG
这是莲花石。此处岩石纹理纵横，形似莲花，颜如芙蓉，仿佛萼瓣层
叠，细蕊欲绽。上有一庵，叫「莲花社」。由此往西上直达洗象池，东下
左通华严顶，右通九老洞。
LONG
);
	set("objects", ([
		CLASS_D("emei") + "/su" : 1,
		CLASS_D("emei") + "/ling" : 1,
	]));
	set("outdoors", "emei");
	set("exits",([ 
		"southeast" : __DIR__"jldongkou",
		"eastdown"  : __DIR__"huayanding",
		"westup"	: __DIR__"ztpo1",  
	]));

	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if(dir == "westup"){
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->add("qi",-10);
	if(((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	tell_object(me,"你在钻天坡往上爬了一阵，好累人。\n");
}
	return 1;
}

