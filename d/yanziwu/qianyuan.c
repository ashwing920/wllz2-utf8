inherit ROOM;

void create()
{
        set("short","前院");
        set("long",@LONG
这里是曼陀罗山庄的前院, 只见一个个丫环, 卑女人来人往穿梭不息, 而
且个个不法轻灵, 显然武功不弱！院子的东面是一个小石桥，南面是一条
长廊。往西走就到了庄门。
LONG);
        set("outdoors","yanziwu");
        set("exits",([
                "west" : __DIR__"zhuangmen",
                "north" : __DIR__"hc4",
                "east" : __DIR__"shiqiao1",
                "south" : __DIR__"cl",
]));
        set("objects", ([
                "/d/qianjinlou/npc/yahuan" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
