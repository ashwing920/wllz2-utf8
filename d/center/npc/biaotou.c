// biaotou.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

#include <ansi.h>

inherit NPC;

string ask_job();
string ask_biaoyin();
int ask_yunbiao();
int ask_finish();

string *target_short = ({
	"武当山下小吃店",
	"少林山下山坡",
	"泰山升仙坊",
	"华山金锁关",
	"昆明近日古楼",
	"大理茶花山",
	"苏州春在楼",
	"蜀都广场",
	"泉州城外的茶亭",
	"相记钱庄",
	"杭州聚景园",
	"北京西门外",
	"天山脚下",
	"灵州大将军府",
	"襄阳大校场",
	"华山苍龙岭",
	"嘉峪关",
	"佛山英雄楼",
	"昆仑山下",
	"襄阳福威镖局",
	"泉州城外烟雨楼",
	"福州郊外的武夷山",
	"福州的福威镖局",
});
string *target_file = ({
	"/d/wudang/shop",
	"/d/shaolin/xiaojing1",
	"/d/taishan/shengxian",
	"/d/huashan/jinsuo",
	"/d/kunming/jinrilou",
	"/d/dali/chahuashan1",
	"/d/suzhou/jiudian",
	"/d/city3/guangchang",
	"/d/quanzhou/chating",
	"/d/city4/bank",
	"/d/hangzhou/jujingyuan",
	"/d/city2/ximenwai",
	"/d/xingxiu/shanjiao",
	"/d/lingzhou/jiangjungate",
	"/d/xiangyang/dajiaochang",
	"/d/huashan/canglong",
	"/d/xingxiu/jiayuguan",
	"/d/foshan/yingxionglou",
	"/d/mingjiao/shanjiao",
	"/d/xiangyang/biaoju",
	"/d/quanzhou/yanyu",
	"/d/fuzhou/wuyishan1",
	"/d/fuzhou/biaoju",
});
void create()
{
	set_name("都大锦", ({ "du dajin","du","dajin" }));
	set("title","龙门镖局");
	set("nickname",HIC"总镖头"NOR);
	set("long", @LONG
他就是龙门镖局的总镖头都大锦，为人仗义，在江湖中也颇有名气。
LONG
);
	set("rank_info/respect", "镖头");
	set("attitude", "friendly");
	set("age",34);
	set("gender", "男性" );
	set("combat_exp",1200000);
	set("shen_type",1);
	set("max_neili",40000);
	set("neili",40000);
	set("jiali",150);
	set("jingli",2000);
	set("max_jingli",2000);
	set("chat_chance_combat",120);
	set("chat_msg_combat", ({
		(: command("perform xianglong") :),
		(: command("exert powerup") :),
		(: command("perform leiting") :),
		(: command("exert recover") :),
	}) );
	set("inquiry", ([
		"难事":(: ask_job():),
		"忧虑之事": (: ask_job():),
		"龙门镖局": "江湖中人，龙门镖局无人不晓，莫非你也有事情委托我们镖局去办？",
		"殷素素":"谁不知道殷女侠是明教殷天正的女儿，这姑娘，唉......",
		"保镖": (: ask_yunbiao() :),
		"镖银": (:ask_biaoyin():),
		"俞岱岩": (: ask_biaoyin() :),
	]));

	set_skill("unarmed",200);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("force",200);
	set_skill("huntian-qigong",200);
	set_skill("xianglong-zhang",200);
	set_skill("xiaoyaoyou",200);
	map_skill("unarmed","xianglong-zhang");
	map_skill("parry","xianglong-zhang");
	map_skill("dodge","xiaoyaoyou");
	map_skill("force","huntian-qigong");        
	set("shen_type",1);
	set("env/wimpy",20);        
	setup();       
	carry_object("/clone/cloth/cloth")->wear();       // 装备
	add_money("gold",1);                           // 金钱
}

