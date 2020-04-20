// combatd.c

//#pragma optimize
//#pragma save_binary

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;

string *guard_msg = ({
	CYN "$N注视著$n的行动，企图寻找机会一击成功。\n" NOR,
	CYN "$N注视著$n的行动，企图寻找机会出手。\n" NOR,
	CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
	CYN "$N以守为攻，想要找出$n的破绽。\n" NOR,
	CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
	CYN "$N缓缓地移动着脚步，等待着最佳的出招方位。\n" NOR,
	CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。\n" NOR,
	CYN "$N眼睛眨也不眨地盯着$n，伺机出手。\n" NOR,
	CYN "$N慢慢地移动著脚步，伺机出手。\n" NOR,
});
string *catch_hunt_human_msg = ({
	HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
	HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
	HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
	HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
	HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
	HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
	HIW "$N喝道：「$n，看招！」\n" NOR,
	HIW "$N对$n喝道：「狗贼！别跑」\n" NOR,
	HIW "$N对$n喝道：「冤家路窄，今天看你往哪逃！」\n" NOR,
});
string *catch_hunt_beast_msg = ({
	HIW "$N怒吼一声，扑了过来攻击$n！\n" NOR,
	HIW "$N对著$n大吼，想杀死$n！\n" NOR,
	HIW "$N发出连串低吼，突然暴起攻击$n！\n" NOR,
});
string *catch_hunt_bird_msg = ({
	HIW "$N对著$n一声怒鸣，飞冲了过来！\n" NOR,
	HIW "$N怒鸣几声，突然暴起攻击$n！\n" NOR,
	HIW "$N一声锐鸣，猛然向$n发动攻击！\n" NOR,
});
string *winner_msg = ({
	CYN "\n$N哈哈大笑，愉快地说道：承让了！\n\n" NOR,
	CYN "\n$N双手一拱，笑著说道：知道我的利害了吧！\n\n" NOR,
	CYN "\n$N哈哈大笑，双手一拱，笑著说道：承让！\n\n" NOR,
	CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
	CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
	CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
	CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});
string *bellicosity_msg = ({
	"\n$N杀红了眼，向$n发起猛烈的攻击，攻得$n连连后退！\n",
	"\n$N凶光乍现，越战越勇，使得$n不禁阵阵心寒！\n",
	"\n$n却见$N来势凶猛，心神慌乱，对$N的招式早已分不清来路！\n",
	"\n但见$n招式错乱，招架不及，细看$N摄人心魄之神情，不禁万分心寒。\n",
	"\n$n胆颤心惊，慌了手脚，眼前仿佛出现了无数个$N的身影。\n",
	"\n$N越战越勇，无视$n如何出招，冲着$n左右二路急攻而去。\n",
	"\n只见$N脸上涨个通红，不待$n接招避让，挥起$w对$n就是一阵乱劈！\n",
});
string *must_die_msg = ({
	"\n只听见“唰”的一声，一道血影划过$n的身躯，$N缓缓的收住招式，露出诡异的一笑。\n",
	"\n只见$N迅速收招，缓缓的用袖口轻拭$w上的血渍，一指轻弹$n的胸口。\n",
	"\n$N一声怒喝：「阎王要你三更死，岂能留你到五更，去死吧！」话音刚落，应声对$n就是致命一击！\n",
	"\n只见$N身形陡然变快，迅速的朝$n冲了过去，$w猛的朝$n的天灵盖劈去！\n",
	"\n$N手中$w锋芒一闪，骤然刮起一阵飓风，空气即刻变得沉寂......\n",
});
	
