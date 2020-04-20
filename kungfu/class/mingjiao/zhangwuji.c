//zhangwuji.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("张无忌", ({ "zhang wuji", "zhang", "wuji" }));
	set("long",@LONG
明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，「九阳神功
」、「乾坤大挪移」独步天下，是江湖中不世出的少年英雄。
LONG
);
	set("nickname",HIR"多情总被多情伤"NOR);
	set("gender", "男性");
	set("age", 20);
	set("shen_type",1);
	set("attitude", "friendly");
	set("class", "fighter");

	set("per", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set("chat_chance_combat",120);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate":),
		(: perform_action, "cuff.zhen" :),
		(: perform_action, "cuff.qishang" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "sword.duo" :),
		(: command("nuoyi zhang wuji") :),
	}) );

	set_skill("staff",800);
	set_skill("claw",800);
	set_skill("strike",800);
	set_skill("force", 800);
	set_skill("unarmed", 800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("sword",800);
	set_skill("blade", 800);
	set_skill("throwing",800);
	set_skill("perception",800);
	set_skill("tulong-daofa",800);
	set_skill("duoming-jinhua",800);
	set_skill("hunyuan-yiqi",800);
	set_skill("jiuyang-shengong", 800);
	set_skill("qiankun-danuoyi", 800);
	set_skill("qishang-quan", 800);
	set_skill("taiji-quan",800);
	set_skill("taiji-dao",800);
	set_skill("shenghuo-ling",800);
	set_skill("cuff",800);
	set_skill("literate",800);
	set_skill("shenghuo-shengong",800);

	map_skill("dodge", "qiankun-danuoyi");
	map_skill("unarmed", "taiji-quan");
	map_skill("sword","shenghuo-ling");
	map_skill("parry","qiankun-danuoyi");
	map_skill("blade","tulong-daofa");
	map_skill("throwing","duoming-jinhua");
	map_skill("cuff","qishang-quan");
	map_skill("force", "shenghuo-shengong");

	create_family("明教",34,"教主");

	set("chat_chance",2);
	set("chat_msg",({
		"张无忌愤然说道：大丈夫当以国为家，捐躯沙场，抗元大业未成，同辈仍需努力！\n",
		"张无忌叹道：人生失一知己，生亦何欢，死亦何忧，敏儿，你在哪里？\n",
		"张无忌道：我教兄弟听了：生于乱世，当克己为公，行侠仗义，荡寇驱魔！\n",
	}));
	set("inquiry",([
		"金毛狮王" : "那是我义父谢大侠的职司。\n",
		"谢逊" :     "他就是我义父的大号。\n",
		"张翠山" :   "你想找我父亲有事麽？\n",
		"殷素素" :   "我妈是明尊座下紫微堂主。\n",
		"张三丰" :   "我太师父近来可好？\n",
		"赵敏" :     "人生失一知己，生亦何欢，死亦何忧，敏儿，你在哪里？\n",
		"小昭" :     "小昭我可一直念着她的好处。\n",
		"周芷若" :   "找她就去峨嵋山, 别来烦我。\n",
	]));
	setup();
	carry_object("/d/mingjiao/obj/yitianjian");
	carry_object("/clone/book/shenghuo-ling");
	carry_object("/clone/weapon/xlongquan");
	carry_object("/clone/cloth/cloth")->wear();

	add_money("silver",50);
}

void init()
{
	object ob;

	if (interactive(this_player()) && this_player()->query_temp("fighting")){
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob=this_player()) && !is_fighting()){
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000){
		command("say 邪魔歪道！受死吧！");
		command("wield yitian jian");
		this_object()->kill_ob(ob);
	}
	else if((int)ob->query("shen")<-5000){
		command("say 魔从心起，于武学不利，其道必诛，劝君放下屠刀，立地成佛。");
	}
	else if((int)ob->query("shen")<-100){
		command("say 这位朋友，人行江湖，言行当正，切务走进邪魔歪道。");
	}
	else if((int)ob->query("shen")>=0){
		command("say 光明正道任人走，劝君多加保重。");
	}
	else if((int)ob->query("shen")>100000){
		command("say 大侠在上，受无忌一礼，"+ RANK_D->query_respect(ob) +"它日必为武林翘楚。");
	}
	return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20){
		command("say 你的悟性太低了，不适合学习我的功夫。");
		return;
	}
	if((string)ob->query("gender")=="无性"){
		command("say 你阳气不足，习我功夫恐将走火如魔。");
		return;
	}
	if((int)ob->query("shen") <= 200000){
		command("say 你应当多作些行侠仗义的事，以修身心。");
		return;
	}
	if((int)ob->query_skill("jiuyang-shengong",1) < 200){
		command("say 你的九阳神功还未到火候，无法再学习上乘的武功！");
		return;
	}
	command("say 好，我就收下你这位好徒弟！");
	command("say 你的职司就是本教的光明使者。");
	command("recruit " + ob->query("id"));
	return;
}

int accept_fight(object ob)
{
	if(((int)ob->query("combat_exp") < 300000)&&((int)ob->query("shen")>0)){
		command("say 武林中人最忌争强斗狠，你不是我的对手，回去吧。\n");
		return 0;
	}
	return 1;
}