// qianshou.c 千手岩
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "千手岩");
	set("long", @LONG
沿山路而上，即达千手岩。这里每交秋冬满山枫叶，如火如锦，煞是
好看。岩上一寺，内供观音坐像一尊。寺前苍松挺拔，寺后峰石嶙峋，别
有一番景致。近旁就是著名高僧弘一法师的墓亭，墓亭边的崖石上刻着他
临终时写的「悲欣交集」四个字。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northup" : __DIR__"laojun",
		"southeast" : __DIR__"mituo",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
