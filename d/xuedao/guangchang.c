// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short","广场");
        set("long",@LONG
这里是血刀门内的广场。广场石埕铺就，黄土垫砌，平整而坚实。广
场的北面就是血刀门大殿。往西是练武场，南面是山门。寺内有一些机关
，不要乱走。
LONG
);
        set("outdoors","xuedao");
        set("exits",([
                "east" : __DIR__"lwchang1",
                "west" : __DIR__"lwchang",
                "north" : __DIR__"dadian",
                "south" : __DIR__"shanmen",
        ]));
        set("objects",([
                CLASS_D("xuedao")+"/dizi": 4, 
        ]));
        setup();
}
