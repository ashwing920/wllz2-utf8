//lixunhuan.c
#include <ansi.h>
inherit NPC;
void greeting(object ob);
int accept_object(object ob);
void create()
{
       set_name(HIW"李寻欢" NOR, ({"li xunhuan", "li","xunhuan" }) );
       set("long", @LONG       
他的外表给人一种风流潇洒的感觉，你看他一身简单的服饰！
谁也没想到他就是江湖人称人见人爱的“李探花-李寻欢”他
一生风流不羁潇洒的性格是谁见了都会钟情与他的。你仔细
一看，就会有一种希望占有他的欲望 ！因为世间再也找不到
比他更加完美的人了！
LONG );
		
	set("attitude", "friendly");
	set("title","朝廷御赐探花");
	set("nickname", HIM "风流不羁" NOR);
	set("gender", "男性");

	set("age", 25);
	set("str", 50);
	set("cps", 50);
	set("cor", 50);
	set("per", 50);
	set("con", 50);
       
	set("neili", 1000);
	set("max_neili", 1000);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("jiali", 100);
       
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("sword", 300);
	set_skill("unarmed", 300);
	set_skill("parry", 300);
       
	set("combat_exp", 300000);
       
	set("no_kill", 1);
	
	set("startroom","/d/center/jiyuan");
	set("chat_chance", 6);
	set("chat_msg", ({
	HIY"李寻欢把飞刀架在自己的脖子上，转过身去，深情地吟道：红颜知己死光光只剩一个李寻欢。\n"NOR,
	HIR"李寻欢向天大声狂笑问道：为什么现在的女子都不肯来安慰我寂寞的心，我虽然风流，可是并不下流啊。\n"NOR,
	HIC"李寻欢摸了一下身上的飞刀说道：哎呀！刚好今天的飞刀用完了,改天如果给我碰见欧阳克这个色狼
  我让他尝尝我飞刀的厉害他！\n"NOR,
	HIM"李寻欢叹道：到现在我还没有找到可以接我衣钵的弟子，看来飞刀绝技要失传了！江湖从此除名！。\n"NOR,
	HIW"李探花对着你大叫：天南地北任我闯，只是身上没银两！\n"NOR,
	}) );
	setup();
	carry_object("/u/bmw/obj/flyblade")->wield();
	carry_object("/d/baituo/obj/baipao")->wear();
	add_money("gold",100);

	setup();
	}
