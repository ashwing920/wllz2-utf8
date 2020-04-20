inherit ROOM;

void create()
{
        set("short", "小舍");
        set("long",@LONG
这间房舍小巧玲珑，颇为精雅。小舍匾额上写着「琴韵」两字笔致，
致颇为潇洒。远处的小屋露出一檐屋角。东西两边各有一条小径不知通向
哪里。
LONG);
        set("exits", ([
                "east" : __DIR__"xiaojing3",
                "north" : __DIR__"xiaodao",
                "west" : __DIR__"xiaojing1",
        ]));
        set("objects", ([
                CLASS_D("murong")+"/bao" : 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        mapping myfam;
        int i;
          
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "慕容世家" ) && dir == "west") {
                inv = all_inventory(me);
                for(i=sizeof(inv)-1; i>=0; i--)
        if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
        if(objectp(present("bao butong", environment(me))))
                return notify_fail("包不同拦住你说道：这位" +RANK_D->query_respect(me) + "请放下兵刃进入慕容家。\n");
        
        }
        return ::valid_leave(me, dir);
}
