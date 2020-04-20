// duchang.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "顺天赌场");
        set("long", @LONG
这里是桃院城的顺天赌场。这是方圆千里之内最大的一家赌场。赌场
大门上写着“英雄会赌”四个大字，大厅里的几张赌桌围着黑压压的赌徒
。各个房间里传出的阵阵吆喝声、惊叹声、欢呼声、咒骂声、哄笑声和噼
哩啪啦的声响，汇成一片，搅在一起。有匾（sign）一块。
LONG
);

        set("exits", ([
                "west"  : __DIR__"roads2",
        ]) );                   

        set("item_desc", ([
                "sign": @TEXT

    骰子的赌法：

    bet <种类> <数量> <货币名称>

    种类：０、１、２、３到１８
    ０：　      赌小    （  ３－１０）  一赔一
    １：        赌大    （１１－１８）  一赔一
    ２：　      赌围骰  （三粒骰子同点）一赔三十六
    ３－１８    赌单点                  一赔八

    例子：
    bet 0 50 silver   赌五十两银子在小上

TEXT
        ]) );


        setup();
}
int valid_leave(object me, string dir)
{
        if (me->query_temp("gamble/amount")){
        message_vision ("$N扔下押注的钱不要了。\n",me);
        me->delete_temp("gamble");
        }
        return ::valid_leave(me,dir);
}

