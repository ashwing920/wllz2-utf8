//jianyu.c
// Design By Robert 蝴蝶君

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","暗房");
	set("long",@LONG
这里是关押那些喜欢胡作非为，扰乱治安的非法份子专用的暗房。暗
房里一片漆黑，伸手不见五指，关到这里来，动也动不了，只能面对着那
面潮湿阴冷的墙壁，面壁思过。
LONG
);
	set("valid_startroom",1);
	set("no_fight",1);
	set("no_kill",1);
	set("no_steal",1);
	set("no_magic",1);
	set("no_spells",1);
	set("no_beg",1);
	set("parsion_room",1);
	setup();
}
void init()
{
	object ob,*all;
	int i;

	if(interactive(ob = this_player()) && !wizardp(ob)){
		all = all_inventory(ob);
		for (i = 0; i<sizeof(all); i++) {
		if(all[i]->query("equipped"))
			all[i]->delete("equipped");
			destruct(all[i]);
		}
		ob->set("startroom","/adm/parsion/jianyu");
		ob->disable_player("<面壁中>");
	}
}
