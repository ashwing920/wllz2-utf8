// questd.c
// Design By 蝴蝶君(Robert) email:robert@cnmuds.com

//#pragma optimize
//#pragma save_binary

#define QUEST_OB		"/quest/questob"

#include <ansi.h>

inherit F_DBASE;

int random_quest(object me,object ob);
mapping create_quest();
void do_bonus(object ob,object me);
int accept_ob(object me,object ob,object obj);

string *name = ({
	"巴天石","刀白凤","段正淳","范骅","傅思归","高升泰","古笃诚","华赫艮","朱丹臣",
	"褚万里","贝锦仪","丁敏君","方碧琳","静慧师太","纪晓芙","静迦师太","静空师太",
	"李明霞","赵灵珠","灭绝师太","苏梦清","静闲师太","静虚师太","静玄师太","静照师太",
	"静真师太","周芷若","何不净","洪七公","简长老","江上游","快活三","李斧头","黎生",
	"梁长老","鲁有脚","马俱为","莫不收","彭有敬","裘万家","全冠清","余洪兴","赵狗儿",
	"左全","林朝英","小龙女","杨过","矮老者","成不忧","丛不弃","封不平","风清扬",
	"高老者","令狐冲","岳不群","宁中则","班淑娴","何太冲","何足道","卫四娘","西华子",
	"梅剑","天山童姥","虚竹","黛绮丝","范遥","韦一笑","谢逊","杨逍","殷天正","包不同",
	"邓百川","风波恶","公冶乾","慕容博","慕容复","陈志益","程瑶迦","房志起","郝大通",
	"李志常","刘处玄","马钰","祁志诚","丘处机","申志凡","孙不二","谭处端","王重阳",
	"王处一","王志坦","尹志平","东方不败","计无施","贾布","蓝凤凰","任我行","上官云",
	"童百熊","向问天","洪安通","陆高轩","胖头陀","瘦头陀","苏荃","殷锦","张淡月",
	"章老三","唐老太太","唐不平","唐亮","唐猛","唐无火","唐无情","冯默风","黄药师",
	"陆乘风","曲灵风","黄蓉","本参","本尘","本观","本相","本因","枯荣大师","谷虚道长",
	"莫声谷","清虚道长","张翠山","守园道长","宋远桥","宋青书","俞岱岩","殷梨亭","俞莲舟",
	"张三丰","制香道长","岑其斯","何红药","何铁手","齐云","龙亦凡","冯阿三","苟读",
	"康广陵","苏星河","逍遥子","薛慕华","出尘子","丁春秋","狮吼子","天狼子","摘星子",
	"宝象","善勇","胜谛","随喜","血刀老祖","达而巴","金轮法王","葛伦布","贡唐仓国师",
	"嘉木活佛","鸠摩智","拉章活佛","灵智上人","萨木活佛","陈近南","马超兴","玄贞道长",
});
string *gift = ({
	"/clone/gift/shenliwan",
	"/clone/gift/unknowdan",
	"/clone/gift/xiandan",
	"/clone/gift/xisuidan",
	"/clone/stone/stone",
	"/clone/stone/stone-1",
	"/clone/stone/stone-2",
	"/clone/stone/stone-3",
	"/clone/stone/stone-4",
});
mapping create_quest()
{
	mapping quest;
	string owner;

	quest = QUEST_OB->query_quest();
	owner = name[random(sizeof(name))];
	quest["owner_name"] = owner;
	quest["task_time"] = 500 + random(240) + time();
	quest["exp_bonus"] = 150 + random(70);
	quest["pot_bonus"] = 180 + random(70);
	quest["score"] = 1;
	quest["weiwang"] = 5;
	quest["from"] = "江湖";
	return quest;
}
int random_quest(object me,object ob)
{
	mapping quest;
	string owner_name,obname;


	if( (int)me->query("score") < 5000
	|| (int)me->query("world_fail_time") > time()){
		message_vision("$N无奈的说道：唉，象我们这种人，每天都是起早贪黑，养家糊口。\n"
				"要知道江湖上的消息，只能多向一些过往的客官打听了。\n",ob);
		return 1;
	}
	if(mapp(quest = me->query("quest"))){
		if(quest["from"] != "江湖"){
			message_vision("$N无奈的说道：唉，象我们这种人，每天都是起早贪黑，养家糊口。\n"
			"要知道江湖上的消息，只能多向一些过往的客官打听了。\n",ob);
			return 1;
		}
		else if(quest["task_time"] > time()){
			message_vision("$N说道：如果你能够帮"+ quest["owner_name"] +"找到"
			+ quest["quest"]+"的话，应该会有所收获。\n",ob,me);
			return 1;
		}
		me->delete("quest");
		me->delete_temp("continue_job");
	}
	
	quest = create_quest();
	me->set("quest",quest);
	message("vision",ob->name() +"凑在"+ me->name() +"的耳边悄悄的说了一些话。\n",environment(me),me);

	obname = (string)me->query("quest/quest");
	owner_name = (string)me->query("quest/owner_name");

	switch(random(5)){
		case 1:
		case 2:
			tell_object(me,sprintf("%s说道：我听说，江湖上大名鼎鼎的%s，最近不知道是何缘故，\n"
			"明查暗访，四处找寻%s的下落。江湖上的人都说，这当中一定有很大的秘密。\n",
			ob->name(),owner_name,obname));
			break;
		case 3:
			tell_object(me,sprintf("%s神秘的说道：%s的事情你听说了吗？\n"
			"据说最近正急着四处寻找%s的下落。\n"
			"%s你要是见过，还得赶紧给送去，听说报酬可是不少啊。\n",
			ob->name(),owner_name,obname,RANK_D->query_respect(me)));
			break;
		default:
			tell_object(me,sprintf("%s神秘兮兮的说：嘿，最近江湖上，可数%s的事最轰动了。\n"
			"听说他为了得到%s，重金悬赏寻到%s之人。\n"
			"%s若是知道%s的下落，还得趁早给送去呀。\n",
			ob->name(),owner_name,obname,obname,RANK_D->query_respect(me),obname));
			break;
	}
	return 1;		
	
}
int accept_ob(object me,object ob,object obj)
{
	mapping quest;
	string msg;
	int con;
	
	if(mapp(quest = me->query("quest"))){
		if(quest["task_time"] < time()){
			message_vision("$N摇了摇头，说道：这东西我已经不需要了。\n",ob);
			me->delete("quest");
			me->delete_temp("continue_job");
			return 1;
		}
		switch(random(5)){
			case 1:
				msg = sprintf("%s欣喜的说道：这不正是我想要的%s嘛？真是有劳这位%s了！\n",
					ob->name(),obj->name(),RANK_D->query_respect(me));
				break;
			case 2:
				msg = sprintf("%s笑道：哈哈！真是皇天不负有心人，踏遍铁鞋无觅处！终于让我找到%s了！\n",
					ob->name(),obj->name());
				break;
			case 3:
				msg = sprintf("%s接过%s，仔细的看了半天，才语重心长的说：对，我要的就是它！\n",
					ob->name(),obj->name(),obj->name());
				break;
			default:
				msg = sprintf("%s惊讶的接过%s，打量了%s一番，感慨万分的说道：真是有劳这位%s了！\n",
					ob->name(),obj->name(),me->name(),RANK_D->query_respect(me));
				break;
		}
		tell_object(me,msg);
		destruct(obj);
		do_bonus(ob,me);
		me->delete("quest");
		return 1;
	}
	return 0;
}

