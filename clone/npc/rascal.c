// rascal.c

#include <ansi.h>
#include <login.h>

inherit NPC;

void create()
{
        string *my_name = ({ "恶棍", "恶霸", "流氓","地痞","小流氓"});
        string *ob_name = ({ "小男孩", "小女孩", "年轻人", "小姑娘", "姑娘", 
                             "老头子", "老太太" });

        set_name(my_name[ random( sizeof(my_name) ) ], ({ "rascal" }) );
        set("help_ob_name", ob_name[ random( sizeof(ob_name) ) ]);
        set("long", sprintf("这是一名%s，样子很凶狠。\n", name()));

        set("attitude", "heroism");
        set("age", random(20) + 20);

        set("str", 20 + random(11));
        set("cps", 20 + random(11));
        set("cor", 20 + random(11));
        set("per", 20 + random(11));
        set("int", 20 + random(11));
        set("con", 20 + random(11));
        set("spi", 20 + random(11));
        set("kar", 20 + random(11));

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                sprintf("%s喝道：今天不给点教训你，也不知道老子的厉害！\n", name()),
                sprintf("%s喝道：多管闲事，你活得不耐烦了吧！\n", name()),
                sprintf("%s喝道：呸！大爷的事也管，去死吧！\n", name()),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("neili", 500);      set("max_neili", 500);          set("jiali",60);
        set("shen_type",-1);

        set_skill("force", random(40) + 10 );
        set_skill("unarmed", random(40) + 10 );
        set_skill("parry", random(40) + 10 );
        set_skill("dodge", random(40) + 10 );
        set("combat_exp", random(4000) + 1000);
        
        setup();

        carry_object("/clone/cloth/cloth")->wear();

        add_money("gold", 1);
}

void do_move()
{
        object *ob, me, player;
        int n, i;

        ob = users();
        i = sizeof(ob);
        i--;
        if( i< 0) return;
        me = this_object();
        player = ob[ random(i) ];

        if( !environment(player) || player->is_fighting() 
        || player->query("combat_exp") < 15000 
        || wizardp(player)
        || environment(player)->query("no_fight")) {
                me->move(START_ROOM);
                return;
        }

        me->move( environment(player) );
        n = player->query("combat_exp") + random(10000) - 5000;
        if( n <= 0 ) n = random(5000) + 1;
        set("combat_exp", n );

        n = player->query_skill("force", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("force", n );
        n = player->query_skill("unarmed", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("unarmed", n );
        n = player->query_skill("parry", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("parry", n );
        n = player->query_skill("dodge", 1) + random(10) - 5;
        if( n <= 0 ) n = random(5) + 1;
        set_skill("dodge", n );

        tell_object(player, "你突然听到远处传来一阵呼救声：“救命啊，救救我啊……”\n");
        tell_object(player, sprintf("你急忙跑过去一看，原来是一个%s正在欺负一位可怜的%s。\n", 
                me->name(), me->query("help_ob_name")));
        message_vision( sprintf( "$N对%s喝道：“大胆狂徒，敢在光天化日之下欺压百姓！”\n", me->name() ), player);
        message_vision( sprintf( "%s对$N喝道：“不要命了，敢管大爷的闲事！”\n", me->name() ), player);

        me->kill_ob( player );
        player->kill_ob( me );
}

void afterdie_func(object killer)
{
        object me;
        int m, n, i;

        me = this_object();
        message("channel:chat",HIC"【飛鸽传书】据探子报「"+ me->name() +"在"+ environment(killer)->query("short")+"已被"+ killer->name() +"歼灭。」\n"NOR,users());

        message_vision( sprintf( "$N打败了%s，帮助了可怜的%s。\n", 
                me->name(), me->query("help_ob_name") ), killer);
        message_vision( "由于$N的侠义表现，$N得到了奖励。\n", killer);

        i = killer->query("combat_exp") / 10000;
        if( i > 300 ) i = 300;
        m = random(50) + i / 10 + 1;
        n = random(200) + i + 1;
        killer->add("potential", m);
        killer->add("combat_exp", n);
        tell_object(killer, sprintf("你的潜能增加了%s点！\n", chinese_number(m)));
        tell_object(killer, sprintf("你的经验增加了%s点！\n", chinese_number(n)));
}
