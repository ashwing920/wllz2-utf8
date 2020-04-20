// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","林中洞口");
	set("long", @LONG
你来到了山洞之前，两边的青苔把洞口装饰得一片碧绿。往洞里望去
，山洞里一片漆黑，什么也看不清。偶尔有一个黑影晃动，发出啪嗒啪嗒
的声响。洞内吹来阵阵阴风，陡然间让人觉得毛骨悚然。
LONG
);
	set("outdoors","forest");
	set("exits",([
		"enter": __DIR__"hole01",
		"south": __DIR__"senglin/exit",
	]));
	setup();
	replace_program(ROOM);
}