void do_bonus(object ob,object me)
{
	mapping quest;
	int exp,pot,score,weiwang,con;
	object obj;

	con = (int)me->query_temp("continue_job");

	if(mapp(quest = me->query("quest"))){
		// 增加一个连续标志
		me->add_temp("continue_job",1);
		// 如果连续完成达到 10 个，开始计算是否为奖励目标
		if(con == 20 || con == 50 || con == 100 ){
			switch(con){
				case 20:
					obj=new(gift[random(sizeof(gift))]);break;
				case 50:
					obj=new("/clone/gift/qiongjiang");break;
				case 100:
					obj=new("/clone/gift/yuye");break;
			}
			obj->move(me,1);
			tell_object(me,sprintf("%s说道：我这里有一%s%s，就当做一点谢礼"
				"送给你吧！小小礼物，不成敬意！\n"
				HIC"由于你连续的做好了%s件江湖事，你得到了一%s%s。\n"NOR,
				ob->name(),obj->query("unit"),obj->name(1),chinese_number(con),
				obj->query("unit"),obj->name(1)));
			// 如果达到了100个，则自动初始化
		}
		
		if(con > 100 ) me->delete_temp("continue_job",1);
		if(intp(exp = quest["exp_bonus"])) me->add("combat_exp",exp);
		if(intp(pot = quest["pot_bonus"])) me->add("potential",pot);
		if(intp(score = quest["score"])) me->add("score",score);
		if(intp(weiwang = quest["weiwang"])) me->add("weiwang",weiwang);
		tell_object(me,sprintf(HIC"你的经验提高了%s点。\n"
					"你的潜能提高了%s点。\n"
					"你的江湖阅历提高了%s点。\n"
					"你的江湖威望提高了%s点。\n"NOR,
					chinese_number(exp),
					chinese_number(pot),
					chinese_number(score),
					chinese_number(weiwang)));
	}
	return;
}
