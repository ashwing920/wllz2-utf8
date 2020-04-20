inherit ROOM;

void create()
{
        set("short","大厅");
        set ("long",@LONG
大厅中陈设简朴, 无什摆设, 正堂上挂着许多人物字画，都是容氏祖
先的遗迹, 用来表示对先人的尊敬。大厅的东边是书房，西边是局室，南
面是后厅。
LONG);
        set("exits",([
                "north" : __DIR__"xiaojing1-2",
                "west" : __DIR__"jushi",
                "south" : __DIR__"houting",
                "east" : __DIR__"shufang",
        ]));
        set("valid_startroom", 1);
        set("objects",([
                   CLASS_D("murong")+"/gongye" : 1,
                   __DIR__"npc/obj/xiangcha" : 2,
                   CLASS_D("murong")+"/master_murong" : 1,
        ]));
        setup();
        "/clone/board/murong_b"->foo();
}
