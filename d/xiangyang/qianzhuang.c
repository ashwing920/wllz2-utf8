// Room: /d/xiangyang/qianzhuang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "钱庄");
        set("long", @LONG
这里是襄阳的钱庄，因为这里商业相当发达，各地的商号都和这里有
银钱来往。钱庄里有很多人在存取钱，也有人在兑换银两。看着这么多的
钱财滚来滚去，真是让人眼馋啊。但眼下大敌当前，全城一致抵御元兵。
钱庄的业务由华山弟子接管，支援大侠郭靖和郭夫人。墙上贴着一个牌子
(paizi)。
LONG
);
        set("item_desc", ([
                "paizi" : @TEXT
        
        本钱庄提供以下服务：
        
        存钱            deposit或者cun
        取钱            withdraw或者qu
        钱币兑换        convert或者duihuan
        查帐            check或者chazhang
        
TEXT
        ]));
        set("exits", ([
                "east" : __DIR__"southjie1",
        ]));
        set("objects", ([
                __DIR__"npc/huangzhen" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
