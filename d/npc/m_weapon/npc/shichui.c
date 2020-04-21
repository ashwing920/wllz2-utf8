// npc: shichui.c

#include <ansi.h>

inherit NPC;
string hammer();

void create()
{
	set_name("侍锤", ({ "shichui"}) );
	set("nickname", RED"锤"NOR );
	set("gender", "男性" );
	set("age", 20);
	set("long",     
		"他头上包着白布头巾，一袭白袍，没有一丝褶皱。\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",500);
	set("jiali",50);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("hammer",150);
	set_skill("parry",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);

	set("combat_exp", 250000);
	set("score",0);
	
	set("attitude", "peaceful");
	
	set("inquiry", ([
		"铸锤"  : "师傅命我帮助别人铸锤，但到现在也不见一个人影。谁要铸锤呢？\n",
		"原料"  : "铸锤可用寒丝羽竹，海底金母，千年神木。但效果各不一样。\n",
		"锤":   (: hammer :),
	]) );

	setup();

	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	
	add_action("do_zhu","zhu");
}


int accept_object(object who, object ob)
{       
	if(!who->query_temp("hammer")){
		command("say 师傅没有同意为你铸锤，您请回吧！");
		return 0;
	}
	who->delete_temp("hammer");
	who->set_temp("m_hammer",1);
	switch ((string)ob->query("id") ) {
		case "shen mu": 
			who->add_temp("shenmu",1);
			break;
		case "jin mu":
			who->add_temp("jinmu",1);
			break;
		case "han zhu": 
			who->add_temp("hanzhu",1);
			break;
		default :
			message("vision","这是什么！师傅说这不能用来打造兵器！",who);
			return 0;
	}
	message("vision","侍锤低头检视了一下手中的"+(string)ob->query("name")+"点了点头说：那好！我们现在就开始铸锤。\n", who);
	write("请这位"+RANK_D->query_respect(who)+"给锤起名字吧！(zhu 锤的名字)\n");
	return 1;
}

int do_zhu(string arg)
{
	string o_name,w_name,tmp;
	object hammer,make_time;   //生成的武器句柄
	object me;
	int i;

	me = this_player();

	if(!me->query_temp("m_hammer")) return 0;

	if((me->query("weapon/make")) ){
		say("侍锤一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？\n");
		return 1;
	}
	if( !arg )
		return notify_fail("侍锤认真的说：想好锤的名称及代号后在对我说。\n");

	sscanf(arg ,"%s" ,w_name);

	if(!w_name)
		return notify_fail(name()+"说道：使用zhu 锤的名字。\n");

	tmp = clean_color(w_name);
	
	if(strlen(tmp) > 4 || strlen(tmp) < 1)
		return notify_fail(name() +"说道：兵器的名字必须为 1 到 4 个字。\n");
	
	i=strlen(tmp);

	while(i--){
		if( tmp[i]<=' ' )
			return notify_fail(name() +"说道：对不起，你的中文名字不能用控制字元。\n");
		if( i%2==0 && !is_chinese(tmp[i..<0]) )
			return notify_fail(name() +"说道：对不起，请您用「中文」取名字。\n");
	}


	me->delete_temp("m_hammer");
	me->delete_temp("get_orc");
	me->delete_temp("or");

	if(me->query_temp("shenmu") ) o_name="千年神木";
	if(me->query_temp("jinmu") )   o_name="海底金母";
	if(me->query_temp("hanzhu") )   o_name="寒丝羽竹";
	make_time=NATURE_D->game_time();
	message_vision(me->name()+"沉吟了一会，对侍锤悄声说了几句话。侍锤点了点头。说：好吧！\n",me );
	message_vision("\n侍锤回过身，转向身后的一个巨大的火炉，鼓动真气燃起了熊熊的大火。说：开始！\n",me );
	message_vision("\n$N双手握住一个巨大的铁锤，猛的向炉中渐渐红热起来的"+o_name+"挥去！\n",me);
	message_vision("\n只听得棚的一声巨响，锤头和"+o_name+"粘在了一起。\n",me );
	message_vision("\n$N只觉得掌心一热，浑身的血液似乎都沸腾了起来！\n",me);
	message_vision("\n一身精血胶合着汩汩的内气，源源不断的向炉中的"+o_name+"涌去！\n",me );
	if((me->query("qi"))<(me->query("max_qi"))
	|| (me->query("jing"))<(me->query("max_jing"))
	|| (me->query("neili"))<(me->query("max_neili"))){
		message_vision(HIR"\n\n突然$N觉得气血一阵翻涌，一口真气接不上来......\n" NOR, me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision("\n只听咯的一声轻响，一柄巨锤从炉中倏然跃起。化作一道青电猛的向$N的前胸刺来！！\n" NOR,me );
	say(HIW"\n侍锤见状大叫：神锤初成，人血以祭！！闪开！\n"NOR);
	message_vision(HIW"\n$N只觉得眼前一花，一条白影迅捷无比的挡在了$N的身前。\n"NOR,me);
	message_vision(HIR"\n巨锤透胸穿出，侍锤惨号一声，鲜血溅得你满脸都是！\n"NOR,me);
	message_vision(HIR"\n侍锤往后退开了几步，手捂着伤口，看起来侍锤已经气息粗重了。\n" NOR,me);
	message_vision("\n巨锤又飞了起来，飞到半空，当的一声落回到地上。\n\n炉中的火灭了。一室的劲气化于无形，一切又归于沉寂。\n",me );
	
	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",0);

	me->set("weapon/make",1);
	me->set("weapon/name",convert_color(w_name) +NOR);
	me->set("weapon/lv",1);
	me->set("weapon/or",o_name);
	me->set("weapon/value",0);
	me->set("weapon/type","锤");
	me->set("weapon/time",make_time);

	hammer=new("/d/npc/m_weapon/weapon/m_hammer",1);
	hammer->move(this_player());
	message_vision(CYN"\n侍锤摸起地上，带着斑斑血迹还有些烫手的巨锤，说：锤..已..成...，侍锤的任务....也就完成了....\n"NOR,me );
	say(CYN"\n侍锤艰难的说：锤....您...收好，我该走了....\n"NOR);
	message_vision("\n侍锤刚说完，眉头一皱......\n",me);
	this_object()->die();
	return 1;
}

string hammer()
{
	object me,weapon;
	me = this_player();
	
	if(me->query("weapon/make") < 0 )  
		return "要铸锤必须找到铸锤的原料。";
	if(me->query("weapon/type") != "锤")
		return "你铸造的兵器好象不是锤吧？";
	if (present("my hammer",me))
		return "你的锤好好的，来找我干什么？";

	weapon = new("/d/npc/m_weapon/weapon/m_hammer",1);
	weapon->set("name",me->query("weapon/name"));
	weapon->set("lv",me->query("weapon/lv"));
	weapon->set("value",me->query("weapon/value"));
	weapon->set("type",me->query("weapon/type"));
	weapon->set("time",me->query("weapon/time"));
	weapon->move(this_player());
	this_player()->save();
	return "好好保存着，别再搞丢了哦！";
	
}
