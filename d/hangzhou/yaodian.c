// yaodian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "胡庆余堂");
        set("long", @LONG
这是一家明净宽敞的药堂，後墙上是一个大药柜。几个伙计正忙着爬
上爬下地从小抽屉里抓药。药柜前摆着一张桌子，名医胡庆余就在这里为
人治疗。柜台上方高挂一个大牌子(paizi).
LONG
);
        set("exits", ([
                "west"    : __DIR__"road14",
        ]));
        set("no_beg",1);
        set("objects", ([
                 __DIR__"npc/hqingyu": 1,
        ]));
        set("item_desc", ([
                "paizi" :
@TEXT
$CYN$
胡庆余堂目前提供几下几种服务：

整容：每次 100 两黄金
改名：每次 1000 两黄金

相关事宜请 ask hu qingyu
$NOR$
TEXT]));

        setup();
        replace_program(ROOM);
}
