// nanmen  by netkill

inherit ROOM;

void create()
{
        set("short", "南门");
        set("long", @LONG
这里是昆明的南门，高高的城楼上写着大大的"南门"两个字，由此南
去，就是滇池了，出入南门的人很少，只有些渔民不时提着新鲜的鱼进城
来卖。
LONG
);
        set("outdoors","kunming");
        set("exits", ([
                "south" : "/d/wudu/road1",
                "north" : __DIR__"nandajie2",
                "east":   __DIR__"posthouse",
        ]));
        setup();
        replace_program(ROOM);
}
