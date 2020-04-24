// zhu.c 朱熹

#include <ansi.h>

inherit NPC;

int ask_weapon();
void kaifeng(object me);
void create()
{
	set_name("白发老者", ({ "lao zhe","master" }));
	set("title",HIY"隐居深山，不亦乐乎"NOR);
	set("long",@LONG
一位清瘦的白发老者，年约七旬，却是鹤发童颜，深陷的眼睛里依然炯炯
有神。
LONG
);
	set("gender", "男性");
	set("age",75);
	set("int",155);
	set("max_qi",20000);
	set("qi",20000);
	
	set_skill("literate", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage", 120);

	set("combat_exp",3200000);
	set("shen_type", 1);
	set("inquiry", ([
		"开锋": (: ask_weapon() :),
		"here": "这里是绝缘之地，顾名思义就是与世外隔绝的意思。",
		"name": "哈哈！老朽我连自己姓甚名谁都忘记了，姓什么名什么并不重要，只要活的逍遥自在！",
		"rumors": "老朽不知！",
	]));
	setup();
}

void init()
{          
	object ob; 
	ob = this_player();
	
	if( interactive(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(NATURE_D->is_night()){
		message_vision("$N挥挥手道：夜深了，老朽要休息了，这位"+ RANK_D->query_respect(ob)+"请回吧！\n",this_object(),ob);
		ob->move("/d/forest/outside02");
		tell_room(environment(ob),ob->name()+"被人从茅屋里赶了出来，吃了一顿闭门羹，模样十分狼狈。\n",({ob}));
	}
	else {
		message_vision("$N看了$n一眼，甚是惊讶的说道：这位"+ RANK_D->query_respect(ob)+"可真是有缘人呀！请进，请进！\n",this_object(),ob);
	}
	return;
}
int ask_weapon()
{
	object me;
	me = this_player();
	
	if(!(int)me->query_temp("ask_ouyezi") || (int)me->query("weapon/changed")) return 0;
	if(NATURE_D->is_night()){
		message_vision("$N挥挥手道：夜深了，老朽要休息了，这位"+ RANK_D->query_respect(me)+"请回吧！\n",this_object(),me);
		me->move("/d/forest/outside02");
		tell_room(environment(me),me->name()+"被人从茅屋里赶了出来，吃了一顿闭门羹，模样十分狼狈。\n",({me}));
		return 1;
	}
	if(!(int)me->query("weapon/make")){
		command("say 这位"+ RANK_D->query_respect(me)+"没有自家的兵器，老朽是不会帮你开锋的。");
		return 1;
	}
	me->set_temp("ask_laozhe_weapon",1);
	command("say 兵刃开锋讲究天时、地利、人和。天地万物，相生相克，如果你能用\n“白玉”和“翡翠”加以调和。老朽可将你手中的兵刃变成一把举世无双的神器。");
	return 1;
}
int accept_object(object who, object ob)
{
	if((string)ob->query("name") == HIW"白玉残片"NOR
	|| (string)ob->query("name") == HIG"翡翠残片"NOR) {
		if(!(int)who->query_temp("ask_laozhe_weapon")){
			say("白发老者笑道："+ ob->name()+"可是兵刃开锋时所需的材料之一，多谢这位"+ RANK_D->query_respect(who)+"了。\n");
			return 1;
		}
		if((int)who->query("weapon/changed")){
			say("白发老者笑道：这位"+ RANK_D->query_respect(who)+"的兵刃已经开锋过了，莫非"+ RANK_D->query_respect(who)+"还嫌兵刃不可手吗？\n");
			return 1;
		}
		if(!(int)who->query_temp("give_stone_green")
		&& (int)who->query_temp("give_stone_white")
		&& (string)ob->query("name") != HIG"翡翠残片"NOR){
			say("白发老者说道：白玉已经有了，现在还缺翡翠，"+ RANK_D->query_respect(who) +"还是快去将它找来吧！\n");
			return 0;
		}
		if((int)who->query_temp("give_stone_green")
		&& !(int)who->query_temp("give_stone_white")
		&& (string)ob->query("name") != HIW"白玉残片"NOR){
			say("白发老者说道：翡翠已经有了，现在还缺白玉，"+ RANK_D->query_respect(who) +"还是快去将它找来吧！\n");
			return 0;
		}
		if((string)ob->query("name") == HIW"白玉残片"NOR){
			if((int)who->query_temp("give_stone_green")) {
				command("say 好！现在材料配齐了，开始吧！");
				kaifeng(who);
			}
			else {
				who->set_temp("give_stone_white",1);
				say("白发老者赞道：嗯！这块"+ ob->name() +"洁白晶莹而不带任何瑕疵，绝对是配合镶嵌于兵器的好材料。\n");
			}
			return 1;
		}
		if((string)ob->query("name") == HIG"翡翠残片"NOR){
			if((int)who->query_temp("give_stone_white")) {
				command("say 好！现在材料配齐了，开始吧！");
				kaifeng(who);
			}
			else {
				who->set_temp("give_stone_green",1);
				say("白发老者赞道：嗯！这块"+ ob->name() +"青翠晶莹而不带任何瑕疵，绝对是配合镶嵌于兵器的好材料。\n");
			}
			return 1;
		}
	}

	command("shake");
	command("say 老朽不希罕这东西。");
	return 0;

}
void kaifeng(object me)
{
	object weapon;
	string wname,type;
	int i = me->query_kar();
	
	wname = (string)me->query("weapon/name");
	type = (string)me->query("weapon/type");
	weapon = present(me->query("weapon/id"),me);
	
	if(!me || environment() != environment(me)) return;
	weapon->unequip();
	message_vision("$N将$n手中的"+ wname +"接过，再将白玉残片和翡翠残片镶嵌在"+ wname +"之上。\n",this_object(),me);
	message_vision("紧接着，只见白发老者手指"+ type +"身，口中喃喃自语，默念着口诀：.x$@!7V . . . . \n",me);
	message_vision("只见"+ wname +"越来越亮，"+ type +"身散发出一阵耀眼的光芒 . . \n",me);
	message_vision("过了半晌，一切终于恢复了平静，$N气喘吁吁的说道：祭祀完成，好好把握它的灵性吧！\n",this_object());
	ENHANCE_D->enhance_weapon(weapon,i*i + 10,type);
	me->set("weapon/name",weapon->name());
	CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("绝缘之地大开,绝世神兵%s现世！",weapon->name()));
	me->set("weapon/id",weapon->query("id"));
	me->set("weapon/rigidity",1);
	me->set("weapon/weapon_prop",weapon->query("weapon_prop"));
	me->delete_temp("give_stone_white");
	me->delete_temp("give_stone_green");
	me->delete_temp("ask_laozhe_weapon");
	me->delete_temp("ask_ouyezi");
	me->set("weapon/changed",1);
	me->save();
	reload_object(weapon);
}