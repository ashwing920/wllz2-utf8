                             // man.c

#include <ansi.h>

inherit NPC;

void create()
{
        int iType;

        iType = random(11);

        if(( iType == 1 ) || ( iType == 2 ))
                set_name("无头鬼",({ "wutou gui","gui" }));
        else if(( iType == 3 ) || ( iType == 4 ))
                set_name("吊死鬼",({ "diaosi gui","gui"}));
        else if(( iType == 5 ) || ( iType == 6 ))
                set_name("饿死鬼",({ "esi gui","gui"}));
        else if(( iType == 7 ) || ( iType == 8 ))
                set_name("晦气鬼",({ "huiqi gui","gui"}));
        else if(( iType == 8 ) || ( iType == 9 ))
                set_name("冤死鬼",({ "yuansi gui","gui"}));
        else 
                set_name("厉鬼",({"li gui","ghost","gui"}));                

        set("age", random(20) + 20);
        set("str", 20 + random(11));
        set("per", 20 + random(11));
        set("int", 20 + random(11));
        set("con", 20 + random(11));
        set("dex", 20 + random(11));
        
        set("chat_chance",5);
        set("chat_msg", ({
                (: random_move :),
                (: command,"snicker" :),
                (: command,"cry" :),
                (: command,"say 我死得好冤哪～～～" :),
                (: command,"say 我死得好惨哪～～～" :),
                this_object()->name()+"发出一阵哀号：呜～～呜～～～～\n",
        }) );
        set("qi",6000);
        set("max_qi",6000);
        set("neili",6000);      
        set("max_neili",6000);  
        set("max_jing",6000);
        set("jing",6000);
        set("env/wimpy",10);

        set_skill("unarmed",250);
        set_skill("force",250);
        set_skill("dodge",250);
        set_skill("claw",250);
        set_skill("taxue-steps",250);
        set_skill("hunyuan-yiqi",250);
        set_skill("jiuyin-baiguzhao",250);
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("force","hunyuan-yiqi");
        map_skill("parry","wuhu-duanmendao");
        map_skill("dodge","taxue-steps");
        map_skill("unarmed","jiuyin-baiguzhao");

        set("combat_exp", 1000000);
        set_temp("apply/armor",250);
        set_temp("apply/dodge",250);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/center/npc/obj/ghost_money");
}

void die()
{
        message_vision("\n$N发出一阵痛苦的哀怨，消失在黑暗之中。\n\n",this_object());
        destruct(this_object());
}

int is_ghost() { return 1; }
