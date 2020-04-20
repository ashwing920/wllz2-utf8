// room: /d/xingxiu/xxh6
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "石道");
        set("long", @LONG
这是星宿海边有人用石头铺成的一条小道，周围弥漫着沼泽的瘴气和
一种说不出来的香味。路边有个石洞。
LONG
);
        set("exits", ([ 
                "east" : __DIR__"xxh4",
                "enter" : __DIR__"xiaoyao",
        ]));
        set("objects", ([ 
                __DIR__"npc/caihua" : 1,
        ]) );
        setup();
}
int valid_leave(object me, string dir)
{
        if(dir =="enter"){
        if(me->query("family/family_name") != "星宿派" && present("caihua zi", environment(me)))
                return notify_fail("采花子挡住了你：喂，你来这里干什么？\n");
        }
        return ::valid_leave(me, dir);
}

