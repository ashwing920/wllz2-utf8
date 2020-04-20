// citong_x1.c 刺桐西路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "刺桐西路");
        set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。西边便是著
名的开元寺及西门吊桥。北边有一家杂货铺，专卖女人家用的东西。
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"citong_w2",
                "east" : __DIR__"zhongxin",
                "north" : __DIR__"zahuopu",
        ]));
        set("objects",([
                "/d/songshan/npc/sha" : 1,
        ]));
        set("outdoors", "quanzhou");
        setup();
}
