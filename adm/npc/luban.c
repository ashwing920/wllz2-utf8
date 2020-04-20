// luban.c 鲁班
// Written by Doing Lu 1998/11/17
// 鲁班是负责建造房间的NPC， 首先，玩家去鲁班那里索要图纸，然后到想建房的地点描绘图纸，
// 必须要有30级以上的绘画技巧才可以，如果不到30级，可以和鲁班学习。
// 然后玩家要把图纸给鲁班，鲁班询问房屋的名称，不能和那里已有的房屋重名，然后再询问房屋
// 的类型（房屋的类型都定义在roomtype.h）中，并且询问每个房间的描述，每个描述不能超过三
// 百二十个字符（即最多四行），其中所有的房间的short 都由房屋名称生成，不需要玩家输入，
// 然后鲁班记录所有的信息，并提示玩家等待巫师（权限在hufa以上）的批准。
// 巫师上线后到鲁班处，鲁班提示巫师处理玩家的信息，如果巫师批准了，就更新信息，等玩家再
// 上线后到鲁班处，鲁班提示玩家可以建房（如果没有被批准，就显示原因，清除信息），玩家交
// 一定的费用，就可以生成房屋文件，并修改玩家的档案，记录玩家已经建过房，并赠送一把钥匙。
// 然后清除记录的信息。
//
// 如果玩家丢了钥匙，可以到鲁班处重新配一把钥匙，如果玩家需要复制钥匙，也可以向鲁班要求。
//
// 如果玩家需要拆除房屋，可以向鲁班提出，经过确认后，删除房屋档案。

// 生成房屋的说明
// 在选择好房屋类型时，鲁班将纪录需要建设的房屋原型的所有文件，这些文件一定要在/d/room/
// XXXX/内，比如玩家选用了独乐居，则房屋文件都在/d/room/dulu/内。在生成房屋文件时，鲁班
// 将把这些文件拷贝到/data/room/playerid/，同时原型房屋必须由一个出口：/d/room/xiaoyuan
// 鲁班将将这个出口替换成玩家建房的地点，原型房还应该有一个以xiaoyuan命名的小院。
// 对于原型方还有一些其他要求，比如原型房继承的是ROOM类型，而建造的房将继承PRIVATE_ROOM
// 类型，因此在原型房的文件中，inherit ROOM之前要求有/**/的字样,而在inhert PRIVATE_ROOM
// 之前需要有//**的字样，因为鲁班会自动的将包含/**/的行去掉，并去掉//**的字样。
// 另外，所有有门的原型房，都必须有以下语句，set ("key", "ROOM_KEY");这是为了给建好的房
// 子添加钥匙。同时原型房中最好有主人set ("owner", "ROOM_OWNER")和类型的设置。

// 关于钥匙的一点说明
// 每个玩家房屋钥匙要生成一个文件，其实这完全可以用一个通用的钥匙文件在每次AUTOLOAD的时
// 候自动的更新，之所以不这么做是因为为了使玩家的房屋数据能够保持一个独立性，不至于过于
// 分散，而且在一个人身上带多把钥匙的时候不至于过于繁琐。

// 一些变量的说明
// 玩家在商谈时纪录的数据
// contract/luban : 纪录商谈数据的mapping，这记录在玩家的临时变量
// contract/luban/room     : 纪录房屋描述信息的mapping，这是room_example的一个元素
// contract/luban/descs    : 纪录房屋描述的mapping
// contract/luban/questing : 玩家商谈状态 quest_name/quest_id/quest_desc
// contract/luban/value    : 建设房屋所需要的价格(以coin为单位)
// contract/luban/position : 建造房屋的地点

// 鲁班记录玩家申请的数据
// form : 记录玩家申请的表单
// form/player/player   : 申请者的名称
// form/player/position : 申请建房的地点
// form/player/room     : 申请建房的类型名称
// form/player/type     : 申请建房的类型代号
// form/player/name     : 房屋的名称
// form/player/id       : 房屋的代号
// form/player/status   : 表单的状态 - 申请/允许/拒绝
// form/player/time     : 申请的时间
// form/player/wizard   : 处理表单的巫师
// form/player/memo     : 巫师填写的备注
// form/player/descs    : 玩家填写的描述

// 玩家自身数据的修改
// private_room/build   : 已经建过房屋
// private_room/position: 房屋所在的位置，即入口处所在场景的文件路径	:: 必须已经有build设置
// private_room/entry   : 房屋入口处的文件路径				:: 必须已经有build设置
// private_room/name    : 房屋名称						:: 必须已经有build设置
// private_room/id      : 房屋ID						:: 必须已经有build设置
// private_room/type    : 房屋类型名称					:: 必须已经有build设置

// 实现方法
// 商谈过程是一个简单的自动机，其状态储存在用户的数据结构中的contract/luban字段，接收消
// 息的函数是do_answer， 这个函数根据状态处理接收的消息即字符串，最要是调用不同的判断函
// 数，如果返回1则已记录输入的信息，如果返回0则表示不与处理或是终止商谈。如果用户在商谈
// 过程输入了stop，则清除自动机的状态和用户数据库中记录的商谈信息。

// 数据存放
// 阶段1 - 商谈
// 数据存放在player->contract/luban/这个mapping中

// 阶段2 - 申请
// 数据存放在luban->form/player/这个mapping中

// 阶段3 - 建设完毕
// 数据存放在player->private_room/这个mapping中
// 生成的文件存放在/data/room/player/这个目录中
// 玩家房屋的存盘文件存放在/data/room/player/这个目录中
// 建房处的存盘文件存放在/data/room/d/...这个目录中，/d/...即这个房屋文件的路径
// 房屋存盘文件名是ROOM_D认可的，如果需要修改，可以修改/adm/daemons/roomd

// 相关文件
// inherit::PRIVATE_ROOM(/inherit/room/private_rom.c)
// 这是用户建造的房屋所具有的属性，主要是用钥匙开门和存放物品
// inherit::RECODABLE_ROOM(/inherit/room/recordable_rom.c)
// 这是建房处的环境所具有的属性，主要是可以记录增加的出口，并修改LONG描述

#include <ansi.h>

inherit	NPC;
inherit	F_SAVE;

// 这里记录了各种样式房屋
// 这里是一个mapping数组，其中每一个mapping指明了一种型号的房屋。 每一个mapping中有三个
// 元素，一是名字、二是类型、三是房屋字符串数组：字符串数组指明了这种房屋所拥有的文件。
// files中的必须有一个是入口文件(既有到/d/room/xiaoyuan的出口)，否则建房时将产生错误。

// 另外：type 和 name 都可以作为房屋类型的标志，只不过一个是中文，另一个是英文的而已，
// 在最终保存在玩家数据库中的是中文的类型名即name字段。

// 注意：由于鲁班是一个需要保存数据的NPC，在改动鲁班的文件后可能会发生一些问题，这时可以
// 将他的存盘文件删除。
mapping *room_example = ({
([	"name"		: "烟竹小筑",
	"type"		: "yanzhu",
	"value"	: 	20000000,
	"files"	: 	([
	"xiaoyuan": 	"/d/room/yanzhu/xiaoyuan.c",
	"room1"	: 	"/d/room/yanzhu/room1.c" ,
	"room2"	: 	"/d/room/yanzhu/room2.c" ,
		]),
]),

([	"name"		: "梦庭院",
	"type"		: "mengting",
	"value"	:	50000000,
	"files"	: ([
	"xiaoyuan": "/d/room/mengting/xiaoyuan.c",
	"room1" :"/d/room/mengting/room1.c",
	"room2"	:"/d/room/mengting/room2.c",
	"room3"	:"/d/room/mengting/room3.c",
	"room4"	:"/d/room/mengting/room4.c",
	]),
]),

([	"name"		: "别墅",
	"type"		: "bieshu",
	"value"	:	100000000,
	"files"	: ([
	"xiaoyuan": "/d/room/bieshu/xiaoyuan.c",
	"room1" :"/d/room/bieshu/room1.c",
	"room2"	:"/d/room/bieshu/room2.c",
	"room3"	:"/d/room/bieshu/room3.c",
	"room4"	:"/d/room/bieshu/room4.c",
	"room5"	:"/d/room/bieshu/room5.c",
	]),
]),
});

#define	WIZLEVEL	4	// 能够处理表单的巫师等级

// 通常函数
int	save();
int	ask_me();
int	ask_paper();
int	ask_drawing();
int	ask_demolish();
int	ask_rebuild();
int	ask_modify();
int	ask_key();
int	ask_desc();
int	recognize_apprentice(object me);
int	accept_object(object me, object ob);
void	luban_say(string msg);
void	user_say();
int	do_answer(string arg);
int	do_stop();
int	do_desc(string arg);
int	do_show(string arg);
int	do_changename(string arg);
int	do_changeid(string arg);
int	do_changetype(string arg);
int	do_changedesc(string arg);
int	do_finish();
int	do_withdraw();
int	decide_withdraw();
int	do_destory();
void	show_desc(string player_id, string arg);
int	quest_user(object me);
int	quest_info(object me);
int	check_name(object me, string arg);
int	check_id(object me, string arg);
int	check_type(object me, string arg);
int	check_legal_name(string name, string position);
int	check_legal_id(string name);
mixed	check_legal_type(string type);
string	obey_description(string desc);
object	get_object(string file_name);
int	record_desc(object me, string room_name, string desc);
void	record_contract(object me);
int	modify_desc_in_form(string player_id, string room_name, string desc);
string	sort_desc(string desc);

