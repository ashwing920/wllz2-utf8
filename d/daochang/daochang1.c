// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;
#include <ansi.h>
void create()
{
	set("short","百人道场一层");
	set("long",@LONG
这里是百人道场的第一层，道场十分宽敞，可却门窗紧闭，只有东边
那道门，是通往道场休息室。道场中间墙壁上挂着一张字画，上面刚劲有
力的写着一个「拳」字。道场中间地面上画着一个圈子，圈中站着一个道
场弟子，据说只要打败了道场弟子就可以进入道场第二层进行更高的挑战
，武林虽大，能够成功闯过百人道场的人却是寥寥无几。
LONG
);

	set("lvl",1);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi1":1,
	]));
	::create();
}

void remove_no_fight()
{
        delete("no_fight");
}
void fullnow(object me)
{
    mapping my;
    object boss;

        me->remove_call_out("revive");
        me->remove_call_out("unconcious");
        remove_call_out("remove_no_fight");

        me->remove_all_enemy(1);
        //boss = query("boss", find_object(__DIR__"lgtd"));
        //if (objectp(boss)) boss->remove_all_enemy(1);
        set("no_fight", "1"); 

        my = me->query_entire_dbase();
        my["jing"]   = my["eff_jing"]   = my["max_jing"]; 
        my["jingli"] = my["eff_jingli"] = my["max_jingli"]; 
        my["qi"]     = my["eff_qi"]     = my["max_qi"]; 
        my["neili"]  = my["max_neili"];
        me->clear_condition();
        me->clear_weak();
        me->full_self();
        call_out("remove_no_fight", 2);
}


int user_cant_die(object me)
{
                if (!playerp(me)) {
                //destruct(me); 
                return 0;
        }
        if (userp(me)) {
                tell_object(me, CYN + "一个空洞的声音在你耳边响起：" + HIR + "你被杀死一次！\n" + NOR);
				fullnow(me);
				me->move(__DIR__"daochang_gate");
        }
        return 1;
}