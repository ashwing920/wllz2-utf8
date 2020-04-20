//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: bashisipan2.c 八十四盘

inherit ROOM;

void create()
{
	set("short","八十四盘");
	set("long",@LONG
八十四盘，道路艰险陡峭，迂回盘折，令人不能喘息。路左是蔽日遮
天的冷杉林，路右是深不见底的绝壁峡谷。由此往上至接引殿，北下到洗
象池。
LONG
);
	set("outdoors","emei");
	set("exits",([
		"southup": __DIR__"bashisipan3",
		"northeast": __DIR__"bashisipan1",
		"east": __DIR__"lengsl3",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	
	if (dir == "southup" ){
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("dodge",1);
	me->add("qi",-10);
	if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	tell_object(me,"你爬上八十四盘，有些累了。\n");
		}
	return 1;
}

