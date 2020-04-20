// paper.c

inherit ITEM;

void create()
{
	set_name("信纸", ({"letter paper", "paper"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",@LONG
这是张普通的信纸，上面是任盈盈写给令狐冲的信，信已写好，而且\n"
封得严严实实的。
LONG
);
	set("material", "paper");
	}
}

