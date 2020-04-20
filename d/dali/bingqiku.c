//Room: /d/dali/bingqiku.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short","兵器房");
        set("long",@LONG
这里是镇南王府的兵器房，四周放这几个兵器架，上面是王府家人弟
子平时练剑用的竹剑。
LONG
);
        set("objects", ([
                "/clone/weapon/zhujian" : 4,
                __DIR__"npc/huyuan": 5,
        ]));
        set("exits",([ /* sizeof() == 1 */
                "south"  : __DIR__"chahua1",
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        int i, j;
        object *inv;
        inv = all_inventory(me);
        i = sizeof(inv);
        for (i = 0; i < sizeof(inv); i++){
                if (inv[i]->query("id") == "zhujian") j++;
     }
        if (j > 1)
                return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一把竹剑就够啦。\n");
        return ::valid_leave(me, dir);
}
