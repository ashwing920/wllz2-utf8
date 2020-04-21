// wuliuqi.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_weiwang();

void create()
{
	set_name("吴六奇", ({"wu liuqi", "wu","liuqi"}));
	set("title", HIR"天地会洪顺堂"NOR"香主");
	set("nickname", "铁丐");
	set("gender", "男性");
	set("age", 50);
	set("long",@LONG
这个老叫化，便是天下闻名的“铁丐”吴六奇，向来嫉恶如仇。他在官居
广东提督之时，手握一省重兵，受了查伊璜的劝导，心存反清复明之志，
暗入天地会，任职洪顺堂香主。
LONG
);

	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	
	set("combat_exp", 150000);
	set("score", 30000);
	
	set_skill("force", 95);			// 基本内功
	set_skill("huntian-qigong", 90);	// 混天气功
	set_skill("unarmed", 90);		// 基本拳脚
	set_skill("xianglong-zhang", 85);	// 降龙十八掌
	set_skill("dodge", 90);			// 基本躲闪
	set_skill("xiaoyaoyou", 95);		// 逍遥游
	set_skill("parry", 85);			// 基本招架
	set_skill("begging", 50);		// 叫化绝活
	set_skill("checking", 50);		// 道听途说
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	set("chat_chance", 3);
	set("chat_msg", ({
	"吴六奇忽然放开喉咙唱起曲来：“走江边，满腔愤恨向谁言？。。。。\n"
	"。。。。。。寒涛东卷，万事付空烟。精魂显大招，声逐海天远。\n",
	"吴六奇说: 江湖威望很重要，威望高大有好处啊。\n",
	"吴六奇突然说道: 松柏二枝分左右，中节洪华结义亭。\n",
	"吴六奇突然说道: 福德祠前来誓愿，反清复明我洪英。\n",
	}));
	set("inquiry", ([
		"陈近南" :  "\n想见总舵主可不容易啊。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
		"入会" :  "\n只要入了我天地会，可以向会中各位好手学武功。\n",
		"反清复明" : "去药铺和棺材店仔细瞧瞧吧！\n",
		"威望" :  (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
	]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say("\n吴六奇说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
	+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
	say("\n吴六奇又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
	return 1;
}