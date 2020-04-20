// xingbu_gate.c 

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "刑部衙门大门");
	set("long", @LONG
一座森严的建筑物，门口有一对石狮子。大门两边各有一个牌子，分
别写着“肃静”，“回避”。门的正上方还有一个牌子，写着“公正廉明
”。门的左侧有一个镜子（mirror),那是包黑子从地府阎王那里取来的，
名曰“照妖镜”。
LONG
);
	set("item_desc", ([
		"mirror": (: look_sign :),
	]) );

	set("exits", ([ /* sizeof() == 1 */
		"west" : "/d/city3/tiduroad",
		"east" : __DIR__"yard",
	]));
	set("outdoors", "beijing");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/xingbu_yacha" : 2,
	]));
	setup();
}

void init()
{
	object ob;

	if( interactive(ob = this_player())){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}
void greeting(object ob)
{
	int pks,sen;
	string outstring;

	if(!ob || environment(ob) != this_object()) return;
    
	pks=ob->query("PKS");
	sen=ob->query("shen");
	if(sen<-100000) outstring="照妖镜里出现了一个魔鬼。\n";
	if(sen>=-100000 && sen<0) outstring="照妖镜里出现了一个凶神恶杀的人。\n";
	if(sen>=0 && sen<100000) outstring="照妖镜里出现了一个和蔼可亲的人。\n";
	if(sen>=100000) outstring="照妖镜里出现了一个天使。\n";
	if(pks>50) outstring="照妖镜出现一个长着两只角的怪物。\n";
	if(pks>10 && pks<=50) outstring="照妖镜出现一个长着一只角的怪物。\n";
	if( !ob  || environment(ob) != this_object()  ) return ;
	tell_object(environment(ob),outstring);
    
}

string look_sign(object me)
{
	int pks,sen;
	pks=me->query("PKS");
	sen=me->query("shen");
	if(pks >50 ) 
	return "你看见一个长着两只角的怪物张牙舞爪的对着你怪叫。\n";
	if(pks >10 ) 
	return "你看见一个长着一只角的怪物对着你微笑。\n";
	if (sen<-100000) 
	return "你看见一个魔鬼对着你微笑。\n";
	if(sen<0)
	return "你看到自己的脸上泛着一层黑气。\n";
	if(sen>100000)
	return "你看见一个头顶着光环的天使对着你微笑。\n"; 
     
	return "你看到自己的脸上泛着一层红光。\n";
}
