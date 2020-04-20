// /d/beijing2/xingbu/hall.c

inherit ROOM;

void create()
{
	set("short", "刑部大厅");
	set("long", @LONG
刑部的大厅，全国重要的案件都要到这里来审判的。大厅的另一端，
正对着门口，一个官老爷高高的坐在上面，他的前面有一个案子，上面摆
了些纸和笔。老爷的上方有一个横匾，上书：明镜高悬。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"gate",
		"north": __DIR__"xingjvshi",
		"south": __DIR__"qiushi_gate",
		"east" : __DIR__"garden",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/gao_yingming" : 1,  //官一名
		__DIR__"npc/xingbu_yacha" : 2,
	]));
	set("no_fight",1);
	set("no_beg",1);
	setup();
	replace_program(ROOM);
}
