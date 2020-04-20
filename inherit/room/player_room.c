// player_room.c 
// Design By Robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

inherit ROOM;

void setup()
{
        ::setup();
}
void create()
{
        set("sleep_room",1);
        set("player_house",1);
        set("restrict_action", 1);
        set("restrict_fly_room",1);
        set("restrict_enter_room",1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_spells", 1);
        set("no_steal", 1);
        set("no_beg",1);
        set("valid_startroom",1);
        setup();
}

void init()
{
        object me;
        me = this_player();

        if( !wizardp(me) 
        && userp(me)
        && me->query("id") != query("PN1")
        && me->query("id") != query("PN2")
        && me->query_temp("yaoqing") != query("PN1")) {
                tell_object(me,"嘿！不要随便闯，那是人家的地方。\n");
                me->move("/d/center/shanzhuang");
                message_vision("$N被人从屋里赶了出来，十分狼狈！！！\n",me);
        }
        add_action("do_save","save");
        add_action("do_yaoqing","yaoqing");
}

int do_yaoqing(string arg)
{
        
        if( this_player()->query("id") != query("PN1") 
        && this_player()->query("id") != query("PN2"))
                return notify_fail("你没有权利邀请他人进入这里。\n");
                
        if(!arg) return notify_fail("你要邀请谁？\n");
        
        if (this_player()->id(arg) || arg == this_player()->query("marry"))
                return notify_fail("不是吧？这也要邀请？\n");
        
        foreach (object player in users()){
        if( player->query("id") == arg && this_player()->visible(player) && environment(player)){
                write("你现在邀请"+player->name(1)+"参观你的家！\n");
                tell_object(player,BOLD+this_player()->name(1)+"邀请你到"+this_object()->query("short")+ HIG"作客。\n"NOR);
                player->set_temp("yaoqing",query("PN1"));
                return 1;
                }
        }
        return notify_fail("没有这位玩家。\n");
}
int do_save(string arg)
{
        object ob;
        ob = this_player();
        
        if(ob->query("id") != query("PN1") 
        && ob->query("id") != query("PN2")) {
                tell_object(ob,"你不能在这里存档！\n");
                return 1;
        }
        return 0;

}
