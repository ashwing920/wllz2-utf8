// chat_room.c

inherit ROOM;

void setup()
{
        ::setup();
}

void create()
{
        set("chat_room", 1);
        set("restrict_enter_room", 1);
	set("restrict_fly_room",1);
        set("restrict_action", 1);
        set("no_sleep_room",1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_spells", 1);
        set("no_steal", 1);
        set("no_beg",1);
           

        setup();
}