// 巫师使用的管理命令相关的函数
void	show_brief(string player_id);
int	exist_form();
int	do_list(string arg);
int	do_type(string arg);
int	do_agree(string arg);
int	do_reject(string arg);
int	do_delete(string arg);
void	show_apply();
void	show_agree();
void	show_reject();
void	show_old();
void	show_brief_title();
void	show_brief_list(string info, string msg);

// 生成房屋的函数
void	create_room(object me);
string	to_player(string player_id, string file_name);

mapping* forms;
mapping my_form;	// 一个表单，用来存放用户提交的建房信息

// 这是提供的函数，之所以用宏定义，仅仅是为了减小运行时的开销
// 查询form
#define	query_form(pid, item)		query("form/" + pid + "/" + item)
// 设置form内的值
#define set_form(pid, item, content)	set("form/" + pid + "/" + item, content)
// 判断该玩家是否有提交申请
#define submit_form(pid)		mapp(query("form/" + pid))

void create()
{
	restore();

	set_name("鲁班", ({ "lu ban", "lu", "luban" }));
	set("title", "第二巧匠");
	set("nickname", HIC "鬼斧神工匠" NOR);
	set("shen_type", 0);

	set("str", 10000);		// 防止接收的东西过多而导致丢失
	set("int", 100);

	set("gender", "男性");
	set("age", 1450);
	set("long",@LONG
这就是号称天下第二巧匠的建筑大师公输班，不论是造什么样子房屋，在他手下
都不是问题。
LONG
);
	set("attitude", "friendly");
	set("inquiry", ([
		"造房"	: (: ask_me :),
		"卖房"	: (: ask_me :),
		"建房"	: (: ask_me :),
		"房子"	: (: ask_me :),
		"room"	: (: ask_me :),
		"house"	: (: ask_me :),
		"图纸"	: (: ask_paper :),
		"纸张"	: (: ask_paper :),
		"纸"	: (: ask_paper :),
		"paper"	: (: ask_paper :),
		"拆屋"  : (: ask_demolish :),
		"拆房"  : (: ask_demolish :),
		"拆毁"  : (: ask_demolish :),
		"重建"  : (: ask_rebuild :),
		"再建"  : (: ask_rebuild :),
		"钥匙"	: (: ask_key :),
		"锁匙"	: (: ask_key :),
		"锁钥"	: (: ask_key :),
		"key"	: (: ask_key :),
		"描述"	: (: ask_desc :),
		"描写"	: (: ask_desc :),
		"desc"	: (: ask_desc :),
		"规则"	: (: ask_desc :),
		"修改"  : (: ask_modify :),
		"修改信息": (: ask_modify :),
		"绘画"    : (: ask_drawing :),
		"画"      : (: ask_drawing :),
		"绘画技巧": (: ask_drawing :),
		"drawing" : (: ask_drawing :),
	]));

	set_skill("drawing",  500);		// 绘画技巧

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

// 存盘函数
int save()
{
	object *inv;
	int i;

	// 每次存盘前释放所有物品
	inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++) destruct(inv[i]);

	::save();
}

void init()
{
	object me;

	::init();

	if (interactive(me = this_player()))
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}

	me->delete_temp("decide_withdraw");
	me->delete_temp("demolish_room");

	add_action("do_stop", "stop");
	add_action("do_answer", "answer");
	add_action("do_desc", "desc");
	add_action("do_show", "show");
	add_action("do_changename", "changename");
	add_action("do_changeid",   "changeid");
	add_action("do_changetype", "changetype");
	add_action("do_changedesc", "changedesc");
	add_action("do_finish", "finish");
	add_action("do_finish", "ok");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "chexiao");
	add_action("decide_withdraw", "decide");
	add_action("do_demolish", "demolish");

	// 如果来的是有资格处理表单的巫师纠正加处理表单的命令
	if (wizardp(me) && wiz_level(me) > WIZLEVEL)
	{
		add_action("do_list", "list");
		add_action("do_type", "type");
		add_action("do_agree", "agree");
		add_action("do_reject", "reject");
		add_action("do_delete", "delete");
	}
}

// 存盘文档
string query_save_file()
{
	return "/data/npc/luban";
}

void greeting(object me)
{
	if (!objectp(me) || environment(me) != environment())
	{
		return;
	}

	// 对巫师提示的信息
	if (wizardp(me) && wiz_level(me) > WIZLEVEL)
	{
		if (query("form") && sizeof(query("form")) >= 1)
		{
			message_vision("鲁班对$N道，来的正好，我这里有些单子正要处理呢。\n", me);
			tell_object(me, HIG "鲁班告诉你：请用" HIW "list" HIG "察看，" +
					HIW "type" HIG "显示详细信息，" HIW "agree" HIG +
					"注册，" HIW "reject" HIG "拒绝，" HIW "delete" HIG "删除表单。\n" NOR);
		} else
		{
			message_vision("鲁班对$N点点头，道：公输班正在授课，不及远迎，失礼了！\n", me);
		}
		return ;
	} else
	if (query("form/" + me->query("id")))
	{
		// 该玩家提交了表单，根据表单的状态返回提示信息
		switch (query("form/" + me->query("id") + "/status")) {
		case "申请" :
			luban_say("巫师还没有查阅你的申请，要向查看你提交的表单可以用show，如果想修改可以问我。\n");
			break;

		case "拒绝" :
			luban_say("你的申请被拒绝了，你可以用show查看详情，如果想修改可以问我。\n");
			break;

		case "同意" :
			luban_say("你的申请已经被批准了，缴纳现金即可建房，查看详情请用show，如果想修改可以问我。\n");
			break;
		}
	} else
	// 对玩家提示的信息
	if (me->query_temp("contract/luban"))
	{
		message_vision("鲁班对$N笑道：这位" + RANK_D->query_respect(me) +
			"，刚才怎么谈着谈着就走了？如是有意，咱们继续谈嘛。\n", me);
	} else
	switch(random(3)) {
	case 0 :
		message_vision("鲁班对$N说道：这位" + RANK_D->query_respect(me) +
			"，可是想建个房子？\n", me);
		break;
	case 1 :
		message_vision("鲁班对$N笑道：这位" + RANK_D->query_respect(me) +
			"，行走江湖，若是没有个落脚之处怎么行啊！\n", me);
		break;
	case 2 :
		message_vision("鲁班对$N一拱手，说道：这位" + RANK_D->query_respect(me) +
			"，很久没见啊，别来无恙？\n", me);
		break;
	}
}

// 认证学习
int recognize_apprentice(object me)
{
	if (me->query_temp("mark/鲁班"))
	{
		message_vision("鲁班对$N说：好，你既然有心学，我就教你一点吧。\n", me);
	}
	me->set_temp("mark/鲁班", 1);
	return 1;
}