string ask_job()
{
	object me;
	me = this_player();
	
	if(me->query("marks/都大锦"))
		return "多谢这位"+ RANK_D->query_respect(me)+"相救，解决了我们镖局的一件大事。";
	
	if(me->query_temp("ask_dudajin"))
		return "请这位"+ RANK_D->query_respect(me)+"赶紧动身，将镖送到武当山去。";

	if(query("yudaiyan"))
		return query("yudaiyan") +"已经替我们镖局将俞岱岩俞大侠送走了，我也终于可以放心了！";
	
	me->set_temp("ask_dudajin",1);
	say(this_object()->name()+"说道：这位"+ RANK_D->query_respect(me)+"，实不相瞒，前些日子我们镖局来了一个女扮男妆\n"
	"的人，送来了一个已经奄奄一息的人，要我们送到武当山去。老夫仔细一\n"
	"看那正是武当派的俞岱岩俞大侠，伤重之势，唯恐已经时日不久了。那人\n"
	"悬银五万两，将镖送到武当山去，否则杀光我们镖局上下所有人。可是，\n"
	"我们与武当派素无来深，唯恐武当派误会俞大侠是遭我龙门镖局的毒手......\n");
	return "要是这位"+ RANK_D->query_respect(me)+"能将镖银代我们送去，那在下真是感激不尽啊。";
}
string ask_biaoyin()
{
	object me,npc;
	me= this_player();
	
	if(me->query("marks/都大锦") || !me->query_temp("ask_dudajin")) 
		return "镖局目前尚无镖银可送，这位"+ RANK_D->query_respect(me)+"还是请回吧。";
	
	if(me->query_temp("get_biaoyin"))
		return "那俞大侠就有劳"+ RANK_D->query_respect(me)+"替我送去了。";

	say(this_object()->name()+"回头对两个趟子说道：把俞大侠抬出来。\n"
	"两个趟子手抱拳道：是！\n"
	"不一会儿，从内堂中抬出了一个奄奄一息的人。你仔细一看，那人正是武当派的俞岱岩。\n");
	npc = new("/d/center/npc/yudaiyan");
	npc->move(environment(me));
	npc->unconcious();
	me->set_temp("get_biaoyin",1);
	me->set_temp("get_yu",npc);
	set("yudaiyan",me->name(1));
	return "这位"+ RANK_D->query_respect(me)+"，那俞大侠就有劳您照顾了。";
}
void create_quest(object me)
{
	object obj;
	mapping quest;
	int time,i;
	string target,msg;

	string *npc = ({
		"/d/center/biaoju/fuhao",
		"/d/center/biaoju/tanguan",
		"/d/center/biaoju/gongzi",
		"/d/center/biaoju/dadao",
	});

	quest = ([ ]);
	
	time = time() + (4 * 150 + random(70));
	obj = new(npc[random(sizeof(npc))]);
	i = random(sizeof(target_short));

	quest["exp_bonus"] = 55 + random(25);
	quest["pot_bonus"] = 65 + random(35);
	quest["quest_type"] = "护送";
	quest["from"] = "镖局";
	quest["task_time"] = time;
	quest["score"] = 1;
	quest["weiwang"] = 1;
	quest["diff"] = 3 + random(3);
	quest["target"] = target_file[i];
	quest["where"] = target_short[i];
	quest["quest"] = obj->name();
	quest["obj"] = obj;
	me->set("quest",quest);
	me->set("title","龙门镖局保镖");
	
	obj->set("target",target_short[i]);
	obj->set("target_file",target_file[i]);
	obj->set("back_time",time);
	obj->set("guard",me);
	msg = obj->query_move_msg();
	obj->move(environment(me));
	message("vision",msg,environment(obj),obj);
}
int ask_yunbiao()
{
	object me,ob,obj;
	mapping quest;
	string msg;
	
	me = this_player();
	ob = this_object();
	
	if((int)me->query("combat_exp") < 3000000){
		command("say 保镖之事十分艰险，依我看这位"+ RANK_D->query_respect(me)+"恐怕还难以担此大任。");
		return 1;
	}
	if((int)me->query("combat_exp") > 15000000){
		command("say "+ RANK_D->query_respect(me)+"德高望重，小小镖局，岂敢劳烦这位"+ RANK_D->query_respect(me)+"呀！");
		return 1;
	}
	if((int)me->query("bjquest_fail_time") > time()){
		command("say 你去好好休息吧，迟些时候有镖要送再叫你。");
		return 1;
	}
	if(mapp(quest = me->query("quest"))){
		if(quest["from"] != "镖局"){
			command("say 这位"+ RANK_D->query_respect(me)+"切勿把保镖当作儿戏，还是先把其他事情做好再说吧。");
			return 1;
		}
		if(quest["task_time"] > time()){
			command("say 镖局的客人"+ quest["quest"] +"安全护送到"+ quest["where"]+"去了嘛？");
			return 1;
		}
		else {
			command("say 好吧，那我就再给你一次机会。");
			me->receive_damage("qi",100,ob);
			if(me->query("quest")) me->delete("quest");
			me->delete_temp("count");
		}
	}
	create_quest(me);
	switch(random(3)){
		case 1:
			msg = sprintf("都大锦说道：你来得正好，马上将这位大人护送到%s，务必一路保护他的安全。\n",
				me->query("quest/where"));
				break;
		case 2:
			msg = sprintf("都大锦指了指%s，说道：这位大人打算前往%s办事，\n"
				"你随他一同前往；路途艰险，务必一路保护他的安全，将他安全送到。\n",
				me->query("quest/quest"),me->query("quest/where"));
				break;
		default:
			msg = sprintf("都大锦说道：来得正好！你随这位大人一起到%s去，务必一路细心保护他的安全。\n",
				me->query("quest/where"));
				break;
	}
	say(msg);
	if(objectp(obj = me->query("quest/obj")) 
		&& environment(obj) == environment(me)){
		msg = obj->query_emote();
		message_vision(msg,obj,me);
	}
	return 1;
}
int accept_object(object who, object ob)
{
	object obj;
	mapping quest;

	if (ob->query("money_id")){
		if(!mapp(quest = who->query("quest")) || quest["from"] != "镖局"){
			command("say 这位"+ RANK_D->query_respect(who) +"莫非是有要事委托？");
			return 0;
		}
		if ( ob->value() < 3000) {
			command("say 这位"+ RANK_D->query_respect(who)+"未必也太小看我们镖局了吧？！");
			return 0;
		}
		if( who->query("quest")) {
			command("say 好吧，我让其他趟子手去做！你下去休息吧！");
			if(objectp(obj = who->query("quest/obj"))) destruct(obj);
			if(who->query("weiwang") > 20) who->add("weiwang",-20);
			who->delete("quest");
			who->delete_temp("count");
			who->set("bjquest_fail_time", time() + 60);
			return 1;
		}
	}
	command("say 这位"+ RANK_D->query_respect(who) +"莫非是有要事委托？");
	return 0;
}
void reset()
{
	if(query("yudaiyan"))
		delete("yudaiyan");
}