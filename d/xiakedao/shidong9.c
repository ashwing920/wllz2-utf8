// shidong9.c 石洞

inherit ROOM;

void create()
{
	set("short", "石洞");
	set("long", @LONG
这是一个很小的石洞，两边点着红烛，光线虽暗，却也能辩得出方向
。走着走着，你隐约看见在前面有一个身影，只见他身穿青色长衫，眼视
前方，一副唯我独尊的样子。
LONG );
	set("exits", ([
		"west" : __DIR__"shidong10",
		"east" : __DIR__"yadi",
	]));
	set("objects",([
		__DIR__"npc/baishou" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if(dir == "west" 
	&& objectp(present("bai zizai",environment(me)))
	&& ((int)me->query("shen") < 10000 
	|| (int)me->query("PKS") > 10 ))
		return notify_fail("白自在把手一拦：你这种邪派人物，还敢到这来，快滚！！\n");
	return ::valid_leave(me, dir);
}
