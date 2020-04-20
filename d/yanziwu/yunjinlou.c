

inherit ROOM;
void create()
{
	 set("short","云锦楼");
	 set("long",@LONG
云锦楼陈设富丽, 一副中堂绘的是孔雀开屏，两边柱子上写了一幅对
联 (duilian)。东面是一间客厅，西面是厢房，往北面走是后院，南面是
后花园。
LONG);
	set("valid_startroom",1);
	set("item_desc", ([
		"duilian" : "漆叶云差密, 茶花雪忌艳。\n"
	]));
	set("exits",([
		"east" : __DIR__"keting",
		"west" : __DIR__"xiangfang1",
		"south" : __DIR__"hhyuan",
		"up" : __DIR__"cangshuge",
		"north" : __DIR__"houyuan",
	]));
	set("objects",([
		__DIR__"npc/wang" : 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	mapping fam;
	fam = (mapping)me->query("family");

	if ((!fam || fam["family_name"] != "慕容世家") && dir == "up" &&
		objectp(present("wang furen", environment(me))))
		return notify_fail("楼上是我曼佗罗山庄的藏书阁，你不是慕容弟子，还是不要上去了吧？\n");

	return ::valid_leave(me, dir);
} 
