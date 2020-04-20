inherit ROOM;

void create()
{
        set("short", "浴龙堂");
        set("long", @LONG
地板是上好的檀香木，光滑而略带潮湿。左手边是一个柜台，后面有
个架子，上面挂满了白毛巾。几个如花似玉的小丫环正在忙碌，望向窗外
，一个巨大的青铜缸架在烈火上，丫环们正在慢慢的加入清泉水。
LONG
);
        set("exits", ([
                "up"   : __DIR__"bathhouse_f",
                "out"  : __DIR__"bathhouse",
                "west" : __DIR__"bathhouse_m1",
        ]));
        set("objects", ([
                __DIR__"npc/little_waitress": 2,    // little_waitress
        ]) );
        setup();
}
