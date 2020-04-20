// Room: /d/shaolin/wuchang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。上千年的
踩踏已使得这些石板如同镜子般平整光滑。西边角上还有两个大沙坑，十
来个僧人正在练习武艺。东西两面各有一练武场。
LONG
);
        set("exits", ([
                "south" : __DIR__"houdian",
                "east" : __DIR__"wuchang2",
                "west" : __DIR__"wuchang1",
                "north" : __DIR__"fzlou",
        ]));
        set("outdoors", "shaolin");
        set("objects",([
                CLASS_D("shaolin") + "/dao-jue" : 1,
        ]));
        setup();
}
void open_path()
{
        mapping *exits;
        exits = this_object()->query("exits");
        if(!exits){
                set("exits", ([
                        "south" : __DIR__"houdian",
                        "east" : __DIR__"wuchang2",
                        "west" : __DIR__"wuchang1",
                        "north" : __DIR__"fzlou",
                ]));
        }
        return;
}