// 接受物品：图纸
int accept_object(object me, object ob)
{
	object build;		// 建房的地点

	if (ob->query("id") == "key" && ob->query("item_make"))
	{
		// 如果接收的是钥匙，就收下
		if(mapp(me->query("private_room"))){
			message_vision("$N疑惑的看着$n问道：你的房子不要了吗？不要的话就把它拆了吧。\n",this_object(),me);
			return 0;
		}
		message_vision("鲁班点点头，收下了" + ob->query("name") + "。\n", me);
		if( !mapp(me->query("private_room")) && (string)ob->query("key_master") == (string)me->query("id")){
			if(file_size("/data/room/"+ me->query("id")+"/key.c") != 0)
			rm("/data/room/"+ me->query("id")+"/key.c");
		}
		return 1;
	}

	if (ob->query("图纸"))
	{
		if (mapp(me->query("private_room")))
		{
			message_vision("鲁班呵呵笑道：莫非你有一处住房还是不够？\n", me);
			return 0;
		}
		// 这是为了防止出现不正确的build_room的标记
		me->delete("private_room");

		if (query("form/" + me->query("id")))
		{
			message_vision("鲁班笑道：慌甚！你不是已经提交了申请么？可以用show察看申请。\n", me);
			return 0;
		}
		if (me->query_temp("contract/luban"))
		{
			message_vision("鲁班疑惑的对$N说道：干什么？刚才不是给过我了么？若是有什么想法，可以改日再谈(stop)。\n", me);
			return 0;
		}

		if (! ob->query("draw"))
		{
			message_vision("鲁班看了一下，对$N说道：你给我一张白纸干什么？你要是不会就和我学学绘画技巧(drawing)吧。\n", me);
			return 0;
		}
		if ( ob->query("draw") < 30)
		{
			message_vision("鲁班接过图纸，看了半天，问$N道：你这画的是什么东西？你要是不会跟我学学绘画技巧(drawing)。\n", me);
			return 0;
		}
		if ( ob->query("draw") < 80)
		{
			message_vision("鲁班接过图纸看了看，对$N笑道：画的还行，马马虎虎吧。\n", me);
		} else
		{
			message_vision("鲁班看了看$N给的图纸图纸，喝彩道：神了，真是有天赋啊！\n", me);
		}

		build = get_object(ob->query("position"));
		if (! objectp(build))
		{
			message_vision("鲁班仔细看了看，叹了口气说道：那个地方现在好像已经不存在了...\n", me);
			return 0;
		}

		if (! build->query("recordable_room"))
		{
			message_vision("鲁班仔细看了看，不禁皱了皱眉，对$N说道：那个地方好像不能建房吧...\n", me);
			return 0;
		}
		me->set_temp("contract/luban/position", ob->query("position"));
		quest_user(me);
		return 1;
	}

	// 看看是否填写了表单
	if (ob->query("money_id") && mapp(query("form/" + me->query("id"))))
	{
		if (query("form/" + me->query("id") + "/status") != "同意")
		{
			message_vision("鲁班摇摇头，对$N道：巫师还没有批准你的申请，你先请回吧。\n", me);
			return 0;
		}
		if (ob->value() < query("form/" +me->query("id") + "/value"))
		{
			message_vision("鲁班接过钱掂了掂，对$N呵呵笑道：这钱似乎不够吧？\n", me);
			return 0;
		}
		create_room(me);
		return 1;
	}

	// 看看是否够定金
	if (ob->query("money_id"))
	{
		if (me->query_temp("contract/luban/questing") != "quest_desc")
		{
			message_vision("鲁班微微一笑，对$N道：干什么这么客气？我不收无功之禄。\n", me);
			return 0;
		}
		if (ob->value() < 50000)
		{
			message_vision("鲁班嘿然冷笑，对$N道：五两黄金你都吝惜？哼哼，就算是天神亲临，我也不打折扣。\n", me);
			return 0;
		}
		message_vision("鲁班满意的对$N说道：很好，我就给你记录在案，若是有了消息，一定通知你。\n", me);
		record_contract(me);
		me->delete_temp("contract");
		return 1;
	}
	message_vision("鲁班摆摆手，对$N道：你还是自己留着吧，我可用不着。\n", me);
	return 0;
}

// 回答有关建房的信息
int ask_me()
{
	object me;
	me = this_player();

	if (mapp(me->query("private_room")))
	{
		message_vision("鲁班点点头，对$N说道：怎么样，住得可满意？若是不满意，可以找我重建哦。\n", me);
		return 1;
	}
	message_vision("鲁班微一叹气，说道：想江湖儿女，一剑纵横，快意恩仇，驰骋天下，若是没有个落脚之处，\n" +
		       "怎生得了？或隐身于闹市，或遁迹于险川，你若有意，何不画张图纸给我，若是地点合适，你\n" +
		       "且挑个满意的样式，我给你建个住房。今生今世，不再惧那风雨。\n", me);
	return 1;
}

// 回答有关图纸的信息
int ask_paper()
{
	object	me;
	object	ob;

	me = this_player();

	if (is_busy())
	{
		write("鲁班正忙着呢，没功夫理你...\n");
		return 1;
	}

	message_vision("鲁班点点头，对$N说道：很好，你拿这份图纸，到了想要建房的地点，画下来拿回给我看看。\n", me);
	ob = new("/d/room/obj/paper");
	if (objectp(ob))
	{
		message_vision("鲁班翻了翻，找到一张图纸，递给了$N。\n", me);
		ob->move(me);
	} else
	{
		message_vision("鲁班翻了半天也没找到，不禁一呆，说道：怎么回事，没有了？你去找巫师问问吧！\n", me);
	}

	start_busy(4);
	return 1;
}

// 回答有关绘画技巧的信息
int ask_drawing()
{
	int	skl;
	object	me;

	me =this_player();
	skl = me->query_skill("drawing", 1);

	message_vision("鲁班对$N说道：要想画张好点的图纸，不会点绘画技巧是不行的，没有人天生就会" +
		       "作画，都得学习，你若有意，不妨和我学学。", me);
	if (skl < 30)
	{
		message_vision("你现在的绘画技巧可太差了。\n", me);
	} else
	if (skl < 80)
	{
		message_vision("你现在的绘画技巧也算是马马虎虎了。\n", me);
	} else
	{
		message_vision("当然了，你现在的水平是相当不错了。\n", me);
	}
	return 1;
}

// 打听拆屋的消息
int ask_demolish()
{
	object me;

	me = this_player();
	if (me->query_temp("contract/luban"))
	{
		message_vision("鲁班对$N说：你不是要建房么，怎么还没建好就要拆房了？真是未雨绸缪啊！\n", me);
		return 1;
	}
	if (query("form/" + me->query("id")))
	{
		message_vision("鲁班哼了一声，对$N道：你的房子还没见到渣呢！你要是不想建了，就撤消(withdraw)申请算了。\n", me);
		return 1;
	}
	if (! mapp(me->query("private_room")))
	{
		message_vision("鲁班哈哈大笑，对$N道：拆屋？你还没有呢，拆什么拆！乱拆别人的屋子可是犯法的！\n", me);
		return 1;
	}
	if (me->query_temp("demolish_room"))
	{
		message_vision("鲁班对$N说：你要是真的想拆屋，就请下决心(demolish)！\n", me);
		return 1;
	}
	message_vision("鲁班睁大了眼睛，奇怪的看着$N，过了良久才说：你若是真到要拆屋，就下决心吧(demolish)！\n", me);
	me->set_temp("demolish_room", 1);
	return 1;
}

// 打听重建的消息
int ask_rebuild()
{
	object me;

	me = this_player();
	if (! mapp(me->query("private_room")))
	{
		message_vision("鲁班摇摇头，对$N说：你还没有房子呢，谈什么重建！\n", me);
		return 1;
	}
	message_vision("鲁班叹了口气，对$N说：你若是要重建，得先拆房！\n", me);
	return 1;
}

// 重新配置钥匙
int ask_key()
{
	object me;

	me = this_player();

	if (is_busy())
	{
		write("鲁班正忙着呢，没空理你...\n");
		return 1;
	}

	if (! mapp(me->query("private_room")))
	{
		message_vision("鲁班看了半天，才对$N说：没有房子你要钥匙干什么？\n", me);
		return 1;
	}

	if( present("key of "+ me->query("id"),me)){
		message_vision("鲁班疑惑的看着$N说：你不是已经有钥匙了吗？\n",me);
		return 1;
	}
	clone_object("/data/room/" + me->query("id") + "/key")->move(me);
	message_vision("鲁班拿出一把钥匙，对$N说：诺，这是钥匙，收好了！\n", me);
	start_busy(4);
	return 1;
}

// 打听描述规则信息
int ask_desc()
{
	luban_say(@INFORMATION
描述信息可以使用颜色，并且可以分行，但是最多不能超过160个汉字：

颜色的规则：
$BLK$ - 黑色		$NOR$ - 恢复正常颜色
$RED$ - 红色		$HIR$ - 亮红色
$GRN$ - 绿色		$HIG$ - 亮绿色
$YEL$ - 土黄色		$HIY$ - 黄色
$BLU$ - 深蓝色		$HIB$ - 蓝色
$MAG$ - 浅紫色		$HIM$ - 粉红色
$CYN$ - 蓝绿色		$HIC$ - 天青色
$WHT$ - 浅灰色		$HIW$ - 白色

换行：
只要在描述信息中添加一个\n就可以。比如：“这是一间小院。\n院子边上的墙很矮。”
实际看到的描述使这个样子的：
这是一间小院。
院子边上的墙很矮。

说明：
系统自动会在描述字符串的尾端加一个 $NOR$ 和 \n。因此描述最好不要以\n结束，以免
空行太多。另外，系统会自动的规范你输入的描述信息，因此你不需要在描述信息前面添
加段落起始的空格，同时也不需要在一个段落内部插入\n以实现换行，对于过长的段落系
统会自动的添加换行符。


INFORMATION );
	return 1;
}

// 打听修改的消息
int ask_modify()
{
	object me;

	me = this_player();
	if (! submit_form(me->query("id")) && me->query_temp("contract/luban/questing") != "quest_desc")
	{
		message_vision("鲁班摇摇头，对$N说：你只有描述时或是提交了申请以后才用得着修改。\n", me);
		return 1;
	}

	message_vision("鲁班点点头，对$N说：你可以修改你提交的申请中的各种信息：\n" +
		"\n你可以通过以下指令修改房屋的各种信息：\n" +
		HIW "changename " NOR "name : 修改房屋的中文名字。\n" +
		HIW "changeid   " NOR "id   : 修改房屋的英文代号。\n" +
		HIW "changetype " NOR "type : 修改房屋的类型。\n" +
		HIW "changedesc " NOR "room desc : 修改某间房屋的描述。\n", me);
	return 1;
}

// 输出鲁班说话时的表情
void luban_say(string msg)
{
	object me;
	me = this_player();
	message("vision", "鲁班对" + me->query("name") + "嘀嘀咕咕说了些话。\n", environment(me), ({ me }));
	write("鲁班说道：" + msg);
}

