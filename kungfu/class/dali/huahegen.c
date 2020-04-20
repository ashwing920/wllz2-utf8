// huahegen.c 华赫艮

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("华赫艮", ({ "hua hegen", "hua" }));
	set("title",  "大理司徒" );
	set("long",@LONG
他是大理国三大公之一。华司徒本名阿根，出身贫贱，现今在大理国位列
三公，未发迹时，干部的却是盗墓掘坟的勾当，  最擅长的本领是偷盗王
公巨贾的坟墓。这些富贵人物死后，必有珍异宝物殉葬，华阿根从极远处
挖掘地道，通入坟墓，然后盗取宝物。所花的一和虽巨，却由此而从未为
人发觉。有一次他掘入一坟，在棺木中得到了一本殉葬的武功秘诀，依法
修习，练成了一身卓绝的外门功夫，便舍弃了这下贱的营生，辅佐保定帝
，累立奇功，终于升到司徒之职。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	
	set("jing",3000);
	set("max_jing",3000);
	set("neili",6750);
	set("max_neili",6750);
	set("jiali",335);
	set("combat_exp",8000000);
	set("score",200000);

	set_skill("force", 450);
	set_skill("dodge", 450);
	set_skill("parry", 450);
	set_skill("cuff", 450);
	set_skill("sword", 450);
	set_skill("staff", 450);
	set_skill("kurong-changong", 450);
	set_skill("tiannan-step", 450);
	set_skill("jinyu-quan", 450);
	set_skill("duanjia-sword", 450);
	set_skill("literate", 450);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 20);

	create_family("大理段家",19,"武将");
}

