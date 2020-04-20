// dadian.c 大殿
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short","大殿");
        set("long",@LONG
这里是血刀门的大殿，中央供奉着佛祖塑像。连一个僧人都见不到。
更不要说是香客了。大殿两侧都是侧殿血刀门弟子留言板(board)。
LONG
);
        set("exits",([
                "east"  : __DIR__"cedian1",
                "west"  : __DIR__"cedian2",
                "south" : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("xuedao")+"/shengdi" : 1,
                CLASS_D("xuedao")+"/dizi" : 4,
                CLASS_D("xuedao")+"/master_xuedao" : 1,
        ]));
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
        "/clone/board/xuedao_b"->foo();
}
