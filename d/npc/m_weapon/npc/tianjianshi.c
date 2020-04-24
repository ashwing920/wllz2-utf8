// npc: /d/npc/m_weapon/npc/tianjianshi.c

#include <ansi.h>
inherit NPC;

int do_weapon();
int do_change();
int ask_kaifeng();
object creat_weapon();

void create()
{
	set_name("欧冶子", ({ "ouye zi", "zi" }) );
	set("nickname", RED "赤心剑胆" NOR );
	set("gender", "男性" );
	set("age", 60);
	set("long",@LONG
他头上包着头巾，三缕长髯飘洒胸前，面目清瘦但红晕有光，二目炯炯有
神，烁烁闪着竟似是凛凛的剑光，浑身似乎都包围在一股剑气之中。
LONG
);
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",5000);
	set("jiali",50);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("claw",200);
	set_skill("jiuyin-baiguzhao",200);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("bibo-shengong",100);
	set_skill("luoying-shenjian",100);
	set_skill("parry",90);
	set_skill("anying-fuxiang",100);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);

	create_family("玄天派",1,"弟子");

	set("combat_exp", 250000);
	set("score",0);
	
	map_skill("force","bibo-shengong");
	map_skill("parry","luoying-shenjian");
	map_skill("sword","luoying-shenjian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("dodge","anying-fuxiang");

	
	set("attitude", "peaceful");
	set("inquiry", ([
		"铸剑"  : "铸剑可是件十分艰苦的事，要消耗人的精气和内力，你有决心和毅力吗？\n",
		"原料"  : "铸剑可用千年玄铁....你找到了我才能帮你铸剑。\n",
		"兵器"  :  (: do_weapon() :),
		"改造兵器": (: do_change() :),
		"兵器开锋": (: ask_kaifeng() :),
	]) );

	setup();
	set("chat_chance", 3);
	set("chat_msg", ({
		 "欧冶子抚剑而歌：巨阙神兵兮，人铸就。盖世宝剑兮，配英雄！\n",
		 "欧冶子低头沉吟，似乎在思考什么。\n"
		 "欧冶子叹了一口气：神兵配英雄，可英雄......\n"
	}) );
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	add_action("do_answer","answer");
	add_action("do_modify","改");
}
int accept_object(object who, object ob)
{       

	if( who->query_temp("change_weapon")){
		if(ob->query("money_id") && ob->value() >= 20000000){
			tell_object(who,this_object()->name() +"说道：请输入：改 （兵器类型）\n");
			who->set_temp("changed",1);
			who->delete_temp("change_weapon");
			return 1;
		}
		else {
			tell_object(who,this_object()->name() +"说道：重新打造兵器一次要二千两黄金呢！\n");
			return 0;
		}
	}

       switch ((string)ob->query("name") ) {
		case "菩提子"  :
		case "叫化鸡"  :
		case "手镯":
		case "辟邪剑谱":
		case "白虎堂令牌":
			if( (who->query_temp("condition")) != (string)ob->query("name")  ){
				message_vision("欧冶子一愣：我对你说过我要这样东西么？\n", who);
				return 1;
			}
			else {
			who->delete_temp("condition");
			message_vision("欧冶子微笑着：很好很好！那我就帮你这一次吧！\n", who);
			who->set_temp("condition_ok",1);
			do_weapon();
			return 1;
			}
	}
	if((int)(who->query("weapon/make")) ){
		say("欧冶子一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？\n");
		return 1;
	}
	if(who->query_temp("have_orc")){
		say("欧冶子说道：你不是有原料了吗？\n");
		return 0;
	}
	switch ((string)ob->query("id") ) 
	{
		case "shen mu": 
			who->set_temp("or",1);
			who->set_temp("get_orc",1);
			break;
		case "jin mu":
			who->set_temp("or",2);
			who->set_temp("get_orc",1);
			break;
		case "han zhu": 
			who->set_temp("or",3);
			who->set_temp("get_orc",1);
			break;
		default :
			message("vision","这是什么！这不能用来打造兵器！",who);
			return 1;
	}
	message("vision","欧冶子低头检视了一下手中的"+(string)ob->query("name")+
			"点了点头说：\n",who);
	write("我这儿可以打造以下兵器：\n"+
		  "      剑(sword)\n"+
		  "      刀(blade)\n"+
		  "      棍(stick)\n"+
		  "      杖(staff)\n"+
		  "      锤(hammer)\n"+
		  "      鞭(whip)\n");          
	say("这位"+RANK_D->query_respect(who)+"要造什么兵器？决定了告诉我(answer)。\n");
	return 1;

}

