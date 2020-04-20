// marry_room.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
string look_zhaopai(object me);
void create()
{
	set("short", "红娘庄");
	set("long", @LONG
你现在正站在风光秀丽的西子湖畔的红娘庄里，临水凭窗，隔着碧绿
的湖面，就是断桥了。红娘庄并不大，但这里却主天下之悲欢离合，成就
所有天下有情人。靠近门口的地方有一块乌木雕成的招牌(zhaopai)。
LONG
);
	set("exits", ([
		"east" : __DIR__"road10",
	]) );
	set("item_desc", ([
		"zhaopai": (: look_zhaopai :),
	]) );
	set("objects", ([
		"/d/center/npc/hongniang" : 1,
		"/d/center/npc/meipo": 1,
	]) );
	setup();
	
}

string look_zhaopai(object me)
{
	return "缔结(marry)或解除(unmarry)婚约。\n";
}