// 输出用户说话时的表情
void user_say()
{
	object me;
	message("vision", me->query("name") + "对鲁班嘀嘀咕咕说了些话。\n", environment(me), ({ me }));
}

// 用户中止商谈
int do_stop()
{
	object me;
	me = this_player();
	if (! me->query_temp("contract/luban"))
	{
		message_vision("鲁班一脸傻样......\n", me);
		return 1;
	}
	me->delete_temp("contract/luban");
	message_vision("鲁班对$N点点头，说道：既然如此，改日再谈也不妨。\n", me);
	return 1;
}

// 用户回答问题
// 根据当前状态做出相应的反应
int do_answer(string arg)
{
	object me;
	string questing;

	me = this_player();
	questing = me->query_temp("contract/luban/questing");

	// 判断现在是否正在商谈
	if (! questing)
		return 0;

	switch (questing) {
	// 商谈房屋名字
	case "quest_name" :
	check_name(me, arg);
	break;

	case "quest_id" :
	check_id(me, arg);
	break;

	case "quest_type" :
	check_type(me, arg);
	break;

	default:
	write("没人问你问题，你想回答什么？\n");
	}
	return 1;
}

// 记录用户输入的描述信息
int do_desc(string arg)
{
	object me;
	string room_name;
	string desc;

	me = this_player();

	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	if (arg)
	{
		if (sscanf(arg, "%s %s", room_name, desc) != 2)
		{
			room_name = arg;
			desc = 0;
		}
	}
	else
	{
		show_desc(me->query("id"), 0);
		return 1;
	}

	record_desc(me, room_name, desc);
	return 1;
}

// 显示用户自己输入的描述信息
int do_show(string arg)
{
	show_desc(this_player()->query("id"), arg);
	return 1;
}

// 改变房屋名字
// 分两种状态处理：商谈中或是申请中
int do_changename(string arg)
{
	object me;
	string player_id;
	string position;

	me = this_player();
	player_id = me->query("id");

	if (submit_form(player_id))
	{
		// 正在申请
		position = query_form(player_id, "position");
		if (! check_legal_name(arg, position)) return 1;

		luban_say("好吧，就改成" + arg + "这个名字吧！\n");
		set_form(player_id, "name", arg);
		set_form(player_id, "status", "申请");
		save();
		return 1;
	} else
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	// 正在商谈
	if (check_legal_name(arg, me->query_temp("contract/luban/position")))
	{
		me->set_temp("contract/luban/name", arg);
		luban_say("好吧，就改成" + arg + "这个名字吧！\n");
	}
	return 1;
}

// 改变房屋代号
// 分两种状态处理：商谈中或是申请中
int do_changeid(string arg)
{
	object me;
	string player_id;
//	string position;

	me = this_player();
	player_id = me->query("id");

	if (submit_form(player_id))
	{
		// 正在申请
		if (! check_legal_id(arg)) return 1;
		luban_say("行啊，就改成" + arg + "这个房屋代号吧！\n");
		set_form(player_id, "id", arg);
		set_form(player_id, "status", "申请");
		save();
		return 1;
	} else
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	// 正在商谈
	if (check_legal_id(arg))
	{
		me->set_temp("contract/luban/id", arg);
		luban_say("行啊，就改成" + arg + "这个房屋代号吧！\n");
	}
	return 1;
}

// 改变房屋类型
// 分两种状态处理：商谈中或是申请中
int do_changetype(string arg)
{
	object me;
	int value;
	string player_id;
//	string position;
	mapping example;

	me = this_player();
	player_id = me->query("id");

	if (submit_form(player_id))
	{
		// 正在申请
		if (! (example = check_legal_type(arg)))
		{
			write("找不到这种类型的房屋，所以没有改变房屋的类型。\n");
			return 1;
		}
		set_form(player_id, "room", example["name"]);
		value = example["value"];
		if (wizardp(me)) value = 0;
		set_form(player_id, "value", value);
		set_form(player_id, "descs", ([ ]));
		set_form(player_id, "status", "申请");
		save();
		luban_say("换一种房型也行，不过请你填写新的描述(changedesc)。\n");
		return 1;
	} else
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	// 正在商谈
	if (! check_type(me, arg))
	{
		write("没有改变房屋类型。\n");
	}
	return 1;
}

// 改变房屋名字
// 分两种状态处理：商谈中或是申请中
int do_changedesc(string arg)
{
	object me;
	string player_id;
//	mapping example;
	string room_name;
	string room_desc;

	me = this_player();
	player_id = me->query("id");

	if (submit_form(player_id))
	{
		// 正在申请
		if (! arg || arg == "")
			return notify_fail("请按照正确格式输入：changedesc room_name description\n");

		if (sscanf(arg, "%s %s", room_name, room_desc) != 2)
		{
			room_name = arg;
			room_desc = 0;
		}

		// 修改描述信息
		modify_desc_in_form(player_id, room_name, room_desc);
		set_form(player_id, "status", "申请");
		save();
		return 1;
	} else
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	// 正在商谈
	do_desc(arg);
	return 1;
}

// 结束输入
int do_finish()
{
	object me;
	int value;
	string msg;

	me = this_player();
	value = (int)me->query_temp("contract/luban/room/value");
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	show_desc(me->query("id"), 0);

	msg = "金临拨拉拨拉算盘，慢条斯理的对$N说道：要造这样的房子，少说也得" + chinese_number(value/10000) + "两黄金，不二价！\n";
	if (wizardp(me))
	{
		msg += "鲁班对金临喝道：不得无理！此乃上届仙人...嘿嘿，到时意思意思就算了吧。\n";
	}
	msg += "鲁班略一沉吟，然后说道：你看看有没有什么问题么？若是没有，请先交五两黄金的定金。\n";
	message_vision(msg, me);

	return 1;
}

// 撤消表单
int do_withdraw()
{
	object me;

	me = this_player();
	if ( me->query_temp("contract/luban"))
	{
		do_stop();
		return 1;
	}
	if (! query("form/" + me->query("id")))
	{
		message_vision("鲁班一脸茫然......对$N说道：现在你好像没有提交的申请吧！\n", me);
		return 1;
	}

	if (me->query_temp("decide_withdraw"))
	{
		message_vision("鲁班对$N说道：你若是要撤消申请，就请下决定(decide)！\n", me);
		return 1;
	}

	switch (query("form/" + me->query("id") + "/status")) {
	case "申请":
	luban_say("可惜，你怎么这就反悔了？\n");
	break;

	case "同意":
	luban_say("哎呀！真是可惜，巫师都同意了，你怎么打退堂鼓了？\n");
	break;

	case "拒绝":
	luban_say("唉！没能被批准也别就打退堂鼓么，看看怎么回事再说么。\n");
	break;
	}
	message_vision("鲁班叹了口气，对$N说道：既然如此，此事也不必勉强，如果你想好了，就下决定(decide)吧！\n", me);
	me->set_temp("decide_withdraw", 1);
	return 1;
}

// 删除表单
int decide_withdraw()
{
	object me;

	me = this_player();
	if (! me->query_temp("decide_withdraw")) return 0;

	me->delete_temp("decide_withdraw");
	delete("form/" + me->query("id"));
	save();
	message_vision("鲁班摇摇头，掏出一个账本，翻了翻，不知道划掉了什么东西。\n", me);
	return 1;
}

// 拆毁房屋
// 必须先询问鲁班有关拆房的信息
int do_demolish()
{
	mapping example;
	string *names;

	object me;
	object ob;

	int i;

	me = this_player();

	if (! me->query_temp("demolish_room"))
		return 0;

	me->delete_temp("demolish_room");
	if (! me->query("private_room")) return 0;
	if (! mapp(me->query("private_room")))
	{
		write("错误的数据已经被删除！\n");
		me->delete("private_room");
		return 1;
	}

	// 删除用户创建的所有文件
	// 保留钥匙文件，因为钥匙有可能留在某些玩家手里
	example = check_legal_type(me->query("private_room/type"));
	if (mapp(example))
	{
		seteuid(getuid());
		names = keys(example["files"]);
		// 删除文件
		for (i = 0; i < sizeof(names); i++)
			rm(to_player(me->query("id"), example["files"][names[i]]));
	}

	ob = get_object(me->query("private_room/position"));
	if (! objectp(ob))
	{
		write("建房的地点已经找不到了！删除了有关房屋的信息。\n");
		me->delete("private_room");
		return 1;
	}

	ob->demolish_room(me->query("private_room/name"));
	ob->save();
	me->delete("private_room");
	message_vision("鲁班点点头，对$N说：好了，剩下的事情我会办妥的！把钥匙给我，然后你就可以走了。\n", me);
	return 1;
}