void create()
{
	seteuid(getuid());
	set("name", "战斗精灵");
	set("id", "combatd");
	set("channel_id", "战斗精灵");
}
string damage_msg(int damage, string type,object ob)
{
	string str;
	int qi=ob->query("qi");
//  return "造成 " + damage + " 点" + type + "。\n";
	if( damage == 0 ) return "结果没有造成任何伤害。\n";
	if (qi>0){
	damage=damage*100;
	damage /= qi;
	}else
	damage=120;
		switch( type ) {
		case "擦伤":
		case "割伤":
			if( damage < 5 ) return "结果只是轻轻地划破$p的皮肉。\n";
			else if( damage < 10 ) return "结果在$p$l划出一道细长的血痕。\n";
			else if( damage < 20 ) return "结果「嗤」地一声划出一道伤口！\n";
			else if( damage < 40 ) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
			else if( damage < 80 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
			else return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
			break;
		case "刺伤":
			if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
			else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
			else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
			else if( damage < 60 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
			else if( damage < 80 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
			else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
			break;
		case "瘀伤":
			if( damage < 5 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
			else if( damage < 10 ) return "结果在$p的$l造成一处瘀青。\n";
			else if( damage < 25 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
			else if( damage < 40 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
			else if( damage < 50 ) return "结果「砰」地一声，$n退了两步！\n";
			else if( damage < 60 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
			else if( damage < 80 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
			else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
			break;
		case "内伤":
			if( damage < 10 ) return "结果只是把$n打得退了半步，毫发无损。\n";
			else if( damage < 20 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
			else if( damage < 30 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
			else if( damage < 40 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
			else if( damage < 60 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
			else if( damage < 75 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
			else if( damage < 90 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
			else return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
			break;
		case "震伤":
			if( damage < 100 ) return "结果$n受到$N的劲力一震，闷哼一声。\n";
			else if( damage < 150 ) return "结果$n被$N以劲力一震，「嘿」地一声退了两步。\n";
			else if( damage < 230 ) return "结果$n被$N以劲力一震，胸口有如受到一记重锤，连退了五六步！\n";
			else if( damage < 340 ) return "结果$N的劲力一下震得$n连退了好几步，差一点摔倒！\n";
			else if( damage < 450 ) return "结果$n被$N的劲力震得全身气血倒流，口中鲜血狂喷而出！\n";
			else return "结果$n被$N的劲力震得眼前一黑，内脏碎裂，身子凭空飞了出去！！\n";
			break;
		case "拉伤":
			if( damage < 15 ) return "结果只是轻轻地划过了$n的皮肤。\n";
			else if( damage < 50 ) return "结果在$n的$l抽出一道细长的血印。\n";
			else if( damage < 150 ) return "结果「啪」地一声$w将$n的$l皮肤扯开，形成一道尺许长的伤口！\n";
			else if( damage < 250 ) return "只听$n「啊」地一声吐出一口鲜血，原来$p$l内的骨头已经被$w的劲力抽裂！\n";
			else if( damage < 350 ) return "结果随着「咔」地一声，$w已将$n$l处的骨头硬生生地抽断，断骨从肉里冒了出来！\n";
			else return "结果$n一声惨嚎，$w已从$p$l处撕下了一大片血淋淋的皮肉，鲜血溅得满地！！\n";
			break;
		case "砸伤":
		case "挫伤":
			if( damage < 20 ) return "结果只是轻轻地碰撞到了$n一下，没有造成什么伤害。\n";
			else if( damage < 80 ) return "结果$w只将$n的$l砸出一块瘀红。\n";
			else if( damage < 160 ) return "结果「啪」地一声，$w打中$n的$l，登时肿了一块老高！\n";
			else if( damage < 320 ) return "结果$w重重得击中$n的$l，打得$p倒退数步，「哇」地吐出一大口鲜血！\n";
			else if( damage < 450 ) return "结果只听见「硼」地一声巨响，$w打在$n身上，将$p像一捆稻草般击飞出去！\n";
			else return "结果$w一下打在$n的身上，几声骨碎声中，$p象散了架似的瘫了下去！！\n";
			break;
		case "抓伤":
			if( damage < 20 ) return "结果只是在$n$l处轻轻刮过，没有什么伤害。\n";
			else if( damage < 40 ) return "结果$n皱了皱眉，$p的$l已经被拉出了一道浅浅的血痕。\n";
			else if( damage < 80 ) return "结果拉下来$n$l的一点皮肉，疼得$p「哇哇」怪叫了起来！\n";
			else if( damage < 120 ) return "结果「唰」地一声，$n的$l上顿时被抓出五道血痕，鲜血流了出来！\n";
			else if( damage < 220 ) return "结果$n疼得大叫一声，$p$l上被抓出了几道深深的血沟，鲜血直流！\n";
			else if( damage < 330 ) return "结果只听见$n一声惨嚎，$N的手爪已在$p的$l处刺出了五个血肉模糊的窟窿！\n";
			else if( damage < 440 ) return "结果「啊」地一声惨叫，$n身上$l处被$N抓下了一大片皮肉，鲜血横飞满地！！\n";
			else return "结果$n一声凄惨的嘶叫，$l处被连皮带肉扯下一大块，露出了白森森的骨头！！\n";
			break;
		case "摔伤":
			if( damage < 20 ) return "结果$n脚下不稳，在地上擦破了点儿皮。\n";
			else if( damage < 80 ) return "结果「啪」地一声，$n在地上摔了个屁礅。\n";
			else if( damage < 160 ) return "结果$n一不小心，被$N重重摔倒在地！\n";
			else if( damage < 300 ) return "结果$n被一下摔倒在地，「噗地」一声喷出了一大口鲜血！\n";
			else if( damage < 420 ) return "结果被$N这一下摔在地上，$l处的骨头「卡嚓」一声断了！\n";
			else return "结果只听见$n一声惨嚎，被$N摔得血肉横飞，惨不忍睹！！\n";
			break;
		case "跌伤":
			if( damage < 20 ) return "结果$p就地一滚，没怎么伤着。\n";
			else if( damage < 40 ) return "结果「吧叽」一声，$p被摔了个屁墩。\n";
			else if( damage < 80 ) return "结果$p的$l着实地被摔了一下！\n";
			else if( damage < 120 ) return "结果$p的$l砸在地上，被摔得青紫！\n";
			else if( damage < 160 ) return "结果在$p的$l立时肿起一大块，鲜血里透着青紫！\n";
			else return "结果$p的$l被摔得皮开肉绽，骨头从肉里戳出来！！\n";
			break;
		case "咬伤":
			if( damage < 20 ) return "结果只是轻轻地蹭了一下$p的皮肉。\n";
			else if( damage < 40 ) return "结果在$p$l咬出一排牙印。\n";
			else if( damage < 80 ) return "结果$p被咬下一片肉来！\n";
			else if( damage < 120 ) return "结果$p连皮带肉被咬下一大块！\n";
			else if( damage < 160 ) return "结果在$p的身上咬下来血肉模糊的一大块$l肉！\n";
			else return "结果只听见$n一声惨嚎，$p的$l上的肉被一口咬掉，露出骨头！！\n";
			break;
		case "鞭伤":
			if( damage < 20 ) return "结果只是在$p$l上擦了一道白印。\n";
			else if( damage < 40 ) return "结果在$p的$l上抽出一道血痕。\n";
			else if( damage < 80 ) return "结果「啪」地一声$p被抽了一道伤口！\n";
			else if( damage < 120 ) return "结果$p的$l上被抽了一道血淋淋的创口！\n";
			else if( damage < 160 ) return "结果「啪」地一声$p被$N的$w抽了一道从头到脚的血印！\n";
			else return "结果只听见「咔嚓」一声，$p的$l的骨头被抽断，$w被染得血红！！\n";
			break;
		default:
			if( !type ) type = "伤害";
			if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
			else if( damage < 20 ) str = "结果造成轻微的";
			else if( damage < 30 ) str = "结果造成一处";
			else if( damage < 50 ) str = "结果造成一处严重";
			else if( damage < 60 ) str = "结果造成颇为严重的";
			else if( damage < 70 ) str = "结果造成相当严重的";
			else if( damage < 80 ) str = "结果造成十分严重的";
			else if( damage < 90 ) str = "结果造成极其严重的";
			else str =  "结果造成非常可怕的严重";
			return str + type + "！\n";
	}
}
string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
	if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
	if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
	if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
	if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return RED "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
	if( ratio > 30 ) return RED "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return RED "受了相当重的伤，只怕会有生命危险。" NOR;
	if( ratio > 10 ) return HIR "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
	if( ratio > 5  ) return HIR "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
	return HIR "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}
string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
	if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
	if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
	if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
	if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return RED "似乎十分疲惫，看来需要好好休息了。" NOR;
	if( ratio > 30 ) return RED "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return RED "看起来已经力不从心了。" NOR;
	if( ratio > 10 ) return HIR "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
	return HIR "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}
varargs void report_status(object ob, int effective)
{
	if( effective )
		message_vision("「$N" + eff_status_msg((int)ob->query("qi") * 100 / (int)ob->query("max_qi") )+ "」\n", ob);
	else
		message_vision("「$N" + status_msg((int)ob->query("qi") * 100 / (int)ob->query("max_qi") )+ "」\n", ob);
}
// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.

varargs int skill_power(object ob, string skill, int usage)
{
	int level, power,status,str,dex;

	if( !living(ob) ) return 0;
	status=1;
	if((int)ob->query("eff_qi") < 1 || (int)ob->query("eff_jing") < 1 ) return 1;
	status = (int)ob->query("eff_qi") * 10 / (int)ob->query("max_qi");
	status *= (int)ob->query("eff_jing") * 10 /(int)ob->query("max_jing");
	if(status < 1) return 1;

	status = status * 10/100; //计算该人物状态，气血、精力所占比重 10%

	level = ob->query_skill(skill);
	switch(usage) {
		case SKILL_USAGE_ATTACK:
			level += (int)ob->query_temp("apply/attack");
			break;
		case SKILL_USAGE_DEFENSE:
			level += (int)ob->query_temp("apply/defense");
			if (ob->is_fighting())
				level = level * (100 + ob->query_temp("fight/dodge") / 10) / 100;
			break;
	}

	//  ---------------------------------------------------------
	//    如果非玩家，该人物攻击力与经验成正比，提高NPC的战斗力与防
	//    护力，增强游戏的耐玩程度。
	//    ---------------------------------------------------------

	if( !level ) return (int)ob->query("combat_exp") / 100;

	// ---------------------------------------------------------
	//   临时呼叫的战斗力以及防御能力不能占太大的比例，否则一些
	//   powerup 之类的外功降大幅度的影响了以下的比例计算。
	//   ---------------------------------------------------------

	level /= 4;

	power = level*level*level/10 * 40/100; //等级所占比重40%
	power *= status;

	str = ((int)ob->query_str() + (int)ob->query_temp("str")) * 10/100; // 臂力占比重 10%
	dex = ((int)ob->query_dex() + (int)ob->query_temp("dex")) * 10/100; // 身法占比重 10%

	if (usage == SKILL_USAGE_ATTACK)
		return (power + (int)ob->query("combat_exp")) / 30 * str * 40/100; // exp 所占比重 40%
	else
		return (power + (int)ob->query("combat_exp")) / 30 * dex * 40/100;
	//return 1; ok?
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//

varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
	mapping my,your,action;
	mapping prepare,kick_exits;
	string *kick_directions,*limbs;
	string limb,result,dodge_msg,parry_msg,map_force,die_msg;
	string attack_skill, martial_skill, dodge_skill, parry_skill;
	string me_family,victim_family;
	mixed foo;
	int ap, dp, pp ;
	int damage, damage_bonus, defense_factor;
	int cost,count;
	int wounded = 0;
	int delta;

	object weapon2,my_weapon; // weapon for victim
	object armor; // armor for victim
	object old_victim;

	if (environment(me) != environment(victim))
	{
		me->remove_enemy(victim);
		victim->remove_enemy(me);
		return 0;
	}

	old_victim = victim;
	if (old_victim->query_temp("shift") == "hitback"
	&& ((int)me->query("combat_exp") / (int)old_victim->query("combat_exp")) < 5
	&& (int)old_victim->query("eff_qi") > 0
	&& living(old_victim)
	&& (random((int)me->query("combat_exp") + (int)me->query_skill("force")) >
	((int)old_victim->query("combat_exp") + (int)old_victim->query_skill("force") * 50))) {
		victim = me;
		map_force = to_chinese( old_victim->query_skill_mapped("force"));
		tell_object(me, WHT "你突然发现打向对方的招式改了方向，向自己袭来！" NOR);
		tell_object(old_victim, WHT "你的"+ map_force +"见效了！"+ me->name() +"的招式突然向自己打去！\n" NOR);
		tell_room(environment(me), WHT "你看到" + me->query("name") + "向" + old_victim->query("name")
			+ "打出的招数突然改变了方向，反而向自己打去！\n" NOR, ({me, old_victim}) );
	};

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();
	prepare = me->query_skill_prepare();
	if (!prepare) prepare = ([]);
	//
	// (0) Choose skills.
	//
	me->delete_temp("fight");
	victim->delete_temp("fight");

	if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
	else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
	else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];
	//else attack_skill = "unarmed";

	//
	// (1) Find out what action the offenser will take.
	//
	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) ) {
	me->reset_action();
	action = me->query("action");
	if( !mapp(action) ) {
		CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s): bad action = %O",
			me->name(1), me->query("id"), me->query("actions", 1)));
		return 0;
	}
}
	if (me->query_temp("action_flag") == 0)
		result = "\n" + action["action"] + "。\n";
	else
		result = "\n" + "紧跟着"+action["action"] + "。\n";

	//
	// (2) Prepare AP, DP for checking if hit.
	//
	limbs = victim->query("limbs");
	if (! arrayp(limbs))
	{
		limbs = ({ "身体" });
		victim->set("limbs", limbs);
	}
	limb = limbs[random(sizeof(limbs))];

	// 以下可能在query_xxxx_msg中，加入招式的特殊防御,
	//比如,victim->set_temp("fight/dodge",100)
	// 因此,应该在计算前先进行调用
	
	dodge_skill = (string)me->query_skill_mapped("dodge");
	if( !dodge_skill ) dodge_skill = "dodge";
	dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(limb,me);

	dodge_skill = (string)victim->query_skill_mapped("dodge");
	if( !dodge_skill ) dodge_skill = "dodge";
	dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(limb,victim);
	if (!dodge_msg || dodge_msg=="")
	dodge_msg = SKILL_D("dodge")->query_dodge_msg(limb,victim);
	parry_skill = (string)victim->query_skill_mapped("parry");
	if( !parry_skill ) parry_skill = "parry";
	parry_msg = SKILL_D(parry_skill)->query_parry_msg(victim,weapon);
	if (!parry_msg || parry_msg=="")
	parry_msg = SKILL_D("parry")->query_parry_msg(victim,weapon);

	// --------------------------------------------------------
	// 以下增加攻击招式的特殊攻防
	if (intp(action["dodge"]))
	victim->add_temp("fight/dodge", action["dodge"]/15);
	if (intp(action["parry"]))
	victim->add_temp("fight/parry", action["parry"]/15);
	if (intp(action["attack"]))
	me->set_temp("fight/attack", action["attack"]/10);
	// ---------------------------------------------------------

	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK,0);

	if((cost = sizeof(victim->query_enemy())) && cost > 1) {
		if(cost > 5) cost=5;
		ap /= cost;
	}
	if(!me->visible(victim)) ap /= 10;
	if( ap < 1) ap = 1;

	if(intp(action["dodge"]))
		me->set_temp("fight/dodge", action["dodge"]);

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE,0);

	if((cost = sizeof(victim->query_enemy())) && cost > 1) {
		if(cost > 5) cost=5;
		dp /= cost;
	}
	if( victim->is_busy() ) dp /= 3;
	if(!victim->visible(me)) dp /= 4;
	if( dp < 1 ) dp = 1;

	//
	// (3) Fight!

	if( random(ap + dp) < dp && living(victim) && living(me)){
	// Does the victim dodge this hit?
	result += dodge_msg;
	// This is for NPC only. NPC have chance to get exp when fail to hit.
	if( (ap < dp) && !userp(me) )
	{
		if( random((int)me->query_int()) > 15 )
		my["combat_exp"] += 1;
		me->improve_skill(attack_skill, random(me->query_int()));
	}
		if(victim->is_fight_npc()) {
			if( userp(me) && victim->query_temp("fighter_id") == my["id"]
			&& sizeof(me->query_enemy()) <= 2) {
			if(dp / 2 < ap){
				my["potential"] += 1 + random(3);
				my["combat_exp"] += 1 + random(3);
				me->improve_skill("dodge", random(4));
			}
		}
	}
		damage = RESULT_DODGE;
	} else {
	//
	//  (4) Check if the victim can parry this attack.
	//
	delta=0;

	if(weapon2 = victim->query_temp("weapon"))
	{
		if (!weapon) delta = 10;
	} else
	{
		if (weapon) delta = -10;
	}

	pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE,delta);

	if((cost = sizeof(victim->query_enemy())) && cost > 1) {
		if(cost > 5) cost=5;
		pp /= cost;
	}
	if( victim->is_busy() ) pp /= 3;

	if(my["bellicosity"] > your["bellicosity"]) pp /= 2;

	if (!victim->visible(me)) pp /= 10;

	if( pp < 1 ) pp = 1;

	if( random(ap + pp)< pp ){
		result += parry_msg;

	if(victim->is_fight_npc()) {
	if( userp(me) && victim->query_temp("fighter_id") == my["id"]
			&& sizeof(me->query_enemy()) <= 2 ) {
			    if(dp / 2 < ap){
				my["potential"] += 1 + random(3);
				my["combat_exp"] += 1 + random(3);
				me->improve_skill("parry", random(4));
			}

	}
}

	    damage = RESULT_PARRY;
	} else {

		//
		//  (5) We hit the victim and the victim failed to parry
		//
		if(weapon)
			damage = (int)me->query_temp("apply/damage");
		else
			damage = (int)me->query_temp("apply/unarmed_damage");

		damage = (damage + random(damage));

		if( action["damage"] )
			damage += action["damage"] /10 * (damage / 20);

		damage_bonus = (int)me->query_str();

		if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
			if( stringp(martial_skill = me->query_skill_mapped("force")) ) {
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
				if( stringp(foo) ) result += foo;
				else if( intp(foo) ) {
					if( !objectp(weapon) ) damage_bonus += foo;
					else damage_bonus += foo / 3;
					} else if( mapp(foo) ) {
						result += foo["result"];
					if( !objectp(weapon) ) damage_bonus += foo["damage"];
						else damage_bonus += foo["damage"] / 3;
				}
			}
		}

		if( action["force"] )
			damage_bonus += action["force"] * (damage_bonus / 100);

		if( stringp(martial_skill = me->query_skill_mapped(attack_skill)) ) {
			foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
			if( stringp(foo) ) result += foo;
			else if(intp(foo) ) damage_bonus += foo;
		}

		if( weapon ) {
			foo = weapon->hit_ob(me, victim, damage_bonus);
			if( stringp(foo) ) result += foo;
			else if(intp(foo) ) damage_bonus += foo;
		} else {
			foo = me->hit_ob(me, victim, damage_bonus);
			if( stringp(foo) ) result += foo;
			else if(intp(foo) ) damage_bonus += foo;
		}
		if( damage_bonus > 0 ) damage += (damage_bonus + random(damage_bonus))/2;
		else damage += (damage_bonus - random(-damage_bonus))/2;
		if( damage < 0 ) damage = 0;
		
		defense_factor = dp + pp;
		while( random(defense_factor) > ap / 3) {
			damage -= damage / 3;
			defense_factor /= 2;
		}

		if (  (defense_factor = victim->query_temp("protect"))
			&& your["neili"] > 100 && random(defense_factor) > 8 ) {
			count = random(defense_factor) / 2;
			if (count >= damage)
					result += HIC+"$n"+HIC+"成功地运用护体真气化解了$N的伤害！\n" + NOR;
				if (count >= damage / 2 && count < damage)
					result += HIR+"$n"+HIR+"成功地运用护体真气化解了$N大部分的伤害！\n" + NOR;
				if (count < damage / 2 && count > 0)
					result += HIM + "$n"+ HIM+"成功地运用护体真气化解了$N一部分的伤害！\n" + NOR;
				damage -= count;
				if (damage < 0) damage = 0;
				if(your["neili"] > 100) your["neili"] -= 100;
		}
		//
		//  (6) Inflict the damage.
		//

		if( stringp(martial_skill = victim->query_skill_mapped("force")) && (int)victim->query_temp("apply/armor_vs_force") ) {
			foo = SKILL_D(martial_skill)->armor_ob(me, victim, damage,(int)victim->query_temp("apply/armor_vs_force"));
			if( stringp(foo) ) {
				result += foo;
				damage=0;
			}
			else if( intp(foo) ) damage = foo;
		}
// npc的特殊防御
		foo = victim->weapon_ob(victim,me, damage);
		if( stringp(foo) ) result += foo;
		else if(intp(foo) ) damage += foo;

		result += damage_msg(damage, action["damage_type"],victim);

		if(objectp(armor = victim->query_temp("armor/cloth"))
		&& damage > (int)armor->query("armor_prop/armor")
		&& armor->query("equipped")) {
			ARMOR_D->hiton_armor(me, victim, weapon,armor,damage);
		}

		damage = victim->receive_damage("qi",damage,me);

		if( random(damage) > (int)victim->query_temp("apply/armor")
		&&((me->is_killing(victim->query("id")))
		&&((!weapon) && !random(4) || weapon && !random(2))
		||((!weapon) && !random(7) || weapon && !random(4)))){
		// We are sure that damage is greater than victim's armor here.
			victim->receive_wound("qi",damage - (int)victim->query_temp("apply/armor"), me);
			wounded = 1;
		}
	
		if (me->query_temp("sum_power"))
			victim->receive_wound("qi", damage - (int)victim->query_temp("apply/armor"), me);

		if( victim->is_fight_npc()) {
		if( userp(me) && victim->query_temp("fighter_id") == my["id"]
		&& sizeof(me->query_enemy()) <= 2) {
		if(ap / 2 < dp ){
			my["potential"] += 1 + random(3);
			my["combat_exp"] += 1 + random(3);
			me->improve_skill(attack_skill, random(4));
				}
			}
		}

		}
	}

	result = replace_string( result, "$l", limb );
	if( victim->query_temp("weapon"))
	result = replace_string( result, "$v", (victim->query_temp("weapon"))->name());
	if( objectp(weapon) )
	result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
	result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "unarmed" )
		  result = replace_string(result, "$w", "无形劲气" );
	else if( attack_skill == "cuff" )
		result = replace_string( result, "$w", "拳头" );
	else if( attack_skill == "finger" )
		result = replace_string( result, "$w", "指间一股真气" );
	else if( attack_skill == "strike" )
		result = replace_string( result, "$w", "无形掌力" );
	else if( attack_skill == "claw" )
		result = replace_string( result, "$w", "手爪" );

	if(!me->query("env/combat"))
	message_vision(result, me, victim );

	if(wizardp(me) && my["env"] && my["env"]["combat"]) {
	if( damage > 0 )
		tell_object(me, sprintf( WHT "我方 AP：%d，对手 DP：%d，对手 PP：%d，伤害力：%d\n" NOR,
		ap, dp, pp, damage));
	else
		tell_object(me, sprintf( WHT "我方 AP：%d，对手 DP：%d，对手 PP：%d\n" NOR,
		ap, dp, pp));
	}
	if( wizardp(victim) && your["env"] && your["env"]["combat"] ) {
	if( damage > 0 )
		tell_object(victim, sprintf( WHT "对手 AP：%d，我方 DP：%d，我方 PP：%d，伤害力：%d\n" NOR,
		ap, dp, pp, damage));
	else
		tell_object(victim, sprintf( WHT "对手 AP：%d，我方 DP：%d，我方 PP：%d\n" NOR,
		ap, dp, pp));
	}
	if( damage > 0 ) {
	report_status(victim, wounded);

	if((your["eff_qi"] < 0 || your["eff_jing"] < 0)
	&& objectp(my_weapon = me->query_temp("weapon"))
	&& my["race"] == "人类"
	&& your["race"] == "人类"
	&& !random(5)
	&& !me->query_temp("pending/fight")
	&& !victim->query_temp("pending/fight")){
		die_msg=must_die_msg[random(sizeof(must_die_msg))];
		die_msg = replace_string(die_msg,"$w",my_weapon->name());
		message_vision(WHT + clean_color(die_msg) + NOR,me,victim);
	}
	if( victim->is_busy() ) victim->interrupt_me(me);
		if(!me->is_killing(your["id"]) && !victim->is_killing(my["id"])
		&& your["qi"]*2 <= your["max_qi"] && living(victim)){
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
			me->delete_temp("pending/fight");
			victim->delete_temp("pending/fight");
		}
		
		if(my["family"]) 
			me_family = my["family"]["family_name"];
		else
			me_family = "无门无派";

		if(your["family"]) 
			victim_family = your["family"]["family_name"];
		else
			victim_family = "无门无派";

		if(environment(me)->query("fight_room")
		&& environment(victim)->query("fight_room")
		&&(your["eff_qi"] <= 50 || your["qi"] <= 50
		|| your["eff_jing"] <= 50 || your["jing"] <= 50 )) {
			if( mapp(kick_exits = environment(victim)->query("exits")) 
			&& sizeof(kick_exits)) {
				kick_directions = keys( kick_exits );
				victim->move(kick_exits[ kick_directions[0]]);
				other_message(HIY,"紫禁之颠",sprintf("%s的%s比武战胜%s的%s，将%s一脚踢下擂台！！",
				me_family,me->name(),victim_family,victim->name(),victim->name()));
				message_vision("$N把$n一脚踢下擂台。\n",me,victim);
			}
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			victim->remove_all_killer();
			me->remove_all_killer();
			victim->unconcious();
			victim->revive();
			your["eff_qi"] = your["max_qi"];
			your["eff_jing"] = your["max_jing"];
			victim->delete_temp("last_damage_from");
			my["fight_wins"]+=1;
			your["fight_lose"]-=1;
		}

	}
	if( functionp(action["post_action"]) )
	evaluate( action["post_action"], me, victim, weapon, damage);
	else
	WEAPON_D->bash_weapon(me, victim, weapon, damage);
	// See if the victim can make a riposte.

	if( attack_type==TYPE_REGULAR
	&&  damage < 1
	&&  victim->query_temp("guarding") ) {
	victim->set_temp("guarding", 0);
	if( random(my["dex"]) < 5 ) {
		message_vision("$N一击不中，露出了破绽！\n", me);
		do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
	} else {
		message_vision("$N见$n攻击失误，趁机发动攻击！\n", victim, me);
		do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
	}
	}
}
//  fight()
//
//  This is called in the attack() defined in F_ATTACK, which handles fighting
//  in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
	object ob,weapon;
	string skill_name,msg;
	mapping my,your;

	if( !living(me) || me->is_busy() ) return;
	if(!me->visible(victim)) return;
	if(environment(me)!=environment(victim) ) return;

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();

	// If victim is busy or unconcious, always take the chance to make an attack.

	weapon = me->query_temp("weapon");
	if(my["bellicosity"] > my["neili"]
	&& my["bellicosity"] / 100 > (int)me->query_cor()
	&& (int)me->query_cor() > (int)victim->query_cor()
	&& your["race"] == "人类"
	&& me->is_killing(your["id"]) && victim->is_killing(my["id"])) {
		me->set_temp("action_flag",1);
		msg = bellicosity_msg[random(sizeof(bellicosity_msg))];
		msg = replace_string(msg,"$w",weapon?weapon->name():"双掌");
		message_vision(RED + clean_color(msg) + NOR, me, victim);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		me->set_temp("action_flag",0);
	}
	if( victim->is_busy() || !living(victim) ) {
		me->set_temp("guarding", 0);
	if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
	if ((random(me->query_int())>50 || random(10)<3) && victim->is_fighting(me)){
		me->set_temp("secondly_weapon",1);
		do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
		me->delete_temp("secondly_weapon");
	}
	else if( me->is_killing(your["id"]) && victim->is_killing(my["id"])) {
	if( (!objectp(me->query_temp("weapon"))
	&& sizeof(me->query_skill_prepare()) > 1)
	|| ( objectp(me->query_temp("weapon"))
	&&(me->query_temp("weapon"))->query("skill_type") == "sword"
	&& me->query_skill("pixie-jian", 1) >= 60
	&& me->query_skill_mapped("sword") == "pixie-jian") ){
		me->set_temp("action_flag",1);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		me->set_temp("action_flag",0);
	} }

	if (living(victim)){
		if(  !objectp(ob=me->query_temp("weapon")))
		skill_name="unarmed";
		else skill_name=ob->query("skill_type");
		skill_name=me->query_skill_mapped(skill_name);
		if (stringp(skill_name)){
		me->set_temp("action_flag",1);
		SKILL_D(skill_name)->do_interlink(me, victim);
		me->set_temp("action_flag",0);
		}
	}

   // Else, see if we are brave enough to make an aggressive action.

	} else if( random( (int)victim->query_dex() * 2 ) < (int)me->query_dex() || random(10)<3) {
	me->set_temp("guarding", 0);
	if( !victim->is_fighting(me) ) victim->fight_ob(me);
	do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
	if(  me->is_killing(your["id"]) && victim->is_killing(my["id"])) {
	if( (!objectp(me->query_temp("weapon"))
	&& sizeof(me->query_skill_prepare()) > 1)
	||  ( objectp(me->query_temp("weapon"))
	&&(me->query_temp("weapon"))->query("skill_type") == "sword"
	&& (int)me->query_skill("pixie-jian", 1) >= 60
	&& (string)me->query_skill_mapped("sword") == "pixie-jian") ){
		me->set_temp("action_flag",1);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
		me->set_temp("action_flag",0);
	}
}
	else if ((random(me->query_int())>50 || random(10)<2) && victim->is_fighting(me)){
		me->set_temp("secondly_weapon",1);
		do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
		me->delete_temp("secondly_weapon");
	}

	if(  !objectp(ob=me->query_temp("weapon")))
	skill_name="unarmed";
	else skill_name=ob->query("skill_type");
	skill_name=me->query_skill_mapped(skill_name);
	if (stringp(skill_name)){
		me->set_temp("action_flag",1);
		SKILL_D(skill_name)->do_interlink(me, victim);
		me->set_temp("action_flag",0);
	}
	} else if( !me->query_temp("guarding") ) {
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
		return;
	} else return;
}

void auto_fight(object me, object obj, string type)
{
	if( !userp(me) && !userp(obj) ) return;

	if( me->query_temp("looking_for_trouble") ) return;

	me->set_temp("looking_for_trouble",1);

	call_out("start_"+type,0,me,obj);
}
void start_berserk(object me, object obj)
{
	int shen,sb_shen;

	if( !me || !obj || !living(me)) return;

	me->set_temp("looking_for_trouble",0);

	if(me->is_fighting(obj) 
	|| environment(me)!=environment(obj) 
	|| environment(me)->query("no_fight")) return;

	message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);

	shen = (int)me->query("shen");
	sb_shen = (int)obj->query("shen");

	if((shen < -100000 || sb_shen > 100000 ) 
	&& me->query_per() > random(obj->query_per()) * 2) {
		message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me) + "看你实在很不顺眼，去死吧。\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N对著$n喝道：喂！" + RANK_D->query_rude(obj)+ "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n",me, obj);
		me->fight_ob(obj);
	}
}
void start_hatred(object me, object obj)
{
	if( !me || !obj || !living(me)) return;

	me->set_temp("looking_for_trouble",0);

	if(me->is_fighting(obj) 
	|| environment(me)!=environment(obj) 
	|| environment(me)->query("no_fight")) return;

	if((string)me->query("race") == "人类" )
		message_vision( catch_hunt_human_msg[random(sizeof(catch_hunt_human_msg))], me, obj);
	if((string)me->query("race") == "野兽" )
		message_vision( catch_hunt_beast_msg[random(sizeof(catch_hunt_beast_msg))], me, obj);
	if((string)me->query("race") == "飞禽" )
		message_vision( catch_hunt_bird_msg[random(sizeof(catch_hunt_bird_msg))], me, obj);

	me->kill_ob(obj);
}
void start_vendetta(object me, object obj)
{
	if( !me || !obj || !living(me)) return;

	me->set_temp("looking_for_trouble",0);

	if(me->is_fighting(obj) 
	|| environment(me)!=environment(obj) 
	|| environment(me)->query("no_fight")) return;

	me->kill_ob(obj);

}
void start_aggressive(object me, object obj)
{
	if( !me || !obj || !living(me)) return;

	me->set_temp("looking_for_trouble",0);

	if(me->is_fighting(obj) 
	|| environment(me)!=environment(obj) 
	|| environment(me)->query("no_fight")) return;

	me->kill_ob(obj);

}
// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
	switch(event)
	{
		case "dead":
			message_vision((string)ob->query("dead_message"), ob);
			break;
		case "unconcious":
			message_vision((string)ob->query("unconcious_message"), ob);
			break;
		case "revive":
			message_vision((string)ob->query("revive_message"), ob);
			break;
	}
}
void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}
int die_for(object victim)
{
	mapping vs;
	string place;

	vs = victim->query_entire_dbase();

	if (!userp(victim)) return 0;

	victim->clear_condition(1);
	victim->skill_death_penalty();

	vs["VKS"] += 1;
	vs["bellicosity"] = 0;
	vs["combat_exp"] -= vs["combat_exp"] / 100;
	
	if( vs["potential"] > vs["learned_points"])
		vs["potential"] += (vs["learned_points"] - vs["potential"]) / 2;

	vs["shen"] -= vs["shen"] /10;
	vs["weiwang"] -= vs["weiwang"] /10;
	vs["score"] -= vs["score"] /10;
	map_delete(vs, "vendetta");
	vs["kill_family"] = 0;
	vs["thief"] -= vs["thief"]/2;
	if (stringp(victim->query_temp("die_for"))){
		CHANNEL_D->do_channel(this_object(), "rumor",
			clean_color(sprintf("%s%s", victim->name(1),(string)victim->query_temp("die_for"))));
		victim->delete_temp("die_for");
	}else{
		place = environment(victim)->short();
		CHANNEL_D->do_channel(this_object(),"sys",vs["name"]+"在("+base_name(environment(victim))+")意外死亡。");
		CHANNEL_D->do_channel(this_object(),"rumor",clean_color(vs["name"]+"在"+place +"死于非命！！"));
	}
	victim->delete_temp("first_kill");
	victim->delete_temp("last_damage_from");
	victim->delete_temp("be_kill");
}
void killer_reward(object killer, object victim)
{
	string w_name,vmark,msg,place;
	object weapon,where;
	mapping ks,vs;

	vs = victim->query_entire_dbase();
	ks = killer->query_entire_dbase();

	if(userp(victim)) {
		if(objectp(weapon = killer->query_temp("weapon")))
		w_name = weapon->name();
		msg = w_name?"死在了"+ ks["name"]+"的"+ w_name +"之下！":"被"+ ks["name"]+"杀死了！";

		if( objectp(where = environment(victim)))
			place = clean_color(where->short());
		else
			place = "某地";

		victim->set_temp("die_for","在「"+ place + "」"+ msg);
		if(victim->query_condition("killer")){
			CHANNEL_D->do_channel(this_object(),"rumor",
				sprintf("听说凶犯%s已经在「%s」被%s就地正法了！！",vs["name"],place,ks["name"]));
				log_file("PKER", sprintf("%s 凶手%s[%s]在[%s]被%s[%s]杀死。\n",ctime(time()),vs["name"],
				vs["id"], place,ks["name"],ks["id"]));
		}
		else if((killer->query_temp("first_kill/"+ victim->query("id"))
		|| victim->query_temp("be_kill/" + killer->query("id")))) {
				CHANNEL_D->do_channel(this_object(),"rumor",
					sprintf("官府发下了海捕文书，捉拿凶犯%s，重赏！！",ks["name"]));
				log_file("KILLED", sprintf("%s %s[%s]在[%s]被%s[%s]杀死。\n",ctime(time()),vs["name"],
				vs["id"], place,ks["name"],ks["id"]));
				killer->apply_condition("killer",(int)killer->query_condition("killer") + 300);
				ks["PKS"] += 1;
		} else {
				log_file("DIED",sprintf("%s %s[%s]在[%s]被%s[%s]杀死。\n",ctime(time()),vs["name"],vs["id"], place,ks["name"], ks["id"]));
		}
		die_for(victim);
	}
	killer->remove_killer(victim);
	if(!ks["quest"] || ks["quest"]["quest"] != vs["name"])

		ks["shen"] -= vs["shen"] / 10;

	victim->afterdie_func( killer );

	ks["MKS"]+=1;

	if(userp(killer)) ks["bellicosity"] += 10;
	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);
}
