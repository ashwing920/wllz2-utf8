// Room: /d/shaolin/zhulin6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "竹林小道");
        set("long", @LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密密的竹林
。这里人迹罕至，惟闻足底叩击路面，有僧敲木鱼声；微风吹拂竹叶，又
如簌簌禅唱。令人尘心为之一涤，真是绝佳的禅修所在。
LONG
);
        set("exits", ([
                "east" : __DIR__"hsyuan6",
                "south" : __DIR__"zhulin5",
        ]));
        set("objects",([
                CLASS_D("shaolin")+"/chengkun": 1,
        ]));
        set("outdoors", "shaolin");
        setup();
        replace_program(ROOM);
}
