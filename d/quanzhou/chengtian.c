            // chengtian.c 承天寺
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "承天寺");
        set("long", @LONG
这是泉州市民祭天求安的寺庙，以保佑年年得以五谷丰登，风调雨顺
。寺内广场中央有一法坛。承天寺西方通往刺桐南路。
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                "northeast" : __DIR__"gtxiang",
                "west" : __DIR__"citong_s2",
        ]));
        set("objects", ([
                __DIR__"npc/monk" : 1,
                "/d/center/npc/lvke": 2,
        ]));
        setup();
}
