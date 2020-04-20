#include <ansi.h>
inherit NPC;

void create()
{
        set_name("严妈妈", ({ "yan mama", "mam", "yan" }));
        set("gender", "女性");
        set("age", 50);      
        set("title",BLU "花肥房管事"NOR);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("jiali",30);
        set("score", 8000);

        set_skill("cuff", 70);
        set_skill("parry",70);
        set_skill("dodge", 70);
        set_skill("force",70);
        set_skill("blade",70);       
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object("clone/weapon/blade")->wield();
        set("inquiry", ([
            "name" : "我是曼佗罗山庄的花房管事。\n",
            "here" : "这里是花肥房，专门把夫人让处死的人做花肥。\n",
            "rumors" : "最近一个姓段的小子从我手里跑了。\n",
        
 ]));           
}
void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && ( (fam = ob->query("family")) && fam["family_name"] != "慕容世家" ) )
        {
                        command("say 近来花肥不太够，让老婆子我拿你做花肥吧！！！\n");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
