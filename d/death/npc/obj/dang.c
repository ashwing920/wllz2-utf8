// waterskin.c

#include <login.h>
#include <command.h>

inherit ITEM;
inherit F_LIQUID;

string *revive_loc= ({
        "/d/center/guandimiao",
        "/d/city/wumiao",
});

void create()
{
        set_name("大海碗", ({ "aiwan", "wan" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个青瓷大海碗\n");
                set("unit", "个");
                set("value",0);
                set("max_liquid", 15);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "alcohol",
                "name": "孟婆汤",
                "remaining": 5,
                "drunk_apply": 6,
        ]) );
}
void init()
{
        add_action("do_drink","drink");
}
int do_drink(string arg)
{
        int i;
        object *inv;

        if(!id(arg)) return 0;
        if(this_player()->is_ghost()){
                message_vision("$N拿起大海碗咕噜噜地喝了几口孟婆汤。\n",this_player());
                this_player()->reincarnate();
                inv =  all_inventory(this_player());
                for (i = 0; i < sizeof(inv); i++)
                        DROP_CMD->do_drop(this_player(), inv[i]);
                this_player()->unconcious();
                this_player()->move(revive_loc[random(sizeof(revive_loc))]);
                this_player()->set("startroom", base_name(environment(this_player())));
                message("vision","你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
                "很久了，只是你一直没发觉。\n", environment(this_player()), this_player());
                return 1;
        }
        return 0;
}
