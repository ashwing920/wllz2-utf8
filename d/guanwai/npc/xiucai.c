// xiucai.c

inherit NPC;

void create()
{
	set_name("落第秀才", ({ "xiu cai" }) );
	set("gender", "男性" );
	set("age", 26);
	set("int", 28);
	set("long",@LONG
这是个饱读诗书，却手无搏鸡之力的落第秀才。
LONG
);
	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
}

