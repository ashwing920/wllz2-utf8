//Room: slxl1.c 松林小路
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","松林小路");
	set("long",@LONG
这是山脚松林中的小路，两边长满参天的红松树，只能看见一线天空
。路旁有道士在奋力砍树。西边通向密林深处，东边可回大道。
LONG
);
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"slxl2",
		"east"  : __DIR__"wdroad10",
	]));
	setup();
}
void init()
{
	object ob,npc;
	int i;

	if(interactive(ob = this_player()) && ob->query_temp("ask_dudajin")
	&& present("yu daiyan",ob) && !ob->query_temp("pk_qiangdao")){
		say("几个黑衣人从丛林中跳了出来，喝道："+ RANK_D->query_rude(ob)+"，竟敢多管闲事！纳命来！\n");
		for(i=0;i<8;i++){
			npc = new("/d/wudang/npc/qiangdao");
			npc->move(environment(ob));
			npc->kill_ob(ob);
			ob->kill_ob(npc);
			npc->set_leader(ob);
		}

	}
}
int valid_leave(object me,string dir)
{
	if(present("yu daiyan",me) && me->query_temp("ask_dudajin")
	&& present("hei yiren",environment(me)))
		return notify_fail("黑衣人往你身前一挡，喝道："+ RANK_D->query_rude(me)+"休逃！纳命来！\n");
	return ::valid_leave(me, dir);
}
