// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","千年古洞");
	set("long", @LONG
你沿着洞中的路道，逐渐走进了山洞的内部。洞中的光线越来越黑，
轻轻触摸洞中的墙壁，湿漉漉的墙壁上，有数道坑坑洼洼的痕迹，好象
是字符，又好象是碎石斑斓的缝隙。山洞的深处不断的传出阵阵阴风，
偶尔夹带着一阵怪声，似痛苦的哀嚎，又似绝望的呻吟。
LONG
);
	set("exits",([
		"south": __DIR__"hole03",
		"north": __DIR__"hole05",
	]));
	setup();
	replace_program(ROOM);
}
