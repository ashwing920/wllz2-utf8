// inn_2f.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

string look_sign(object me);
int valid_leave(object me,string dir);

void create()
{
        set("short", "桃源客栈二楼");
        set("long", @LONG
这里是桃源城客栈二楼的走廊。你可以听到一些客房里不时地传出呼
呼的打酣声，一阵高过一阵。不时有睡意朦胧的旅客进进出出。走廊前面
挂着一个牌子(sign)。
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :), 
        ]) );

        set("exits", ([ 
             "down" :    __DIR__"inn" ,
                "1" :    __DIR__"inn_2f1" ,
                "2" :    __DIR__"inn_2f2" ,
                "3" :    __DIR__"inn_2f3" ,
                "4" :    __DIR__"inn_2f4" ,
                "5" :    __DIR__"inn_2f5" ,
        ]) );

        setup();
}

string look_sign(object me)
{
        return "牌子写著：前两间“双”字号是夫妻房，其余都是单人房。\n";
}

int valid_leave(object me,string dir)
{
        mapping exits;
        object env, *inv;
        int i, total;

        env = environment(me);
        if( dir != "down" ) {
                if( mapp(exits = env->query("exits")) && !undefinedp(exits[dir]) ) {
                        if( ! objectp(env = find_object(exits[dir])) ) {
                                call_other(exits[dir], "???");
                                env = find_object(exits[dir]);
                        }
                        inv = all_inventory(env);
                        total = 0;
                        for(i=0; i<sizeof(inv); i++) {
                                if( inv[i]==me ) continue;
                                if( inv[i]->is_corpse() ) continue;
                                if( !inv[i]->is_character()) continue;
                                if( !me->visible(inv[i]) ) continue;
                                total ++;
                        }
                }
        }
        return ::valid_leave(me,dir);
}
