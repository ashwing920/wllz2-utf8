// story:shanzei

#include <ansi.h>

string *place = ({
	"/d/center/guangchang",
	"/d/city/guangchang",
	"/d/dali/center",
	"/d/city2/tian_anm",
});

string give_gift();

private mixed *story = ({
        "报～～报～～，一个深受重伤的士兵苟延残喘，挣扎的爬进了军营。",
        "士兵：报. .报告. . .将军，乱贼. .李..自成攻陷京城，京城失势了！！",
        "吴三桂：啊～，那现在京城之里情况怎样？",
        "士兵：李自成的军队象疯狗一样在城里滥杀无辜，奸淫掳掠，百姓死的死，逃得逃，乱成一片。",
        "吴三桂一把揪起士兵的盔甲，急道：那，那陈圆圆呢？！",
        "士兵慌道：陈圆圆，陈圆圆也被李自成一起抓进宫了～～",
        "吴三桂摸了摸鼻子，怒道：妈的！老子一定要把圆圆抢回来！",
        "吴三桂：全军将士听令，我欲与清兵议和，所有人原地待命，如有违令，格杀勿论。",
        "士兵：啊～",
        "终于，吴三桂以“为祟祯皇帝报仇”为由，将清兵引入关内。",
        (: give_gift :)
});
private void create(){ seteuid(getuid());}
mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
string give_gift()
{
        object obj;
        int i,n;
        string path;
        path = place[random(sizeof(place))];
        n = random(10) + 5;
        for(i=0;i<n;i++){
        	obj = new("/clone/npc/qingbing");
        	obj->move(path);
        }
        return CHANNEL_D->do_channel(this_object(),"rumor","听说吴三桂那大汉奸将清兵引入关啦！！");
}
