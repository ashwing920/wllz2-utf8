// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short","般若台");
        set("long",@LONG
这是个普通的石台，相传当年佛祖曾降临此台传法。再往南去就是本
寺重地——牟尼堂。江湖中传言天龙寺的镇寺之宝——六脉神剑谱就藏于
此中，但你千万不要打什么主意。
LONG
);
        set("exits",([
                "south": __DIR__"munitang",
                "north": __DIR__"doushuai",
        ]));
        setup();
}
void init()
{
        if(this_object() && !this_object()->query("exits")){
                remove_call_out("reset_path");
                call_out("reset_path",120,this_object());
        }
}
void reset_path()
{
        if(this_object()->query("exits")) return;
        set("exits",([
                "south": __DIR__"munitang",
                "north": __DIR__"doushuai",
        ]));
        return;
}
