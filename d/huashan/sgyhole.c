// Room: /d/huashan/sgyhole.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这是一个毫不起眼的山洞，但是里面的石壁上却画满了五岳剑派所有
已经失传的精妙绝招。花岗岩石壁(wall)上很多小人，全是用利器刻制，
想见当初运力之人内力十分深厚。在石洞的还有许多骸骨，也许是当然有
人在此厮杀过，还有许多骸骨到现在还保持着格斗的姿式。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"out"    : __DIR__"sgyhole1",
	]));
	set("item_desc", ([ 
		"wall" : @TEXT

	   o   | o      o      \ o       o        o      <o      <o>
	--^|\   ^|^  --v|^      v|v      |/v     \|X|   \|        |
	   /\    >\    /<        >\     /<        >\    /<        >\

	   o>    o        o       o       o       o       o       o
	   \ __   x      </      <|>    </>     <\>     <)>      |\__
	  /<      >\    /<        >\    /<        >\     >>      L
TEXT
	]));
	setup();
}
void init()
{
	add_action("do_ketou","ketou"); 
	add_action("do_mianbi", "mianbi");
}
int do_ketou()
{
	 object ob;
	 int c_skill;
	 ob = this_player();
	 c_skill =(int)ob->query_skill("sword",1);
	 if(ob->query_temp("lookfeng",1)) {
	 message_vision("$N恭恭敬敬地在几具骸骨前跪了下来，磕了一个响头。\n",ob);
	 message_vision("$N觉得有点昏昏沉沉，可能是由于磕头的缘故。\n",ob);
	 ob->add("qi",-50);
	 return 1;
}
	 if (c_skill<150){
	 message_vision("$N恭恭敬敬地在几具骸骨前跪了下来，磕了一个响头。\n",ob);
	 message_vision("$N觉得有点昏昏沉沉，可能是由于磕头的缘故。\n",ob);
	 ob->add("qi",-150);
	 return 1;
	 }
	 else {
	 message_vision("$N双膝跪下，向着骸骨磕了一个响头！\n",ob);
	 message_vision("突然膝下响了一下，吓了$N一跳，还发出了轰轰的响声！\n",ob);
	 call_out("ketou1",random(4), ob );
	 return 1;
      }
}
void ketou1()
{
	object me;
	me = this_player();
	message_vision("$N你突然发现在其中一具骸骨后面石壁上刻有几行小字：\n\n", this_player());
	message_vision("    余风清扬空负绝世剑法，身受师门深恩，于师门有难时却未能及\n" , me);
	message_vision("时效力，师门惨遭大难。可叹凶徒竟为同门。呜呼！欲雪大恨，又恐\n",me);
	message_vision("师门从此式微，愧对先祖。唯有埋剑深山，退隐江湖。\n",me);
	message_vision("    汝能不拘小口，跪拜魔教十大长老，实乃性情中人也。见吾留字\n",me);
	message_vision("，可谓有缘，请赴后山吾处相见。吾当量材以教，授以神剑。于华山\n",me);
	message_vision("云台峰，自有人引汝至吾隐居之所。\n\n",me);
	message_vision("                                            华山罪徒 风清扬字\n",me);
	me->set_temp("lookfeng",1);
}
int do_mianbi()
{
	object ob;
	int c_exp,c_skill;
	ob = this_player();

	c_skill=(int)ob->query_skill("sword", 1);
	if (c_skill <20)
	{
		message_vision("$N的基本剑法显然太低，无法领悟石壁内容。\n",ob);
		return 1; 
	}
	c_exp=ob->query("combat_exp");

	if ((c_skill*c_skill*c_skill/10)> c_exp)
	{
		message_vision("$N的实战经验不足，无法领悟石壁内容。\n",ob);
		return 1; 
	}
	if (ob->query("jing")<20)
	{
		message_vision("$N太累了，现在无法领悟石壁内容。\n",ob);
		return 1; 
	}
	if (c_skill>101)
	{
		message_vision("$N觉得石壁内容太肤浅了。\n",ob);
		return 1; 
	}

	message_vision("$N面对着石壁趺坐静思，良久，对基本剑法似有所悟。\n",ob);
	ob->improve_skill("sword", random(10*ob->query("int")));
	ob->add("jing",-5);
	return 1;
}
