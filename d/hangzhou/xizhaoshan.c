// xizhaoshan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "夕照山");
	set("long", @LONG
夕照山上遍植栖树和红枫。每逢深秋，层林尽染，分外壮观。山顶有
一座塔，雷峰塔。神话“白蛇传”中的白娘娘就是被法海禁锢在这座塔里
。每当夕阳西下，彩云缭绕，塔影幢幢，这就是西湖十景之一的“雷峰夕
照”。
LONG
);
	set("exits", ([
		"southdown"   : __DIR__"road16",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
