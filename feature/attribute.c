// attribute.c

#include <dbase.h>
#include <skill.h>

int query_str()
{
	int improve = query_skill("unarmed", 1) / 10;

	if ( query_skill("unarmed",1)
	  || query_skill("strike", 1)
	  || query_skill("finger", 1)
	  || query_skill("cuff", 1)
	  || query_skill("hand", 1)
	  || query_skill("claw", 1))
	{
		if ( query_skill("strike", 1) >= improve * 10 )
			improve = (int)query_skill("strike", 1) / 10;
		if ( query_skill("finger", 1) >= improve * 10)
			improve = (int)query_skill("finger", 1) / 10;
		if ( query_skill("cuff", 1) >= improve * 10)
			improve = (int)query_skill("cuff", 1) / 10;
		if ( query_skill("hand", 1) >= improve * 10)
			improve = (int)query_skill("hand", 1) / 10;
		if ( query_skill("claw", 1) >= improve * 10)
			improve = (int)query_skill("claw", 1) / 10;
	}

	return (int)query("str") + // (int)query("jiali")
		 query_temp("apply/strength") + improve;
}
int query_cor()//杀气
{
	int improve = query_skill("buddhism", 1) / 10;

	if( query_skill("buddhism",1)
	|| query_skill("taoism", 1)
	|| query_skill("lamaism", 1)
	|| query_skill("mahayana", 1)
	|| query_skill("poison", 1)){
		if ( query_skill("buddhism", 1) >= improve * 10 )
			improve = (int)query_skill("buddhism", 1) / 10;
		if ( query_skill("taoism", 1) >= improve * 10)
			improve = (int)query_skill("taoism", 1) / 10;
		if ( query_skill("lamaism", 1) >= improve * 10)
			improve = (int)query_skill("lamaism", 1) / 10;
		if ( query_skill("mahayana", 1) >= improve * 10)
			improve = (int)query_skill("mahayana", 1) / 10;
		if ( query_skill("poison", 1) >= improve * 10)
			improve = (int)query_skill("poison", 1) / 10;
	}

	return (int)query("cor") + improve;
}
int query_int()
{
	return (int)query("int") + query_temp("apply/intelligence") +
		(int)query_skill("literate", 1) / 10;
}

int query_con()
{
	return (int)query("con") + query_temp("apply/constitution") +
		(int)query_skill("force", 1) / 10;
}

int query_dex()
{
	return (int)query("dex") + query_temp("apply/dexerity") +
		(int)query_skill("dodge", 1) / 10;
}

int query_kar()
{
	return (int)query("kar")+ query_temp("apply/spirituality") + 
		(int)query_skill("spells",1) /10;
}

int query_per()
{
	return (int)query("per")+query_temp("apply/personality");
}

int query_spi()
{
	return (int)query("spi")
		+ ( query_temp("apply/spirituality") >= 15 ? 15: query_temp("apply/spirituality"));
}
