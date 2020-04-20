// look.c
// Design By Robert 蝴蝶君 email:robert_st@263.net

#include <room.h>
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

#define RETURN_RESULT           1

int look_room(object me, object env,int brief);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

string desc_of_objects(object *obs);
string look_all_inventory_of_room(object me, object env, int ret_str);

static int light;

string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string exp_level(object me,object obj);
string *tough_level_desc = ({
	CYN"不堪一击"NOR,
	CYN"毫不足虑"NOR,
	CYN"不足挂齿"NOR,
	CYN"初学乍练"NOR,
	CYN"勉勉强强"NOR,
	HIC"初窥门径"NOR,
	HIC"初出茅庐"NOR,
	HIC"略知一二"NOR,
	HIC"普普通通"NOR,
	HIC"平平淡淡"NOR,
	BLU"平淡无奇"NOR,
	BLU"粗通皮毛"NOR,
	BLU"半生不熟"NOR,
	BLU"马马虎虎"NOR,
	BLU"略有小成"NOR,
	HIB"已有小成"NOR,
	HIB"鹤立鸡群"NOR,
	HIB"驾轻就熟"NOR,
	HIB"青出于蓝"NOR,
	HIB"融会贯通"NOR,
	WHT"心领神会"NOR,
	WHT"炉火纯青"NOR,
	WHT"了然于胸"NOR,
	WHT"略有大成"NOR,
	WHT"已有大成"NOR,
	HIW"豁然贯通"NOR,
	HIW"出类拔萃"NOR,
	HIW"无可匹敌"NOR,
	HIW"技冠群雄"NOR,
	HIW"神乎其技"NOR,
	YEL"出神入化"NOR,
	YEL"非同凡响"NOR,
	YEL"傲视群雄"NOR,
	YEL"登峰造极"NOR,
	YEL"无与伦比"NOR,
	HIY"所向披靡"NOR,
	HIY"一代宗师"NOR,
	HIY"精深奥妙"NOR,
	HIY"神功盖世"NOR,
	HIY"举世无双"NOR,
	RED"惊世骇俗"NOR,
	RED"撼天动地"NOR,
	RED"震古铄今"NOR,
	RED"超凡入圣"NOR,
	RED"威镇寰宇"NOR,
	HIR"空前绝后"NOR,
	HIR"天人合一"NOR,
	HIR"深藏不露"NOR,
	HIR"深不可测"NOR,
	HIR"返璞"HIG"归真"NOR,
});
string *heavy_level_desc= ({
	"极轻",
	"很轻",
	"不重",
	"不轻",
	"很重",
	"极重"
});
string *exp_level_desc= ({
	BLU"飞"NOR,
	HIB"雪"NOR,
	GRN"连"NOR,
	HIG"天"NOR,
	CYN"射"NOR,
	HIC"白"NOR,
	RED"鹿"NOR,
	HIR"笑"NOR,
	MAG"书"NOR,
	HIM"神"NOR,
	YEL"侠"NOR,
	HIY"倚"NOR,
	WHT"碧"NOR,
	HIW"鸳"NOR,
});
private void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me),0);
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
	     {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	     } else result = look_room_item(me, arg);

	return result;
}

