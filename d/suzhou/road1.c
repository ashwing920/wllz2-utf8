                                                // Room: /d/suzhou/road1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "青石官道");
        set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆
而过。大道两旁有一些小货摊，似乎是一处集市。南面就是苏州城了。
LONG
);
        set("outdoors", "suzhou");
        set("exits", ([
                "south"  : __DIR__"beimen",
                "southwest" : __DIR__"huqiu",
                "northwest" : "/d/guiyun/shanlu2",
        ]));
        set("objects",([
                "/d/huanghe/npc/peng" : 1,
                "/d/huanghe/npc/sha" : 1,
                "/d/huanghe/npc/liang" : 1,
                "/d/huanghe/npc/hou" : 1,
                "/d/huanghe/npc/ma" : 1,
                "/d/huanghe/npc/qian" : 1,
                "/d/huanghe/npc/shen" : 1,
                "/d/huanghe/npc/wu" : 1,
                "/d/guiyun/npc/duantiande" : 1,
                "/d/guiyun/npc/wanyankang" : 1,
                "/d/guiyun/npc/wanyanhonglie" : 1,
                "/d/guiyun/npc/jinbing" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
