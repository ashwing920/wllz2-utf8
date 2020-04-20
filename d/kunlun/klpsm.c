// Room: /d/kunlun/klpsm.c

inherit ROOM;

void create()
{
        set("short", "昆仑派山门");
        set("long", @LONG
在你眼前是一座古色古香的山门, 上面以龙飞凤舞的笔迹书写著「昆
仑派」三字，据说是昆仑派开山祖师何足道亲笔所题。往北方看过去是一
个颇大的广场。门前则是一条岩石铺设的阶梯沿著山腰往南而下。
LONG
);
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/dizi" : 4,
        ]));
        set("outdoors","kunlun");
        set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"wft",
                "north" : __DIR__"bwc",
        ]));

        setup();
        set("valid_startroom","1");
        call_other("/clone/board/kunlun_b","??");
        replace_program(ROOM);
}
