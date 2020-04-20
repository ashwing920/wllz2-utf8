                                //zhangwuji.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>
#include <globals.h>

string ask_job();
string ask_cancel();
inherit NPC;

void create()
{
        set_name("无名", ({ "wu ming","ming","wu" }));
        set("long",@LONG
他就是江湖中令人闻风丧胆的杀手盟盟主，此人心狠手辣，杀人无数。在
江湖中靠杀人舔血，收受钱财为生。他门下杀手不计其数，个个都是武艺
超群的江湖人。
LONG
);
        set("title","杀手盟盟主");
        set("gender", "男性");
        set("age",40);
        set("shen_type",-1);
        set("attitude", "friendy");

        set("per", 30);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_jing",8000);
        set("neili", 7500);
        set("max_neili", 7500);
        set("jiali",375);

        set("combat_exp",12500000);
       
        set_skill("force",500);
        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("hand",500);
        set_skill("sword",500);
        set_skill("blade", 500);

        set("inquiry",([
                "任务":  (: ask_job() :),
                "quest": (: ask_job() :),
                "取消":  (: ask_cancel :),
                "cancel": (: ask_cancel :),
        ]));
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/sword")->wield();

        add_money("gold",20);
}

string ask_job()
{
        object ob,me,obj;
        me = this_player();

        if( me->query("combat_exp") < 500000) {
                return RANK_D->query_respect(me)+"这点拳脚功夫，依我看，还是免了吧？";
        }

        if( me->query("combat_exp") >= 3000000) {
                return RANK_D->query_respect(me)+"德高望重，这点小事，还是由别人去办吧！";
        }

        if( me->query("killer_npc")) {
                command("say 吩咐你的事情，你办妥了吗？");
                return"你也可以拿"+ MONEY_D->price_str(me->query("combat_exp") / 300)+ CYN"来，我叫别人去做。"NOR;
        }

        if((time() - me->query("bad_time")) < 120){
                return "差事已经找别人做了，你稍后再来吧！";
        }

        ob = new("/clone/npc/choujia");
        switch(random(21)){
                case 0:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","扬州");
                        ob->move("/d/city/beimen");
                        break;
                case 1: 
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","成都");
                        ob->move("/d/city3/eastgate");
                        break;
                case 2: 
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","大理");
                        ob->move("/d/dali/center");
                        break;
                case 3: 
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","长安");
                        ob->move("/d/city4/westgate");
                        break;
                case 4:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","泉州");
                        ob->move("/d/quanzhou/beimen");
                        break;
                case 5:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","北京");
                        ob->move("/d/city2/xichang2");
                        break;
                case 6:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","佛山");
                        ob->move("/d/foshan/street2");
                        break;
                case 7:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","峨嵋");
                        ob->move("/d/emei/guanyintang");
                        break;
                case 8:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","扬州");
                        ob->move("/d/shaolin/hanshui1");
                        break;
                case 9:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","泰山");
                        ob->move("/d/taishan/taishanjiao");
                        break;
                case 10:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","桃源城");
                        ob->move("/d/center/roadn3");
                        break;
                case 11:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","法元寺");
                        ob->move("/d/xuedao/wangyougu");
                        break;
                case 12:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","天山");
                        ob->move("/d/xingxiu/tianroad1");
                        break;
                case 13:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","神龙岛");
                        ob->move("/d/shenlong/haitan");
                        break;
                case 14:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","扬州");
                        ob->move("/d/huanghe/shulin1");
                        break;
                case 15:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","扬州");
                        ob->move("/d/huanghe/shulin1");
                        break;
                case 16:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","昆明");
                        ob->move("/d/kunming/qingshilu");
                        break;
                case 17:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","昆明");
                        ob->move("/d/kunming/qingshilu");
                        break;
                case 18:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","昆仑山");
                        ob->move("/d/kunlun/klpsm");
                        break;
                case 19:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","少林寺");
                        ob->move("/d/shaolin/shanmen");
                        break;
                case 20:
                        ob->set("title",npc_name("男性")+"的仇家");
                        ob->set_name(npc_name("男性"),({"chou jia","chou"}));
                        me->set("killer_npc_name",ob->query("name"));
                        me->set("killer_npc",ob->query("title"));
                        ob->set("where","少林寺");
                        ob->move("/d/shaolin/shanmen");
                        break;

        }
        if( !present("sha shouling",me)) {
        obj=new("/clone/misc/ling");
        obj->move(me);
        message_vision("$N递给$n一块杀手令。\n",this_object(),me);
}

        tell_object(me,this_object()->name()+"说道：" + ob->query("title") + ob->query("name") +"已经来到"+ob->query("where") +"。受人钱财，替人消灾。\n");
        return "快去快回，手脚干净一点。";
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id")){
                if(!who->query("killer_npc")){
                        message_vision(CYN"$N说道：就这点钱？我才不稀罕呢！哼！\n"NOR,this_object());
                        return 0;
        }
        if ( ob->value() < (who->query("combat_exp") / 300 )) {
                        return 0;
        }
        
        if( who->query("killer_npc") && who->query("killer_npc_name")) {
                who->delete("killer_npc");
                who->delete("killer_npc_name");
                command("say 那好吧！我找别人去做！你走吧！");
                who->set("bad_time",time());
                return 1;
        
                }
        }
}       
