// lingmu.c 灵山圣墓
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "灵山圣墓");
	set("long", @LONG
这是泉州东边灵山的南麓，传闻唐高祖武德年间，伊斯兰教创始人穆
罕莫德派门徒三贤沙仕偈、四贤吾高仕来泉州传教，卒葬于此。墓后有一
半圆形石筑廊，上立有一中文碑记，乃「郑和行香碑」(monument)。这是
著名航海家三宝太监郑和第五次下西洋路过泉州，特至此墓行香祷告，官
府为之刻石记事的碑刻。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"shuiguan",
		"east" : __DIR__"lyqiao",
		"south" : __DIR__"gangkou3",
	]));
	set("outdoors", "quanzhou");
	set("item_desc",([
		"monument" : "【钦差总兵太监郑和，前往西洋忽鲁漠斯等国公干。永乐\n"
			     "十五年来此行香，望神灵保佑。镇抚浦和日记立】\n",
	]));
	setup();
	replace_program(ROOM);
}
