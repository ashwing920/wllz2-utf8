inherit ITEM;

void create()
{
	set_name( "向问天书信", ({ "xiang shuxin", "shuxin" })
		 );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long","这是一封向问天写的书信。\n");
	      }
	setup();
      }
