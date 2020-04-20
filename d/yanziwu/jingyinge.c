inherit ROOM;

void create()
{
        set("short","静音阁");
        set("long",@LONG
这里是修身养性的好场所，这里静悄悄的，没有主人的吩咐，谁也不
能够随便出入这里，在墙上挂着一幅图。
LONG);

        set("valid_startroom",1);
        set("exits",([
                "east" : __DIR__"neitang",
                "west" : __DIR__"c16-2",
                "south" : __DIR__"c16-5",
        ]));
        set("objects", ([
                CLASS_D("murong")+"/murongfu" : 1,
        ]));
        setup();
}
