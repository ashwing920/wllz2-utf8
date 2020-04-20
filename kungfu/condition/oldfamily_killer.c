// oldfamily_killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        object ob;
        mapping old_family;
        old_family = me->query("old_family");
        
        if (duration < 1) return 0;
        me->apply_condition("oldfamily_killer", duration - 1);
        if (duration == 1) {
                message("channel:rumor",HIM"【武林传奇】某人：听说"+ old_family["family_name"] +"已经放弃追杀"+ me->query("name") +"了。\n"+ NOR,users());
                me->delete("old_family");
        }
        if(random(10) ==2 && !environment(me)->query("no_fight")){
                ob=new("/clone/npc/oldfamily_killer");
                ob->set("family",old_family);
                ob->set("title",old_family["family_name"]+"第"+ chinese_number(old_family["generation"])+"代惩恶使");
                ob->set("combat_exp",me->query("combat_exp"));
                ob->make_skill();
                NPC_D->full_init(ob);
                ob->move(environment(me));
                me->fight_ob(ob);
        }
        return 1;
}
