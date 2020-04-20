// jishitang.c - 济世堂
// Design By Robert 蝴蝶君 email:robert_st@263.net


inherit ROOM;

void create()
{
        set("short", "济世堂");
        set("long", @LONG
这里是桃源城的济世堂。这是由城里一些名气显赫的大侠和一些达官
贵人自发组织起来的一个慈善性机构。济世堂常常在门口散发一些包子或
者稀粥给饿着肚子的穷人。有时候，还为一些没有钱的人们看病。
LONG
);

        set("exits", ([
                "west"  : __DIR__"roads4",
        ]));
        set("objects",([
        	"/clone/food/baozi": 10,
        ]));
        setup();
        replace_program(ROOM);
}
