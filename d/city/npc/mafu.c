// mafu.c 马夫

inherit NPC;
#include <ansi.h>
int do_ride();

void create()
{
        set_name("马夫", ({ "ma fu","ma","fu"}));
        set("age", 32);
        set("gender", "男性");
        set("long","驯马和租马的小贩，给他租金就可以雇到马。\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("force", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/armor", 30);
        set("chat_chance",2);
        setup();
}

void init()
{
        object ob;

        
        if( interactive(ob = this_player()) && !is_fighting() ) {
                   remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_ridebj", "ridebj");
        add_action("do_ridesz", "ridesz");
        add_action("do_ridehz", "ridehz");
        add_action("do_ridefz", "ridefz");
        add_action("do_ridedl", "ridedl");
        add_action("do_rideyd", "rideyd");
        add_action("do_rideyl", "rideyl");
        add_action("do_ridefs", "ridefs");
        add_action("do_rideem", "rideem");
        add_action("do_ridexy", "ridexy");
        add_action("do_ridety", "ridety");
        add_action("do_ridecd", "ridecd");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "马夫点头哈腰地说道：这位客官，是想到这里挑一匹好马吧？\n");
}

int accept_object(object who, object ob)
{
        if ( who->query_temp("is_riding")) {
                message_vision("马夫邹起眉头，说到：这位客倌您不正骑着马吗？\n",who);
                return 0;
        }               
        if (ob->query("money_id") && ob->value() >= 100){
        message_vision("马夫对$N说：好！这位"+RANK_D->query_respect(who) +
                "现在就出发马? 那就上马吧。\n", who);
                this_player()->set_temp("marks/horserent",1);
                        return 1;
        }
        else  
                message_vision("马夫皱眉对$N说：您给的也太少了吧？\n", who);
        return 1;
}

// ride in yangzhou

int do_rideyl()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+"这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/xidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/xidajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/ximen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/ximenroad");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/road1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/hanguguan");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/road2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/zhongnan");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/road3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/road4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/eastgate");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/center");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/westgate");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/xxroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/xxroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/xxroad3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/jiayuguan");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/silk1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/silk2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/silk3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/silk4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/shanjiao");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/beijiang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xingxiu/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达天山脚下的伊犁镇。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄。\n",ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_rideyd()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beimen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/caodi1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/caodi2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/shulin1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/shulin3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/tiandi1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/tiandi3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/tiandi4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/huanghe1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/weifen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/huanghe_1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/hetao");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/huangtu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/huanghe_2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/huanghe_3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/yongdeng");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/huanghe/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达永登。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄！\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_ridexy()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/xidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/xidajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/ximen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/ximenroad");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/road1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city4/hanguguan");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xiangyang/caodi3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xiangyang/northgate2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xiangyang/northgate1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xiangyang/northjie");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xiangyang/dingzi");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xiangyang/northroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/xiangyang/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达襄阳城。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄。\n",ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_ridets()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/city/xidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/city/xidajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/city/ximen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/city/ximenroad");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/xxroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/xxroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/xxroad3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/jiayuguan");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/silk1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/silk2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/silk3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/silk4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/shanjiao");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/beijiang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n");
        ob->move("/d/xingxiu/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达天山脚下的北疆小镇。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄。\n",ob);
        tell_room(environment(ob),hname+"一路疾驰到达天山脚下。\n");
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_ridesz()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/dongdajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/dongdajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/dongmen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/taishan/yidao");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/taishan/yidao1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/suzhou/dongmen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/suzhou/dongdajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/suzhou/dongdajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/suzhou/canlangting");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/suzhou/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/suzhou/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达苏州。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄！\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_ridebj()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beimen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/yidao1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/yidao2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/hanshui1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"跃入汉水中奋力游向对岸。\n", ({ob}));
        ob->move("/d/shaolin/hanshui2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/nanyang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/yidao3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/ruzhou");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/road10");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/road9");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/road8");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/road4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/road7");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/road6");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/road5");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/yongding");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/nandaj2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/nandaj1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city2/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达北京。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄！\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_ridefz()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/dongdajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/dongdajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/dongmen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/taishan/yidao");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/taishan/yidao1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/erbapu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/yanping");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad8");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad9");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad11");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/ximen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/ximendajie");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/xidajie");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/dongjiekou");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/dongdajie");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/rongcheng");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/fuzhou/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达福州。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄！\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_ridefs()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nandajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nandajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nanmen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/henshan/hsroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/henshan/hsroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/henshan/hsroad3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/henshan/hengyang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/henshan/hengyang1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/henshan/hsroad4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/henshan/hsroad5");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/henshan/hsroad9");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/foshan/nanling");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/foshan/northgate");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/foshan/street3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/foshan/street4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/foshan/yingxionglou");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/foshan/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达佛山。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄！\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_rideem()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nandajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nandajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nanmen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad5");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad6");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad7");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad8");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/sanbuguan");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/wdroad");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/xiaolu1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/xiaolu2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/qsjie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/qsjie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/caopeng");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/majiu1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达峨嵋山脚。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄。\n",ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_ridedl()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nandajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nandajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nanmen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad5");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad6");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad7");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad8");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/sanbuguan");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/wdroad");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/xiaolu1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/xiaolu2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/qsjie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/qsjie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/qsjie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/road1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/road2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/road3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/dehuabei");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/taihecheng");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/dalinorth");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/northgate");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/paifang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/taihejiekou");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/center");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/shizilukou");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/dahejiewest");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/bingying");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/dali/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达大理城。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄。\n",ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

int do_ridehz()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/dongdajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/dongdajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/dongmen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/taishan/yidao");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/taishan/yidao1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/jiaxing");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/quanzhou/jxnanmen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/hongchunqiao");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road5");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road6");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road7");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road8");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road9");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road10");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road11");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road12");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/road13");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/hangzhou/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达杭州。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄！\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
int do_ridety()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beimen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/yidao");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/yidao1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/yidao2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/hanshui1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/roadw4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/roadw3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/roadw2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/roadw1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/roadw");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/shaolin/road");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/gatee");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/roade4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/roade3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/roade2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/roade1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/roadn1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/roadn2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/roadn3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/roadn4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/center/chemadian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达桃源城。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄！\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
int do_ridecd()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+"这个"+RANK_D->query_rude(ob)+"想偷马！");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision("马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵起哄：喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N骑两腿一夹，"+hname+"穿街而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nandajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nandajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city/nanmen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad5");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad6");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad7");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/wdroad8");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/wudang/sanbuguan");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/wdroad");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/xiaolu1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/xiaolu2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/emei/qsjie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city3/road1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city3/road2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city3/fuheqiaoe");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city3/eastgate");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city3/eastroad2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city3/shuduroad1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city3/guangchang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city3/tiduroad");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
        ob->move("/d/city3/masi");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达成都的马厩。\n");
        message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄。\n",ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
