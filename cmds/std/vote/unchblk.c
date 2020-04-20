// vote unchblk

#include <vote.h>
#include <ansi.h>
#include <net/dns.h>

inherit F_CONDITION;

int clear_vote(object victim);

int vote(object me, object victim)
{
	int reason; // vote for what?
	int vv;	// valid voter numbers
	int vc; 	// vote count;
	int df;
	string *juror, my_id;
	string my_name, v_name;

	if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
	{
		return notify_fail("要把当前的表决完成以后才可以提新的动议。\n");
	}

	if(!victim->query("chblk/all"))
		return notify_fail(victim->name()+"的频道已经是打开的了。\n");

	if(victim->query("chblk/by_wiz"))
		return notify_fail("你无权将巫师关闭的频道打开。\n");

	if (reason <= 0){
		victim->set("vote/reason", (int)V_UNCHBLK);
	}

	my_id = me->query("id");

	// dont allow me to vote twice for the same issue
	juror = victim->query("vote/juror");

	if( !pointerp(juror) )
	{
		victim->set("vote/juror", ({ my_id }) );
	} else if( member_array(my_id, juror) == -1 )
	{
		victim->set("vote/juror", juror+({ my_id }) );
	} else
	{
		me->add("vote/abuse", 10);
		return notify_fail("一人一票！滥用表决权是要受惩罚的！\n");
	}

	vv = (int) ("/cmds/std/vote")->valid_voters(me)/3;
	vc = victim->add("vote/count", 1);

	df = vv - vc;
	if (vv < 4) df = 4 - vc;

	my_name = me->name();
	if (me == victim) v_name = "自己";
		else	v_name = victim->name();

	if (df>1)
	{
		shout( HIG "【表决】"+my_name+"投票打开" +v_name +"的聊天频道，还差"+sprintf("%d", df)+"票。\n" NOR);
		write( HIG "【表决】"+my_name+"投票打开" +v_name +"的聊天频道，还差"+sprintf("%d", df)+"票。\n" NOR);
		victim->apply_condition("vote_clear", 10);
	} else
	{
		if (me != victim){
			shout( HIG "【表决】"+my_name+"投票打开" +v_name+"的聊天频道。"+v_name+"的聊天频道被打开了！\n" NOR);
			write( HIG "【表决】"+my_name+"投票打开" +v_name+"的聊天频道。"+v_name+"的聊天频道被打开了！\n" NOR);
		} else
			{
			shout( HIG "【表决】"+my_name+"投票打开自己的聊天频道。"+my_name+"的聊天频道被打开了！\n" NOR);
			write( HIG "【表决】"+my_name+"投票打开自己的聊天频道。"+my_name+"的聊天频道被打开了！\n" NOR);
		}
		victim->apply_condition("vote_clear", -10);
		victim->delete("chblk/all");
	}
	return 1;
}
