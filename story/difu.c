// story:difu

#include <ansi.h>

string random_player();
string prompt() {
        return HIR"【阴曹地府】"NOR;
}
private mixed *story = ({
        "地府阎罗殿上，生死判官崔珏正在仔细的翻阅着《生死薄》！",
        "崔珏：咦？黑白无常何在？！",
        "黑白无常：小的在！小的在. . .",
        "崔珏：外间为何这般吵闹，孤魂啼哭不断？你等做何事去了？",
        "黑无常：禀告判官，近日有一恶人，一日内屠杀数条人命，凡间生灵无不遭殃！",
        "白无常：我与黑无常每日二更天时分便要上阳间，接引亡灵. . .",
        "崔珏：哦？！那厮是何方神圣，竟敢这般做恶！速去带来给我瞧瞧！",
        "黑白无常：是！小的这就去将其带来！",
        (: random_player() :),
});
void create(){ seteuid(getuid());}
mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
string random_player()
{
        int i;
        object *ob,player;

        ob = filter_array(children(USER_OB),(: userp :));
        if(sizeof(ob))
        i = sizeof(ob);
        while(i--){
                if(!environment(ob[i])) continue;
                if(ob[i]->query("PKS") < 10) continue;
                if( wizardp(ob[i])) continue;
                player = ob[random(i)];
        }
        if(player){
                tell_object(player,HIW"一道白光突然在你眼前泛起，你仿佛看见黑、白无常正在向你招手！\n"NOR);
                tell_object(player,HIW"\n慢慢的，慢慢的. . . 你已经昏昏欲睡 . . . \n"NOR);
                player->unconcious();
                CHANNEL_D->do_channel(this_object(),"rumor", sprintf("听说%s的魂魄被黑白无常勾走了！！",player->name()));
                return "黑白无常：大人，"+ player->query("name")+"已经带来了。";
        }
        else {
                return "黑白无常跑上凡间来捉拿恶人啦！";
        }

}
