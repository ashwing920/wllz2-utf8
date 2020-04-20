// dibao.c

#include <ansi.h>

inherit NPC;

int ask_me(string name);

void create()
{
	set_name("地保", ({ "dibao" }) );
	set("gender", "男性" );
	set("age", 43);
	set("long", @LONG
赵洪是这个村子土生土长的人，年轻的时候到外面去闯荡过一阵。在镖局
当过趟子手，攒了点钱，回来後娶了房老婆，物农为生。村里人因他在外
见过世面，又会些武功，就推他做了地保。
LONG
);
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", 1);
	set_skill("unarmed", 30);
	set_skill("dodge", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set("inquiry",([
		"怪事": (: ask_me ,"怪事":),
		"大虫": (: ask_me ,"大虫":),
		"怀疑": (: ask_me ,"怀疑":),
		"什么": (: ask_me ,"怀疑":),
		"怀疑什么": (: ask_me ,"怀疑":),
	]));
	set("combat_exp", 2500);
	set("attitude", "peaceful");
	setup();
	add_money("coin", 150);
	carry_object("/clone/cloth/cloth")->wear();
}
int ask_me(string name)
{
	object me;
	me = this_player();


	if(me->query_temp("apply_job/guanfu")){
		if( name == "怪事"){
			say("地保说道：我们村最近老有人无故失踪，都是一些孩子和村里的妇女，有人说是被"HIY"大虫"NOR"给刁了去。\n");
			me->set_temp("ask_dibao",1);
			return 1;
		}
		if( name == "大虫"){
			if((int)me->query_temp("ask_dibao") == 1){
				say("地保说道：自我在这里当地保到现在，从没听说过有大虫，要有大虫，那村里的牲口不是早完了吗？我"HIY"怀疑"NOR"...\n");
				me->set_temp("ask_dibao",2);
				return 1;
			}
			else return 0;
		}
		if(name == "怀疑"){
			if((int)me->query_temp("ask_dibao") == 2){
				say("地保说道：我怀疑，怕是给贼人抓了。听说最近从山东来了一帮人贩子，驻扎在东\n"+
			    	"村外的一个山洞里。他们专门掳掠抓小孩和媳妇。小孩卖给那些没孩子的有钱人家\n"+
			    	"媳妇则卖给人家做老婆，要不就是卖到妓院去。唉，可惜我学艺不精，力不从心，\n"+
			    	"否则一定去"HIY"盗贼的山洞"NOR"将那帮丧尽天良的贼子杀了。\n");
				me->set_temp("ask_dibao",3);
				return 1;
			}
			else return 0;
		}
	return 0;
	}

}