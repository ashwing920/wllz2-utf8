// story:biaoche.c

#include <ansi.h>

string give_gift();

string prompt() {
	return HIC"【江湖逸事】"NOR;
}

private string *stone = ({
	"/clone/stone/stone-1",
	"/clone/stone/stone-2",
	"/clone/stone/stone-3",
	"/clone/stone/stone-4",
});

private mixed *story = ({
	"趟子手：顺风镖局，我武威扬～～～",
	"顺风镖局的镖头和趟子手们，押送着一队镖车，浩浩荡荡而来。",
	"趟子手：哎，这一车又笨又重烂石头有什么用啊？",
	"镖头：找死啊，小声点，这里面每一颗石头都是价值连城，一颗可以卖好几百两黄金呢。",
	"趟子手：啊～！！？",
	"镖头：废话少说，快走吧，以免引人注目！招来杀身之祸。",
	"趟子手：哦！",
	"趟子手举目四望，趁镖头不备，偷偷的摸出了一颗，往路边丢了下去。",
	(: give_gift :),
	"镖队又浩浩荡荡的继续前行了。",
});
void create(){ seteuid(getuid());}
mixed query_story_message(int step)
{
	return step < sizeof(story) ? story[step] : 0;
}
string give_gift()
{

	STORY_D->give_gift(stone[ random(sizeof(stone))], 1,HIY"\n“啪嗒”的一声，一颗闪闪发光的石头掉在你的面前。\n\n" NOR);
	return "趟子手：顺风镖局，我武威扬～～";
}
