                                   //wuguan.c
//Design By 蝴蝶君 Email:Robert_st@263.net 

inherit ROOM;

void create()
{

        set("short","枫林武馆");
        set("long",@LONG
这里是桃源城里赫赫有名的一间武馆，只见武馆大门上挂着一块金字
招牌，上面写着「枫林武馆」四个大字，想必也是一间老字号的武馆了。
武馆大门敞开，不时从武馆里传来阵阵喝哈声。你不禁伸长了脖子望里面
望去。
LONG
);

        set("outdoors","taoyuan");
        set("exits",([
                "east": __DIR__"wuguan-2",
                "west": __DIR__"roadn3",
        ]));
        setup();

}
