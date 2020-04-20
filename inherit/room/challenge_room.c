// challenge_room.c

inherit ROOM;

void setup()
{
        ::setup();
}
void create()
{
        set("no_sleep_room",1);
        set("challenge_room",1);
        setup();
}
void reset_status()
{
        mapping obj_list;
        object *obj;
        int i;

        obj_list = query("objects");
        obj=all_inventory(this_object());

        if(!sizeof(obj)) return;

        for(i = 0; i < sizeof(obj); i++)
        {
                if(interactive(obj[i])) continue;
                if(obj[i]->is_character() && !obj[i]->is_corpse()) 
continue;
                if(obj[i]->query("capacity"))  continue;
                if(undefinedp(obj_list[base_name(obj[i])]))
                        destruct(obj[i]);
        }
        this_object()->reset();
}
