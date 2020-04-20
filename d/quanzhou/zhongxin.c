// zhongxin 中心广场
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "中心广场");
        set("long", @LONG
这是泉州的中心地带，树荫浓郁，整齐划一。人山人海，摩肩接踵，
来来往往的人群中时常可见不同肤色的胡人。泉州因其广植刺桐树，又名
「刺桐城」，是「海上丝绸之路」的起点。数以万计的外国商贾、使节和
宗教信徒远涉重洋来到此地，其中不少人就定居于此。
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"citong_n3",
                "south" : __DIR__"citong_s1",
                "east" : __DIR__"citong_e1",
                "west" : __DIR__"citong_w1",
        ]));
        set("objects", ([
                __DIR__"npc/huren" : 1,
                __DIR__"npc/mao-fan" : 1,
                "/clone/npc/xunbu": 4,
                __DIR__"npc/youxun": 1,
        ]));
        set("outdoors", "quanzhou");
        setup();
        replace_program(ROOM);
}