int do_answer(string arg)
{
	object me,w_or;
	me = this_player();

	if(!me->query_temp("get_orc"))
		return notify_fail("欧冶子疑道：你找到原料了吗？\n");
       
	if(!arg)
		return notify_fail("欧冶子疑道：你要造什么兵器？\n");

	if(me->query_temp("have_orc"))
		return notify_fail("欧冶子说道：你不是有原料了吗？\n");

	message("vision",me->name()+"对欧冶子轻声说了几句。\n",environment(me), ({me}) );
	switch (arg) {
	  case "sword" :
		me->add_temp("sword",1);
		write("带着原料去找侍剑吧！\n");
		message("vision","去吧！"+me->name()+"！\n",me);
		break;
	  case "blade" :
		me->add_temp("blade",1);
		write("带着原料去找侍刀吧！\n");
		message("vision","去吧！"+me->name()+"！\n",me);
		break;
	  case "stick" :
		me->add_temp("club",1);
		write("带着原料去找侍棍吧！\n");
		message("vision","去吧！"+me->name()+"！\n",me);
		break;
	  case "staff" :
		me->add_temp("staff",1);
		write("带着原料去找侍杖吧！\n");
		message("vision","去吧！"+me->name()+"！\n",me);
		break;
	  case "hammer" :
		me->add_temp("hammer",1);
		write("带着原料去找侍锤吧！\n");
		message("vision","去吧！"+me->name()+"！\n",me);
		break;
	  case "whip" :
		me->add_temp("whip",1);
		write("带着原料去找侍鞭吧！\n");
		message("vision","去吧！"+me->name()+"！\n",me);
		break;
	  default :
		message_vision("欧冶子一脸狐疑：什么兵器？\n",me);
		return notify_fail("欧冶子仔细的说：此事不可儿戏，请慎重！！\n");
	}
	switch ( me->query_temp("or") ) {
	  case 1:
		w_or = new("/d/npc/m_weapon/tan/item/shenmu",1);
		w_or->move(me);
		message_vision(HIC "欧冶子给了$N一块千年神木。\n" NOR, me);
		me->delete_temp("get_orc");
		me->delete_temp("or");
		me->set_temp("have_orc",1);
		break;
	  case 2:
		w_or = new("/d/npc/m_weapon/tan/item/jinmu",1);
		w_or->move(me);
		message_vision(HIC "欧冶子给了$N一块海底金母。\n" NOR, me);
		me->delete_temp("get_orc");
		me->delete_temp("or");
		me->set_temp("have_orc",1);
		break;
	  case 3:
		w_or = new("/d/npc/m_weapon/tan/item/hanzhu",1);
		w_or->move(me);
		message_vision(HIC "欧冶子给了$N一块寒丝羽竹。\n" NOR, me);
		me->delete_temp("get_orc");
		me->delete_temp("or");
		me->set_temp("have_orc",1);
		break;
	}
	return 1;
}

int do_weapon()
{
	object me,weapon,obj;
	string w_id;
	me = this_player();
	w_id = me->query("weapon/name");

	if( !(me->query("weapon/make")) )
		return notify_fail("你造过兵器吗？\n");

	if(objectp(obj = present("my sword", me)) 
	&& objectp(obj = present("my blade", me))
	&& objectp(obj = present("my staff", me))
	&& objectp(obj = present("my whip", me))
	&& objectp(obj = present("my club", me))
	&& objectp(obj = present("my hammer", me)))
	{
		say("欧冶子脸色一沉：您的武器不就在你手边么？还来干什么！\n");
		return 1;
	}
	if (me->query_temp("condition") )
	{
		say("欧冶子脸色一沉：不是让你去拿"+(me->query_temp("condition") )+"了么？还没拿到回来干嘛！\n");
		return 1;
	}

	if( !(me->query_temp("condition_ok")) ) {
		message_vision(HIY "这位"+RANK_D->query_respect(me)+"想要重新得到兵器？这不难。不过......\n" NOR, me);
		message_vision(HIY "欧冶子沉吟了一下说：你得找到我要的东西。\n" NOR, me);
		switch( random(5) ) {
			case 0:
				message_vision("拿到菩提子，再来吧！\n",me);
				me->set_temp("condition","菩提子");
				break;
			case 1:
				message_vision("给我叫化鸡，我就帮你！！\n",me);
				me->set_temp("condition","叫化鸡");
				break;
			case 2:
				message_vision("嗯...你就拿黑木崖白虎堂令牌来换吧！！\n",me);
				me->set_temp("condition","白虎堂令牌");
				break;
			case 3:
				message_vision("....我想看看有名的手镯！\n",me);
				me->set_temp("condition","手镯");
				break;
			case 4:
				message_vision("如果你能替我找到辟邪剑谱的话......\n",me);
				me->set_temp("condition","辟邪剑谱");
				break;
			}
		}
	else    {
		say("开始制造1\n");
		me->delete_temp("condition_ok");
		say("开始制造\n");
		weapon = creat_weapon();
		weapon->move(me);
	}
	return 1;
}

