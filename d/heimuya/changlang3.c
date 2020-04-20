// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
        set("short", "长廊");
        set("long", @LONG
一条长长的过道，左右两旁都是墙，每隔四五丈，墙上都点着一支明
晃晃的巨烛。
LONG
);
        set("exits", ([ 
                "north" : __DIR__"liangongfang",
                "east" : __DIR__"changlang4",
                "west" : __DIR__"qianqiudian",
        ]));
        set("objects",([
                CLASS_D("riyue")+"/yang" : 1,
                __DIR__"npc/shizhe": 4,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "日月神教") && dir == "north" &&
                objectp(present("yang", environment(me))))
                return notify_fail("杨莲亭喝道：你不是日月神教弟子，不得入内。\n");
        return ::valid_leave(me, dir);
}
