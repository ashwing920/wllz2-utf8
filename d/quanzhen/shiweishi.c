                                     // shiweishi.c 事为室
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "事为室");
        set("long", @LONG
这里是全真七子之首马钰的居室。房间很小，只摆放了一张床、一张
书桌和一把椅子。书桌上放着一本‘老子’，只看了一半，床上被褥折叠
得整整齐齐。
LONG
);
        set("exits", ([
                "south" : __DIR__"cetang",
        ]));

        set("objects", ([
               CLASS_D("quanzhen")+"/ma": 1,
        ]));
        setup();
        replace_program(ROOM);
}
