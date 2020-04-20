// NPC : /d/shaolin/npc/zshiseng.c

inherit NPC;

void create()
{
	set_name("执事僧",({ "zhishi seng","zhishi","seng"}));
	set("gender","男性");
	set("age",30);
	set("no_get",1);
	set("long",@LONG
一个粗壮的僧人，一看就知道长年从事体力劳动！
少林寺的弟子们，都可以找他询问“厨房执事”。
LONG
);
	set_skill("force",300);
	set_skill("dodge",300);
	set_skill("unarmed",300);
	set_skill("parry",300);
	set("neili",30000);
	set("max_neili",30000);
	set("combat_exp",500000);
	set("attitude", "friendly");
	setup();
}
