// updated.c

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

private void create() { seteuid(getuid()); }

void check_user(object me)
{
	object weapon,cloth,shoe,ring,horse,mailbox;
	mapping my;

	my = me->query_entire_dbase();

	if( my["marry"] ){
		ring = new("/clone/misc/marry_ring");
		ring->move(me);
		ring->wear();
	}

	if( my["weapon"] && my["weapon"]["make"]){
		switch(my["weapon"]["type"]){
			case "剑":
				weapon=new("/d/npc/m_weapon/weapon/m_sword");
				break;
			case "刀":
				weapon=new("/d/npc/m_weapon/weapon/m_blade");
				break;
			case "棍":
				weapon=new("/d/npc/m_weapon/weapon/m_club");
				break;
			case "杖":
				weapon=new("/d/npc/m_weapon/weapon/m_staff");
				break;
			case "鞭":
				weapon=new("/d/npc/m_weapon/weapon/m_whip");
				break;
			case "锤":
				weapon=new("/d/npc/m_weapon/weapon/m_hammer");
				break;
		}
		weapon->move(me);
		weapon->wield();
	}
	if(wizhood(me) == "(player)"){
		if(my["class"] == "taoist"){
			if(my["gender"] == "女性"){
				cloth=new("/clone/cloth/daogu-cloth");
				shoe=new("/clone/cloth/dao-xie");
			}
			else {
				cloth=new("/clone/cloth/dao-cloth");
				shoe = new("/clone/cloth/dao-xie");
			}
		}
		else if(my["class"] == "bonze"){
			if(my["gender"] == "女性"){
				cloth=new("/clone/cloth/ni-cloth");
				shoe=new("/clone/cloth/ni-xie");
			}
			else {
				cloth= new("/clone/cloth/seng-cloth");
				shoe=new("/clone/cloth/seng-xie");
			}
		}
		else if(my["gender"] == "女性"){
			cloth = new(sprintf("/clone/cloth/female%d-cloth",1+random(8)));
			shoe = new("/clone/cloth/female-shoe");
		}
		else {
			cloth=new(sprintf("clone/cloth/male%d-cloth",1+random(8)));
			shoe=new("clone/cloth/male-shoe");
		}
	}
	else if(my["gender"] == "女性") {
		cloth=new("/clone/cloth/chang-silk");
		shoe = new("/clone/cloth/female-shoe");
	}
	else {
		cloth=new("/clone/cloth/jinduan");
		shoe=new("clone/cloth/male-shoe");
	}

	if(my["armor"] && my["armor"]["make"]){
		destruct(cloth);
		cloth = new("/clone/misc/m_cloth");
	}

	cloth->move(me);
	cloth->wear();
	shoe->move(me);
	shoe->wear();

	if(my["make_horse"] && my["make_horse"]["finish"]){
		horse = new("/clone/misc/animal");
		horse->move(me);
	}

	mailbox = new("/clone/misc/mailbox");
	mailbox->move(me);
	destruct(mailbox);

	if(my["family"]){
		if(my["family"]["family_name"] == "慕容世家"
		|| my["family"]["family_name"] == "白驼山派"
		|| my["family"]["family_name"] == "灵鹫宫"
		|| my["family"]["family_name"] == "唐门"
		|| my["family"]["family_name"] == "大理段家" )
			me->set("title",my["family"]["family_name"]+"第"+ chinese_number(my["family"]["generation"]) +"代传人");
		else
			me->set("title",my["family"]["family_name"]+"第"+ chinese_number(my["family"]["generation"])+"代弟子");
	}

	if(!me->query("change")){
		if(me->query("my_friends")) me->delete("my_friends");
		if(me->query("jiebai_id")) me->delete("jiebai_id");
		if(me->query("jiebai")) me->delete("jiebai");
		if(me->query("baby")) me->delete("baby");
		me->set("change",1);
	}
	if(!me->query("change1")){
		if(me->query("private_room")) me->delete("private_room");
		me->set("change1",1);
	}
	if(my["socre"]){
		my["score"] += my["socre"];
		me->delete("socre");
	}
	if(!me->query("change2")){
		me->delete("quest_fail_time");
		me->delete("gfquest_fail_time");
		me->delete("letter_fail_time");
		me->delete("world_fail_time");
		me->delete("quest");
		me->set("change2",1);
	}

}
object load_player(string user)
{
	object ob;
	object login_ob;

	ob = find_player(user);
	if (!ob)
	{
		login_ob = new(LOGIN_OB);
		login_ob->set("id", user);
		ob = LOGIN_D->make_body(login_ob);
		if (! ob)
		{
			catch(destruct(login_ob));
			return 0;
		}

		evaluate(bind((: seteuid(getuid()) :), ob));

		if (! ob->restore())
		{
			catch(destruct(login_ob));
			catch(destruct(ob));
			return 0;
		}

		ob->set_temp("temp_loaded", 1);
		ob->start_call_out(bind((: call_other, __FILE__, "global_destruct_player", ob, 0 :), ob), 0);
		catch(destruct(login_ob));
	}
	return ob;
}

// 析构一个被 UPDATE_D 调入的玩家
void global_destruct_player(object ob, int raw)
{
	if (objectp(ob) && ob->query_temp("temp_loaded"))
	{
		if (raw) ob->save();
		destruct(ob);
	}
}
