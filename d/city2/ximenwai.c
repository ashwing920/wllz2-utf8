//Design By Robert 蝴蝶君 email:stcoolman@21cn.com


inherit ROOM;

void create()
{
        set("short", "西门外");
        set("long", @LONG
这里是北京的西城门外。出入于这里的，多是一些来往的商人和游客
，人头攒攒，十分热闹。
LONG
);
        set("exits", ([
                "east" : __DIR__"ximen",
        ]));
        
        
        set("outdoors", "city2");
        
        setup();
        replace_program(ROOM);
}
