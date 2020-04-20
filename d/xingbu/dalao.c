#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","刑部监狱");
        set("long",@LONG 
这里是刑部的监狱，一般都是用来关押杀人略货，以及造谣生事的重
犯。监狱里光线昏暗，四壁潮湿，地面上铺满了厚厚的稻草，稻草中还残
留着几许血迹，引来苍蝇蚊子贪婪的舔食，更散发出阵阵难闻的腥臭。来
到这里，就再也无法做任何事情了，只能老老实实的呆着，等待刑期到为
止。
LONG
);
        set("valid_startroom",1);
        set("no_fight",1);
        set("no_kill",1);
        set("no_steal",1);
        set("no_magic",1);
        set("no_spells",1);
        set("no_beg",1);
        set("parsion_room",1);
        setup();
}
void init()
{
        object me = this_player();
        object *all;
        int i;
        all = all_inventory(me);
        if( !wizardp(me) && me->query("kill_flag"))
        for (i = 0; i<sizeof(all); i++) {  
                if(all[i]->query("equipped"))
                all[i]->delete("equipped");
                destruct(all[i]);
                me->set("startroom","/d/center/guangchang");
        }
        add_action("do_fairy",  "music");
        add_action("do_fairy",  "set");
        add_action("do_fairy",  "unset");
        add_action("do_fairy",  "suicide");
        add_action("do_fairy",  "quit");
        add_action("do_fairy",  "finger");
        add_action("do_fairy",  "update");
        add_action("do_fairy",  "rumor");
        add_action("do_fairy",  "rumor*");
        add_action("do_fairy",  "shout");
        add_action("do_fairy",  "who");
        add_action("do_noway",  "chat");
        add_action("do_noway",  "chat*");
        add_action("do_noway",  "music*");
        add_action("do_noway",  "music");
        add_action("do_noway",  "wllz*");
        add_action("do_noway",  "wllz");
}
int do_fairy()
{
        object me = this_player();
        if(!wizardp(me) && me->query("kill_flag")) {
                tell_object(me,"狱卒摇了摇头：老老实实的呆着吧！谁叫你被抓呢？\n");
                return 1;
        }
        return 0;
}
int do_noway()
{
        object me =this_player();
        if(!wizardp(me) && me->query("kill_flag")) {
        if(random(6) > 2) {
                tell_object(me,"囚犯狠狠的瞪了你一眼，骂道：吵什么吵？小心大爷宰了你！\n");
                return 1;
        }
        else return 0;
        }
        
}