int look_room(object me, object env,int brief)
{
	int i;
	mapping exits;
	string str, *dirs;

	if( !env ) {
		write("你的四周灰蒙蒙地一片，什么也没有。\n");
		me->move("/d/center/guangchang.c");
		me->save();
		destruct(me);
		return 1;
	}
	if(NATURE_D->is_night() && env->query("outdoors") 
		&& (int)me->query("mud_age") > 345600
		&& !me->query_temp("light")) 
		light = 0;
	else
		light = 1;

	if(brief){
		str = sprintf(HIC"%s，"NOR,env->query("short"));
	}
	else{
		str = sprintf( HIC"%s "NOR"%s\n\n　　%s",
		env->short(),env->query("outdoors")? HIC"- "NOR + NATURE_D->outdoor_room_description( env ) : "",
		env->long());
	}
	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });

		if( sizeof(dirs)==0 )
				str += "    这里没有任何明显的出路。\n";
		else if( sizeof(dirs)==1 )
			if(brief)
				str += "这里唯一的出口是『" + HIW + dirs[0] + NOR + "』。\n";
			else
				str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
		else
			if(brief)
				str += sprintf("这里明显的出口是『" + HIW + "%s" + NOR + "』和『" + HIW + "%s" + NOR + "』。\n",
					implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
			else
				str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
					implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
	}
	if( brief < 2 ) str += look_all_inventory_of_room(me, env, RETURN_RESULT);

	if(light)
		tell_object(me,convert_color(str));
	else
		tell_object(me,HIK + clean_color(str) + NOR);

	return 1;
}
string desc_of_objects(object *obs)
{
	int i;
	object ob;

	string  str;
	string  ustr;
	mapping count;
	mapping unit;
	string  short_name;
	string  *dk;

	if (obs && sizeof(obs) > 0)
	{
		str = "";
		count   = ([]);
		unit    = ([]);
    
		foreach (ob in obs)
		{
			short_name = ob->short();
			if (undefinedp(count[short_name]))
			{
				if (ob->query_amount() > 1)
					ustr = "批";
				else
					ustr = ob->query("unit");
				count += ([ short_name : 1 ]);
				unit += ([ short_name : ustr ]);
			}
			else
				count[short_name] += 1;
		}
    
		dk = sort_array(keys(count), 1);
		for (i = 0; i < sizeof(dk); i++)
		{
			str += "  ";
			if (count[dk[i]] > 1)
				str += chinese_number(count[dk[i]]) + unit[dk[i]];
			str += dk[i] + "\n";
		}
		return str;
	}

	return "";
}

string look_all_inventory_of_room(object me, object env, int ret_str)
{
	object *inv;
	object *obs;

	string  str;

	if (! env || ! me) return "";

	str = "";

	inv = all_inventory(env);
	if (! sizeof(inv)) return str;

	obs = filter_array(inv, (: $(me) != $1 && userp($1) && $(me)->visible($1) :));
	str += desc_of_objects(obs);

	obs = filter_array(inv, (: $(me) != $1 && ! userp($1) && $1->is_character() &&
				   $(me)->visible($1) :));
	str += desc_of_objects(obs);

	obs = filter_array(inv, (: ! $1->is_character() :), me);
	str += desc_of_objects(obs);

	if (! ret_str)
		tell_object(me, str);

	return str;
}


