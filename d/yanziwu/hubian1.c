inherit ROOM;

void create()
{
        set("short","湖边");
        set("long", @LONG
俗话说：上有天堂，下有苏杭。这里正是大大有名的太湖。湖面绿波
上漂着一叶叶的小舟, 一阵阵悦耳的小曲儿随着湖上的轻风不时漂入你的
耳中。
LONG
);
        set("outdoors","yanziwu");
        set("exits", ([
                "west" : __DIR__"hubian",
                "southeast" : __DIR__"shiqiao",
        ]));
        set("objects",([
                CLASS_D("murong")+"/feng": 1,
        ]));
        setup();
        replace_program(ROOM);
}
