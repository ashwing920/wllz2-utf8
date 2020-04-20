// damen.c 大门
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "全真教大门");
        set("long", @LONG
你已走到了终南山半山腰，前面就是全真教的总部重阳宫了。殿宇依
山而筑，高低错落有致。周围古木森森，翠竹成林，景色清幽。正前方黄
墙碧瓦，飞檐翘檩，正中有一道二丈来宽，三丈来高的朱红杉木包铜大门
(gate)，气势不凡。门上挂着一块匾(bian)，门前的石柱上挂着一副对联
(duilian)。
LONG
);
        set("exits", ([
                "westdown" : __DIR__"jiaobei",
                "east":      __DIR__"datang1",
        ]));
        set("outdoors", "quanzhen");
        set("item_desc", ([
                "gate":"一道三丈来高的"HIR"朱红杉木"HIY"包铜"NOR"大门。\n",
                "bian": @TEXT 
$CYN$           
＊＊＊＊＊＊＊＊＊＊＊＊＊
＊＊　　　　　　　　　＊＊
＊＊　全　真　古　刻  ＊＊
＊＊　　　　　　　　　＊＊
＊＊＊＊＊＊＊＊＊＊＊＊＊
$NOR$
TEXT,
                "duilian": @TEXT
$HIY$
        一      地
        生      法
                天
                天
        生      法
        三      道
        三      道
        生      法
        万      自
        物      然
$NOR$   
TEXT
        ]) );
        set("objects",([
                __DIR__"npc/zhike" : 1,
                CLASS_D("quanzhen")+"/master_quanzhen": 1,
        ]));
        setup();
}
int valid_leave(object me,string dir)
{
        if(dir == "east"
        && present("zhike daozhang",environment(me))
        && me->query("family") && me->query("family/family_name") != "全真教")
                return notify_fail("知客道长说道：这位"+ RANK_D->query_respect(me)+"请回罢，重阳宫不接待俗人。\n");
                
        return ::valid_leave(me, dir);
}
