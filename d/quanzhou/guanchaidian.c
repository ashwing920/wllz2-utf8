// Room: /d/city/guancaipu
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
      set ("short", "棺材铺");
      set ("long", @LONG
这是泉州城里最大的棺材铺，在棺材铺的后面是一个大院，摆放着大
大小小的棺材，让人感到有的阴森恐怖，特别是这的老板，苍白的面宠，
一对死鱼般的眼睛，活象一个死人，泉州城的人都叫他“活阎王”。旁边
贴着一张白纸(paper)，上面好象写着什么。 
LONG
);
        set("item_desc",([
                "paper": @TEXT
由于近日店内事物繁多，需找男性砍柴工
若干名，有意者请：

    ask laoban about 工作

待遇丰厚！
TEXT
        ]));
        set("no_fight",1);        
        set("exits", ([ 
                "west" : __DIR__"citong_n2",
        ]));
        set("objects",([
                __DIR__"npc/boss": 1,
        ]));

        setup();

}
