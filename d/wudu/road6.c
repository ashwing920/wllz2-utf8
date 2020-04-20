// Room: /d/wudu/road1. c

inherit ROOM;

void create()
{
        set("short","滇池湖边");
        set("long", @LONG
这里是滇池湖边，茫茫五百里滇池拦住了去路，遥谣看去只见天水一
色，群山拥湖，一片美丽的景色，西面一座大山，犹如一个美丽的女子在
静静的沉睡，那就是有名的睡美人了。
LONG
);
        set("outdoors", "wudu");
        set("exits", ([
                "west" : __DIR__"road7",
                "northeast" : __DIR__"daguanlou",
        ]));
        setup();
        replace_program(ROOM);
}

