                                          // Room: /d/shaolin/yidao4.c

inherit ROOM;

void create()
{
        set("short", "大驿道");
        set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶
着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑
快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林，东
面就是烟波飘渺的太湖。
LONG
);

        set("exits", ([
                "west": __DIR__"yidao3",
                "east":"/d/yanziwu/hubian",
        ]));
        set("objects",([
                __DIR__"npc/dao-ke" : 1,
        ]));
        set("outdoors", "taishan");
        setup();
        replace_program(ROOM);
}
