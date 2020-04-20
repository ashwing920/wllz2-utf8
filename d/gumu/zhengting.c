// zhengting.c 正厅
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "正厅");
        set("long", @LONG
这里是古墓的正厅，本来应该停放灵柩棺木之类的东西，却不知道被
人般到哪里去了。厅正中端坐着一位白衣少女和一个独臂的汉子，他们就
是江湖上鼎鼎大名，有着神仙情侣之称的杨过和小龙女。正厅摆设简单，
显得格外简陋。站在这里，不时感到从东边传来阵阵寒意。
LONG
);
        set("exits", ([
                "west" : __DIR__"liangong",
                "north" : __DIR__"xiaoting",
                "south" : __DIR__"houting",
                "east":  __DIR__"cool-bed",
        ]));
        set("objects", ([
                CLASS_D("gumu") +"/longnv" : 1,
                CLASS_D("gumu") +"/master_gumu" : 1,
        ]));
        set("no_sleep_room",1);
        set("valid_startroom",1);
        setup();
        "/clone/board/gumu_b"->foo();
}
