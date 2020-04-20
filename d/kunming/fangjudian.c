// Room: /city/zuixianlou.c

inherit ROOM;

void create()
{
        set("short", "防具店");
        set("long", @LONG
这里是昆明城内的一家防具店，只见防具店两边各有一个架子，上面
放满了各式各样的布匹和一些已经制作精美的防具，布衣。不少江湖侠客
，都远道而来，在这里挑选布匹，定制服饰。柜台前站着一个亭亭玉立的
小姑娘，大概是这里的老板，你一进门，便用一种热情的眼神看着你。店
门口贴着张告示(sign)，好象写着什么。
LONG
);
        set("exits", ([
                "west" : __DIR__"beidajie",
        ]));
        set("item_desc",([
                "sign": @TEXT

本店招收洗衣工人，男女不限。有意思者请找店主询问：

ask nian ci about $HIG$job$NOR$

TEXT
        ]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_sleep_room",1);                
        set("objects", ([
                __DIR__"npc/nianci":1,
        ]));
        setup();
        replace_program(ROOM);
}
