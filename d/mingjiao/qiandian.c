// d/mingjiao/qiandian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void init();

void create()
{
        set("short","明教前殿");
        set("long", @LONG
你来到这里，放眼窗外望去，漫漫昆仑雪山，晶莹剔透，苍天浩浩，
白云悠悠。东方沃野千里，楚天辽阔；西面高山巍巍，迤逦万里。这里就
是叱咤武林八百年的明教总舵的前殿。
LONG
);
        set("exits",([
                "east"    : __DIR__"eastdian",
                "west"    : __DIR__"westdian",
                "north"  : __DIR__"dadian",
                "southdown" : __DIR__"square",
        ]));
        set("objects",([
                CLASS_D("mingjiao")+"/yintianzheng":1,
                CLASS_D("mingjiao")+"/xiexun":1,
                CLASS_D("mingjiao")+"/weiyixiao":1,
                CLASS_D("mingjiao")+"/daiyisi":1,
        ]));
        setup();
        replace_program(ROOM);
}
