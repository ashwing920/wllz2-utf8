// houdian.c 后殿
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short","后殿");
        set("long",@LONG
这里是雪山寺的后殿，也是雪山弟子闭门练功的地方。殿内是一些练
功的蒲团和木人，还有一些吊挂着的沙袋和直竖的木桩。
LONG
);
        set("exits",([
                "north":  __DIR__"houdian2",
                "south" : __DIR__"neidian",
        ]));
        set("objects",([
                "/d/shaolin/npc/mu-ren" : 5,
        ]));
        setup();
        replace_program(ROOM);
}
