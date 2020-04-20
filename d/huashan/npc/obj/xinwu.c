
// letter.c
inherit ITEM;

void create()
{
     set_name("信物", ({"xinwu"}));
     set_weight(100);
     if( clonep() )
                set_default_object(__FILE__);
       else {
               set("unit", "件");
               set("no_give","这个不能给人。");
              set("no_sell","这不能卖。");
              set("no_drop","这不能随便扔。");      
             set("long",
"这是田伯光的信物，是当年风前辈送给令狐冲的，以作相见之用。\n");
          }
     }

