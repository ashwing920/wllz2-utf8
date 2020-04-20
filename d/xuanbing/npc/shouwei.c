// shouwei.c 石室守卫

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
	set_name(npc_name("男性"), ({ "shou wei", "wei" }));
	set("title","石室守卫");
	set("gender", "男性");

	set("age",random(10)+20);
	set("combat_exp",5000000);

	set("inquiry", ([
		"武林大会" : (: ask_me :),
		"比武"   : (: ask_me :),
	]));
	add_temp("apply/damage",500);
	add_temp("apply/armor",500);
	add_temp("apply/dodge",500);
	add_temp("apply/attack",500);
	create_family("古墓新派",21,"弟子");
	setup();
	NPC_D->full_init(this_object());
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/sword")->wield();
}
void init()
{
	add_action("do_sign", "sign");
	add_action("do_join", "join");
}
string ask_me()
{
	object me;

	me = this_player();

	if (PK_D->is_pking())
		return "现在武林大会正在举行呢，你想干什么？";

	if (PK_D->is_ready())
		return "很好，现在武林大会正要开始，你要报名么(sign)？";

	return "武林大会？你慢慢等着吧。要是无聊，现在要是想进去玩玩(join)也行。";
}

int do_join()
{
	if (PK_D->is_pking())
		return notify_fail(name() +"眼睛一弹，喝道：“现在里面正比赛呢，你这些人等等吧。”\n");

	if (PK_D->is_ready())
		return notify_fail(name() +"懒懒道：“要想正式比赛就进去，其他人先等着。”\n");

	message_vision("$N赔笑对$n道：“我进去溜达溜达，放行可好？”\n",
		       this_player(), this_object());

	if (PK_D->join_competition(this_player()))
	{
		message("vision", this_player()->name() + "一溜小跑进了玄冰石室。\n",environment());
		return 1;
	}

	return 0;
}

int do_sign()
{
	object me;
	string msg;
	object ob;

	me = this_player();
	message_vision("$N有板有眼睛的对$n说道：“在下"+ me->name() +"，应邀前来参加武林大会，请予以放行。”\n",me, this_object());
	if (me->query("combat_exp") < 50000)
	{
		message_vision("$n摇了摇头道：“就你这点本事？还是去练好功夫再来吧！”\n",me, this_object());
		return 1;
	}

	if (stringp(msg = PK_D->reject_join(me)))
	{
		command("say " + msg);
		return 1;
	}

	foreach (ob in deep_inventory(me))
		if (ob->is_character())
		{
			command("say 你背的谁？去比赛还拖家带口的？快给我滚！");
			message_vision("$N飞起一脚，把$n踢倒在地！\n",this_object(), me);
			me->receive_damage("qi", 50);
			return 1;
		}

	message_vision("$n点点头，对$N道：“好吧，你先进去准备吧。”\n$N点点头，向北面的准备室走去。\n", me, this_object());
	me->move("/d/xuanbing/ready");
	message("vision", me->name() + "精神抖擞的走了进来。\n",environment(me), ({ me }));
	return 1;
}

