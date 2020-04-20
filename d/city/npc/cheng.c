// cheng.c 程药发

#include <ansi.h>

inherit NPC;
int ask_job();
int ask_finish();
string *city=({
        "d/center",
        "d/dali",
        "d/city",
        "d/kunming",
        "d/suzhou",
        "d/hangzhou",
        "d/city2",
});
string *city_name=({
        "桃源之城",
        "大理城",
        "扬州城",
        "昆明",
        "苏州",
        "杭州",
        "北京",
});
        
void create()
{
        set_name("程药发", ({ "cheng yaofa", "cheng" }));
        set("title", "扬州知府");
        set("gender", "男性");
        set("age", 43);
        set("str", 20);
        set("dex", 20);
        set("long", "他就是程药发，扬州现任知府。\n");
        set("combat_exp", 30000);
        set("attitude", "heroism");

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 15);
        set("inquiry",([
                "任务":  (: ask_job :),
                "job": (: ask_job :),
                "finish": (: ask_finish :),
        ]));
        set("neili", 500); 
        set("max_neili", 500);
        set("jiali", 10);

        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int ask_job()
{
        object me;
        string quest_city,chinese_city_name;
        int i;
        me = this_player();
        
        if((int)me->query("combat_exp") < 100000){
                command("say 这位" + RANK_D->query_respect(me)+"经验尚浅，想替官府办事还是等以后再说吧。");
                return 1;
        }
        if((int)me->query("combat_exp") > 1000000){
                command("say 这位" + RANK_D->query_respect(me)+"已经是武林高手了，这点事情哪能牢烦您呢？");
                return 1;
        }
        if( me->query_temp("xuncheng")) {
                command("say 你的差事还没有办妥吧？");
                return 1;
        } 

        i = random(sizeof(city));
        quest_city = city[i];
        chinese_city_name = city_name[i];

        me->set_temp("xuncheng",quest_city);
        tell_object(me,CYN"程药发说道：据说最近"+ chinese_city_name +"流氓猖獗，你速去巡视["HIG"see"NOR+CYN"]一番，再回来向我禀报["HIG"ask cheng about finish"NOR+CYN"]。\n"NOR);
        return 1;
}
int ask_finish()
{
        object me,money;
        int n,p;
        me = this_player();
        n = sizeof(me->query_temp("xuncheng_path")) * 2;
        n += me->query_temp("xuncheng_kill");

        if( !me->query_temp("xuncheng")){
                command("say 我好象没叫你去巡城吧？");
                return 1;
        }
        if( me->query_temp("xuncheng") == "d/center"
        && n < 40){
                command("say 好象桃源城你都还没有巡视完整吧？");
                tell_object(me,sprintf("桃源之城共有四十处需要巡视，你现在已经巡视了%s个地方。\n",chinese_number(n)));
                return 1;
        }
        else if( me->query_temp("xuncheng") == "d/dali"
        && n < 50 ){
                command("say 好象大理城你都还没有巡视完整吧？");
                tell_object(me,sprintf("大理城共有五十处需要巡视，你现在已经巡视了%s个地方。\n",chinese_number(n)));
                return 1;
        }
        else if( me->query_temp("xuncheng") == "d/city"
        && n < 40 ){
                command("say 好象扬州城你都还没有巡视完整吧？");
                tell_object(me,sprintf("扬州城共有四十处需要巡视，你现在已经巡视了%s个地方。\n",chinese_number(n)));
                return 1;
        }
        else if( me->query_temp("xuncheng") == "d/kunming"
        && n < 20) {
                command("say 好象昆明一带你都还没有巡视完整吧？");
                tell_object(me,sprintf("昆明城共有二十处需要巡视，你现在已经巡视了%s个地方。\n",chinese_number(n)));
                return 1;
        }
        else if( me->query_temp("xuncheng") == "d/suzhou"
        && n < 30) {
                command("say 好象苏州一带你都还没有巡视完整吧？");
                tell_object(me,sprintf("苏州一带共有三十处需要巡视，你现在已经巡视了%s个地方。\n",chinese_number(n)));
                return 1;
        }
        else if( me->query_temp("xuncheng") == "d/hangzhou"
        && n < 30 ){
                command("say 好象杭州一带你都还没有巡视完整吧？");
                tell_object(me,sprintf("杭州一带共有三十处需要巡视，你现在已经巡视了%s个地方。\n",chinese_number(n)));
                return 1;
        }
        else if( me->query_temp("xuncheng") == "d/city2"
        && n < 30 ){
                command("say 好象北京一带你都还没有巡视完整吧？");
                tell_object(me,sprintf("北京共有三十处需要巡视，你现在已经巡视了%s个地方。\n",chinese_number(n)));
                return 1;
        }
        else {
                n += random(me->query("kar"));
                p = n + random(30);
                command("pat "+ me->query("id"));
                message_vision("$N对$n说道：好，做得很好！\n",this_object(),me);
                tell_object(me,sprintf("由于你成功的完成了任务，你获得了%s点实战经验和%s点潜能做为奖励！\n",chinese_number(n),chinese_number(p)));
                tell_object(me,sprintf("你的江湖阅历提高了一点，你还获得了一些银两。\n"));
                money = new("/clone/money/silver");
                money->set_amount(n/6);
                money->move(me);
                me->add("score",1);
                me->add("combat_exp",n);
                me->add("potential",p);
                me->delete_temp("xuncheng");
                me->delete_temp("xuncheng_path");
                if( me->query_temp("xuncheng_kill")){
                        tell_object(me,HIW"由于你在巡城的过程中惩恶扬善，你获得了额外的嘉奖！\n"NOR);
                        tell_object(me,"你的江湖威望提高了五十点。\n");
                        me->add("weiwang",50);
                        me->delete_temp("xuncheng_kill");
                }
                        return 1;
        }
}
