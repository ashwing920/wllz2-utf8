// Room: /d/mingjiao/shanjiao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "昆仑山下");
        set("long", @LONG
这里是千里昆仑的东麓，远望苍天浩浩，白云悠悠。东方沃野千里，
楚天辽阔；西面高山巍巍，迤逦万里。叱咤武林八百年的明教就座落在这
群山之中。明教----是多少武林豪杰所向往的地方，在那里，有无数生死
相许的好兄弟，无论是正是邪。就在这西方的群山之后，等待着你去谱写
又一曲武林传奇。路边有块牌匾(sign)，好象写着什么。
LONG
);
        set("exits", ([
                "west" : __DIR__"tomen2",
                "east" : __DIR__"gebitan5",
                "southeast": "/d/kunlun/sbxd",
        ]));
        set("item_desc",([
                "sign": @TEXT

$YEL$

              -----  戈壁滩
               \ 
                \
                   昆仑派
$NOR$
TEXT
        ]));
        set("outdoors", "mingjiao");
        setup();
        replace_program(ROOM);
}
