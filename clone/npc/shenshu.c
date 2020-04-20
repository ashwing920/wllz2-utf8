// shenshu.c 
// Design By Robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

inherit NPC;
int ask_me();
void create()
{
        set_name("飞天神鼠",({"feitian shenshu","shenshu"}));
        set("long",@LONG
他便是江湖上，喜爱收藏希奇古怪的东西的汪洋大盗，没有人知道他的真
实姓名，只见此人轻功了得，箭步如飞，便称他为飞天神鼠。
LONG
);
        set("attitude", "heroism");
        set("str", 20 + random(11));        
        set("per", 20 + random(11));        
        set("int", 20 + random(11));        
        set("con", 20 + random(11));        
        set("dex", 500);            
        set("kar", 40 + random(11));    
        set("inquiry",([
                "偷": (: ask_me :),
                "木人": "你怎么知道我有木人的？嘿嘿，一个一百两黄金！",
        ]));
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("silver", 20);
}

void init()
{
        add_action("do_steal","偷");
}

int accept_object(object who, object ob)
{
       
        if( ob->value() >= 1000000 ) {
                message_vision("$N点头哈腰，对$n说道：哈哈，有钱好办事！！\n",this_object(),who);
                tell_object(who,"飞天神鼠在你耳边悄悄的说：想我帮你偷点什么说吧！\n");
                tell_object(who,"请输入：偷 <物品名称>\n");
                who->set_temp("give_steal_paid",1);
                } 
        else   {
                command("say 哈，就这点钱，你赏给叫花子去吧！");
                return 0;
        }
        return 1;
}

int ask_me()
{
        object me;
        me = this_player();
        if(!me->query_temp("give_steal_paid")){
                tell_object(me,"飞天神鼠阴笑道：难道江湖上又有了什么希奇古怪的东西了吗？\n");
                tell_object(me,"你要是喜欢，我可以去帮你偷过来，只要有钱！嘿嘿！\n");
        }
                else{
                tell_object(me,"飞天神鼠疑道：你要我偷什么快说啊！要没事就别来烦大爷我啦！\n");
                tell_object(me,"请输入：偷 <物品名称>\n");
        }
        return 1;
}

int do_steal(string arg)
{
        object me,ob,obj;
        string course;
        me = this_player();
        ob = this_object();
        
        if(!me->query_temp("give_steal_paid")) return 0;
        if( !arg || sscanf(arg,"%s",course) != 1) return notify_fail("请输入：偷 <物品名称>\n");
        
        if( course == "木人" || course == "竹人" || course == "机关人" || course == "橡皮人"
        || course == "蜘蛛人"){
                message_vision("$N说道：哈，就这鬼东西？小事一桩！你在这里等我一下吧！\n",ob,me);
                message_vision("$N说完，纵身飞起，顿时消失得无影无踪！\n",ob);
                me->delete_temp("give_steal_paid");

        switch(course){
                case "木人":
                        obj = new("/d/shaolin/npc/mu-ren");
                        obj->set("startroom","/clone/misc/void");
                        obj->set("master",me->query("id"));
                        obj->move(me);
                        obj->set("name",me->name()+"的"+ obj->name());
                        obj->delete("no_get");
                        message_vision("过了一会儿，$N突然出现在你的跟前，说道：东西已经到手，给你吧！\n",ob);
                        tell_object(me,"飞天神鼠给你一个木人！\n");
                        break;
                case "竹人":
                        obj = new("/d/tangmen/npc/zhuren");
                        obj->set("startroom","/clone/misc/void");
                        obj->set("master",me->query("id"));
                        obj->move(me);
                        obj->set("name",me->name()+"的"+ obj->name());
                        obj->delete("no_get");
                        message_vision("过了一会儿，$N突然出现在你的跟前，说道：东西已经到手，给你吧！\n",ob);
                        tell_object(me,"飞天神鼠给你一个竹人！\n");
                        break;
                case "机关人":
                        obj = new("/d/taohua/npc/jiguan");
                        obj->move(me);
                        obj->set("startroom","/clone/misc/void");
                        obj->set("master",me->query("id"));
                        obj->set("name",me->name()+"的"+ obj->name());
                        obj->delete("no_get");
                        message_vision("过了一会儿，$N突然出现在你的跟前，说道：东西已经到手，给你吧！\n",ob);
                        tell_object(me,"飞天神鼠给你一个机关人！\n");
                        break;
                case "橡皮人":
                        obj = new("/d/city3/npc/xiangpi-ren");
                        obj->move(me);
                        obj->set("startroom","/clone/misc/void");
                        obj->set("master",me->query("id"));
                        obj->set("name",me->name()+"的"+ obj->name());
                        obj->delete("no_get");
                        message_vision("过了一会儿，$N突然出现在你的跟前，说道：东西已经到手，给你吧！\n",ob);
                        tell_object(me,"飞天神鼠给你一个橡皮人！\n");
                        break;
                case "蜘蛛人":
                        obj = new("/d/wudu/npc/zhizhuren");
                        obj->move(me);
                        obj->set("startroom","/clone/misc/void");
                        obj->set("master",me->query("id"));
                        obj->set("name",me->name()+"的"+ obj->name());
                        obj->delete("no_get");
                        message_vision("过了一会儿，$N突然出现在你的跟前，说道：东西已经到手，给你吧！\n",ob);
                        tell_object(me,"飞天神鼠给你一个蜘蛛人！\n");
                        break;
                default:
                        message("vision","$N环顾四周，疑道："+ me->name()+"走了？！他妈的，骗老子白跑一趟了。\n",ob,environment(ob));
                        break;
        }
                
                
                return 1;
        }
                else
                        {
                                message_vision("$N摇了摇头，说道：这东西我偷不来！你找别人吧！\n",ob);
                                return 1;
                        }
}
