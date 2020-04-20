// yu.c

inherit NPC;

string ask_jiasha();

void create()
{
	set_name("余沧海", ({ "yu canghai", "yu", "canghai" }));
	set("gender", "男性");
	set("age", 52);
	set("long", "他身形矮小，可是神情凝重，俨然一派大宗师气。\n");
	set("class", "taoist");
	set("combat_exp",6400000);
	set("shen_type", -1);
	set("inquiry",([
		"辟邪剑谱": "我也一直在苦寻辟邪剑谱的下落，莫非你知道它的下落？",
		"林家袈裟": (: ask_jiasha() :),
	]));
	
	set("max_neili",12000);
	set("neili",12000);
	set("max_qi",60000);
	set("qi",60000);
	set("max_jing",60000);
	set("jing",60000);
	set("max_jingli",10000);
	set("jingli",10000);

	set_temp("apply/damage",400);
	set_temp("apply/armor",500);

	set_skill("literate",400);
	set_skill("unarmed",400);
	set_skill("kuihua-xinfa",400);
	set_skill("parry",400);
	set_skill("force",400);
	set_skill("dodge",400);
	set_skill("changquan",400);
	set_skill("pixie-jian",400);
	set_skill("sword",400);

	map_skill("sword","pixie-jian");
	map_skill("parry","pixie-jian");
	map_skill("dodge","pixie-jian");
	map_skill("force","kuihua-xinfa");
	map_skill("unarmed","changquan");

	create_family("青城派", 7, "掌门");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

string ask_jiasha()
{
	int i;
	object me,npc;
	me = this_player();
	
	if(!me->query_temp("ask_linpingzhi") || query_temp("be_ask"))
		return "别问我，我什么也不知道。";
	
	if(me->query_temp("ask_yu_jiasha") >= 2){
		command("say 天堂有路你不走，地狱无门你偏进来！");
		command("say 青城弟子何在？给我拿下这"+ RANK_D->query_rude(me)+"！！");
		message_vision("青城派弟子一拥而上，纷纷拔剑相迎，冲着$N围成了一圈！\n",me);
		for(i=0;i<25;i++){
			npc=new("/kungfu/class/qingcheng/dizi");
			npc->move("/d/qingcheng/songfengguan");
			if(environment(me))
			npc->kill_ob(me);
			me->kill_ob(npc);
		}
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
		set_temp("be_ask",1);
		return RANK_D->query_rude(me)+"！纳命来！";
	}
	if(me->query_temp("ask_yu_jiasha") >= 1){
		me->set_temp("ask_yu_jiasha",2);
		return "我说了，我什么都不知道，你在不离开，休怪我不客气！！";
	}

	if(!me->query_temp("ask_yu_jiasha")) me->set_temp("ask_yu_jiasha",1);
	return "我不知道。青城派不是你随意进出的地方，还请尽快离开！";
}
void reset()
{
	delete_temp("be_ask");
}
void afterdie_func(object killer)
{
	if(killer->query_temp("ask_linpingzhi")
	&& killer->query_temp("ask_yu_jiasha") > 1)
	set("killer",killer->query("name"));
}
