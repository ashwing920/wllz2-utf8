// furen.c - 富豪大院
// Design By Robert 蝴蝶君 emial:robert_st@263.net

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "富豪大院");
        set("long", @LONG
这里是桃源城富豪大院的大门。只见一座富丽堂皇的大宅院出现在你
的眼前，两头高大的石狮子镇住大门两侧，朱漆大门足足有三寸厚。门上
挂着两个灯笼。几个家丁睁大眼睛瞪着你。他们体格粗壮，全然不似一般
的护院、武师。门口贴着一张告示(gaoshi)，好象写着什么。
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"roads2",
                "west"  : __DIR__"fuhaodayuan/main-01",
        ]) );                   
        set("item_desc",([
                "gaoshi": @TEXT
$CYN$
府邸内目前招收短工若干名，男女不限，有意者请到府邸内与管家：

ask zhang about job 询问！

$NOR$
TEXT
       ]));
        setup();
        create_door("west","朱漆大门","east",DOOR_CLOSED);
        
}
