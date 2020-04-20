// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "前殿");
	set("long", @LONG
来到一座雄伟的殿堂，大殿两旁分别立着八尊威武的塑像，高约八尺
，手中持着不同的武器，神态动作各异，而大殿当中设有一座祭坛，坛上
燃烧着蓝色的火焰，异常诡秘。
LONG
);
	set("valid_startroom",1);
	set("exits", ([
		"east" : __DIR__"changlang",
		"west" : __DIR__"shibanlu",
	]));
	set("objects", ([
		CLASS_D("riyue")+"/shang" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	mapping myfam;
	int i;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "日月神教" ) && dir == "east") {
		inv = all_inventory(me);
		for(i=sizeof(inv)-1; i>=0; i--)
		if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
		if(objectp(present("shang guanyun", environment(me))))
			return notify_fail("上官云拦住你说道：这位" + RANK_D->query_respect(me) + "请放下兵刃才能进见教主。\n");
	}
	return ::valid_leave(me, dir);
}

