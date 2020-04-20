// xilou.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
        set("short", "戏楼");
        set("long", @LONG
这是一家戏楼。只见大门上方挂着一个牌子，上面写着：「桃源戏楼
」四个大字。你跨进大门，一个足有六尺多高的戏台呈现在你的眼前。戏
台下面，则是给宾客们喝茶，歇息的桌椅。一个小贩正穿梭于宾客之间，
放声叫卖着。只见戏台上花旦们正在尽情的表演，说唱，喝彩声，还有小
贩们的叫卖声，掺杂在一起，好不热闹。
LONG
);
        set("exits", ([
                "east" : __DIR__"roads5",
        ]));
        set("objects",([
                __DIR__"npc/selang": 1,
        ]));
        setup();
}