int look_item(object me, object obj)
{
	mixed *inv;

	write( convert_color( obj->long() ) );
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object() );
		message("vision", sprintf("里面有：\n  %s\n",
			implode(inv, "\n  ") ), me);
	}
	return 1;
}
int look_living(object me, object obj)
{
	int per;
	string str, pro,callme;
	mixed *inv;
	mapping my_fam, fam;
	int equip, wearornot;

	per = obj->query_per();

	if( me!=obj && !wizardp(me))
		message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);

	str = obj->long();
	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	if (obj->query_temp("is_riding"))
		str += sprintf("%s正骑在%s上，低头看着你。\n", pro, obj->query_temp("is_riding"));

	if( (string)obj->query("race")=="人类" && intp(obj->query("age")) ){
		if(wizardp(obj))
		str += sprintf(HIW"此人谈吐不凡，仙风道骨，看起来绝非等闲之辈啊！\n"NOR,pro);
		else if((int)obj->query("age") < 10 )
		str += sprintf("%s看起来还不足十岁，只是个雪白粉嫩的小孩子。\n",pro);
		else if((int)obj->query("age") < 15 && (int)obj->query("age") > 10 && (string)obj->query("gender") == "男性")
		str += sprintf("%s看起来大概只有十多岁，是个青春少年郎。\n", pro);
		else if((int)obj->query("age") < 15 && (int)obj->query("age") > 10 && (string)obj->query("gender") == "女性")
		str += sprintf("%s看起来大概只有十多岁，是个含苞欲放的小姑娘。\n", pro);
		else if((int)obj->query("age") >= 15 && (int)obj->query("age") < 20 )
		str += sprintf("%s看起来大概只有二十来岁。\n", pro);
		else if((int)obj->query("age") >= 20 && (int)obj->query("age") < 30  && (string)obj->query("gender") == "男性")
		str += sprintf("%s看起来大约二十多岁，已是身强力壮的年轻小伙了。\n", pro);
		else if((int)obj->query("age") >= 20 && (int)obj->query("age") < 30  && (string)obj->query("gender") == "女性")
		str += sprintf("%s看起来大约二十多岁，已是亭亭玉立的黄花大闺女了。\n", pro);
		else if((int)obj->query("age") >= 30 && (int)obj->query("age") < 40 )
		str += sprintf("%s看起来已是中年了。\n", pro);
		else if((int)obj->query("age") >= 40 && (int)obj->query("age") < 50 && (string)obj->query("gender") == "男性")
		str += sprintf("%s看起来已是壮年了，一副身强力壮的样子。\n", pro);
		else if((int)obj->query("age") >= 40 && (int)obj->query("age") < 50 && (string)obj->query("gender") == "女性")
		str += sprintf("%s看起来已经四十来岁了，却仍然徐娘半老，风韵犹存。\n", pro);
		else if((int)obj->query("age") >= 50 && (int)obj->query("age") < 70 )
		str += sprintf("%s"WHT"头发花白，想必年过半百，已是不惑之年了。\n"NOR, pro);
		else if((int)obj->query("age") >= 70 )
		str += sprintf("%s"HIW"白发苍苍，满脸皱纹，一副老态龙钟的样子。\n"NOR, pro);
		if(wizardp(me) || obj == me || !userp(obj)){
		str += sprintf("%s的武功看来", pro);
		str +=gettof(me,obj);
		str +=sprintf("，");
		str +=sprintf("出手似乎");
		str +=getdam(me,obj);
		str +=sprintf("。\n");
			if(obj->query("family")){
			str +=sprintf("%s现在的武功造诣在当前武林中属于「",pro);
			str +=exp_level(me,obj);
			str +=sprintf("」字辈高手。\n");
			}
		}
	}

	if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "无性"){
		if(per >= 40 ) str += pro +HIW"现在一派神人气度，仙风道骨，举止出尘。\n"NOR;
		else if( per == 39) str += pro +HIG"现在神清气爽，骨格清奇，宛若仙人。\n"NOR;
		else if( per == 38) str += pro +HIG"现在丰神俊朗，长身玉立，宛如玉树临风。\n"NOR;
		else if( per == 37) str += pro +HIG"现在飘逸出尘，潇洒绝伦。\n"NOR;
		else if( per == 36) str += pro +HIG"现在面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
		else if( per == 35) str += pro +HIG"现在丰神如玉，目似朗星，令人过目难忘。\n"NOR;
		else if( per == 34) str += pro +HIY"现在粉面朱唇，身姿俊俏，举止风流无限。\n"NOR;
		else if( per == 33) str += pro +HIY"现在双目如星，眉梢传情，所见者无不为之心动。\n"NOR;
		else if( per == 32) str += pro +HIY"现在举动如行云游水，独蕴风情，吸引所有异性目光。\n"NOR;
		else if( per == 31) str += pro +HIY"现在双眼光华莹润，透出摄人心魄的光芒。\n"NOR;
		else if( per == 30) str += pro +HIY"生得英俊潇洒，风流倜傥。\n"NOR;
		else if( per == 29) str += pro +MAG"生得目似点漆，高大挺俊，令人心动。\n"NOR;
		else if( per == 28) str += pro +MAG"生得面若秋月，儒雅斯文，举止适度。\n"NOR;
		else if( per == 27) str += pro +MAG"生得剑眉星目，英姿勃勃，仪表不凡。\n"NOR;
		else if( per == 26) str += pro +MAG"生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。\n"NOR;
		else if( per == 25) str += pro +MAG"生得眉如双剑，眼如明星，英挺出众。\n"NOR;
		else if( per == 24) str += pro +CYN"生得虎背熊腰，壮健有力，英姿勃发。\n"NOR;
		else if( per == 23) str += pro +CYN"生得肤色白皙，红唇墨发，斯文有礼。\n"NOR;
		else if( per == 22) str += pro +CYN"生得浓眉大眼，高大挺拔，气宇轩昂。\n"NOR;
		else if( per == 21) str += pro +CYN"生得鼻直口方，线条分明，显出刚毅性格。\n"NOR;
		else if( per == 20) str += pro +CYN"生得眉目清秀，端正大方，一表人才。\n"NOR;
		else if( per == 19) str += pro +YEL"生得腰圆背厚，面阔口方，骨格不凡。\n"NOR;
		else if( per == 18) str += pro +YEL"生得相貌平平，不会给人留下什么印相。\n"NOR;
		else if( per == 17) str += pro +YEL"生得膀大腰圆，满脸横肉，恶形恶相。\n"NOR;
		else if( per == 16) str += pro +YEL"生得獐头鼠须，让人一看就不生好感。\n"NOR;
		else if( per == 15) str += pro +YEL"生得面颊深陷，瘦如枯骨，让人要发恶梦。\n"NOR;
		else if( per == 14) str += pro +RED"生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。\n"NOR;
		else if( per == 13) str += pro +RED"生得贼眉鼠眼，身高三尺，宛若猴状。\n"NOR;
		else if( per == 12) str += pro +RED"生得面如桔皮，头肿如猪，让人不想再看第二眼。\n"NOR;
		else if( per == 11) str += pro +RED"生得呲牙咧嘴，黑如锅底，奇丑无比。\n"NOR;
		else if( per <= 10) str += pro +RED"生得眉歪眼斜，瘌头癣脚，不象人样。\n"NOR;
	}
	else {
		if ((string) obj->query("gender") == "女性"){
			if ( per >= 40 ) str += pro + HIW"现在宛如玉雕冰塑，似梦似幻，已不再是凡间人物。\n"NOR;
			else if( per == 39) str += pro + HIG"现在美若天仙，不沾一丝烟尘。\n"NOR;
			else if( per == 38) str += pro + HIG"现在灿若明霞，宝润如玉，恍如神妃仙子。\n"NOR;
			else if( per == 37) str += pro + HIG"现在气质美如兰，才华馥比山，令人见之忘俗。\n"NOR;
			else if( per == 36) str += pro + HIG"现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。\n"NOR;
			else if( per == 35) str += pro + HIG"现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。\n"NOR;
			else if( per == 34) str += pro + HIY"现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。\n"NOR;
			else if( per == 33) str += pro + HIY"现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。\n"NOR;
			else if( per == 32) str += pro + HIY"现在眉目如画，肌肤胜雪，真可谓闭月羞花。\n"NOR;
			else if( per == 31) str += pro + HIY"现在娇若春花，媚如秋月，真的能沉鱼落雁。。\n"NOR;
			else if( per == 30) str += pro + HIY"生得闲静如姣花照水，行动似弱柳扶风，体态万千。\n"NOR;
			else if( per == 29) str += pro + MAG"生得娇小玲珑，宛如飞燕再世，楚楚动人。\n"NOR;
			else if( per == 28) str += pro + MAG"生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。\n"NOR;
			else if( per == 27) str += pro + MAG"生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。\n"NOR;
			else if( per == 26) str += pro + MAG"生得丰胸细腰，妖娆多姿，让人一看就心跳不已。\n";
			else if( per == 25) str += pro + MAG"生得粉嫩白至，如芍药笼烟，雾里看花。\n"NOR;
			else if( per == 24) str += pro + CYN"生得腮凝新荔，目若秋水，千娇百媚。\n"NOR;
			else if( per == 23) str += pro + CYN"生得鲜艳妍媚，肌肤莹透，引人遐思。\n"NOR;
			else if( per == 22) str += pro + CYN"生得巧笑嫣然，宛约可人。\n"NOR;
			else if( per == 21) str += pro + CYN"生得如梨花带露，清新秀丽。\n"NOR;
			else if( per == 20) str += pro + CYN"生得风姿楚楚，明丽动人。\n"NOR;
			else if( per == 19) str += pro + YEL"生得肌肤微丰，雅淡温宛，清新可人。\n"NOR;
			else if( per == 18) str += pro + YEL"生得虽不标致，倒也白净，有些动人之处。\n"NOR;
			else if( per == 17) str += pro + YEL"生得身材瘦小，肌肤无光，两眼无神。\n"NOR;
			else if( per == 16) str += pro + YEL"生得干黄枯瘦，脸色腊黄，毫无女人味。\n"NOR;
			else if( per == 15) str += pro + YEL"生得满脸疙瘩，皮色粗黑，丑陋不堪。\n"NOR;
			else if( per == 14) str += pro + RED"生得一嘴大暴牙，让人一看就没好感。\n"NOR;
			else if( per == 13) str += pro + RED"生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。\n"NOR;
			else if( per == 12) str += pro + RED"生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。\n"NOR;
			else if( per == 11) str += pro + RED"生得歪鼻斜眼，脸色灰败，直如鬼怪一般。\n"NOR;
			else str += pro + RED"生得丑如无盐，状如夜叉，女人长成这样真是人生悲剧。\n"NOR;
	}
		else {
		if (living(obj)){
		if (!obj->query_temp("owner"))
			str += pro+"是一只未被驯服的畜生，眼光里满是戒心和敌意。\n";
		else
			str += pro+"是一只被"+obj->query_temp("ownername")+"驯服的畜生，一副很温驯的样子。\n";
		}
	    }
	}
	wearornot = 0;
	inv = all_inventory(obj);
	for(equip=0; equip<sizeof(inv); equip++)
	{
		if( inv[equip]->query("equipped") ) wearornot = 1;
	}
	//check about wife and husband
	if((obj->parse_command_id_list())[0]==me->query("marry") )
	{
	      if( (string)me->query("gender")=="女性" )
	      {
		    str += sprintf("%s是你的丈夫。\n", pro);
	      }
	      else{
		    str += sprintf("%s是你的妻子。\n", pro);
	      }
	}
	if (me->query("jiebai"))
	if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
	{
	      if( obj->query("gender")=="女性" )
	      {
		    if (obj->query("mud_age") > me->query("mud_age"))
			str += sprintf("%s是你的义姐。\n", pro);
		    else
			str += sprintf("%s是你的结义妹子。\n", pro);
	      }
	      else{
		    if (obj->query("mud_age") > me->query("mud_age"))
			str += sprintf("%s是你的结义兄长。\n", pro);
		    else
			str += sprintf("%s是你的义弟。\n", pro);
	      }
	}
	if((wearornot == 0 ) && userp(obj) )
		if( !wizardp(obj) && obj->query("age") > 18 )
			str += pro+"全身清洁溜溜的，真是有伤风化！！\n"NOR;
		else
			str += pro+"全身赤裸，一丝不挂，小孩子是不可以看哟！\n";
	// If we both has family, check if we have any relations.
	if( obj!=me
	&&      mapp(fam = obj->query("family"))
	&&      mapp(my_fam = me->query("family"))
	&&      fam["family_name"] == my_fam["family_name"] ) {

		if( fam["generation"]==my_fam["generation"] ) {

			if( (string)obj->query("gender") == "男性" ||
				(string)obj->query("gender") == "无性")
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"]? "": "同门",
					my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
			else
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"]? "": "同门",
					my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( my_fam["master_id"] == obj->query("id") )
				str += pro + "是你的师父。\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "是你的同门长辈。\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "是你的师伯。\n";
			else
				str += pro + "是你的师叔。\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "是你的同门晚辈。\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "是你的弟子。\n";
			else
				str += pro + "是你的师侄。\n";
		}
	}

	if( obj->query("max_qi") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if(obj->is_corpse() && obj->query("kantou") == 1) str += sprintf("%s连头都被割走了。\n", pro);

	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n": "只见%s：\n%s\n",
				pro, implode(inv, "\n") );
	}

	message("vision", str, me);

	if( (int)obj->query_per() > (int)me->query_per()
	&& living(obj) && !obj->is_fighting() && obj->query("can_speak")){
		if(obj->query("gender") == "男性") callme = "帅哥";
		else if(obj->query("gender") == "女性") callme = "美女";
		else callme = "俊俏的太监";
		write(sprintf(RED"%s脸色一沉，转过头来瞪了你一眼，骂道：“看什么看，没见过%s啊！\n"NOR,
			obj->name(),callme));
	}
	return 1;
}

