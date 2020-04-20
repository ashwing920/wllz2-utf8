// man.c

#include <ansi.h>
inherit NPC;

mapping default_dirs1 = ([
        "north":                "北面",
        "south":                "南面",
        "east":                 "东面",
        "west":                 "西面",
        "northup":              "北边",
        "southup":              "南边",
        "eastup":               "东边",
        "westup":               "西边",
        "northdown":            "北边",
        "southdown":            "南边",
        "eastdown":             "东边",
        "westdown":             "西边",
        "northeast":            "东北",
        "northwest":            "西北",
        "southeast":            "东南",
        "southwest":            "西南",
        "up":                   "上面",
        "down":                 "下面",
        "enter":                "里面",
        "out":                  "外面",
]);

void create()
{
        set_name(npc_name("男性"),({"ren fan"}));
        set("attitude", "heroism");
        set("nickname",HIR"朝廷重犯"NOR);
        set("age", 30+random(20));
        set("str", 30);
        set("per", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 50);
        
        set("chat_chance_combat",300);
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
        set("env/wimpy",10);
        set("combat_exp",200000);
        set("no_get",1);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        remove_call_out("back");
        call_out("back",180,this_object());
}
void init()
{       
        object ob;
        if( interactive(ob = this_player()) 
        && environment(ob) 
        && living(this_object())
        && !this_object()->query_temp("unconcious")
        && ob->query("guanfu/npc_name") == this_object()->name()) {
                add_action("do_come","yasong");
                add_action("do_give","give");
                add_action("do_bang","bang");
                remove_call_out("back");
                call_out("back",ob->query("guanfu/quest_time")- time(),this_object());
        }
}
int do_bang(string arg)
{
        object ob,me;
        me = this_player();
        ob = this_object();
        
        if(!arg || arg =="" || !id(arg))
                return notify_fail("你要绑什么？\n");
        if(ob->name() != me->query("gaunfu/npc_name")
        && me->query("guanfu/type") != "押解")
                return notify_fail(ob->name()+"喝道：绑什么绑？找死啊？\n");
        if(ob->query("bang"))
                return notify_fail(ob->name()+"已经被绑住了。\n");
        
        message_vision("$N拿出铁链，对着$n露出一阵阴暗的笑容。\n",me,ob);
        command("fear");
        message_vision("$N把$n绑了个牢牢实实。\n",me,ob);
        ob->set("bang",1);
        return 1;
}
        
