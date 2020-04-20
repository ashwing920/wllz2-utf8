//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "杨柳胡同");
        set("long", @LONG
你走在巷道上，感到似乎有些不妙。南边仍是空荡荡的小道，见不到
几个行人。东边是一家面馆。北边是西长安大道。一股阴风吹来，尘沙四
起，你禁不住打了个寒颤。 
LONG
);
        set("outdoors", "city2");
        set("exits", ([
                "east" : __DIR__"mianguan",
                "south" : __DIR__"alley2",
                "north" : __DIR__"xichang2",
        ]));
        set("objects",([
                "/clone/npc/lietou":1,
        ]));
        setup();

        replace_program(ROOM);
}
