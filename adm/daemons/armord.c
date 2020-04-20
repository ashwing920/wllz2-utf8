// armor_d.c 
// 防护系统

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

void hiton_armor(object me, object victim, object weapon,object armor,int damage)
{
	string msg;
	int lvl;
	mapping armor_prop;

	armor_prop = armor->query("armor_prop");

	if(!random(5)){
		damage -= armor_prop["armor"]/2;
		if(objectp(weapon)){
			msg = "只听见「嗤啦」一声，$N的"+ weapon->name(1)+"在$n的"+ armor->name(1)+"划过，";
			if(damage < 100) msg += "只是轻轻擦破了一个衣角。\n";
			else if(damage > 300) msg += "当即留下了一道刀口般大小裂痕。\n";
			else if(damage > 500) msg += "当即破开了一道深深的裂痕。\n";
			else if(damage > 700) msg += "当即绽开了一个大口。\n";
			else if(damage > 1200) msg += armor->name(1) +"「啪」的一声剧响，出现了龟裂的伤痕，险些碎做几块。\n"NOR;
			else msg += "造成一处极其严重的创伤。\n";
		}
		else {
			msg = armor->name(1)+"荡起一道尘埃，化解了$N的部分伤害。\n"NOR;
		}
		message_vision("\n"WHT + clean_color(msg) + NOR,me,victim);

	// 防具的防护程度
	if(armor->query("ownermake"))
		lvl = armor_prop["armor"];
	else
		lvl = armor_prop["armor"] * 5; 

	armor_prop["bad"] += damage / 100; // 防具的损坏程度
	armor->set("consistence",1);

	// 如果是属于自造防具，应写上物主身上的损坏标志
	if(armor->query("ownermake")) 
	victim->add("armor/bad",damage / 100);
	
	// 以下是防具与其他防具的对比
	if(armor_prop["bad"] > lvl * 3)
		if(armor->query("ownermake")
		&& (int)victim->query("armor/lv") > 0
		&& armor->query("equipped")){
			armor_prop["armor"] -= 10;
			armor->unequip();
			victim->add("armor/lv",-1);
			tell_object(victim,HIC"你的"+ clean_color(armor->name(1))+"防护能力降低了。\n"NOR);
		}
		else {
			message_vision(HIY"只听见一声猛烈的响声，"+ armor->name(1)+ HIY"碎做了数块，带着$N的血迹，轻轻的飘落在地上。\n"NOR,victim);
/*
			armor->set("name","破烂不堪的"+armor->name(1));
			armor->set("value",0);
			armor->set("long",armor->query("long") +"然而，它已经破烂不堪，无法再穿了。\n");
			armor->delete("armor_type");
			armor->move(environment(victim));
*/
			if( armor->query("ownermake")) {
				tell_object(victim,"你的"+ (string)victim->query("armor/name")+"毁灭了。\n");
				victim->delete("armor");
			}
			destruct(armor);
		}
	}
}