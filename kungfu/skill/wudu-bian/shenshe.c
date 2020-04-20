//五毒神蛇

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("你只能在站斗中才能引蛇。\n");

        if((int)me->query_skill("wudu-bian",1) < 120
                ||(int)me->query_skill("wudu-xinfa",1) < 120 )
                return notify_fail("你的五毒心法功力太浅，无法引蛇！\n");

        if((int)me->query("neili") < 100)
                return notify_fail("你的内力不够了。\n");

        if((int)me->query_temp("yinshe") > 10)
                return notify_fail("你呼唤来的蛇太多了。\n");

        me->start_busy(2);
        msg = HIB "$N潜运内力，口中念念有词的不知说了些什么。\n"NOR;
        message_vision(msg, me, target);
        me->add_temp("yinshe",1);
        me->add("neili",-100);
        call_out("yinshe",1,me);
        if( me->query_temp("yinshe") > 10) {
                call_out("clean_she",30,me);
        }
        return 1;
}
void yinshe()
{
        object ob,me,target;
        int lvl;
        me = this_player();

        if( !target ) target = offensive_target(me);
        lvl = (int)me->query_skill("pour",1);

        if( lvl >= 400 && lvl < 500 ) lvl = 550;
        if( lvl >= 300 && lvl < 400 ) lvl = 450;
        if( lvl >= 200 && lvl < 300 ) lvl = 350;
        if( lvl >= 100 && lvl < 200 ) lvl = 250;

        message_vision(HIG"\n只听见悉唆的声响，一道黑影突然出现在$N的眼前！\n\n"NOR,me);
        ob=new("/d/wudu/npc/she");

        switch(lvl) {
                case 250:
                        ob->set_name(HIR"毒蛇"NOR,({"du she","she","snake"}));
                        ob->set("eff_qi",lvl * 2);
                        ob->set("max_qi",ob->query("eff_qi"));
                        ob->set("qi",ob->query("max_qi"));
                        ob->set("eff_jing",lvl * 2);
                        ob->set("max_jing",ob->query("eff_jing"));
                        ob->set("max_jing",ob->query("eff_jing"));
                        ob->set("jing",ob->query("max_jing"));
                        ob->add_temp("apply/attack",lvl);
                        ob->add_temp("apply/damage",lvl);
                        ob->add_temp("apply/dodge",lvl);
                        ob->add_temp("apply/armor",lvl);
                        ob->set("combat_exp",me->query("combat_exp") / 5);
                        ob->set("lvl",lvl);
                        break;
                case 350:
                        ob->set_name(HIY"金环蛇"NOR,({"jinhuan she","she","snake"}));
                        ob->add_temp("apply/attack",lvl);
                        ob->add_temp("apply/damage",lvl);
                        ob->add_temp("apply/dodge",lvl);
                        ob->add_temp("apply/armor",lvl);
                        ob->set("eff_qi",lvl * 2);
                        ob->set("max_qi",ob->query("eff_qi"));
                        ob->set("qi",ob->query("max_qi"));
                        ob->set("eff_jing",lvl * 2);
                        ob->set("max_jing",ob->query("eff_jing"));
                        ob->set("max_jing",ob->query("eff_jing"));
                        ob->set("jing",ob->query("max_jing"));
                        ob->set("combat_exp",me->query("combat_exp") / 3);
                        ob->set("lvl",lvl);
                        break;
                case 450:
                        ob->set_name(HIG"五步神蛇"NOR,({"wubu shenshe","she","snake"}));
                        ob->add_temp("apply/attack",lvl);
                        ob->add_temp("apply/damage",lvl);
                        ob->add_temp("apply/dodge",lvl);
                        ob->add_temp("apply/armor",lvl);
                        ob->set("eff_qi",lvl * 2);
                        ob->set("max_qi",ob->query("eff_qi"));
                        ob->set("qi",ob->query("max_qi"));
                        ob->set("eff_jing",lvl * 2);
                        ob->set("max_jing",ob->query("eff_jing"));
                        ob->set("max_jing",ob->query("eff_jing"));
                        ob->set("jing",ob->query("max_jing"));
                        ob->set("combat_exp",me->query("combat_exp") / 3);
                        ob->set("lvl",lvl);
                        break;
                case 550:
                        ob->set_name(HIW+BLK"黑冠巨蟒"NOR,({"heiguan juman","she","snake"}));
                        ob->add_temp("apply/attack",lvl);
                        ob->add_temp("apply/damage",lvl);
                        ob->add_temp("apply/dodge",lvl);
                        ob->add_temp("apply/armor",lvl);
                        ob->set("eff_qi",lvl * 2);
                        ob->set("max_qi",ob->query("eff_qi"));
                        ob->set("qi",ob->query("max_qi"));
                        ob->set("eff_jing",lvl * 2);
                        ob->set("max_jing",ob->query("eff_jing"));
                        ob->set("max_jing",ob->query("eff_jing"));
                        ob->set("jing",ob->query("max_jing"));
                        ob->set("combat_exp",me->query("combat_exp") / 2);
                        ob->set("lvl",lvl);
                        break;

                default:
                        ob->set_name(HIG"竹叶青蛇"NOR,({"zhuyeqing she","she","snake"}));
                        ob->add_temp("apply/attack",lvl);
                        ob->add_temp("apply/damage",lvl);
                        ob->add_temp("apply/dodge",lvl);
                        ob->add_temp("apply/armor",lvl);
                        ob->set("combat_exp",random(me->query("combat_exp") / 2));
                        ob->set("lvl",lvl);
                        break;
                }

        ob->move(environment(me));
        if( target
        && present(target,environment(me))
        && me->is_fighting(target)
        && target->is_fighting(me)) {
        	message_vision(HIR"\n"+ ob->name() + HIR"听从$N的指挥，“嗖”的一声，对$n发动了攻击！\n\n"NOR,me,target);
        	ob->kill_ob(target);
        	target->kill_ob(ob);
	}
        return;
}

void clean_she()
{
        object me;
        me = this_player();

        if( me->query_temp("yinshe")) {
                me->delete_temp("yinshe");
        }
}