object creat_weapon()
{
	object me,weapon;
	string mask;    //the verible that record the type of weapon
	me = this_player();
	mask = me->query("weapon/type");
	write(mask+"ok\n");
	switch(mask)    {
		case "剑":
			weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
			return weapon;
		case "刀":
			weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
			return weapon;
		case "棍":
			weapon = new("/d/npc/m_weapon/weapon/m_club",1);
			return weapon;
		case "杖":
			weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
			return weapon;
		case "锤":
			weapon = new("/d/npc/m_weapon/weapon/m_hammer",1);
			return weapon;
		case "鞭":
			weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
			return weapon;
	}
}
int do_change()
{
	object me;
	me = this_player();
	
	if(!me->query("weapon")){
		message_vision("$N对$n疑道：你有打造过兵器吗？\n",this_object(),me);
		return 1;
	}
	
	message_vision("$N笑道：这位"+RANK_D->query_respect(me)+"要改兵器类型，你有二千两黄金吗？\n",this_object());
	me->set_temp("change_weapon",1);
	return 1;
}

int do_modify(string arg)
{
	object me;
	me = this_player();
	
	if(!me->query_temp("changed")
	|| !me->query("weapon")) return 0;

	if( !arg || arg == "") return notify_fail("指令格式：改 （兵器类型）\n");
	
	if(arg != "剑" && arg != "刀" && arg != "棍" 
	&& arg != "鞭" && arg != "锤" && arg != "杖" )
		return notify_fail("请输入你要修改的类型！（剑、刀、棍、鞭、锤、杖）\n");
	
	if( arg == (string)me->query("weapon/type"))
		return notify_fail(this_object()->name()+"疑道：你这不是送钱给我花吗？\n");
	
	switch(arg){
		case "剑":
			me->set("weapon/type","剑");
			tell_object(me,this_object()->name()+"说道：兵器修改好了，重新进入后才可以生效！\n");
			me->save();
			break;
		case "刀":
			me->set("weapon/type","刀");
			tell_object(me,this_object()->name()+"说道：兵器修改好了，重新进入后才可以生效！\n");
			me->save();
			break;
		case "棍":
			me->set("weapon/type","棍");
			tell_object(me,this_object()->name()+"说道：兵器修改好了，重新进入后才可以生效！\n");
			me->save();
			break;
		case "鞭":
			me->set("weapon/type","鞭");
			tell_object(me,this_object()->name()+"说道：兵器修改好了，重新进入后才可以生效！\n");
			me->save();
			break;
		case "锤":
			me->set("weapon/type","锤");
			tell_object(me,this_object()->name()+"说道：兵器修改好了，重新进入后才可以生效！\n");
			me->save();
			break;
		case "杖":
			me->set("weapon/type","杖");
			tell_object(me,this_object()->name()+"说道：兵器修改好了，重新进入后才可以生效！\n");
			me->save();
			break;
		default:
			tell_object(me,"没有这种类型！\n");
			break;
		}
	me->delete_temp("change_weapon");
	me->delete_temp("changed");
	return 1;
}
int ask_kaifeng()
{
	object me;
	me = this_player();
	
	if(!me->query("weapon")){
		command("say 开锋兵器需要集天时、地利、人和，你连独门的兵器都没有，就更别说开锋你的兵器了。");
		return 1;
	}
	if((int)me->query("weapon/lv") < 30){
		command("say 你的兵器等级还不够，就算开锋了，也未能激发其灵性。");
		return 1;
	}
	if((int)me->query("weapon/changed")){
		command("say 这位"+ RANK_D->query_respect(me)+"的独门兵器是否可手呀？");
		return 1;
	}
	command("think");
	command("say 相传有一位著名的铁匠，隐居在绝缘之地，你可以到绝缘之地看看，有缘的话，或许他会答应你的。");
	me->set_temp("ask_ouyezi",1);
	return 1;
}
