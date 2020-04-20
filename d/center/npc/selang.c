// selang.c - 凤天南
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit NPC;

void create()
{
        set_name("凤天南", ({ "feng tiannan", "feng" }) );
        set("long", @LONG
他就是恶霸凤天南。他是一位出了名的色狼。
LONG
);

        set("attitude", "heroism");
        set("gender", "男性" );
        set("age",32);

        set("combat_exp",50000+random(10000));
        set("shen_type",-1);
        set("env/wimpy", 30);
        set("chat_chance",5);
        set("chat_chance",5);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set_skill("unarmed",50); 
        set_skill("parry",50);
        set_skill("dodge",50);
        set_skill("force",50);
        setup();
        
        carry_object("/clone/cloth/dahong-silk")->wear();
        add_money("silver", 1);
}

void init()
{       
        object ob;
       
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object me;

        me = this_object();
        if( !ob || environment(ob) != environment() ) return;

        switch( random(4)) {
                case 0:
                        if( ob->query("gender") == "女性" && ob->query("per") >= me->query("per") ) {
                                me->set_leader(ob);
                                message_vision("$N似乎打算跟随$n一起行动。\n", me, ob);
                        }
                        break;
                case 1:
                        if( ob->query("gender") == "女性" ) {
                                say(me->query("name") + "色迷迷地叫道：亲亲的" + ob->query("name") + "妹妹好啊～～～\n" );
                        }
                        break;
                case 2:
                        if( ob->query("gender") == "女性" ) {
                                message_vision("$N一副色迷迷的样子似乎想调戏$n。\n", me, ob);
                        }
                        break;
                case 3:
                        if( ob->query("gender") == "女性") {
                                command("qiangjian "+ ob->query("id"));
                        }
                        break;
        }
}
