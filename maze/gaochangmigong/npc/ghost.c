// gargoyle.c

#include <ansi.h>

inherit NPC;

string *all_msg = ({
	"你已经受伤过重，只怕一运真气便有生命危险！\n",
	HIW "你全身放松，坐下来开始运功疗伤。\n" NOR,
	"战斗中运功疗伤？找死吗？\n",
	"「你上一个动作还没有完成，不能施用外功。」\n",
	"( 你上一个动作还没有完成，不能施展神通。)\n",
	"你的动作还没有完成，不能移动。\n",
	"你太累了，休息一下再走吧。\n",
	"你要往哪个方向走？\n",
	"你现在精力充沛。\n",
	"你的内力不够。\n",
	"「你"HIY "气喘嘘嘘，看起来状况并不太好。"NOR"」\n",
	"「你"RED "已经伤痕累累，正在勉力支撑著不倒下去。"NOR"」\n",
	"「你"RED "气息粗重，动作开始散乱，看来所受的伤著实不轻。"NOR"」\n",
});
void create()
{
	set_name("无主游魂", ({ "you hun", "ghost" }) );
	set("long","一个无主游魂，四处飘荡。\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg",({
		(: random_move :),
		HIB + name() +"鬼鬼祟祟的躲在角落里偷偷的看着你。\n"NOR,
		HIB + name() +"伸长了舌头，对你做了个鬼脸。\n"NOR,
	}));
	set("age", 217);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_qi", 900);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);
	setup();
}
void init()
{
	object ob;
	
	if(interactive(ob= this_player())){
		call_out("tell_msg",1,ob);
	}
}
void tell_msg(object ob)
{
	string msg;

	if(!ob) return;
	msg = all_msg[random(sizeof(all_msg))];
	tell_object(ob,msg);
	return;
}
int is_ghost(){ return 1;}

int heal_up()
{
        if( environment() && time() >= query("back_time")) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",sprintf(HIB"\n%s突然出现在你跟前，对着%s挥挥手，把%s带走了。\n\n",random(2)?"黑无常":"白无常",
        name(),name()),environment(), this_object() );
        destruct(this_object());
}