string inventory_look(object obj, int flag)
{
	string str,units;

	units =obj->query("unit");
	str = obj->short();
	if(obj->query("armor_type"))
	switch( obj->query("armor_type") ) {
		case "head":
			str = "头上戴着一" + units + str;
			break;
		case "neck":
			str = "脖子上戴着一" + units + str;
			break;
		case "shield":
			str = "身上披着一" + units +str;
			break;
		case "cloth":
		case "armor":
			str = "身穿一"+ units + str;
			break;
		case "waist":
			str = "腰间绑着一"+units+str;
			break;
		case "boots":
			str = "脚上穿着一" + units + str;
			break;
		case "wrists":
			str = "手腕上缚着一" + units + str;
			break;
		case "hands":
			str ="手上戴着一"+ units + str;
			break;
		case "finger":
			str ="手指上戴着一"+ units + str;
			break;
		default:
			str = "装备着"+str;
	}
	else if( obj->query("equipped"))
		if(obj->query("equipped") == "horse")
		str = "骑着一"+ units + str;
		else if (obj->query("skill_type")=="throwing")
		str ="身上带着"+str;
		else str ="手持一" + units + str;
	if(obj->query("equipped"))
		str = HIC "  ★" NOR + str;
	else if( !flag )
		str = "    " + str;
	else
		return 0;

	return str;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("这里只有灰蒙蒙地一片，什麽也没有。\n");

	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write( convert_color( item[arg] ) );
		else if( functionp(item[arg]) )
			write( convert_color( (string)(*item[arg])(me) ) );

		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			look_room(me, env,0);
		else {
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]),0);
		}
		return 1;
	}
	return notify_fail("你要看什么？\n");
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	int attack_points;
	if( objectp(weapon = ob->query_temp("weapon")) )
	{
		skill_type = weapon->query("skill_type");
		parry_type = "parry";
	}
	else
	{
		skill_type = "unarmed";
		parry_type = "unarmed";
	}

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	return tough_level((int)(attack_points/100));
}
string tough_level(int power)
{

	int lvl;
	int rawlvl;
	int grade = 2;
	if(power<0) power=0;
	rawlvl = (int)pow((float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl*grade);
			if( lvl >= sizeof(tough_level_desc) )
				lvl = sizeof(tough_level_desc)-1;
			return tough_level_desc[((int)lvl)];
}
string getdam(object me, object obj)
{

	int level;
	level = obj->query_temp("apply/damage") + obj->query("jiali");
	level = level / 60;
			if( level >= sizeof(heavy_level_desc) )
				level = sizeof(heavy_level_desc)-1;
			return heavy_level_desc[((int)level)];
}
string exp_level(object me,object obj)
{
	int exp;

	exp = obj->query("combat_exp") / 2000000;

		if( exp >= sizeof(exp_level_desc))
			exp = sizeof(exp_level_desc) -1;
			return exp_level_desc[((int)exp)];
}
int help (object me)
{
	write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

这个指令让你查看你所在的环境、某件物品、生物、或是方向。

HELP
);
	return 1;
}