// 显示用户输入的描述信息
// 如果用户正在商谈，就显示用户刚输入的描述信息，如果用户在等待审批，则显示用户
// 以前输入的描述信息
// 获得一个player对房屋的描述
// room_name是用户指定的房屋中的某一间的short描述
void show_desc(string player_id, string room_name)
{
	mapping filesp;		// 原型房屋描述的文件mapping
	mapping descsp;		// 玩家的描述mapping

	int i;
	int value;		// 房屋造价
	int count;		// 显示的描述信息的数目
	object me;		// 调用该函数的对象
	object player;	// 被显示的player的object
	object ob;		// 被描述的房屋的object或是建房场景的object

	string desc;		// 房屋描述的mapping
	string *names;		// 房屋mapping的关键字的字符串表
	string room_nameid;	// 房屋名字及ID
	string room_type;		// 房屋类型
	string position;		// 建房的位置

	string ids;			// 查询时使用

	string info;		// 最后给出的提示信息
	string msg;			// 临时变量，用于显示信息

	me = this_player();
	info = "";

	if (mapp(query("form/" + player_id)))
	{
		// 在表单中有该玩家提交的表单
		ids = "form/" + player_id + "/";
		room_type = query(ids + "type");
		for (i = 0; i < sizeof(room_example); i++)
		{
			if (room_example[i]["type"] == room_type)
			{
				filesp = room_example[i]["files"];
				break;
			}
		}
		if (! mapp(filesp))
		{
			write("你申请的房屋类型(" + room_type + ")已经不存在了，请和巫师联系。\n");
			return;
		}
		descsp = query(ids + "descs");
		room_type = query(ids + "room") + "(" + room_type + ")";
		room_nameid = query(ids + "name") + "(" + query(ids + "id") + ")";
		value = query(ids + "value");
		position = query(ids + "position");
		// 提示信息中给出该房屋的申请结果
		msg = query(ids + "wizard");
		switch (query(ids + "status")) {
		case "申请" :
			info = "巫师还没有查阅这份申请。";
			break;

		case "拒绝" :
			info = msg + "已经拒绝了这份申请！";
			if (query(ids + "memo") != "无")
				info += "\n原因是：" + query(ids + "memo");
			break;

		case "同意" :
			info = msg + "已经同意了这份申请！";
			break;
		}

		if (this_player()->query("id") == player_id)
		{
			if (query(ids + "status") == "同意")
			{
				info += HIW "\n你现在可以建造房屋了。如果这时修改了房屋的信息，就要得到巫师的再次批准。" NOR;
			} else
			if (query(ids + "status") == "拒绝")
			{
				info += HIR "\n你现在最好修改房屋的信息以获得巫师的批准，否则请撤消申请。" NOR;
			}
			info += "\n你可以撤消(withdraw)你提交的申请。";
		}
	} else
	if (objectp(player = present(player_id, environment(this_object()))) &&
	    player->query_temp("contract/luban/questing") == "quest_desc")
	{
		filesp = player->query_temp("contract/luban/room/files");
		descsp = player->query_temp("contract/luban/descs");
		room_type = player->query_temp("contract/luban/room/name");
		room_type += "(" + player->query_temp("contract/luban/room/type") + ")";
		room_nameid = player->query_temp("contract/luban/name") + "(" +
			      player->query_temp("contract/luban/id") + ")";
		value = player->query_temp("contract/luban/value");
		position = player->query_temp("contract/luban/position");
	} else
	{
		// 没有商谈
		luban_say("呵呵，这位好像还没有打算建房子吧。\n");
		return;
	}

	ob = get_object(position);
	if (! objectp(ob))
	{
		write("你申请的建造房屋的地方(" + position + ")已经不存在了，请和巫师联系!\n");
		return;
	}

	msg = "好，你看看吧：\n" + "这里选用的是" + room_type + "这种类型的房屋。\n" +
		  "它的名字是" + room_nameid + "，将建筑在" + ob->query("short");
	if (wizardp(me) && wiz_level(me) > WIZLEVEL)
		msg += "(" + position + ")";
	msg += "。\n";
	luban_say(msg);

	names = keys(filesp);
	count = 0;
	for (i = 0; i < sizeof(filesp); i++)
	{
		// 查找该房屋的object
		ob = get_object(filesp[names[i]]);
		if (! objectp(ob))
		{
			write("找不到示例的房屋" + names[i] + "，请和巫师联系。\n");
			continue;
		}
		if (! room_name || room_name == "" ||
		    ob->query("short") == room_name || names[i] == room_name)
		{
			// 查找用户输入的描述信息
			desc = sort_desc(descsp[names[i]]);
			write(WHT"────────────────────────────────────────\n"NOR);
			write(HIW + "关于" + ob->query("short") + "(" + names[i] + ")" + HIW + "的描述：\n\n" + NOR);
			if (! desc)
			{
				// 用户没有输入描述信息，显示缺省信息
				desc = "现在还没有输入描述信息，使用系统缺省的描述信息。如下：\n\n";
				desc += sort_desc(ob->query("default_long"));
			}
			write(desc +"\n");
			count++;
		}
	}

	if (! count)
	{
		write("但是这里没有" + room_name + "这个房间，请用show查看所有的房间！\n");
		return ;
	}

	write(WHT"────────────────────────────────────────\n"NOR);
	write("描述就是上面列出的这些内容。\n");

	if (! value)
		info += "\n建造这些房间不需要花费任何银两。";
	else
		info += "\n建造这些房间需要花费" HIY + chinese_number(value/10000) + "两黄金。" NOR;

	write(info + "\n");

	return ;
}

// 询问玩家必要的建房信息，然后记录，留给巫师审批
int quest_user(object me)
{
	message_vision("鲁班对$N说道：好，来，咱们仔细谈谈！\n", me);
	// 询问房屋名称
	luban_say("先告诉我你想建的房子叫什么名字(answer name)。\n你若是不想谈了(stop)，告诉我也无妨。\n");
	me->set_temp("contract/luban/questing","quest_name");
	return 1;
}

// 询问描述信息
int quest_info(object me)
{
	message_vision("鲁班对$N说道：好，看来你喜欢" + me->query_temp("contract/luban/room/name") +
			"这种样式的。\n", me);
	// 显示房屋样式信息

	luban_say(@INFORMATION
你可以为你的房间添加你喜欢的描述，格式是：desc 房间名称 描述。当
然你也可以使用原有的描述，如果你想看看你输入的情况，可以用show来察看。若一
切都输入好了以后键入finish或是ok就可以了。如果想修改输入的房屋名字，代号，
类型的信息可以向我询问<修改>的方法。

举个描述的例子：“desc 小院 这里是一间别致的小院。”这样就给小院添加了一行
描述。如果想取消小院的描述可以键入：“desc 小院”就可以了。

描述还可以使用颜色，可以多行，具体细节可以问我 <规则>。这里要需要注意的是：
系统自动会在描述字符串的尾端加一个 $NOR$ 和 \n。因此描述不要以\n结束，以免
空行太多。另外，系统会自动的规范你输入的描述信息，因此你不需要在描述信息前
面添加段落起始的空格，同时也不需要在一个段落内部插入\n以实现换行，对于过长
的段落系统会自动的添加换行符。

另外，在描述的字符串内部不要输入空格，跳格，这些输入都会被抹掉。
INFORMATION );

	me->set_temp("contract/luban/questing","quest_desc");

	// 清除描述信息
	me->delete_temp("contract/luban/descs");
	me->set_temp("contract/luban/descs", ([ ]));
	return 1;
}

// 判断用户输入的房屋名字
int check_name(object me, string arg)
{
	if (! arg || arg == "")
	{
		luban_say("你怎么不说话？要是不想谈了(stop)，明说就是！\n");
		return 0;
	}
	if (arg == "stop")
	{
		do_stop();
		return 0;
	}
	if (! check_legal_name(arg, me->query_temp("contract/luban/position"))) return 0;

	// 记录商谈好的房屋名字
	me->set_temp("contract/luban/name", arg);

	luban_say("请确定你的房屋的代号(3到10个英文字母)，考虑好了就回答我(answer id)。\n");
	me->set_temp("contract/luban/questing", "quest_id");
	return 1;
}

// 判断用户输入的房屋代号
int check_id(object me, string arg)
{
	if (! arg || arg == "")
	{
		luban_say("你怎么不说话？要是不想谈了(stop)，明说就是！\n");
		return 0;
	}
	if (arg == "stop")
	{
		do_stop();
		return 0;
	}
	if (! check_legal_id(arg)) return 0;

	// 记录商谈好的房屋代号
	me->set_temp("contract/luban/id", arg);

	luban_say("你想要哪种样式的住房(answer type)? 若是不太清楚，你可以到附近的小院一观。\n");
	me->set_temp("contract/luban/questing","quest_type");
	return 1;
}

// 判断用户输入的房屋类型
int check_type(object me, string arg)
{
	mapping *example;
	int value;

	if (! arg || arg == "")
	{
		luban_say("你想要哪种样式的住房(answer type)？若是不太清楚，你可以到附近的小院一观。\n");
		return 0;
	}
	if (arg == "stop")
	{
		do_stop();
		return 0;
	}
	if (! (example = check_legal_type(arg)))
	{
		luban_say("你要的样式真稀奇，我这现在还没有。看清楚了再告诉我。\n");
		return 0;
	}
	// 记录用户选定的房屋类型
	me->set_temp("contract/luban/room", example);

	// 计算房屋的价值 - 房屋数 * 2000 gold
	value = me->query_temp("contract/luban/room/value");
	if (wizardp(me)) value = 0;
	me->set_temp("contract/luban/value", value);

	quest_info(me);
	return 1;
}

