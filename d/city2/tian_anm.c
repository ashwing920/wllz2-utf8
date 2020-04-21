//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "天安门");
        set("long", @LONG
这里就是天安门广场，灰色的城墙给人以庄严肃穆之感，再往北就是
皇宫了。皇宫正门前有座小桥，一条护城河绕城而过。越过小桥向北望去
，紫禁城的轮廓益发显得雄伟高大。一条笔直的大道横贯东西，东边是东
长安街，西边是西长安街。南边是一条繁华的大道，从那往下有一座天桥
，据说游人很多。
LONG );
        set("exits", ([
                "south" : "/d/city2/nandaj1",
                "north" : "/d/city2/bridge",
                "west" : "/d/city2/xichang1",
                "east" : "/d/city2/dongcha1",
        ]));
        set("objects", ([
                "/d/city/npc/bing" : 2,
                "/d/city/npc/polan" : 2,
                "/clone/npc/xunbu": 2,
        ]));
        set("outdoors", "city2");

        setup();
        replace_program(ROOM);
}