// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "朱雀堂");
	set("long", @LONG
堂内只点着两盏油灯，两朵火焰忽明忽暗，相距既远，火光又暗，依
稀有几个人在打座练功，但相貌如何便瞧不清楚了。
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"chengdedian",
		"west" : __DIR__"baihutang",
	]));
	set("objects",([ 
		CLASS_D("riyue")+"/bao" : 1,
	]));
	setup();
	replace_program(ROOM);
}