int do_come(string arg)
{
        object ob,me,env,obj;
        mapping exit;
        string where;
        
        ob = this_object();
        me = this_player();

        if( !arg || arg =="")
                return notify_fail("你要把"+ ob->name()+"往哪押解啊？\n");

        if(ob->name() != me->query("guanfu/npc_name")
        && me->query("guanfu/type") != "押解")
                return notify_fail(ob->name()+"恶狠狠的说道：干吗？想找死啊？\n");

        if(!ob->query("bang"))
                return notify_fail(ob->name()+"怎么也不愿跟你走，还是把他绑住吧！\n");

        if(ob->is_fighting())
                return notify_fail("你没看"+ ob->name() +"正在战斗吗？\n");
        if(me->is_busy())
                return notify_fail("你还忙着呢！\n");
        if(me->is_fighting()) 
                return notify_fail("你先解决你自己吧！\n");
        if(me->query("qi") < 50 ||me->query("jing") < 50 )
                return notify_fail("你太累了，还是休息一下再走吧！\n");
        
        if(objectp(present("robber", environment(me)))){
                message_vision("$N拉着$n回头就想走，却见蒙面人喝道：放下我兄弟，放你走路。\n", me,ob);
                        return notify_fail("蒙面人一把拦阻了你的去路。\n");
        }

        env = environment(me);
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                return notify_fail("这个方向没有出路。\n");
        }
        if(present(ob,env)){
        where =default_dirs1[arg];
        message("vision",me->name()+"用铁炼牵着"+ ob->name() +"往"+ where +"离开了。\n"NOR, env, ({me}));
        
        switch(random(15)){
                        case 1:
                        obj = new("/clone/npc/robber");
                        obj->set("combat_exp",me->query("combat_exp") * 2);
                        obj->move(environment(me));
                        message_vision("突然路边跳出了一个蒙面人，说时迟那是快，一个身影顿到你的跟前。\n",me);
                        message_vision("$N喝道：识相的，放了我兄弟，让你走路。\n",obj);
                        message_vision("$N定睛一看，却见$n的招式已经向$N袭来。\n",me,obj);
                        obj->kill_ob(me);
                        obj->set_leader(me);
                        ob->add("path",5);
                        me->kill_ob(obj);
                        break;
                        case 3:
                        message_vision("忽然一道黑影袭来，一面飞刀正好刺中$n的手臂，$N四处张望，却毫无发现。\n",me,ob);
                        ob->receive_wound("qi",200);
                        ob->receive_wound("jing",200);
                        ob->add("path",5);
                        COMBAT_D->report_status(ob);
                        break;
                        case 5:
                        message_vision("一个商旅摸样的汉子在$N身边走过，突然掏出一把小刀，向$n刺去。\n",me,ob);
                        ob->receive_wound("qi",200);
                        ob->receive_wound("jing",200);
                        ob->add("path",5);
                        COMBAT_D->report_status(ob);
                        break;
                        case 6:
                        obj = new("/clone/npc/robber");
                        obj->set("combat_exp",me->query("combat_exp") * 2);
                        obj->move(environment(me));
                        message_vision("突然路边跳出了一个蒙面人，说时迟那是快，一个身影顿到你的跟前。\n",me);
                        message_vision("$N喝道：$n，你已落入衙门手中，今日兄弟我不能留你。\n",obj,ob);
                        message_vision("$N闷声不吭的对$n发动攻击。\n",obj,ob);
                        obj->kill_ob(ob);
                        ob->kill_ob(obj);
                        ob->add("path",10);
                        break;
                        default:
                        message("vision","你用铁炼牵着"+ ob->name()+"上路了。\n", me);
                        me->move(exit[arg]);
                        ob->move(environment(me));
                        message("vision",ob->name()+"被押着走了过来。\n",me);
                        all_inventory(env)->follow_me(me, arg);  
                        message("vision",me->name()+"牵着"+ ob->name()+"，十分谨慎的走了过来。\n"NOR, environment(me), ({me}) );
                        ob->add("path",1);
                        break;
                }
                me->add("jing",-50);
                me->add("qi",-50);
        return 1;
        }
}
int do_give(string arg)
{
        object me,ob,target;
        mapping guanfu;
        int exp;
        me = this_player();
        
        if(!arg || arg == "") return 0;
        if(sscanf(arg,"%s to %s", ob, target)!=2 )
        if(sscanf(arg,"%s %s", target, ob) !=2 ) return 0;
        if(!id(ob) ) return 0;
        if(!(guanfu = me->query("guanfu"))) return 0;
        
        if(!ob = present(target,environment(me)) ) 
                return notify_fail("你想要把"+ this_object()->name() +"交给谁？\n");
        
        if(!living(ob) )
                return notify_fail("看来要先把"+ ob->name()+"救醒再说。\n");

        if(!living(this_object()))
                return notify_fail("看来要先把"+ this_object()->name()+"救醒再说。\n");

        if(!ob->is_guanfu())
                return notify_fail("你不能把"+ this_object()->name() +"交给"+ ob->name()+"。\n");
        
        
        tell_object(me,"你成功的将"+ this_object()->name()+"交给了"+ ob->name() + "。\n");
        me->delete("guanfu");
        me->delete("kill_bad_time");
        if(guanfu["quest_time"] > time()) {
        exp = (this_object()->query("path") * 2) + random(80);
        if(exp <= 200 ) exp = 200;
        if(exp >= 800) exp = 800;
        me->add("combat_exp",exp /2);
        me->add("potential",exp * 2);
        me->add("score",1);
        SCORE_D->set_score(me);
        message_vision("$N成功的将$n押解到了刑部，获得了嘉奖。\n",me,this_object());
        tell_object(me,"你被奖励了"+ chinese_number(exp/2) +"点经验，"+ chinese_number(exp) +"点潜能。\n");
        tell_object(me,"你的江湖阅历提高了一点。\n");
        }
        else {
                tell_object(me,"可惜时间已经延误了。\n");
        }
        
        destruct(this_object());
        return 1;
}
void back()
{
        if(!this_object()) return;
        destruct(this_object());
}