// 判断用户输入的房屋名是否合法
// 同时判断该处是否已经有住房
// Copy & modify from /adm/daemons/logind.c
int check_legal_name(string name, string position)
{
	object ob;
	int i;

	i = strlen(name);

	if( (strlen(name) < 4) || (strlen(name) > 16 ) ) {
		write("对不起，你房屋的名字必须是 2 到 8 个中文字。\n");
		return 0;
	}
	while(i--)
	{
		if( name[i] <= ' ' )
		{
			write("对不起，你的房屋名字不能用控制字元。\n");
			return 0;
		}
		if( i % 2==0 && ! is_chinese(name[i..<0]) )
		{
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}

	ob = get_object(position);
	if (! objectp(ob)) return 1;

	if (ob->exist_room(name))
	{
		luban_say("对不起，据我所知，那里已经有一个住房叫这个名字了！请另外起一个名字。\n");
		return 0;
	}

	return 1;
}

// 判断用户输入的房屋代号是否合法
int check_legal_id(string roomid)
{
	int i;

	i = strlen(roomid);

	if( (strlen(roomid) < 3) || (strlen(roomid) > 10 ) ) {
		write("对不起，你房屋的代号必须是 3 到 10 个英文字母。\n");
		return 0;
	}
	while(i--)
	{
		if(((roomid[i] < 'A') || (roomid[i] > 'Z')) &&
		   ((roomid[i] < 'a') || (roomid[i] > 'z')))
		{
			write("对不起，你房屋的代号必须用英文字母。\n");
			return 0;
		}
	}
	return 1;
}

// 判断用户输入的房屋类型是否存在
// 如果存在则返回那个房屋类型对应的mapping的指针
mixed check_legal_type(string type)
{
	int i;
	for (i = 0; i < sizeof(room_example); i++)
	{
		if (room_example[i]["type"] == type ||
		    room_example[i]["name"] == type )
		return room_example[i];
	}
	return;
}

// 获得一个房屋对象
object get_object(string file_name)
{
	object ob;

	if (! file_name || file_name == "")
		return 0;

	if (! (ob = find_object(file_name)))
		ob = load_object(file_name);

	return ob;
}

// 记录用户描述某一间房间的信息
int record_desc(object me, string room_name, string desc)
{
	mapping filesp;
	mapping descsp;

	int i;
	object ob;
	string *names;

	if (! (desc = obey_description(desc))) return 0;

	filesp = me->query_temp("contract/luban/room/files");
	descsp = me->query_temp("contract/luban/descs");

	names = keys(filesp);
	for (i = 0; i < sizeof(names); i++)
	{
		// 查找该房屋的object
		ob = get_object(filesp[names[i]]);
		if (ob->query("short") == room_name || names[i] == room_name)
		{
			// 查找用户输入的描述信息
			if (! desc || desc =="")
			{
				write("你没有输入描述" + room_name + "的信息，将使用系统缺省的描述信息。\n");
				write("缺省的描述信息如下：\n" + sort_desc(ob->query("default_long")));
				map_delete(descsp, names[i]);
			} else
			{
				descsp[names[i]] = desc;
				write("你描述了" + ob->query("short") + "。\n");
			}
			return 1;
		}
	}
	write("没有找到" + room_name + "，请查证再输入描述信息。\n");
	return 0;
}

// 保存用户输入的建房信息
void record_contract(object me)
{
	string id;
	mapping descp;

	id = me->query("id");
	if (! mapp(query("form"))) delete("form");

	set_form(id, "player", me->query("name"));
	set_form(id, "name", me->query_temp("contract/luban/name"));
	set_form(id, "id", me->query_temp("contract/luban/id"));
	set_form(id, "room", me->query_temp("contract/luban/room/name"));
	set_form(id, "type", me->query_temp("contract/luban/room/type"));
	set_form(id, "position", me->query_temp("contract/luban/position"));
	set_form(id, "value", me->query_temp("contract/luban/value"));
	set_form(id, "time", time());
	set_form(id, "status", "申请");
	set_form(id, "wizard", "无");
	set_form(id, "memo", "无");

	descp = me->query_temp("contract/luban/descs");

	set_form(id, "descs", descp);
	save();
}

// 改变玩家描述某一间房间的信息
// 修改的数据是存放在form中的
int modify_desc_in_form(string player_id, string room_name, string desc)
{
	mapping example;
	mapping filesp;
	mapping descsp;

	int i;
	object ob;
	string *names;

	if (! (desc = obey_description(desc))) return 0;

	if (! (example = check_legal_type(query_form(player_id, "type"))))
	{
		write("这种房屋的类型已经不存在了，所以没有改变房屋的描述，请和巫师联系。\n");
		return 1;
	}

	filesp = example["files"];
	descsp = query_form(player_id, "descs");
	names = keys(filesp);

	for (i = 0; i < sizeof(names); i++)
	{
		// 查找该房屋的object
		ob = get_object(filesp[names[i]]);
		if (ob->query("short") == room_name || names[i] == room_name)
		{
			// 查找用户输入的描述信息
			if (! desc || desc =="")
			{
				write("你没有输入描述" + room_name + "的信息，将使用系统缺省的描述信息。\n");
				write("缺省的描述信息如下：\n" + sort_desc(ob->query("default_long")));
				map_delete(descsp, names[i]);
			} else
			{
				descsp[names[i]] = desc;
				write("你重新描述了" + ob->query("short") + "。\n");
			}
			return 1;
		}
	}
	write("没有找到" + room_name + "，所以没有修改描述信息。请查证再修改描述信息。\n");
	return 0;
}

// 讲一个描述的字符串正规化
string obey_description(string desc)
{
	if (strlen(desc) > 330)
	{
		luban_say("你的描述也太长了吧...\n");
		return 0;
	}

	if (! desc || desc == "") return "";

	desc = replace_string(desc, "\"", "'");
	desc = replace_string(desc, "\\n", "\n");
	desc = replace_string(desc, "\t", "");
	desc = replace_string(desc, " ", "");
	desc = replace_string(desc, "$BLK$", BLK);
	desc = replace_string(desc, "$RED$", RED);
	desc = replace_string(desc, "$GRN$", GRN);
	desc = replace_string(desc, "$YEL$", YEL);
	desc = replace_string(desc, "$BLU$", BLU);
	desc = replace_string(desc, "$MAG$", MAG);
	desc = replace_string(desc, "$CYN$", CYN);
	desc = replace_string(desc, "$WHT$", WHT);
	desc = replace_string(desc, "$HIR$", HIR);
	desc = replace_string(desc, "$HIG$", HIG);
	desc = replace_string(desc, "$HIY$", HIY);
	desc = replace_string(desc, "$HIB$", HIB);
	desc = replace_string(desc, "$HIM$", HIM);
	desc = replace_string(desc, "$HIC$", HIC);
	desc = replace_string(desc, "$HIW$", HIW);
	desc = replace_string(desc, "$NOR$", NOR);
	desc = desc + NOR;

	return desc;
}

// 列出表单
// 巫师使用
int do_list(string arg)
{
	if (! exist_form()) return 1;

	if (! arg || arg == "" || arg == "all" || arg == "全部" || arg == "所有")
	{
		show_apply();
		show_agree();
		show_reject();
		show_old();
		return 1;
	}

	switch (arg) {
	case "apply":
	case "申请":
	case "new":
		show_apply();
		return 1;

	case "agree":
	case "同意":
	case "批准":
		show_agree();
		return 1;

	case "reject":
	case "否决":
	case "不批准":
	case "没批准":
		show_reject();
		return 1;

	case "old":
	case "旧":
		show_old();
		return 1;
	}

	write("list的使用说明：\nlist all   : 显示所有的表单。\nlist apply : 显示申请的表单。\n" +
	      "list agree : 显示巫师已经批准的表单。\nlist reject : 显示巫师已经否决的表单。\n" +
	      "list old   : 显示过期很久的表单。\n\n");
	return 1;
}

// 显示表单的详细信息
// 格式：type player_id room_name 显示该player描述的某间房屋
//   或：type player_id           显示该player的所有描述
// 此时如果由其他玩家正在输入，也可以察看
int do_type(string arg)
{
	string player_id;
	string room_name;
//	int a;

	if (! wizardp(this_player()) || wiz_level(this_player()) < WIZLEVEL)
	{
		write("你无权察看表单中的描述信息！\n");
		return 1;
	}
	if (!arg||arg=="")
		return notify_fail("type player_id room_name\n");
	if (sscanf(arg, "%s %s", player_id, room_name) != 2)
	{
		player_id = arg;
		room_name = "";
	}

	show_desc(player_id, room_name);
	return 1;
}

// 显示一个申请的简要说明
void show_brief(string player_id)
{
	mapping form;
	string msg;
	string wizard;
	string memo;
//	int i;

	form = query("form/" + player_id);
	if (! form || ! mapp(form)) return;

	// 申请者ID    申请者姓名  申请时间    房  型  状态  注册的巫师  备   注
	// 10         .10        . 10        . 6      .4    .10         .16
	msg = sprintf("%10s  %10s  %10s  %6s", player_id, form["player"], ctime(form["time"])[0..9], form["type"]);

	// 现实表单的状态
	switch (form["status"]) {
	case "申请" :
		msg += HIW;
		break;

	case "同意" :
		msg += HIY;
		break;

	case "拒绝" :
		msg += HIR;
		break;
	}
	msg += "  " + form["status"] + NOR + "  ";

	wizard = form["wizard"];
	memo = form["memo"];

	if (! stringp(wizard) || wizard == "无" || wizard == "")
		wizard = "----------";

	if (! stringp(memo) || memo == "无" || memo == "")
		memo = "------";

	msg += sprintf("%10s  %s\n", wizard, memo);
	write(msg);
	return;
}

// 判断表单是否存在，调用者是否有资格处理该表单
int exist_form()
{
	if (! mapp(query("form")) || sizeof(query("form")) < 1)
	{
		write("现在并没有任何表单。\n");
		return 0;
	}
	if (! wizardp(this_player()) || wiz_level(this_player()) < WIZLEVEL)
	{
		write("你无权处理表单。\n");
		return 0;
	}
	return 1;
}

// 批准表单
// 巫师使用
int do_agree(string arg)
{
	if (! exist_form()) return 1;

	if (! arg || arg == "" || ! query("form/" + arg))
		return notify_fail("你要操作谁的表单？\n");


	if (query("form/" + arg + "/status") == "同意")
	{
		write("已经有其他巫师批准此表单了。\n");
		return 1;
	}
	set("form/" + arg + "/status", "同意");
	set("form/" + arg + "/wizard", this_player()->query("name"));
	set("form/" + arg + "/memo", "无");
	write("你批准了" + query("form/" + arg + "/player") + "(" + arg + ")的申请。\n");
	save();

	return 1;
}

// 拒绝表单
// 巫师使用
int do_reject(string arg)
{
	string player;
	string memo;

	if (! exist_form()) return 1;

	if (! arg || arg == "")
		return notify_fail("你要操作谁的表单？\n");

	if (sscanf(arg, "%s %s", player, memo) != 2)
	{
		player = arg;
		memo = "无";
	}

	if (! query("form/" + player))
		return notify_fail("你要操作谁的表单？\n");

	if (memo == "无")
	{
		write("你可以添加备注信息(reject player 备注信息)，说明拒绝的理由。\n");
	}

	set("form/" + player + "/status", "拒绝");
	set("form/" + player + "/wizard", this_player()->query("name"));
	set("form/" + player + "/memo", memo);

	write("你已经拒绝了" + query("form/" + player + "/player") + "(" + player + ")的申请。\n");
	save();

	return 1;
}

// 删除表单
// 巫师使用
int do_delete(string arg)
{
	if (! exist_form()) return 1;

	if (! arg || arg == "" || (! query("form/" + arg) && arg != "old"))
		return notify_fail("你要操作谁的表单？\n");

	if (query("form/" + arg + "/status") == "申请")
	{
		return notify_fail("你不能删除一个申请后还没有处理的表单。\n");
	}

	write("" + query("form/" + arg + "/player") + "(" + arg + ")提交的表单被删除了。\n");
	delete("form/" + arg);
	save();

	return 1;
}

// 显示刚刚申请的表单
void show_apply()
{
	show_brief_list("申请", HIW + "以下是玩家提交的申请的表单" + NOR);
}

// 显示被批准的表单
void show_agree()
{
	show_brief_list("同意", HIY + "以下是巫师已经批准申请的表单" + NOR);
}

// 显示被拒绝的表单
void show_reject()
{
	show_brief_list("拒绝", HIR + "以下是被巫师拒绝申请的表单" + NOR);
}

// 显示比较陈旧的表单 - 过了15天的表单
void show_old()
{
	int i;
	int count;

	string *ids;

	if (! exist_form()) return;

	count = 0;
	ids = keys(query("form"));
	for (i = 0; i < sizeof(ids); i++)
	{
		if (query("form/" + ids[i] + "/time") - time() > 86400 * 15)
		{
			// 超过15天的表单
			if (! count)
			{
				write(YEL "-------------------------------------------------------------------------------\n" NOR);
				write(HIC "以下是玩家提交了很久的表单：\n" + NOR);
				show_brief_title();
			}
			count++;
			show_brief(ids[i]);
		}
	}
	if (count)
	{
		write("共有" + ((string) count) + "张比较陈旧的表单。\n");
	}
}

// 显示列表
// info是显示的表单的类型 - info为空表示显示所有表单
// msg是显示的列表的名称 - 如“这是巫师批准的表单”
void show_brief_list(string info, string msg)
{
	int i;
	int count;

	string *ids;

	if (! exist_form()) return;

	count = 0;
	ids = keys(query("form"));
	for (i = 0; i < sizeof(ids); i++)
	{
		if (info == "" || query("form/" + ids[i] + "/status") == info)
		{
			if (! count)
			{
				write(YEL "-------------------------------------------------------------------------------\n" NOR);
				write(msg + "\n");
				show_brief_title();
			}
			count++;
			show_brief(ids[i]);
		}
	}
	if (count)
	{
		write("共有" + ((string) count) + "张表单。\n");
	}
}

// 显示列表题头
void show_brief_title()
{
	write("申请者代号  申请者姓名  申请的时间  房  型  状态  注册的巫师  备   注\n");
}

// 根据一个表单建造房屋
void create_room(object me)
{
	mapping filesp;		// 建造的原型房的文件mapping
	mapping descsp;		// 玩家填写的描述mapping

	string player_id;	// 建找房间的玩家的ID
	string room_type;	// 房屋类型
	string room_name;	// 房屋名字
	string room_id;		// 房屋ID
	string room_owner;	// 房屋的主人
	string room_key;	// 房屋的钥匙
	string position;	// 建造房屋的地点(路径名)
	string position_short;	// 建造房屋的地点的中文名字
	string entry;		// 房屋的入口

	string *content;	// 源文件的内容
	string *names;		// filesp的关键字集合
	string filename;	// 生成的文件名称
	string dstfile;		// 生成的文件内容

	string desc;		// 某间房屋的描述::钥匙的描述
	object ob;		// 房屋的object

	int i;
	int k;
	string ids;		// 快捷查询字符串

	me = this_player();
	if (! objectp(me)) return;

	player_id = me->query("id");
	entry = "";

	if (! mapp(query("form/" + player_id)))
	{
		// 没有找到玩家提交的表单
		return;
	}

	// 在表单中有该玩家提交的表单
	ids = "form/" + player_id + "/";
	room_type = query(ids + "type");
	for (i = 0; i < sizeof(room_example); i++)
	{
		if (room_example[i]["type"] == room_type)
		{
			filesp = room_example[i]["files"];
			break;
		}
	}

	if (! mapp(filesp))
	{
		write("你申请的房屋类型(" + room_type + ")已经不存在了，请和巫师联系。\n");
		return;
	}

	descsp = query(ids + "descs");
	room_type = query(ids + "room");
	room_name = query(ids + "name");
	room_id = query(ids + "id");
	position = query(ids + "position");
	names = keys(filesp);

	room_owner = query(ids + "player");
	room_key = "key of " + player_id;

	ob = get_object(position);
	if (! objectp(ob))
	{
		write ("你建房的地点已经不存在了，请和巫师联系！\n");
		return ;
	}
	position_short = ob->query("short");
	message("vision", HIY "鲁班拍拍手，说道：弟子们，生意来了！赚金子银子的时候到了！！！\n" NOR +
		       YEL "霎时天昏地暗，你只觉得眼前模模糊糊，什么也看不清楚，浑然不知道发生了什么事情。\n" NOR, environment(this_object()));

	// 读入并处理所有的文件
	for (i = 0; i < sizeof(names); i++)
	{
		// long_flag 是为了将原型房文件中出现在@LONG和LONG之间的字符串去掉而使用的标志。
		int long_flag;
		// enter_receive 是为了消除过多的空行使用的
		int enter_receive;

		if (file_size(filesp[names[i]]) <= 0)
		{
			write("缺少文件:" + filesp[names[i]] + "，不能生成房屋，请和巫师联系。\n");
			// 删除已经产生的文件
			for (k = i - 1; k >= 0; k--)
				rm(to_player(player_id, filesp[names[k]]));
			return;
		}
		content = explode(read_file(filesp[names[i]]), "\n");
		long_flag = 0;
		enter_receive = 0;
		filename = to_player(player_id, filesp[names[i]]);
		dstfile = "// File(" + to_player(player_id, filesp[names[i]]) + ")" +
			  " of " + player_id + "'s room\n// Create by LUBAN which written by Robert\n";
		for (k = 0; k < sizeof(content); k++)
		{
			if (strsrch(content[k], "LONG") != -1)	// 查到了一个LONG标志
			{
				long_flag = ! long_flag;
				if (! long_flag)
				{
					// 填充新的long描述
					desc = descsp[names[i]];
					if (! desc || desc == "")
					{
						// 采用了缺省描述
						ob=get_object(filesp[names[i]]);
						desc = ob->query("default_long");
					}
					desc = replace_string(desc,"ROOM_POSITION", position_short);
					desc = sort_desc(desc);
					dstfile += "\tset (\"long\", @LONG\n" + desc + "LONG\n";
				}
				continue;
			}
			// 如果是LONG描述则忽略
			if (long_flag) continue;

			// 如果该句包含有/**/则忽略
			if (strsrch(content[k], "/**/") != -1) continue;

			// 去除语句中的//**
			content[k] = replace_string(content[k], "//**", "");

			// 如果该句以//开头，表示注释，则忽略
			if (content[k][0..1] == "//") continue;

			// 判断该文件是否是入口文件，即该文件是否有到建房处(position)的出口
			if (strsrch(content[k], "/d/room/xiaoyuan") != -1)
				entry = filename;

			// 替换语句中的ROOM_KEY, OWNER, position
			content[k] = replace_string(content[k], "ROOM_KEY", room_key);
			content[k] = replace_string(content[k], "ROOM_OWNER", room_owner);
			content[k] = replace_string(content[k], "ROOM_NAME", room_name);
			content[k] = replace_string(content[k], "ROOM_ID", room_id);
			content[k] = replace_string(content[k], "ROOM_POSITION", position_short);
			content[k] = replace_string(content[k], "/d/room/xiaoyuan", position);

			// 添加该语句
			if (content[k] == "")
				enter_receive ++;
			else
				enter_receive = 0;
			if (enter_receive > 1) continue;

			dstfile += content[k] + "\n";
		}
		if (long_flag)
		{
			write("文件:" + filesp[names[i]] + "格式错误，LONG不匹配，不能生成房屋，请和巫师联系。\n");
			// 删除已经产生的文件
			for (k = i - 1; k >= 0; k--)
				rm(to_player(player_id, filesp[names[k]]));
			return;
		}

		// 写入磁盘
		seteuid(getuid());
		rm(filename);
		assure_file(filename);
		write_file(filename, dstfile);
		dstfile = "";
	}

	// 在建房处添加入口到玩家的房屋
	if (! entry || entry == "")
	{
		message("vision", "\n过了一会，鲁班和众弟子踉踉跄跄的赶了回来。\n鲁班苦着脸说：这是怪事，居然找不到入口！你去问问巫师究竟是怎么搞的！\n", environment(this_object()));
		// 删除已经产生的文件
		for (k = i - 1; k >= 0; k--)
			rm(to_player(player_id, filesp[names[k]]));
		return;
	}

	ob = get_object(position);
	if(!ob->create_room(room_name, entry))
	{
		message("vision", "\n过了一会，鲁班和众弟子踉踉跄跄的赶了回来。\n鲁班一脸霉样，苦着脸说：真邪门了，那里居然还有个名字一样的房子，结果我们被人扁了回来！\n奶奶的头，我公输班活了一千多年还是头次听闻这种事！\n", environment(this_object()));
		// 删除已经产生的文件
		for (k = i - 1; k >= 0; k--)
			rm(to_player(player_id, filesp[names[k]]));
		return;
	}
	message("vision", "\n须臾，鲁班和众弟子已然归来。\n鲁班喜道：呵呵，房屋建好了，一切顺利，恭喜恭喜！\n", environment(this_object()));
	//ob->set("exits/enter", entry );        //修改没有创建房屋入口的bug   山猫Adx
	ob->save();
	reload_object(ob);

	// 创建玩家房屋的钥匙文件
	filename = "/data/room/" + player_id + "/key.c";
	dstfile = "// File(" + filename + ")" +
		  " of " + player_id + "'s key\n// Create by LUBAN which written by Doing Lu\n";
	dstfile += @KEY

inherit ITEM;
#include <ansi.h>

string query_autoload() { return "1"; }

void autoload(string param)
{
}


void create()
{
	set_name(YEL "KEY_NAME" NOR, ({"key", "KEY_ID"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "KEY_DESCRIPTION。\n");
		set("unit", "把");
		set("no_pawn", 1);
		set("item_make", 1);
		set("value",0);
		set("no_steal",1);
		set("no_get",1);
		set("no_beg",1);
		set("no_put",1);
		set("key_master","KEY_MASTER");
	}
}
KEY;
	// 替换钥匙名称，ID，描述
	desc = "一把用来开启" + room_name + "(" + room_id + ")的钥匙。\n";
	dstfile = replace_string(dstfile, "KEY_DESCRIPTION", desc);
	dstfile = replace_string(dstfile, "KEY_NAME", me->query("name") + "家的钥匙");
	dstfile = replace_string(dstfile, "KEY_ID", room_key);
	dstfile = replace_string(dstfile, "KEY_MASTER",me->query("id"));

	seteuid(getuid());
	rm(filename);
	assure_file(filename);
	write_file(filename, dstfile);

	// 生成钥匙
	ob = clone_object(filename);
	message_vision("鲁班拿出一把钥匙，对$N说：诺，这是钥匙，收好了！若是丢了可以到我这里再配一把。\n", me);
	ob->move(me);

	// 删除鲁班处纪录的表单
	delete("form/" + player_id);
	save();

	// 设置玩家的数据库
	me->set("private_room/build", 1);		// 已经建过房屋
	me->set("private_room/position", position);	// 房屋所在的位置
	me->set("private_room/entry", entry);		// 房屋入口处的文件路径				:: 必须已经有build设置
	me->set("private_room/name", room_name);	// 房屋的名字
	me->set("private_room/id", room_id);		// 房屋的ID
	me->set("private_room/type", room_type);	// 房屋的类型
	me->save();
	return;
}

// 将原型房的文件名转化成为用户房屋的文件名
string to_player(string player_id, string file_name)
{
	string typestr;
	string retstr;

	sscanf(file_name, "/d/room/%s/%s", typestr, retstr);
	return "/data/room/" + player_id + "/" + retstr;
}

// 这是为了加快运行速度使用的宏函数
// 判断首部的字符串是否相同(字符串1必须比字符串2长)
#define	IS_HEAD(s1,s2)	  (s1[0..strlen(s2) - 1] == s2)
// 判断字符串首部是否为英文标点符号
#define	IS_HEAD_ESIGH(s1) (s1[0] == '.' || s1[0] == '!' || s1[0] == ';' || s1[0] == ',' || s1[0] == ':')
// 判断字符串首部是否为中文标点符号
#define	IS_HEAD_CSIGH(s1) (s1[0..1] == "。" || s1[0..1] == "！" || s1[0..1] == "；" || s1[0..1] == "，" || s1[0..1] == "：")
// 判断字符串首部是否是中文字符
#define	IS_HEAD_CHN(s1)	  (s1[0] >= 128)

// 规范描述信息
// 这个函数主要为讲用户输入的描述信息添加回车和跳格
string sort_desc(string desc)
{
	string res;
	int len;		// desc的剩余长度
	int curlen;		// res的当前行长
	int perline = 63;	// 最大行长(如果有标点符号，可能会超出)
	int crlen;		// 换行符的长度
	int escflag;		// 转义序列的长度

	res = "";
	curlen = 4;		// 新段落前的跳格长度

	crlen = strlen("\n");
	escflag =0;

	if (! desc || desc =="")
		return 0;

	for (len = strlen(desc);(len + curlen > perline) && len > 0;)
	{
		// 添加字符
		// 判断是否为汉字
		while (curlen < perline)
		{
			if (IS_HEAD_CHN(desc))
			{
				res += desc[0..1];
				desc = desc[2..len - 1];
				len -=2;
				curlen += 2;
			} else
			if (desc[0] >= 32)
			{
				res += desc[0..0];
				desc = desc[1..len - 1];
				len --;
				curlen ++;
			} else
			  break;
		}

		// 判断下一个字符是否为标点，标点不能出现在行首
		if (IS_HEAD_CSIGH(desc) && curlen < perline + 2)
		{
			res += desc[0..1];
			desc = desc[2..len - 1];
			len -= 2;
			curlen += 2;
		}

		if (IS_HEAD_ESIGH(desc) && curlen < perline + 2)
		{
			res += desc[0..0];
			desc = desc[1..len - 1];
			len --;
			curlen ++;
		}

		// 如果计满一行，就添加换行符
		if (curlen >= perline)
		{
			res += "\n";
			curlen = 0;
		}

		// 判断是否为换行
		if (IS_HEAD(desc, "\n"))
		{
			if (curlen) res += "\n";	// 避免刚刚有换行
			res += "    ";
			desc = desc[crlen..len - 1];
			len -= crlen;
			curlen = 4;
		}

		// 扫描desc，查找转义字符
		if (desc[0] == 27)
			while (desc[escflag] != 'm') escflag++;

		if (escflag > 0)
		{
			// 颜色不计长度
			res += desc[0.. escflag];
			desc = desc[escflag + 1..len - 1];
			len -= escflag + 1;
			continue;
		}
	}

	// 消除行尾的换行符
	if (len >= crlen && desc[len - crlen..len - 1] != "\n" ) desc += "\n";

	res += desc;
	return res;
}
