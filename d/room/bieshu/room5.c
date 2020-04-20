// rouw_home 梦庭院

// 在生成房屋时：
// /**/开头的语句将被去掉
// //**开头的语句将被使用。

/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short","闭关炼丹室");
	set("long",@LONG
这里是主人家的闭关炼丹室，主人经常在这里闭关修炼、炼制丹药，室内
中间一个八卦炼丹炉炉火熊熊，旁边一个蒲团静静放在一边。
LONG
);
	set("playerhouse",1);
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
/**/	set("default_long","这里是主人家的闭关炼丹室，主人经常在这里闭关修炼、炼制丹药，室内中间一个八卦炼丹炉炉火熊熊，旁边一个蒲团静静放在一边。");
	set("exits", ([
		"west" : __DIR__"room2",
	]));
	set("objects", ([
		"/d/quanzhou/yaopu/yaolu":1,
	]));
	set("owner", "ROOM_OWNER");
	setup();
}
