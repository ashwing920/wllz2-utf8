// man.c

#include <ansi.h>

inherit NPC;
void checking();
void create()
{
        set_name(npc_name("男性"),({ "yi fan","fan","robber"}));
        set("title","疑犯");
        set("attitude", "heroism");
        set("age", 30+random(20));
        set("str", 30);
        set("per", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 50);
        set("chat_chance",5);
        set("chat_msg", ({
                (: random_move :),
        }));

        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
                 (: command, "exert recover":),
                 (: command, "exert regenerate":),
        }));

        set("max_jing",5000);
        set("jing",5000);
        set("qi",5000);
        set("max_qi",5000);
        set("neili",2000);
        set("max_neili", 2000);
        set("env/wimpy",20);
        set("combat_exp",100000);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("gold",1);
        remove_call_out("back");
        call_out("back",600,this_object());
}
void init()
{
        object ob;

        if( interactive(ob = this_player())
        && ob->query("quest/quest") == this_object()->query("name")
        && ob->query("quest/task_time") > time()) {
                checking();
                add_action("do_arrest","arrest");
        }
}
int do_arrest(string arg)
{
        object me,ob;
        ob = this_object();
        me = this_player();
        
        if(!id(arg))
                return notify_fail("你要抓什么人？\n");
        if( ob->query("name") != me->query("quest/quest")
        && me->query("quest/from") != "官府")
                return notify_fail("你没有权利逮捕这个人。\n");
        
        if( me->is_busy())
                return notify_fail("你正忙着呢！抓什么抓！\n");

        if( me->is_fighting())
                return notify_fail("战斗中无法抓人！\n");

        if(!living(ob))
                return notify_fail(ob->name()+"现在已经昏迷了，你根本无法确认是不是你的目标。\n");

        if( ob->query_temp("arrest") == me)
                return notify_fail(ob->name()+"已经被你抓起来了，快回去["HIG"ask xingbu shangshu about 复命"NOR"]吧！\n");
                
        message_vision("$N喝道：$n，刑部尚书高大人想见你，快随我到刑部走一趟！\n",me,ob);
        switch(random(10)){
                case 1:
                        message_vision("$n一愣，吓得双腿直哆嗦道：是.是...小的..这就.就和大人走。\n",me,ob);
                        message_vision("$n决定乖乖的跟着$N一起到刑部去了。\n",me,ob);
                        ob->set_leader(me);
                        ob->delete("chat_chance");
                        tell_object(me,"快带"+ ob->name()+"回去复命["HIG"ask xingbu shangshu about 复命"NOR"]吧！\n");
                        ob->set_temp("arrest",me);
                        me->set_temp("arrest",ob);
                        break;
                case 2:
                        message_vision("$n脸色一变，对$N喝道：嘿嘿！想抓大爷我？打赢我再说吧！\n",me,ob);
                        message_vision("$n话音刚落，立刻向$N扑来！\n",me,ob);
                        ob->fight_ob(me);
                        me->fight_ob(ob);
                        remove_call_out("checking_status");
                        call_out("checking_status", 1, me, ob);
                        break;
                case 3:
                        message_vision("$n定了定神，神色坦然，笑道："+ RANK_D->query_respect(me)+"叫道，小的听命就是！\n",me,ob);
                        message_vision("$N心想：没想到这次任务如此顺利。谁知$n话音刚落，立刻对$N发起攻击！\n",me,ob);
                        ob->fight_ob(me);
                        me->fight_ob(ob);
                        remove_call_out("checking_status");
                        call_out("checking_status", 1, me, ob);
                        break;
                default:
                        message_vision("$n对$N爱理不理，好象没听到$N说什么。\n",me,ob);
                        break;
        }
        return 1;
}
int checking_status(object me, object ob)
{
        int my_max_qi, his_max_qi;

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if(ob->is_fighting(me)
        && me->is_fighting(ob)) {
                if ( (ob->query("qi")*100 / his_max_qi) <= 80 )
                command("exert recover");
                command("exert regenerate");
                call_out("checking_status", 1, me, ob);
                return 1;
        }
        if ( !present(me, environment()) ) return 1; 
        if (( (int)ob->query("qi")*100 / his_max_qi) <= 50 ) {
                message_vision("$n吓得脸色惨白，连忙向$N跪地求饶："+ RANK_D->query_respect(me)+"饶命，小的跟您走就是。\n",me,ob);
                message_vision("$n决定乖乖的跟着$N一起到刑部去了。\n",me,ob);
                tell_object(me,"快带"+ ob->name()+"回去复命["HIG"ask xingbu shangshu about 复命"NOR"]吧！\n");
                remove_call_out("checking_status");
                ob->remove_all_enemy(1);
                me->remove_all_enemy(1);
                ob->set_leader(me);
                ob->delete("chat_chance");
                ob->set("qi",ob->query("max_qi"));
                ob->set("eff_qi",ob->query("max_qi"));
                ob->set("eff_jing",ob->query("max_jing"));
                ob->set("jing",ob->query("max_jing"));
                ob->set_temp("arrest",me);
                me->set_temp("arrest",ob);
                ob->set_temp("fight_lost_for",me);
                ob->fight_ob(me);
                me->fight_ob(ob);
                return 1;
        }
        if (( (int)me->query("qi")*100 / my_max_qi) < 50 ) {
                message_vision("$n哈哈大笑：就凭你这点皮毛也想抓我？回家种田去吧！\n",me,ob);
                message_vision("$n说完，一个纵身跳开数丈之远，消失在人群之中。$N的任务失败了。\n",me,ob);
                destruct(ob);
                return 1;
        }

        return 1;  
}

