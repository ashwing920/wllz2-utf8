//Room: /d/dali/chahuashan1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com


inherit ROOM;
void create()
{
        set("short","茶花山");
        set("long",@LONG
你站在一座小山西面脚下，大理盛产茶花，好品种的茶花遍地生长，
东面的这片小山林也长满了好茶。西边不远就是大理城的北门了。
LONG
);
        set("outdoors", "dali");
        set("exits",([
                "west"    : __DIR__"northgate",
                "eastup"  : __DIR__"chahuashan2",
                "east":     "/d/tangmen/chapu",
        ]));
        setup();
        replace_program(ROOM);
}

