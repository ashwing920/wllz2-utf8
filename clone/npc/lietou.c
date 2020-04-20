//zhangwuji.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit NPC;

string *family_name = ({
        "白驼山派",
        "大理段家",
        "峨嵋派",
        "丐帮",
        "古墓新派",
        "华山剑派",
        "云龙门",
        "昆仑派",
        "灵鹫宫",
        "明教",
        "慕容世家",
        "全真教",
        "日月神教",
        "少林派",
        "神龙教",
        "唐门",
        "桃花岛",
        "天龙寺",
        "武当派",
        "五毒神教",
        "逍遥派",
        "血刀门",
        "星宿派",
        "雪山寺",
});
string *master_name = ({
        "欧阳锋",
        "段正淳",
        "灭绝师太",
        "洪七公",
        "杨过",
        "岳不群",
        "陈近南",
        "何足道",
        "天山童老",
        "张无忌",
        "慕容复",
        "王重阳",
        "任我行",
        "达摩祖师",
        "洪安通",
        "唐老太",
        "黄药师",
        "枯荣大师",
        "张三丰",
        "何铁手",
        "逍遥子",
        "血刀老祖",
        "丁春秋",
        "鸠摩智",
});
string *master_id = ({
        "oyang feng",
        "duan zhengchun",
        "miejue shitai",
        "hong qigong",
        "yang guo",
        "yue buqun",
        "chen jinnan",
        "he zudao",
        "tianshan tonglao",
        "zhang wuji",
        "murong fu",
        "wang chongyang",
        "ren woxing",
        "da mo",
        "hong antong",
        "tang laotai",
        "huang yaoshi",
        "kurong dashi",
        "zhang sanfeng",
        "he tieshou",
        "xiaoyao zi",
        "xuedao laozu",
        "ding chunqiu",
        "jiu mozhi",
});
string *title = ({
        "罚恶使者",
        "赏善使者",
        "大师兄",
        "代掌门",
});
string *shizhe_id = ({
        "fae shizhe",
        "shanshan shizhe",
        "da shixiong",
        "dai zhangmen",
});
string ask_job();
string ask_pk();
string ask_cancel();

void create()
{
        set_name("黄泉", ({ "huang quan","huang","quan" }));
        set("title",HIY"赏金"HIR"猎头"NOR);
        set("long",@LONG
他是江湖中的杀手盟盟主，人称赏金猎头，此人身手不凡，手下培养的杀
手个个都是杀人不眨眼的杀人狂魔。据说只要有钱，就可以向猎头聘请杀
手。
LONG
);
        set("nickname",HIR"杀人不眨眼"NOR);
        set("family/family_name","血刀门");
        set("gender", "男性");
        set("age",40);
        set("shen_type",-1);
        set("attitude", "friendy");

        set("per", 30);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("jing",12000);
        set("max_jing",12000);
        set("neili",60000);
        set("max_neili",60000);
        set("jiali",1200);

        set("combat_exp",80000000);
        set("inquiry",([
                "杀人": (: ask_pk :),
        ]));
        setup();
        NPC_D->full_init(this_object());
        add_money("gold",1);
}
void init()
{
        add_action("do_name","杀");
//        add_action("do_quest","quest");
}
string ask_pk()
{
        object me;
        me = this_player();

        if( me->query("weiwang") < 3000)  {
                return "你凭什么要我帮你杀人？";
        }
        if( me->query_temp("ask_killer")){
                return "请先输入你的暗杀对象id。指令格式为：[杀 目标id]";
        }
        me->set_temp("ask_killer",1);
        command("say 要我杀人可以，你只要你能付得起这个钱！？嘿嘿！");
        return "请先输入你的暗杀对象id。指令格式为：[杀 目标id]";
}

