
inherit ROOM;

void create()
{
        set("short", "武器库");
        set("long", @LONG
这里是慕容家族的武器库，慕容家为了兴复大燕，早已从各个方面做
好了准备。
LONG
);
        set("no_sleep_room",1);
        set("exits",([
                "west" : __DIR__"wuchang",
        ]));
        set("objects",([
                "/clone/weapon/changjian":3,
                "/clone/weapon/blade":3,
                "/clone/weapon/tiejia":3,
        ]));
        setup();
        replace_program(ROOM);
}