int accept_fight(object ob)
{
        command("say 在下怎么是"+ RANK_D->query_respect(this_player())+"的对手呢？见笑！见笑！");
        return 1;
}
void checking()
{
        object me, ob;
        mapping hp_status, skill_status, map_status, prepare_status;
        mapping my;
        string *sname, *mname, *pname;
        int i, temp;

        me = this_object();
        ob = this_player();

        if (mapp(skill_status = ob->query_skills()))//判断对象是否有功夫，如有将用这个函数复制全部功夫
        {
                skill_status = ob->query_skills();
                sname = keys(skill_status);//传回所有对象功夫阵列

                for (i = 0; i < sizeof(skill_status); i++)
                me->set_skill(sname[i], skill_status[sname[i]]);//为自己复制所有功夫
        }

        if (mapp(map_status = me->query_skill_map()))//判断自己是否有已装配的基本功夫
        {
                mname = keys(map_status);
                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                me->map_skill(mname[i]);
        }

        if (mapp(map_status = ob->query_skill_map()))//判断对象所装配的基本功夫，如有将用这个函数复制
        {
                mname = keys(map_status);

                for(i = 0; i < sizeof(map_status); i++)
                me->map_skill(mname[i], map_status[mname[i]]);
        }

        if (mapp(prepare_status = me->query_skill_prepare()))//判断自己是否有已装配的特殊功夫
        {
                pname = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i = 0; i < temp; i++)
                me->prepare_skill(pname[i]);
        }

        if (mapp(prepare_status = ob->query_skill_prepare()))//判断对象所装配的特殊功夫，如有将用这个函数复制
        {
                pname = keys(prepare_status);

                for(i = 0; i < sizeof(prepare_status); i++)
                me->prepare_skill(pname[i], prepare_status[pname[i]]);
        }

                hp_status = ob->query_entire_dbase();//得到对象现有状态
                my = me->query_entire_dbase();//得到自己现有状态

        my["str"] = hp_status["str"];//开始复制状态
        my["int"] = hp_status["int"];
        my["con"] = hp_status["con"];
        my["dex"] = hp_status["dex"];
        my["spi"] = hp_status["spi"];
        my["cor"] = hp_status["cor"];
        my["kar"] = hp_status["kar"];

        my["max_qi"] = hp_status["max_qi"];
        my["eff_qi"] = hp_status["eff_qi"];
        my["qi"] = my["max_qi"];
        my["max_jing"] = hp_status["max_jing"];
        my["eff_jing"] = hp_status["eff_jing"];
        my["jing"] = my["max_jing"];
        my["max_neili"] = hp_status["max_neili"];
        my["neili"] = hp_status["neili"];
        my["jiali"] = hp_status["jiali"] / 2;
        my["combat_exp"] = hp_status["combat_exp"];//结束复制状态
        me->set_temp("apply/armor",200);
        me->reset_action();//更新身体
        return;

}
void back()
{
        if(!this_object()) return;
        destruct(this_object());
}