int do_name(string target)
{
        object me, dest, *all,ob;
        int dest_exp;

        ob=this_player();
        me = this_object();
        all = livings();

        if( ob->query_temp("buy_killer"))
                return notify_fail(me->name()+"说道：还杀，快给钱吧！\n");
        if(base_name(environment())!=query("startroom") && !wizardp(ob))
                return notify_fail(me->name()+"四下望了望，说道：这种事在这里说不太妥当吧！\n");
        if( !target || target==" ")
                return notify_fail(me->name()+"恶狠狠地说道：快告诉我那家伙的名字，我可没功夫听你闲聊！\n");
        foreach (dest in livings()) {
                if( target == dest->name(1) || dest->id(target) )
                break;
        }
        if( !dest || !environment(dest))
                return notify_fail(me->name()+"一声冷笑：他现在不在游戏中，过会再来吧。\n");
        if(!(target == dest->name(1) || dest->id(target)) )
                return notify_fail(me->name()+"一声冷笑：他现在不在游戏中，过会再来吧。\n");
        if( dest->query("mud_age") < 345600)
                return notify_fail(me->name()+"冷笑道：叫大爷我去杀小孩？你他妈的不想活了是吧？\n");
        if (dest->is_ghost())
                return notify_fail(me->name()+"很不高兴：他已经是个死鬼了，你还来找我干什么！\n");
        if (dest==me){
                command("say 你是来找岔的吧？");
                me->kill_ob(ob);
                return 1;
        }
        if (dest==ob){
                command("say 既然你活腻了，大爷就送你一程！");
                me->kill_ob(ob);
                ob->kill_ob(me);
                return 1;
        }

        dest_exp = (dest->query("combat_exp") + dest->query("weiwang") + dest->query("score"));
        if( dest_exp < 10000000) dest_exp = 10000000;
        if( dest_exp > 2100000000 ) dest_exp = 2100000000;


        tell_object(ob,me->name(1)+"想了想，"+ dest->name() +"的头大概值"+ MONEY_D->price_str(dest_exp * 10)+"，你买得起吗？\n");
        ob->set_temp("buy_killer/exp",dest_exp);
        ob->set_temp("buy_killer/name",dest);
        ob->set_temp("buy_killer/id",dest->query("id"));
        ob->set_temp("buy_killer/time",time());
        return 1;
}
int accept_object(object who, object ob)
{
        string family;
        int n;
        object me,obj,dest,ob1;
        mapping killer;
        n = random(sizeof(family_name));
        family = family_name[n];
        me = this_object();
        killer = who->query_temp("buy_killer");


        if( ob->query("money_id") 
        && who->query("killer_quest")
        && !who->query_temp("ask_killer")){
                if( ob->value() >= 10000) {
                        if( ob1 = who->query("killer_quest/ob")){
                                destruct(ob1);
                        }
                                tell_object(who,me->name()+"说道：好吧！我找其他人去做，你去休息一下再来吧！\n");
                                who->delete("killer_quest");
                                who->set("killer_quest_fail_time",time()+60);
                                return 1;
                        }
                        else {
                        tell_object(who, me->name()+"沉下脸来：就这点钱？恐怕还不够我们兄弟开销呀！\n");
                        return 0;
                }
        }

        if(ob->query("money_id")) {
                if( who->query("age") < 18 ) {
                        tell_object(who, me->name()+"沉下脸来：小孩子的生意我不做，快回家找你爹妈吧。\n");
                        return 1;
                }
                if(!killer) {
                        tell_object(who,me->name()+"疑道：你还没说你要杀谁呢！\n");
                        return 1;
                }
                if( ob->value() < killer["exp"] * 10){
                        command("say 就这点钱？您还是自己去吧！");
                        command("heng");
                        return 1;
                }
                dest = killer["name"];
                if(dest && environment(dest)) {
                        tell_object(who, me->name()+"嘿嘿一笑，说道：受人钱财替人消灾，你等我的好消息吧。\n");
                        obj=new("clone/npc/killer");
                        obj->set("combat_exp",killer["exp"] * 2);
                        obj->set("victim",killer["id"]);
                        obj->set("family/family_name",family);
                        NPC_D->full_init(obj);
                        obj->add_temp("apply/damage",1000);
                        obj->add_temp("apply/armor",1000);
                        obj->add_temp("apply/parry",1000);
                        obj->add_temp("apply/dodge",1000);
                        obj->move(environment(dest));
                        who->delete_temp("ask_killer");
                        who->delete_temp("buy_killer");
                        who->add("weiwang",-500);
                        who->add("PKS",1);
                        CHANNEL_D->do_channel(me,"rumor","听说赏金猎人又派出了一个杀手，江湖又多一血案了。");
                        log_file("buykiller",sprintf("%s花了%s在"+ ctime(time())+"雇佣"+me->name()+"杀%s\n",
                        who->query("name"),MONEY_D->price_str(killer["exp"]* 10),dest->query("name")));
                        return 1;
                }
                else {
                        command("say 人已经走了，这事还是以后再说吧。");
                        who->delete_temp("ask_killer");
                        who->delete_temp("buy_killer");
                        return 1;
                }
        }

        else {
                command("say 你给我这个干什么？");
                return 0;
        }
}
/*
int do_quest(string arg)
{
        object ob,me,obj,*player,link_ob,ling;
        string file_path,outdoors,where,family,npc_name,npc_id,npc_title,npc_id2;
        int n,i;
        n = random(sizeof(family_name));
        family = family_name[n];
        npc_name = master_name[n];
        npc_id = master_id[n];
        n = random(sizeof(title));
        npc_title = title[n];
        npc_id2 = shizhe_id[n];

        me = this_player();
        ob = this_object();
        
        if(me->query("combat_exp") <= 15000000) {
                tell_object(me,ob->name()+"说道：这位" + RANK_D->query_respect(me)+"道行未足，恐怕难以担此大任呀！\n");
                return 1;
        }
        if(me->query("killer_quest")){
                tell_object(me,ob->name()+"说道：我给你的任务完成了吗？！\n");
                return 1;
        }

        if(me->query("killer_quest_fail_time") > time()){
                tell_object(me,ob->name()+"说道：事情我已吩咐其他人去做了，你稍后再来吧！\n");
                return 1;
        }
        switch(random(3)){
                case 0: 
                        obj = new("clone/npc/master_npc");
                        obj->set("title",family+"第"+ chinese_number(random(30) + 1)+"代掌门人");
                        obj->set_name(npc_name,({ npc_id,"master"}));
                        obj->set("combat_exp",me->query("combat_exp") + me->query("combat_exp") /2);
                        obj->set("family/family_name",family);
                        break;
                case 1:
                        obj = new("clone/npc/master_npc");
                        obj->set("title",family+"第"+ chinese_number(random(30) + 1)+"代"+ npc_title);
                        obj->set_name(npc_name("男性"),({npc_id2}));
                        obj->set("combat_exp",me->query("combat_exp") + me->query("combat_exp") /2);
                        obj->set("family/family_name",family);
                        break;
                default:
                        player=users();
                        i=sizeof(player);
                        for( i=0;i<sizeof(player);i++) {
                                if(!environment(player[i]) )continue;
                                if(!objectp(link_ob = player[i]->query_temp("link_ob")) ) continue;
                                if(wizardp(player[i]) || player[i] == me ) continue;
                                if((int)link_ob && (int)player[i]
                                && player[i]->query("combat_exp") > 1000000
                                && player[i]->query("family/family_name")) {
                                obj = new("/clone/npc/master_npc");
                                obj->set("combat_exp",player[i]->query("combat_exp"));
                                obj->set("family/family_name",player[i]->query("family/family_name"));
                                obj->set("title",player[i]->query("title"));
                                obj->set_name(player[i]->query("name"),({"victim "+ player[i]->query("id"),"victim"}));
                                break;
                        }
                        else {
                        obj = new("clone/npc/master_npc");
                        obj->set("title",family+"第"+ chinese_number(random(30) + 1)+"代"+ npc_title);
                        obj->set_name(npc_name("男性"),({npc_id2}));
                        obj->set("combat_exp",me->query("combat_exp") + me->query("combat_exp") /2);
                        obj->set("family/family_name",family);
                        break;
                        }
                }
}
                        NPC_D->full_init(obj);
                        obj->make_skill();
                        obj->set("my_killer",me);
                        file_path = PLACE_D->get_path();
                        obj->move(file_path);
                        outdoors = PLACE_D->query_city(environment(obj));
                        where=outdoors +"的"+ environment(obj)->query("short");
                        if( !present("mi ling",me)) {
                                ling=new("/clone/misc/killer_ling");
                                ling->move(me);
                                message_vision("$N给$n一块杀手令牌！\n",this_object(),me);
                        }
                        
                        tell_object(me,this_object()->name()+"在你耳边悄声说道："+ me->name()+"听令：\n速到"+ where +"将「"+ obj->short(1)+"」杀死，将其首级与我送来。\n");
                        me->set("killer_quest/name",obj->name());
                        me->set("killer_quest/time",time() + 300);
                        me->set("killer_quest/type","取首级");
                        me->set("killer_quest/where",where);
                        me->set("killer_quest/title",obj->query("title"));
                        me->set("killer_quest/ob",obj);
                        command("say 要是完不成任务，就不要回来见我。");
                return 1;
}
*/