// jingxiushi.c 静修室
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "静修室");
	set("long", @LONG
这里是全真教弟子静修参悟道情的房间，房间很小，但收拾的干干净
净，桌椅都摆放得整整齐齐，让人一看就心无杂念。
LONG
);
	set("exits", ([
		"east" : __DIR__"houshan",
		"south" : __DIR__"diziju",
		"west" : __DIR__"houtang3",
	]));
	set("objects", ([
		CLASS_D("quanzhen")+"/liu" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;

	if (dir == "east" ){
	if(!(fam = me->query("family")) || fam["family_name"]!="全真教"){
	if(present("liu chuxuan", environment(me)) && living(present("liu chuxuan", environment(me))))
	{
	return notify_fail("刘处一伸手拦住你道：后面是本教祖师清修之地，" + RANK_D->query_respect(me) + "请止步。\n");
		}
		else
			return ::valid_leave(me, dir);
		}
		else
			return ::valid_leave(me, dir);
	}
	else
		return ::valid_leave(me, dir);

}
