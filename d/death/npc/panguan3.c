// TIE@FY3

#include <ansi.h>
#include <command.h>

inherit NPC;

string *death_msg = ({
	HIW"$N那锐利的目光象利刃一般在$n身上扫来扫去。\n\n"NOR,
	HIW"$N翻了翻勾魂簿，疑道：$n阳寿未尽，怎么跑这里来了？\n\n"NOR,
	HIW"$N脸色一黑，喝道：牛头马面，怎么把阳寿未尽的人也抓来了？\n\n"NOR,
	HIW"$N对着牛头马面的屁股狠狠的踢了一脚，疼得牛头马面捂着屁股呜呜大叫。\n\n"NOR,
	HIW"$N合上簿子，对$n说道：你阳寿未尽，命不该绝，快回阳间去吧。\n\n"NOR,
	HIW"$N说完，伸手凌空一指，只听见“乓”的一声炸响，半空中突然敞开一个大洞。\n\n"NOR,
	HIW"一道猛烈的阳光象利刃般从洞外照射进来，直刺$n的胸口。\n\n"NOR,
	HIW"$n再也忍受不住，发出“啊～～”的一声惨嚎，终于晕了过去。\n\n"NOR,
});

string *revive_loc= ({
	"/d/center/guandimiao",
	"/d/city/wumiao",
});

void create()
{
	set_name("朱笔判官", ({ "panguan", "ghost judge" }) );
	set("long",
		"阎王身边的朱笔判官，专勾画天下人的生死。\n");
	set("attitude", "peaceful");
	set("age", 217);
	set("combat_exp", 20000);
	set("max_gin", 900);
	set("max_kee", 900);
	set("max_sen", 200);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	setup();
}

void init()
{

	if( !previous_object()
	||  !userp(previous_object())) return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	int i;
	object *inv;

	if( !ob || environment(ob) != environment()) return;

	message_vision(death_msg[stage],this_object(),ob);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

	inv = all_inventory(ob);
	for (i = 0; i < sizeof(inv); i++)
	destruct(inv[i]);
	ob->set_temp("block_msg/all",1);
	ob->move(revive_loc[random(sizeof(revive_loc))]);
	ob->set("startroom", base_name(environment(ob)));
	ob->delete_temp("block_msg");
	tell_object(ob,HIY"你“嗖”的一声从地上坐了起来，睁开眼睛惊魂未定的东张西望。\n"
			"原来只是是虚惊一场，好险，好险！你不禁捏了一把冷汗......\n"NOR);
	message("vision",
		"\n"HIC + ob->name(1)+"大汗淋漓，惶恐不安的眼神四处张望，好像受到什么惊吓似的 . . .\n\n"NOR, environment(ob), ob);
}
