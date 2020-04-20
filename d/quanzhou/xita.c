// xita.c 西塔

inherit ROOM;

void create()
{
	set("short", "西塔");
	set("long", @LONG
西塔又名仁寿塔，它与东塔除局部略有区别外，建筑规则基本相同，
恰似一对挛生姊妹。西塔须弥座束腰部分则雕刻着各种花、鸟、虫、兽和
装饰图案，也都线条清晰，形态逼真，给人一种欣悦、舒畅的美感。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"yuetai",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
