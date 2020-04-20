// man.c

#include <ansi.h>

inherit NPC;
void checking();

string *family_name = ({
        "古墓新派",
        "云龙门",
        "逍遥派",
        "武当派",
        "华山剑派",
        "灵鹫宫",
        "少林派",
        "雪山派",
        "丐帮",
        "血刀门",
        "星宿派",
        "五毒神教",
        "昆仑派",
        "唐门",
        "神龙教",
        "明教",
        "峨嵋剑派",
});

void create()
{
        string family;
        int n;
        n = random(sizeof(family_name));
        family = family_name[n];
        set("family/family_name",family);
        set_name(npc_name("男性"),({ "zhong fan","fan"}));
        set("attitude", "heroism");
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

        set("shen_type",-1);
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
        call_out("back",300,this_object());

}
void init()
{       
        object ob;
        
        if( interactive(ob = this_player()) 
        && !this_object()->query_temp("unconcious")
        && ob->query("guanfu/npc_title") == this_object()->query("title")
        && ob->query("guanfu/npc_name") == this_object()->query("name")
        && ob->query("guanfu/quest_time") > time()) {
        checking();
        }
        add_action("do_fight","hit");
        add_action("do_fight","touxi");
        add_action("do_fight","halt");
}
int do_fight(string arg)
{
        object ob,me;
        ob = this_object();
        me = this_player();
        
        if(id(arg)
        && me->query("guanfu/npc_title") == ob->query("title")
        && me->query("guanfu/npc_name") == ob->query("name")) {
                checking();
                return 1;
        }
        return 0;
}
void checking()
{
        object me, player;
        int n;
        me = this_object();
        player = this_player();
        
        command("say 该死的，又来了一个朝廷的！纳命来！");
        command("follow "+ player->query("id"));
        me->kill_ob(player);
        player->kill_ob(me);
        n =(int)player->query("combat_exp");
        this_object()->set("combat_exp",n);
        NPC_D->full_init(this_object());
        if((int)player->query_temp("powerup") 
        && !(int)this_object()->query_temp("powerup")){
                add_temp("apply/attack",query_skill("force")/4);
                add_temp("apply/armor",query_skill("force")/4);
                set_temp("powerup",1);
        }
}
void afterdie_func(object killer)
{
        object me;
        mapping guanfu;
        int m, n, s;

        me=this_object();

        if(!(guanfu = killer->query("guanfu"))) return;       
        if(guanfu["npc_name"] != me->name() 
        || guanfu["npc_title"] != me->query("title")) return;
        
        message_vision("$N打败了$n，完成了任务。\n",killer,this_object());
        
        if(guanfu["quest_time"] > time()) {
        n = (int)me->query("combat_exp") / 100;
        n = n / 100;
        if( n > 800 ) n = 800;
        m = n / 2 + random(n/100);

        killer->add("potential", m);
        killer->add("combat_exp",n);
        killer->add("score",1);
        killer->add("balance",n);
        tell_object(killer, sprintf("你的潜能增加了%s点，你的经验增加了%s点！\n", chinese_number(m),chinese_number(n)));
        tell_object(killer, sprintf("你的江湖阅历增加了%s点！你得到了"+ MONEY_D->price_str(n * 10) +"的存款为报酬。\n", chinese_number(1)));
        SCORE_D->set_score(killer);
        s = guanfu["quest_time"] - time();
        if( s > 100 )
        tell_object(killer,sprintf(HIY"\n由于你提早的完成了任务，为民除害，你的江湖威望提高了%s点！\n\n"NOR,chinese_number(s/12)));
        killer->add("weiwang",s / 12);
        }
        else {
        tell_object(me,"可惜时间已经太迟了。\n");
        }
        killer->delete("guanfu");
        killer->delete("kill_bad_time");
}

int accept_fight(object ob)
{
        object me;
        me=this_object();

        if( me->is_fighting()&&!( me->is_fighting(ob))) 
                return notify_fail(me->name()+"冷笑说道：“想倚多为胜吗！”\n");

        if( (int)ob->query("combat_exp") < 100000 ){
                command("heihei");
                command("say 凭你这一点功夫，还不配与我动手！\n");
                return 0;
        }

        me->set("combat_exp",ob->query("combat_exp"));
        NPC_D->full_init(me);
        if( !me->is_killing( ob->query("id") )) me->kill_ob(ob);
        return 1;
}
void back()
{
        object ob;
        ob = this_object();
        if( environment() && !is_fighting()){
                message_vision("$N恨恨的骂道：他奶奶的！下次别让我再看见你。见你一次杀一次！哼！\n",ob);
                message_vision("话音刚落，$N消失得无影无踪了，你不得不佩服$N的轻功绝顶厉害。\n",ob);
                destruct(ob);
        }
        else {
        remove_call_out("back");
        call_out("back",100,ob);
        }
}
