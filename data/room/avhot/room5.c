// File(/data/room/avhot/room5.c) of avhot's room
// Create by LUBAN which written by Robert

inherit PRIVATE_ROOM;

void create()
{
	set("short","闭关炼丹室");
	set ("long", @LONG
这里是主人家的闭关炼丹室，主人经常在这里闭关修炼、炼制丹药，室内中间一个八卦炼丹炉炉火熊熊，旁边一个蒲团静静放在一边。
LONG
);
	set("playerhouse",1);
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	set("exits", ([
		"west" : __DIR__"room2",
	]));
	set("objects", ([
		"/d/quanzhou/yaopu/yaolu":1,
	]));
	set("owner", "东京热");
	setup();
}
